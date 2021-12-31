

/////////////////////////////////////////////////////////////////////
//
// connections.cpp: implementation of the connections class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


extern connection_services_multimap	*gsm_connection_services;
extern connections	*gsm_connections;
extern package_map	*gsm_packages;


void reversethis(char s[])
{
        int c, i, j;

        for (i=0, j=strlen(s)-1; i<j; i++, j--)
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}

void myitoathis(int n, char s[])
{
        int i, sign;
 
        if ((sign = n) < 0)
        n = -n;
 
        i = 0;
        do
        {
                s[i++] = n % 10 + '0';
        }
        while
        ((n /= 10) > 0);
 
        if (sign<0)
        s[i++] = '-';
        s[i] = '\0';
        reversethis(s);
}

void connections::print_detail()
{
	for(CONNECTION_DEF::iterator i=conn.begin(); i!=conn.end(); i++)
		cout<<"{"<<(*i).first<<"} {"<<(*i).second.connection<<"}"<<endl;
}


connections::connections()
{
	start_date=""; 
	current=NULL;
}

// sets the current pointer to correct account_no
bool connections::set_current(int account_no)
{
	i_current = conn.find(account_no);
	if(i_current != conn.end())
	{
		current=&(*i_current).second;
		return true;
	}
	return false;
}

float connections::get_vat_amount(float amount, float vat_rate)
{

//	int int_vat_amount = (int)(amount*vat_rate*100);
// The above line was commented because truncation occured in the value assignment to int_vat_amount

	float float_vat_amount1 = (amount*vat_rate*100);

	double float_vat_amount = (double)(float_vat_amount1/100.0);

	return float_vat_amount;
}


void connections::calc_conn_serv_rental()
{
/*
Calculates the individual service rentals(i.e. SER_<SERVICE_CODE> ) and adds that up
and calculates the total service rental (i.e. SER_RENTAL)
*/

	bool	bAddServRental = false; /* A flag to denote whether to calculat ethe service rentals */
	bool	vat	=	false;	// VAT Registered, show tax as previously shown
	float	cVatRate	=	1.15;
	const	char*	cGRICIdenti = "GRIC";

	current->charge.ser_email			=	0;
	current->charge.ser_http			=	0;
	current->charge.ser_gric			=	0;
	current->charge.ser_fhttp			=	0;
	current->charge.mail_box_rental		=	0;
	current->charge.ser_other			=	0;

	// Adding rentals from connection_services
	if (current->connection.rental_applicability)
	{
		CONNECTION_SERVICES_DEF::iterator i_csd=gsm_connection_services->all_connection_services.begin();
		//cout << "MAP SIZE CONNECTION_SERVICES: " << gsm_connection_services->all_connection_services.size() << endl;
		while (i_csd != gsm_connection_services->all_connection_services.end())
		{
			if ( gsm_connections->current->connection.account_no == (*i_csd).second.account_no )
			{
			
				// Addition by Arjuna Aryasinha on 2003-NOV-10
				//------------------------------------------------------------------------

				bAddServRental = false;

				// If the connection status is perm. disconnected
				if ( strcmp( ((*i_csd).second.connection_status).c_str(), "PDISC") == 0 )
				{


					// Check if the copy of end date falls within the start and end of bill cycle
					if 
					(
						( 
							(	
								( gsm_connections->reng_start_date <  ((*i_csd).second.reng_end_date) ) ||
								( gsm_connections->reng_start_date == ((*i_csd).second.reng_end_date) ) 
							)
						)
						&&
						(
							( 
								( ((*i_csd).second.reng_end_date) <  gsm_connections->reng_end_date ) ||
								( ((*i_csd).second.reng_end_date) == gsm_connections->reng_end_date )
							)
						)
					)
					{
						// set the flag not to apply rental to the bill, both package and service
						bAddServRental = true;
					}
					else
					{
						bAddServRental = false;
					}
				}
				else
				{
					bAddServRental = true;
				}

				//------------------------------------------------------------------------
				// End of addition by Arjuna Aryasinha on 2003-NOV-10

				// Addition by Arjuna Aryasinha on 2003-NOV-10
				//------------------------------------------------------------------------


				/* If the connection service is eligible for rental applicability, then calculate rental */
				if ( bAddServRental )
				{
				
					if  ( (strcmp( "EMAIL", ((*i_csd).second.service_code).c_str()) )==0)
					{
						current->charge.ser_email += (*i_csd).second.rental;

					}

					else if ( (strcmp( "HTTP", ((*i_csd).second.service_code).c_str()) )==0)
					{
						current->charge.ser_http += (*i_csd).second.rental;
					}
					else if ( (strcmp( "FHTTP", ((*i_csd).second.service_code).c_str()) )==0)
					{
						current->charge.ser_fhttp += (*i_csd).second.rental;
					}

					// Added by Arjuna Aryasinha - 2002.APR.23
					else if ( cGRICIdenti == (*i_csd).second.service_code )
					{
						if ( current->call.gric_charge > 0.001 ) 
						{
							current->charge.ser_gric += (*i_csd).second.rental;
						}
					}
					// End of addition by Arjuna Aryasinha - 2002.APR.23

					else 
					{
						current->charge.ser_other += (*i_csd).second.rental;
					}

				}

				//-------------------------------------------------------------
				// End of addition by Arjuna Aryasinha on 2003-NOV-10
		
			}
			i_csd++;
		}
	}

	current->charge.service_rental = current->charge.ser_email + current->charge.ser_http + current->charge.ser_gric + current->charge.ser_fhttp + current->charge.mail_box_rental + current->charge.ser_other;
}

