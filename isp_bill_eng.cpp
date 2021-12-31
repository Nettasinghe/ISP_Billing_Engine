

///////////////////////////////////////////////////////////////////////////////////////////
// 
// ISP (Internet Service Provider) Billing Engine – 
// The function of a ISP Billing Engine is to read the rated ISP CDRs and ISP customers 
// billing plans from the databaseand while keeping them in memory, calculating the periodic
// bill values, discounts, taxesand other chargesand finally writing those values which need
// to bill the ISP customer base, to the database.
//
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//
// isp_bill_eng.cpp
// ISP Billing Engine
// main method contains here
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdio.h>

#include "db.h"
#include "db_data_containers.h"
#include "My_Debug.h"

//#define INTERIM_BILL			// Comment #define for regular month end bill

// Comment out the following line to turn off debug messages

//#define MYDEBUG

using namespace std;


// static member
BILL_SUMMARY_DEF connections::summary;	



// -- db data containers begin
bill_cycle						*gsm_bill_cycle;
connections						*gsm_connections;
taxes							*gsm_taxes;
package_map						*gsm_packages;
connection_services_multimap	*gsm_connection_services;
discounts						*gsm_discounts;
FILE *logfile;

char in_login[256];
char buf1[256];
char buf2[256];
char buf3[256];
// --db data containers end

char *version = "2.0.15";

