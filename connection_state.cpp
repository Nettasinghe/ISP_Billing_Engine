

/////////////////////////////////////////////////////////////////////
//
// connection_state.cpp: implementation of the connection_state class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


extern package_map	*gsm_packages;
extern connection_services_multimap	*gsm_connection_services;
extern connections	*gsm_connections;

#define		CENTS		100

void connection_state::check_rental_aapplicability_for_disconnected_connections()
{
	// boolean made true because calling init() missed somewhere - 02-02-2003 
	gsm_connections->current->connection.rental_applicability = true;
	
	// Modified by Arjuna Aryasinha on 2002-SEP-16th for rental calculation 
	// for temp. disconnected cxs

	// If the connection status is temp. disconnected
	if (strcmp( (gsm_connections->current->connection.connection_status).c_str(), "TDISC") == 0 )
	{
		// Check if the current status date falls within the bill cycle
		if ( 
			(
				( gsm_connections->reng_start_date < gsm_connections->current->connection.current_status_date ) ||
				(gsm_connections->reng_start_date == gsm_connections->current->connection.current_status_date) 
			 )
			 &&
			 (
			  ( gsm_connections->current->connection.current_status_date < gsm_connections->reng_end_date )	  ||
			  (gsm_connections->current->connection.current_status_date == gsm_connections->reng_end_date )
			 )
			)
		{
			// set the flag not to apply rental to the bill, both package and service
			gsm_connections->current->connection.rental_applicability = true;
		}
		else
		{
			gsm_connections->current->connection.rental_applicability = false;
		}
	}
	// If the connection status is perm. disconnected
	else if (strcmp( (gsm_connections->current->connection.connection_status).c_str(), "PDISC") == 0 ) 
	{
		// set the flag not to apply rental to the bill, both package and service
		gsm_connections->current->connection.rental_applicability = false;
	}
}




float connection_state::compute_package_rental()
{
	// Adding rental from packages
	packages *pkg;
	PACKAGE_DEF::iterator i=gsm_packages->all_packages.find(connection.package_code);
	if (i== gsm_packages->all_packages.end())
	{
		cout << "pkg not found" << endl;
	}

	pkg=&(*i).second;

	// Modified by Arjuna Aryasinha on 2002-SEP-16th for rental calculation 
	if (connection.rental_applicability==false)
	{
		charge.pkg_rental = 0;		// to add back when rental advance payments (for 2nd ledger entry)
		charge.pkg_rental_charge = 0;
	}
	else
	{
		charge.pkg_rental = pkg->rental;		// to add back when rental advance payments (for 2nd ledger entry)
		charge.pkg_rental_charge = pkg->rental;
	}

	
	// Commented CJN 10-04-2002 to charge tax on Rental Adv. payments
	/*
	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i_adv=gsm_connections->rental_advance_payments_map.find(connection.account_no);

	bool notfound = (i_adv == gsm_connections->rental_advance_payments_map.end());
	
	if(notfound)
	{
		//charge.rental += pkg->rental;
		charge.pkg_rental_charge = pkg->rental;
	}
	else
	{
		charge.pkg_rental_charge = 0;
	}
	*/

	return charge.pkg_rental;

}


float connection_state::compute_connection_services_rental(int u_account_no)
/*
This is used to compute the total service rental (i.e. SER_RENTAL), and the
rental for additional mailbox quotas (i.e. SER_ADDMB).
*/
{

	
	if (connection.rental_applicability)
	{
		const	string	sEMAILIdentifier = "EMAIL";

		const	string	sGRICIdentifier	= "GRIC";
		// Adding rentals from connection_services
		CONNECTION_SERVICES_DEF::iterator i_csd=gsm_connection_services->all_connection_services.begin();
	
		while (i_csd != gsm_connection_services->all_connection_services.end())
		{
			if (u_account_no == (*i_csd).second.account_no)
			{

				// Added by Arjuna Aryasinha - 2003-DEC-05
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
					// Added by Arjuna Aryasinha - 2002.APR.23

					/*	
					Include the GRIC rental charge to the service rental, only in there is an access
					charge for GRIC services
					*/
					if ( (*i_csd).second.service_code ==  sGRICIdentifier )
					{
						if ( call.gric_charge > 0.001 ) 
						{
							charge.service_rental	+= (*i_csd).second.rental;
						}
					}
					else
					{
						
						/*
						If the service is not GRIC, then check if cx is liable 
						for being charged for additional mail quota.  If so,
						add the extra email quota charge to the service rental
						*/					
						// Added on 23-01-2003 to charge additional amount for extra mail box cfapacity
						if ( (*i_csd).second.service_code ==  sEMAILIdentifier )
						{

							if ((*i_csd).second.service_quota > gsm_connections->default_quota)
							{

								int int_mail_box_rental = (int)(( (*i_csd).second.service_quota - gsm_connections->default_quota )*gsm_connections->extra_rental*100);

								double float_mail_box_rental = (double)(int_mail_box_rental/100.0);

								charge.mail_box_rental += float_mail_box_rental;

								charge.service_rental	+= float_mail_box_rental;
							}
						}
						else
						{
							charge.service_rental	+= (*i_csd).second.rental;
						}
					}
					// End of addition by Arjuna Aryasinha - 2002.APR.23
				}
				// End of addition by Arjuna Aryasinha - 2003-DEC-05


			}
			i_csd++;
		}
	}

	return charge.service_rental;
	
}