void connections::prepare_db_log_state()
{
	bool	bAddServRental = false; /* A flag to denote whether to calculat ethe service rentals */
	bool	vat	=	false;	// VAT Registered, show tax as previously shown
	float	cVatRate	=	1.15;
	bill_summary_item bsi;		// VAT - 12-09-2002
	const	char*	cGRICIdenti = "GRIC";

	summary.clear();

	float bal_rental = 0;	// Rental excluding package rental
	float tot_adj	 = 0;	// Total Adjustments

	if ( (strcmp(current->connection.vat_no.c_str(),"UNDEF") == 0  ) && (strcmp((current->connection.tax_group_id).c_str(), "DPL")!=0) )
	{
		vat = true;		// VAT Unregistered - amount*vat_rate - tax=0
	}


	DISCOUNT_DETAIL_DEF:: iterator i_dis;

	for(i_dis = current->discount_detail.begin(); i_dis != current->discount_detail.end(); i_dis++)
	{
		
		char string[80];
		strcpy( string, "DIS_");
		strcat( string, ((*i_dis).first).c_str());

		string[9] = '\0';

		bsi.init();
		bsi.amount = (*i_dis).second;
		
		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount((*i_dis).second,cVatRate);
		}
		else
		{
			bsi.vat_amount = (*i_dis).second;
		}

		summary[string]	= bsi;

		
	}


	TAX_DETAIL_DEF:: iterator i_tax;

	for(i_tax = current->tax_detail.begin(); i_tax != current->tax_detail.end(); i_tax++)
	{
		
		char string[80];
		strcpy( string, "TAX_");
		strcat( string, ((*i_tax).first).c_str());

		int position = strcspn( string, " " );

		string[position] = '\0';

		bsi.init();
		bsi.amount = (*i_tax).second;
		if (vat)
		{
			bsi.vat_amount = 0;
		}
		else
		{
			bsi.vat_amount = (*i_tax).second;
		}

		summary[string]	= bsi;
		
	}

	for (BILL_ADJUSTMENT_TYPE_DEF::iterator j = current->charge.adjustment_items_value_map.begin(); j!=current->charge.adjustment_items_value_map.end(); j++)
		
	{
		char adj_string[80];
		strcpy( adj_string, "ADJ_");
		strcat( adj_string, ((*j).first).c_str());
		adj_string[19] = '\0';

		bsi.init();
		bsi.amount = (*j).second.value;

		if ( vat ) 
		{
			if ( strcmp(adj_string, "ADJ_WORK_ORDER") == 0 )
			{
				// VAT Unregistered, Work Order untaxable adjustment(already taxed)
				bsi.vat_amount = (*j).second.value;
			}
			else
			{
				// VAT Unregistered, Adjustments other than Work Orders should be taxed
				bsi.vat_amount = get_vat_amount((*j).second.value,cVatRate);
			}
		}
		else
		{
			// VAT Registered
			bsi.vat_amount = (*j).second.value;
		}
		
		summary[adj_string]	=  bsi;
		
	}

	
	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i_adv=gsm_connections->rental_advance_payments_map.find(current->connection.account_no);
	
	if (i_adv != gsm_connections->rental_advance_payments_map.end())
	{
		bsi.init();
		bsi.amount = current->charge.pkg_rental;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.pkg_rental,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.pkg_rental;
		}
		summary["RENT_ADV_RECG"]	= bsi;
	}

	bsi.init();
	bsi.amount = current->charge.brought_forward;			// Brought Forward	
	bsi.vat_amount = current->charge.brought_forward;

	summary["B_F"]			= bsi;			// Brought Forward
	
	bsi.init();
	bsi.amount = current->charge.payments;					// Payments
	bsi.vat_amount = current->charge.payments;
	summary["PAYMENTS"]		= bsi;					// Payments
	
	bsi.init();
	bsi.amount = current->charge.taxable_adjustment + current->charge.untaxable_adjustment;

	if ( vat ) 
	{
		bsi.vat_amount = (get_vat_amount( current->charge.taxable_adjustment,cVatRate) ) + current->charge.untaxable_adjustment;
	}
	else
	{
		bsi.vat_amount = current->charge.taxable_adjustment + current->charge.untaxable_adjustment;
	}

	summary["ADJUSTMENTS"]		= bsi;

	bsi.init();
	bsi.amount = current->charge.taxable_adjustment;

	if ( vat ) 
	{
		bsi.vat_amount = get_vat_amount(current->charge.taxable_adjustment,cVatRate);
	}
	else
	{
		bsi.vat_amount = current->charge.taxable_adjustment;
	}
	summary["ADJUSTMENTS_TAX"]	= bsi;
	
	
	bsi.init();
	bsi.amount = current->charge.untaxable_adjustment;
	bsi.vat_amount = current->charge.untaxable_adjustment;

	summary["ADJUSTMENTS_NOTAX"]= bsi;
	
	bsi.init();
	bsi.amount = current->call.charge;	

	if ( vat ) 
	{
		bsi.vat_amount = get_vat_amount(current->call.charge,cVatRate);
	}
	else
	{
		bsi.vat_amount = current->call.charge;
	}
	summary["TOT_USG_CHG"]	= bsi;
	
	// Added by Arjuna Aryasinha - 2002.MAR.26
	bsi.init();
	bsi.amount =  current->call.gric_charge;

	// Irrespective of VAT registration , GRIC is non-taxable
	bsi.vat_amount = current->call.gric_charge;

	summary["TOT_GRIC_CHG"]	= bsi;

	// End of addition by Arjuna Aryasinha - 2002.MAR.26

	bsi.init();
	bsi.amount = current->charge.discounts;

	if ( vat ) 
	{
		bsi.vat_amount = get_vat_amount(current->charge.discounts,cVatRate);
	}
	else
	{
		bsi.vat_amount = current->charge.discounts;
	}

	summary["DISCOUNT"]		= bsi;

	bsi.init();
	bsi.amount = current->charge.tax;
	if ( vat ) 
	{
		bsi.vat_amount = 0;
	}
	else
	{
		bsi.vat_amount = current->charge.tax;
	}
	summary["TAX"]			= bsi;
	
	bsi.init();
	bsi.amount = current->charge.tot_pay; 
	bsi.vat_amount = current->charge.tot_pay; 
	summary["TOT_PAY"]		= bsi;
	
	bsi.init();
	bsi.amount = current->charge.bill_amount; 
	bsi.vat_amount = current->charge.bill_amount; 
	summary["BILL_AMOUNT"]   = bsi;
							
	bsi.init();
	bsi.amount = current->charge.c_f;
	bsi.vat_amount = current->charge.c_f;
	summary["C_F"]				=  bsi;
						

	bsi.init();
	bsi.amount = current->charge.pkg_rental_charge;

	if ( vat ) 
	{

		bsi.vat_amount = get_vat_amount(current->charge.pkg_rental_charge,cVatRate);

	}
	else
	{
		bsi.vat_amount = current->charge.pkg_rental_charge;
	}

	summary["PACK_RENTAL"]		= bsi;
	
	bsi.init();
	bsi.amount = current->charge.pro_rate;	

	if ( vat ) 
	{
		bsi.vat_amount = get_vat_amount(current->charge.pro_rate,cVatRate);
	}
	else
	{
		bsi.vat_amount = current->charge.pro_rate;
	}

	summary["PRO_RATE"]			= bsi;
	
	
	bsi.init();
	bsi.amount = current->call.time_duration - (current->call.free_units - current->call.balance_free_units);
	bsi.vat_amount = bsi.amount;
	summary["CHG_MIN"]			= bsi;
	
	bsi.init();
	bsi.amount = current->call.time_duration;
	bsi.vat_amount = bsi.amount;
	summary["TOT_MIN_USED"]		= bsi;
	
	bsi.init();
	bsi.amount = current->call.free_units;
	bsi.vat_amount = bsi.amount;
	summary["PKG_FREE_MIN"]		=  bsi;
	
	bsi.init();
	bsi.amount = current->call.balance_free_units;
	bsi.vat_amount = bsi.amount;
	summary["BAL_FREE_MIN"]		= bsi;
	
	bsi.init();
	bsi.amount = current->call.free_units - current->call.balance_free_units;
	bsi.vat_amount = bsi.amount;
	summary["FREE_MIN_USED"]	= bsi;

	if (current->charge.ser_email > 0)	
	{
		bsi.init();
		bsi.amount = current->charge.ser_email;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.ser_email,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.ser_email;
		}
	
		summary["SER_EMAIL"]	= bsi;
	}

	if (current->charge.ser_http  > 0)
	{
		bsi.init();
		bsi.amount = current->charge.ser_http;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.ser_http,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.ser_http;
		}

		summary["SER_HTTP"]		= bsi;
	}

	if (current->charge.ser_fhttp  > 0)
	{
		bsi.init();
		bsi.amount = current->charge.ser_fhttp;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.ser_fhttp,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.ser_fhttp;
		}

		summary["SER_FHTTP"]		= bsi;
	}
	
	// Added by Arjuna Aryasinha - 2002.MAR.26
	if (current->charge.ser_gric  > 0.001) 
	{
		bsi.init();
		bsi.amount = current->charge.ser_gric;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.ser_gric,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.ser_gric;
		}
		
		summary["SER_GRIC"]		= bsi;
	}
	else
	{
		bsi.init();
		bsi.amount = 0;
		bsi.vat_amount = 0;
		summary["SER_GRIC"]	= bsi;
	}
	// End of addition by Arjuna Aryasinha - 2002.MAR.26

	if (current->charge.ser_other > 0)
	{
		bsi.init();
		bsi.amount = current->charge.ser_other;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.ser_other,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.ser_other;
		}

		summary["SER_OTHER"]		= bsi;
	}

	if (current->charge.mail_box_rental > 0)
	{
		bsi.init();
		bsi.amount = current->charge.mail_box_rental;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount(current->charge.mail_box_rental,cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.mail_box_rental;
		}

		summary["SER_ADDMB"]		= bsi;
	}

	

	// Total service rental, includes rental for HTTP, EMAIL, GRIC, FHTTP ONLY
	// Added additional rental for extra mail box size - charge.mail_box_rental - 27-01-2003
		bsi.init();

		bsi.amount = current->charge.service_rental;

		if ( vat ) 
		{
			bsi.vat_amount = get_vat_amount( (current->charge.service_rental),cVatRate);
		}
		else
		{
			bsi.vat_amount = current->charge.service_rental;
		}

		summary["SER_RENTAL"]		= bsi;
	// End of addition by Arjuna Aryasinha - 2002.MAR.26

	bsi.init();

	bsi.amount = current->charge.rental;

	if ( vat ) 
	{
		bsi.vat_amount = get_vat_amount(current->charge.rental,cVatRate);
	}
	else
	{
		bsi.vat_amount = current->charge.rental;
	}

	summary["TOT_RENTAL"]		= bsi;

}