void main(int argc, char *argv[])
{

#ifdef INTERIM_BILL
	cout<<"ISP Interim Billing Engine "<<endl
#else
	cout<<"ISP Billing Engine "<<endl
#endif
	<<"Millennium Information Technologies"<<endl
	<<"Colombo, Sri Lanka"<<endl
	<<"ver " << version << " compiled on "<<__DATE__<<" at "<<__TIME__
	<<endl;

	cout<<endl;
	debug("In debug mode");


	// -- db data space containers
	gsm_bill_cycle			= new bill_cycle;
	gsm_connections			= new connections; //(gsm_useage_summary);
	gsm_packages			= new package_map;
	gsm_connection_services	= new connection_services_multimap;
	gsm_taxes				= new taxes;
	gsm_discounts			= new discounts;

	if (argc == 2) 
	{
		gsm_bill_cycle->set_bill_cycle_code(argv[1]);
	}
	else
	{
		cout<<"\n\n\nUsage:\n\t IspBillEngine  <bill_cycle_code>"<<endl
		<<"\t e.g \n\t IspBillEngine B0131"<<endl<<endl;
		exit(1);
	}

#ifndef INTERIM_BILL
	
	int option;
	cout << endl;
	cout << endl;
	cout << "Enter 1 if database connect string is changed : "<<endl;
	cout << "Otherwise Enter 0  : "<<endl;
	cin >> option;
	

	if (!( (option == 0)||(option == 1) ))
	{
		cout << "Invalid entry " << endl;
		exit(0);
	}

	if ( option == 1 )
	{
		cout << "Enter new database connect string : "<<endl;
		cout << "eg format :  <username/password@connectstring>" << endl;
		cin >> buf1;
		gsm_bill_cycle->crypt(buf1, buf2);

		FILE *cryptfile;

		if( (cryptfile  = fopen( "./Crypt.config", "w" )) == NULL )
		{
			printf( "The file './Crypt.config' was not opened\n" );
			exit(0);
		}
		
		fprintf( cryptfile, "%s", buf2 );

		if( fclose( cryptfile ) )
			printf( "The file './Crypt.config' was not closed\n" );
	}
#endif

    FILE *cryptfile;

	if( (cryptfile  = fopen( "./Crypt.config", "r" )) == NULL )
	{
		printf( "The file './Crypt.config' was not opened\n" );
		exit(0);
	}
		
	fscanf( cryptfile, "%s", buf3 );

	if( fclose( cryptfile ) )
		printf( "The file './Crypt.config' was not closed\n" );

    char isp_login[128];
	gsm_bill_cycle->de_crypt(buf3, isp_login);


	cout<<"bill_run_code : "<<argv[1]<<endl;
		
	int run_id=0, total_bills_generated=0;

	

// establish connection to database

	db_connect_isp(isp_login);
#ifdef INTERIM_BILL
	gsm_connections->db_read_billrun_definitions_for_interim_bill();
#else
	gsm_connections->check_bill_master_raw();
	gsm_connections->check_bill_summary_items_raw();
	gsm_connections->db_read_billrun_definitions();
#endif

	
	string log_file_name = "./IspBillEngLog.";
	char zTime[30];
	time_t t;
	time(&t);
	strftime(zTime, 30, "%Y_%m_%d_%H_%M_%S", localtime(&t));
	log_file_name.append(zTime);
	
	const char* log = log_file_name.c_str();

	if( (logfile  = fopen( log, "w+" )) == NULL )
	{
		cout <<"The file "<< log_file_name << " was not opened" << endl;
		exit(0);
	}
	fprintf(logfile, "%s%s",  "\nbill_run_code : ", argv[1]);

	cout <<"start_date	: "<< gsm_connections->start_date <<endl;
	cout <<"end_date	: " << gsm_connections->end_date <<endl;
	cout <<"due_date	: " << gsm_connections->due_date <<endl;
	cout << endl;

	fprintf(logfile, "%s%s",  "\nstart_date : ", gsm_connections->start_date.c_str());
	fprintf(logfile, "%s%s",  "\nend_date : ", gsm_connections->end_date.c_str());
	fprintf(logfile, "%s%s",  "\ndue_date : ", gsm_connections->due_date.c_str());

	gsm_taxes->db_read_tax_items();
	gsm_taxes->db_read_tax_group_items();

#ifdef INTERIM_BILL
	gsm_connections->truncate_bill_summary_items_i();
	gsm_connections->truncate_bill_master_i();
	gsm_connections->db_read_clients_for_interim_bill();
	gsm_connections->db_read_bill_adjustment_types();
	gsm_connections->db_read_connections_for_interim_bill();	// reads db table "connections"
																//This initializes calls & charges
#else
	gsm_connections->db_read_clients();
	gsm_connections->db_read_bill_adjustment_types();
	gsm_connections->db_read_connections();						// reads db table "mirrored_bill_connections"
																//This initializes calls & charges
#endif
	
	CONNECTION_DEF::iterator i_begin=gsm_connections->conn.begin();
	CONNECTION_DEF::iterator i_end=gsm_connections->conn.end();
	if (i_begin != i_end)
	{
		gsm_connections->start_ac_no=(*i_begin).first;
		//cout <<"start_ac_no : " << gsm_connections->start_ac_no <<endl;
		fprintf(logfile, "%s%d",  "\ngsm_connections->start_ac_no : " , gsm_connections->start_ac_no  );
		gsm_connections->end_ac_no=(*(--i_end)).first;
		//cout <<"end_ac_no : " << gsm_connections->end_ac_no <<endl;
		fprintf(logfile, "%s%d",  "\ngsm_connections->end_ac_no : ", gsm_connections->end_ac_no);
	}

#ifdef INTERIM_BILL	
	gsm_packages->db_read_packages_for_interim_bill();
	gsm_connections->add_package_free_units();
	gsm_connections->db_read_sessions();
	// Added by Arjuna Aryasinha - 2002.MAR.26
	gsm_connections->db_read_gric_sessions();
	// End of addition by Arjuna Aryasinha - 2002.MAR.26
	gsm_connections->db_read_bill_master_for_interim_bill();
	gsm_connection_services->db_read_connection_services_for_interim_bill();
	gsm_connections->db_read_bill_account_adjustments();
	gsm_discounts->db_read_discount_types();
	gsm_discounts->db_read_discount_rules();
	gsm_discounts->db_read_connection_discounts();
	gsm_connections->db_read_rental_advance_payments_for_interim_bill();
	gsm_connections->db_read_pro_rate_newcust();
	gsm_connections->db_read_pro_rate_services();
	gsm_connections->db_read_isp_services();
	// all databse read ups done

	cout<<" Interim Billing start "<<endl;
	fprintf(logfile, "%s",  "\nInterim Billing start ");
#else
	gsm_packages->db_read_packages();
	gsm_connections->add_package_free_units();
	gsm_connections->db_read_sessions();
	// Added by Arjuna Aryasinha - 2002.MAR.26
	gsm_connections->db_read_gric_sessions();
	// End of addition by Arjuna Aryasinha - 2002.MAR.26
	gsm_connections->db_read_bill_master();
	gsm_connections->check_open_bill_presence();
	gsm_connection_services->db_read_connection_services();
	gsm_connections->db_read_bill_account_adjustments();
	gsm_discounts->db_read_discount_types();
	gsm_discounts->db_read_discount_rules();
	gsm_discounts->db_read_connection_discounts();
	gsm_connections->db_read_rental_advance_payments();
	gsm_connections->db_read_pro_rate_newcust();
	gsm_connections->db_read_pro_rate_services();
	gsm_connections->db_read_isp_services();
	// all databse read ups done

	cout<<" Month End Billing start "<<endl;
	fprintf(logfile, "%s",  "\nMonth End Billing start ");
#endif

	connection_state *ac;


	for(CONNECTION_DEF::iterator i_current=gsm_connections->conn.begin(); i_current != gsm_connections->conn.end(); i_current++)
	{

		if(gsm_connections->set_current((*i_current).first)==false)
				continue; // skip any missing bits.
		ac = gsm_connections->current;
		fprintf(logfile, "%s%d",  "\nAccount no : ", (*i_current).first);

		total_bills_generated++;
		ac->check_rental_aapplicability_for_disconnected_connections();
		ac->compute_package_rental();
		ac->compute_connection_services_rental(ac->connection.account_no);
		gsm_connections->calc_conn_serv_rental();
		gsm_discounts->discount_compute(ac);
		gsm_taxes->simple_tax_compute(ac);
		ac->set_bill_item_values();

#ifdef INTERIM_BILL
		gsm_connections->db_insert_bill_master_i();
		gsm_connections->prepare_db_log_state();
		gsm_connections->db_insert_bill_summary_items_i();
#else
		gsm_connections->db_insert_bill_master_raw();
		gsm_connections->prepare_db_log_state();
		gsm_connections->db_insert_bill_summary_items_raw();
#endif

	}

#ifndef INTERIM_BILL
	gsm_connections->db_insert_bill_month_definitions();
#endif
	
	db_disconnect_isp();
}
