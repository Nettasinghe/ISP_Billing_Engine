

/////////////////////////////////////////////////////////////////////
//
// discounts.cpp: implementation of the discounts class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


//  rule_type clasification
/*
23-07-2000
Table - discount_rules
hierarchy day_id > time_band_group > time_band_type
If content_or_duration 'M'							- rule_type = 1
If time_band_type, time_band_group, day_id NOT NULL	- rule_type = 2
If time_band_group, time_band_type NOT NULL	others NULL		- rule_type = 3
If day_id NOT NULL others NULL						- rule_type = 4
*/


#include "db_data_containers.h"

extern connections *gsm_connections;
extern FILE *logfile;

void discounts::insert(string s,discount_rule dr)
{
	discount_rule_multimap.insert(pair<string, discount_rule>(s, dr));
	
}

void discounts::insert_connection_discount(int i,string s)
{
	connection_discount_multimap.insert(pair<int, string>(i, s));
	
}

float discounts::discount_compute(connection_state *c_s)
{
	DISCOUNT_DEF::iterator i;
	float discountable_value, discount, total_discount; 
	
	// initial conditions 
	total_discount	= 0;
	
	
	discountable_value = c_s->get_discountable_value(); // get from bill
	

		
	for(i = discount_rule_multimap.begin(); i != discount_rule_multimap.end(); i++)
	{
		
		fprintf(logfile, "%s", "discount_rule_multimap data " );
		fprintf(logfile, "%s", "--------------------------- " );
		fprintf(logfile, "%s%s", "discount_type : " , (*i).first.c_str() );
		fprintf(logfile, "%s%s", "discount_type : " , (*i).second.discount_type.c_str() );
		fprintf(logfile, "%s%d", "rule_number : " , (*i).second.rule_number );
		fprintf(logfile, "%s%f", "percentage : ", (*i).second.percentage );
		fprintf(logfile, "%s%f", "rate : " , (*i).second.rate );
		fprintf(logfile, "%s%s", "content_or_duration : " , (*i).second.content_or_duration.c_str() );
		fprintf(logfile, "%s%s", "rental_waived : ", (*i).second.rental_waived.c_str() );
		fprintf(logfile, "%s%f", "upper_limit : " , (*i).second.upper_limit );
		fprintf(logfile, "%s%f", "lower_limit : " , (*i).second.lower_limit );
		fprintf(logfile, "%s%d", "************** rule type : " , (*i).second.rule_type );
		
		TimeBand TB	= (*i).second.time_band;


		
		fprintf(logfile, "%s%s", "time_band_group : " , TB.time_band_group.c_str() );
		fprintf(logfile, "%s%s", "time_band_type : " , TB.time_band_type.c_str() );
		fprintf(logfile, "%s%s", "day_id : " , TB.day_id.c_str() );

		
		for (CONNECTION_DISCOUNT_DEF::iterator j=connection_discount_multimap.equal_range(c_s->connection.account_no).first;
		j!=connection_discount_multimap.equal_range(c_s->connection.account_no).second; j++)
		{
			fprintf(logfile, "%s%d", "discount_type from  connection_discount_multimap: " , (*j).second );

			if ((*i).second.discount_type == (*j).second)
			{
				discount = 0;	// Initializes discount
				fprintf(logfile, "%s", "discount_type matches " );

				if ( (*i).second.rental_waived == "Y" )
				{
					gsm_connections->current->call.rental_waived = 1;	// not to update rental_advance_payments
					gsm_connections->current->charge.pkg_rental_charge = 0;
				}

				if ( ( (*i).second.content_or_duration=="C" ) || ( (*i).second.content_or_duration=="D" ) )
				{
					fprintf(logfile, "%s", "A content or duration discount  "  );
					TIME_BAND_DEF::iterator iter= gsm_connections->current->call.time_band_detail.find((*i).second.time_band);
					if ( iter != gsm_connections->current->call.time_band_detail.end() )
					{
						fprintf(logfile, "%s", "Time band found : "  );
						TimeBand tb = (*iter).first;

						fprintf(logfile, "%s%s", "time_band_group : " , tb.time_band_group.c_str() );
						fprintf(logfile, "%s%s", "time_band_type : " , tb.time_band_type.c_str() );
						fprintf(logfile, "%s%s", "day_id : " , tb.day_id.c_str() );
						fprintf(logfile, "%s%f", "duration : " , (*iter).second.time_duration );
						fprintf(logfile, "%s%f", "bytes_in : " , (*iter).second.bytes_in );
						fprintf(logfile, "%s%f", "bytes_out : " , (*iter).second.bytes_out );
						
						float total_bytes = ( (*iter).second.bytes_in + (*iter).second.bytes_out ) / 1000;	// divided by 1000 to convert to KB
						
						fprintf(logfile, "%s%f", "total_kilo_bytes : " , total_bytes );


						if  ( ( (*i).second.content_or_duration=="C" ) && ((*i).second.upper_limit >= total_bytes) && ( (*i).second.lower_limit <= total_bytes) ) 
						{
							//discount = (*i).second.rate * ((*iter).second.bytes_in+(*iter).second.bytes_out) ;
							discount = (*i).second.rate * total_bytes ;
							fprintf(logfile, "%s%f", "content discount : " , discount );
						}

						if ( ( (*i).second.content_or_duration=="D" ) && ((*i).second.upper_limit >= (*iter).second.time_duration) && ((*i).second.lower_limit <= (*iter).second.time_duration) )
						{
							discount = (*i).second.rate * (*iter).second.time_duration ;
							fprintf(logfile, "%s%f", "duration discount : " , discount );
						}
										
					}
					
				}
				if ( ( (*i).second.content_or_duration=="M" ) && (discountable_value <= (*i).second.upper_limit) && (discountable_value >= (*i).second.lower_limit) )
				{
					fprintf(logfile, "%s", "A monetory discount " );
					discount = (*i).second.percentage * discountable_value / 100;
					fprintf(logfile, "%s%f", "monetory discount : " , discount );
				}

				
				DISCOUNT_DETAIL_DEF::iterator i_current;
				i_current = c_s->discount_detail.find((*i).second.discount_type);
					
				if (i_current == c_s->discount_detail.end())
				{
					c_s->discount_detail[(*i).second.discount_type] = discount;
				}
				else
				{
					float temp_discount = (*i_current).second + discount;
					(*i_current).second = temp_discount;
					//c_s->discount_detail[(*i).second.discount_type] = temp_discount;
				}

				if (discount > 0)
				{
					c_s->charge.discounts += discount;
					total_discount += discount;
					fprintf(logfile, "%s%f", "Discount : " , discount );
					fprintf(logfile, "%s%f", "Total Discount : " , total_discount );
				}

				
			}
			else
			{
				fprintf(logfile, "%s", "discount_type does not match " );
			}
		}
	}
	fprintf(logfile, "%s%f","total_discount : ", total_discount );
	return total_discount;
}