void connections::add_package_free_units()
{
	for(CONNECTION_DEF::iterator i=conn.begin(); i!=conn.end(); i++)
	{

		packages *pkg;
		PACKAGE_DEF::iterator i_pkg=gsm_packages->all_packages.find((*i).second.connection.package_code);
		pkg=&(*i_pkg).second;

		conn[(*i).first].call.free_units = pkg->free_minutes;
		conn[(*i).first].call.balance_free_units = pkg->free_minutes;

	}
}


void connections::insert(int account_no, connection_detail &c_d )
{
	conn[account_no].connection = c_d;
	conn[account_no].charge.init();
	conn[account_no].call.init();
}


int	connections::start()
{
	i_current = conn.begin();
	current = &(*i_current).second;
	return conn.size();
}


bool connections::next()
{
	i_current++;
	if(i_current != conn.end())
	{	
		current = &(*i_current).second;
		return true;
	}
	return false;
}


bool connections::initalise(int start_ac, int end_ac)
{
	start_ac_no = start_ac;
	end_ac_no=end_ac;
	return true;
}

bool connections::initalise_temp()
{
	start_date = end_date;
	end_date = sys_date; 
	return true;
}

void connections::update_rental_advance_payments()
{
	advance_payment *ap;

	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i;
	
	for(i = rental_advance_payments_map.begin(); i != rental_advance_payments_map.end(); i++)
	{
		ap=&(*i).second;
		db_update_rental_advance_payments(ap->account_no, ap->client_code, ap->date_paid);
	}
}