float connection_state::get_and_set_taxable_value()
{

	return call.charge + call.gric_charge;

}

float connection_state::get_discountable_value()
{
	float disval =	  call.charge
					+ charge.rental
					+ charge.adjustment
					+ charge.pro_rate;
					
	return disval;
}

float connection_state::get_gst_taxable_value()
{
	float taxval = 0;
	
	taxval =		call.charge
					+ charge.pkg_rental_charge
					+ charge.service_rental
					+ charge.taxable_adjustment
					+ charge.pro_rate
					- charge.discounts;

	// 16-01-2002 "adjustment" changed to "taxable_adjustment"

	

	return taxval;
}

float connection_state::get_nsl_taxable_value()
{

	// 2002-MAR-22 included for GRIC roaming usage charge taxing by Arjuna Aryasinha

	float taxval =	0;

	taxval =		call.charge
					+ call.gric_charge  // Only NSL applied to GRIC charges
					+ charge.pkg_rental_charge
					+ charge.service_rental
					+ charge.taxable_adjustment
					+ charge.pro_rate
					- charge.discounts;

	// 16-01-2002 "adjustment" changed to "taxable_adjustment"

	

	return taxval;
}


float connection_state::total_current_charge()
{
	return call.charge;
}


float connection_state::get_total_due()
{
	charge.total_due =    charge.total_charges
						+ charge.brought_forward
						- charge.payments;
	return charge.total_due;
}


float connection_state::get_total_previous_month()
{
	return(charge.brought_forward-charge.payments);
}


// -------------- log_state
void connection_state::set_bill_amount()
{
	
	charge.bill_amount =  call.charge 
						
						// Addition of GRIC charges on 2002-MAR-26 by Arjuna Aryasinha
						+ call.gric_charge 
						// End of addition on 2002-MAR-26 by Arjuna Aryasinha

						+ charge.rental 
						+ charge.pro_rate
						+ charge.taxable_adjustment + charge.untaxable_adjustment 
						- charge.discounts 
						+ charge.tax;

	// Added by Arjuna aryasinha 2002.APR.30
	
	// check if the current account no is eligible for rental advance payment recognition
	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i_adv=gsm_connections->rental_advance_payments_map.find(connection.account_no);

	bool notfound = (i_adv == gsm_connections->rental_advance_payments_map.end());
	
	// if account no is not eligible for rental advance payment recognition then
	if(notfound == false)
	{
	}
	// End of addition by Arjuna aryasinha 2002.APR.30


}


void connection_state::set_tot_pay()
{

	charge.tot_pay =  call.charge 
					+ call.gric_charge 
					+ charge.rental
					+ charge.pro_rate
					- charge.discounts
					+ charge.tax;

}

void connection_state::set_c_f()
{

	charge.c_f	= charge.brought_forward
				+ call.charge 
				// Addition of GRIC charges on 2002-MAR-26 by Arjuna Aryasinha
				+ call.gric_charge 
				// End of addition on 2002-MAR-26 by Arjuna Aryasinha
				+ charge.rental
				+ charge.pro_rate
				- charge.discounts
				+ charge.tax
				- charge.payments
				+ charge.taxable_adjustment + charge.untaxable_adjustment;
}

void connection_state::set_total_rental()
{
	// Commented by Arjuna Aryasinha 2002.APR.30

	// The check for rental advance payment eligibility 
	// and the subsequent TOT_RENTAL assignment of charge.rental
	// was carried up to connection_state::set_bill_item_values()
	// so that the check need not be repeated in all other
	// methods called by connection_state::set_bill_item_values()

	/*
	// Changed CJN 10-04-2002 to deduct Rental Adv. payment after charging tax
	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i_adv=gsm_connections->rental_advance_payments_map.find(connection.account_no);

	bool notfound = (i_adv == gsm_connections->rental_advance_payments_map.end());
	
	if(notfound)
	{
		charge.rental	=	charge.pkg_rental_charge
						+ charge.service_rental;
	}
	else
	{
		charge.rental	=	 charge.service_rental;
	}
	*/
	// End of comment by Arjuna Aryasinha 2002.APR.30

	// Added by Arjuna Aryasinha 2002.APR.30

	charge.rental	=	charge.pkg_rental_charge
						+ charge.service_rental;

	// End of addition by Arjuna Aryasinha 2002.APR.30

}

void connection_state::set_bill_item_values()
{
	
	// Added by Arjuna Aryasinha 2002.APR.30
	
	RENTAL_ADVANCE_PAYMENTS_DEF::iterator i_adv=gsm_connections->rental_advance_payments_map.find(connection.account_no);

	// check if the account no is eligible for rental advance payment recognition
	bool notfound = (i_adv == gsm_connections->rental_advance_payments_map.end());
	
	// if eligible, then set package rental to 0
	if(notfound == false)
	{
		charge.pkg_rental_charge = 0;
	}
	// End of addition by Arjuna Aryasinha 2002.APR.30

	set_total_rental();
	set_bill_amount();
	set_tot_pay();
	set_c_f();

}
//-------------- log_state-end
