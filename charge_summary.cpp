

/////////////////////////////////////////////////////////////////////
//
// charge_summary.cpp: implementation of the charge_summary class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"

extern connections	*gsm_connections;


void charge_summary::init()
{
	open_bill_found		=0;

float brought_forward	=0;		
	payments			=0;				
	total_previous_month=0; 
	monthly_services	=0;		
	misc_charges		=0;			
	contract_charges	=0;		
	discount_surcharge	=0;		
	taxable_value		=0;
	gst					=0;
	nsl					=0;
	tax					=0;					
	total_charges		=0;		
	total_due			=0;			
	rental				=0;				
	pro_rate			=0;				
	interest			=0;				
	adjustment			=0;

	discounts			=0;			
	
	pkg_change_pro_rate	=0;
	service_rental		=0;
	
	
	// for bill
	total_usage_peak	=0;	// TOT_USG_P
	total_usage_off		=0;	// TOT_USG_O
	free_usage_peak		=0;	// FREE_USG_P
	free_usage_off		=0;		// FREE_USG_O

	debit_notes			=0;
	credit_notes		=0;
	pkg_rental			=0;
	pkg_rental_charge	=0;

	tot_pay				=0;	// TOT_PAY
	bill_amount			=0;	// BILL_AMOUNT
	c_f					=0;	// C_F

	ser_email			=0;
	ser_http			=0;
	ser_fhttp			=0;
	
	// Added by Arjuna Aryasinha - 2002.MAR.26
	ser_gric			=0;
	// End of addition by Arjuna Aryasinha - 2002.MAR.26

	ser_other			=0;

	bill_adjustment_type bat;
	BILL_ADJUSTMENT_TYPE_DEF::iterator it = gsm_connections->bill_adjustment_type_map.begin();
        for(; it!=gsm_connections->bill_adjustment_type_map.end(); it++)
        {
                bat.adjustment_type 	= (*it).second.adjustment_type;
                bat.tax			= (*it).second.tax;
                bat.value		= (*it).second.value;
		adjustment_items_value_map[(*it).second.adjustment_type] = bat;
        }

	taxable_adjustment	=0;
	untaxable_adjustment=0;
	mail_box_rental		=0;

}
