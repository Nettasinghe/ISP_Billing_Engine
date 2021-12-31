

/////////////////////////////////////////////////////////////////////
//
// connection_detail.cpp: implementation of the connection_detail class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////



#include "db_data_containers.h"


void connection_detail::init()
{
	account_no			= 0;
	client_code			= "";
	package_code		= "";
	//disconnected_date	= "";
	current_status_date.init();
	tax_group_id		= "";
	corporate_code		= "";
	invoice_no			= "";
	vat_no				= "";
	connection_status	= "";
	rental_applicability= true;
	
}



ostream& operator<<(ostream& out, connection_detail x)
{
	out
	<<" account_no = "<<x.account_no <<", "
	<<" package_code = "<<x.package_code <<", "
	<<" current_status_date = "<<x.current_status_date <<", "
	<<" corporate_code = "<<x.corporate_code <<", "
	<<" tax_group_id = "<<x.tax_group_id<<", "
	<<" vat_no = "<<x.vat_no;
	return(out);
}