void connections::update_rental_advance_payments_for_one_connection(int account_no)
{
	advance_payment *ap;

	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i;
	i = rental_advance_payments_map.find(account_no);
	if(i != rental_advance_payments_map.end())
	{
		ap=&(*i).second;
		db_update_rental_advance_payments(ap->account_no, ap->client_code, ap->date_paid);
	}
}
	
void connections::set_billrun_dates(char* yearstr, char* monthstr, char* daystr)
{
	char buf[30];
	string tempdate;
	char month[2];
	char day[2];
	tempdate =  daystr;
	strcpy(month, (tempdate.substr(5,2)).c_str());
	strncpy(buf, daystr, 4);
	strncpy( buf + 4, month, 2 );
	if (start_day >9)
	{
		myitoathis(start_day, day);
		strncpy( buf + 6, day, 2 );
	}
	else
	{
		char pad[1];
		pad[0] = '0';
		strncpy( buf + 6, pad, 1 );
		myitoathis(start_day, day);
		strncpy( buf + 7, day, 1 );
	}
	
}

void connections::check_open_bill_presence()
{
	if ((gsm_connections->start()) == 0)
	{
		cout << "No active Connections found for Bill Run Code " << gsm_connections->br_code << endl;
		cout << "Exiting with Error " <<  endl;
		exit(0);
	}

	do
	{
		if ((current->charge.open_bill_found)==0)
		{
			cout << "Open bill not present for Account Number " << current->connection.account_no << endl;
			cout << "Client Code " << current->connection.client_code << endl;
			cout << "Exiting with Error " <<  endl;
			exit(0);
		}
	}
	while (gsm_connections->next());

	cout << "Open Bills present for all relevant accounts " <<  endl;
}




