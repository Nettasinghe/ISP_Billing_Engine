

/////////////////////////////////////////////////////////////////////
//
// taxes.cpp: implementation of the taxes class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include <math.h>
#include <stdlib.h>


bool tax_key::operator < (const tax_key &s) const 
{
	if(group < s.group)
		return true;
	else if ((group == s.group) && (priority < s.priority))
		return true;
	else if ((group == s.group) && (priority == s.priority) && (type < s.type))
		return true;
	else if ((group == s.group) && (priority == s.priority) && (type == s.type) && (slab < s.slab))
		return true;
	return false;
}


bool taxes::insert(tax_key &c, float value)
{
    taxation_rules[c]=value;
	return true;
}


void taxes::print()
{
	for(TAX_DEF::iterator i=taxation_rules.begin(); i!=taxation_rules.end(); i++)
		cout<<"{"<<(*i).first<<" -> "<<(*i).second<<"}"<<endl;
}




float taxes::simple_tax_compute(connection_state *c_s)
{
	float total_tax=0; 

	if (strcmp((c_s->connection.tax_group_id).c_str(), "DPL")!=0)
	{
		TAX_DEF::iterator i;
		float taxable_value, tax; 
		float gst_taxable_value=0, nsl_taxable_value=0;

		tax_key current_tax_band;

		// initial conditions 
		total_tax = 0;

		bool initial = true;
		computed_taxes.clear(); // init

		string t_grp = c_s->connection.tax_group_id;

		//gst_taxable_value = c_s->get_gst_taxable_value(); // get from bill
		//nsl_taxable_value = c_s->get_nsl_taxable_value(); // get from bill

		gst_taxable_value = c_s->get_gst_taxable_value(); // get from bill
		
		// Only NSL applied to GRIC charges - Arjuna Aryasinha 2002-MAR-22
		// nsl_taxable_value = c_s->get_taxable_value(); // get from bill
		nsl_taxable_value = c_s->get_nsl_taxable_value(); // get from bill

		for(i = taxation_rules.begin(); i != taxation_rules.end(); i++)
		{
			//cout << "In Tax calculation " << endl;
			//cout << "t_grp " <<t_grp<<"END"<< endl;
			//cout << "(*i).first.group " <<(*i).first.group<<"END"<< endl;
			tax = 0;
			if( (*i).first.group == t_grp)	
			{
				current_tax_band = (*i).first; // debugger friendly assignment

				if(current_tax_band.type == "GST")
				{	
					taxable_value = gst_taxable_value;
					//cout << "At GST taxable_value" <<taxable_value<< endl;
				}
				else if (current_tax_band.type == "NSL")
				{
					taxable_value = nsl_taxable_value+c_s->charge.gst;
					//cout << "At NSL taxable_value" <<taxable_value<< endl;
					//cout << "nsl_taxable_value :" << nsl_taxable_value << endl;
					//cout << "c_s->charge.gst : " << c_s->charge.gst << endl;
				}

				tax = (*i).second * taxable_value / 100;

				//int  temptax = (int)(tax * 100);
				//cout << "temptax :"<< temptax << endl;
				//tax = temptax / 100.0;
				//cout << "TAX : " << tax << endl;
				//tax = floor((tax+.5));
				

				if(current_tax_band.type == "GST")
					c_s->charge.gst = tax;
				else if (current_tax_band.type == "NSL")
					c_s->charge.nsl = tax;

				computed_taxes[current_tax_band.type] = tax;
				c_s->charge.tax += tax;

				// Added on 08-03-00 after commenting bellow TAX_DETAIL_DEF::iterator i_current; 
				c_s->tax_detail[(*i).first.type] = tax;
			}
		}
	}

		/*	
			// update useage summary
			for(map<string, float>::iterator j=computed_taxes.begin(); j!=computed_taxes.end(); j++)
			{
				u_summary->add_bill((*j).first, (*j).second);
			}
			u_summary->add_bill("Total tax",total_tax);
		*/
	return total_tax;
}




void tax_key::init()
{
	group = "";
	priority = -1;
	slab = -1;
	type = "";
}


ostream& operator<<(ostream& out, tax_key x)
{
	out<<
	x.group<<", "<<
	x.priority<<", "<<
	x.type<<", "<<
	x.slab;

	return out;
}



float taxes::total()
{
	float tax=0;
	for(map<string, float>::iterator i=computed_taxes.begin(); i!=computed_taxes.end(); i++)
		tax += (*i).second;
	return tax;
}




