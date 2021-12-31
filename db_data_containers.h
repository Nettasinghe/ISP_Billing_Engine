

/////////////////////////////////////////////////////////////////////
//
// db_data_containers.h: definitions for main classes.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#ifndef CONTAINERS
#define	CONTAINERS

#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <set>
#include <stdio.h>

#define MIN_YEAR 1949
#define MAX_YEAR 2051

using namespace std;

class reng_time;

class reng_time
{
public:
	int hour;
	int min;
	int second;
	bool set_time(int h, int m, int s=0);
	bool set_time(char *t);
	bool set_h_m(const char *t);
	bool set_from_db(char *t, int secs);

	bool operator < (const reng_time  &s) const;
	reng_time operator+ (int s) const;
	void Print();
	void init();
};


ostream& operator<<(ostream& out, reng_time x);

class reng_date
{
public:
	int year;
	int month;
	int day;
	bool operator < (const reng_date  &s) const;
	bool operator == (const reng_date  &s) const;
	bool set_date(int y, int m, int d);
	bool set_date(char *d);
	void init();
};

ostream& operator<<(ostream& out, reng_date x);


class reng_date_time
{
public:
	reng_date date;
	reng_time time;
	bool set_date_time(char *d);
	bool operator < (const reng_date_time  &s) const;
};

ostream& operator<<(ostream& out, reng_date_time x);

class bill_adjustment_type
{
public:
	string	adjustment_type;
	bool	tax;
	float	value;
};



// timeband discounting - start
class TimeBand
{
public:
	string	time_band_type;
	string	time_band_group;
	string	day_id;
	bool operator < (const TimeBand &s) const;
	bool operator == (const TimeBand &s) const;
};

class TimeBandData
{
public:
	float 	time_duration;				
	float	bytes_in;	
	float	bytes_out;
	float	charge;
	float	no_of_units;
	float	free_min;
};

typedef map<TimeBand, TimeBandData, less<TimeBand> >TIME_BAND_DEF;

// timeband discounting - end


// session_data -- start ---------------------------------------------------------------

class session_data
{
public:
	string	session_id;				
	string	user_id;		
	string	ip_login;					
	double	time_duration;				
	string	start_time;		
	string	end_time;				
	int		bytes_in;	
	int		bytes_out;		
	int		input_pkts;		
	int		output_pkts;		
	string	service_type;
	float	charge;
	int		account_no;

	float	no_of_units;

	// for bill
	string	peak_offpeak;
	float	free_min;
	
};

ostream& operator<<(ostream& out, session_data x);

// session_data -- end -----------------------------------------------------------------

// gric session_data -- start ---------------------------------------------------------------

class gric_session_data
{
public:
	string	client_code;
	int		account_no;
	string	service_type;
	string	record_type;
	string	gmt_start_date;		
	string	gmt_start_time;		
	string	local_start_date;		
	string	local_start_time;		
	string	user_id;		
	string	service_provider;		
	string	time_unit;
	double	time_duration;				
	string	region_name;
	float	charge;
	float	no_of_units;
	string	rated_date;		
	int		file_id;
	string	session_id;				
	string	nas_ip_login;					
	string	local_country;					
	
};

ostream& operator<<(ostream& out, gric_session_data x);

// gric session_data -- end -----------------------------------------------------------------

// ibill_data -- start ---------------------------------------------------------------

class ibill_data
{
public:
	int		account_no;
	string	user_id;
	int		time_duration;				
	string	end_date;				
	int		bytes_in;	
	int		bytes_out;		
	int		input_pkts;		
	int		output_pkts;		
	float	charge;
	float	no_of_units;
	float	tot_peak;
	float	free_peak;
	float	tot_off;
	float	free_off;

	
	float	free_min;
	int		balance_free_units;
	
};

// ibill -- end -----------------------------------------------------------------


// connection_services -- start ---------------------------------------------------------------


class connection_services
{
public:
	float	rental;				
	string	start_date;		
	string	end_date;					
	int		account_no;				
	string	client_code;		
	string	service_code;				
	//string	protocol_id;	
	string	user_username;		
	int		service_instance;		
	string	connection_status;		
	string	attribution;
	string	rate_group_id;
	string	rental_actv_date;
	float	service_quota;

	/* Added by Arjuna on 2003-NOV-10 */
	reng_date	reng_end_date;  /* A copy of end_date to facilitate date arithmatic */
	/* End of addition by Arjuna on 2003-NOV-10 */
	
};

typedef multimap<int, connection_services> CONNECTION_SERVICES_DEF;

class connection_services_multimap
{
public:
	CONNECTION_SERVICES_DEF	all_connection_services;
	CONNECTION_SERVICES_DEF::iterator i_current_connection_service;
	void db_read_connection_services();
	void db_read_connection_services_for_interim_bill();
	//bool set_current(string package_code);

	void insert(int k,connection_services cs);
};

//ostream& operator<<(ostream& out, connection_services x);

// connection_services -- end -----------------------------------------------------------------

// packages -- start ---------------------------------------------------------------

class packages
{
public:
	string	package_code;				
	string	description;		
	float	rental;					
	string	free_applied_on;				
	int		free_in_bytes;		
	int		free_out_bytes;				
	int		free_minutes;	
	string	activated_on;
	string	deactivated_on;
	string	package_type;
	int		free_units;
		
};


typedef map<string,packages> PACKAGE_DEF;

class package_map
{
public:
	PACKAGE_DEF	all_packages;
	PACKAGE_DEF::iterator i_current_package;
	void db_read_packages();
	void db_read_packages_for_interim_bill();
	//bool set_current(string package_code);
	bool print();
};

//ostream& operator<<(ostream& out, packages x);

// packages -- end -----------------------------------------------------------------


// connection_detail -- start ----------------------------------------------------------


class connection_detail
{
public:
	int		account_no;
	string	package_code;
	reng_date current_status_date;	//introduced by ArjunaA on 26-9-2002	
	string	tax_group_id;
	string  corporate_code;
	string	invoice_no;
	string	client_code;
	string	vat_no;
	string	connection_status;
	bool	rental_applicability;		// flag for charging package and services rentals for disconnected connections
										// introduced on 16-09-2002
	void	init();
};

extern ostream& operator<<(ostream& out,connection_detail x);


// connection_detail -- end ------------------------------------------------------------




class bill_cycle;

class account_s
{
	string account_code;
	float amount;
};

class bill_s
{
	string item_code;
	float amount;
};



class call_summary
{
public:
	string	user_id;

	double usage_charges;				
	float taxes;			
	float discounts;			
	float interest;		
	float adjustments;			
	float misc_charges;			
	float usage_bytes;	
	float usage_duration;
	
	float	time_duration;				
	int		bytes_in;	
	int		bytes_out;		
	int		input_pkts;		
	int		output_pkts;		
	double	charge;
	float	tot_peak;
	float	free_peak;
	float	tot_off;
	float	free_off;

	string	gric_user_id;
	float	gric_time_duration;
	float	gric_no_of_units;	
	long double	gric_charge;
	
	float	free_min;
	float	no_of_units;

	bool	rental_waived;		// To indicate whether rental_waived in discount_rules

	TIME_BAND_DEF time_band_detail;	// for time band discounting

	// for bill
	float	total_usage_peak;
	float	total_usage_off;
	float	free_usage_peak;
	float	free_usage_off;

	float	free_units;				// Package - free units
	float	balance_free_units;		// actually these are balance free minits

	void	add_to_summary();
	void	init();
	void	summarize_sessions(session_data *sd);
	void	summarize_gric_sessions(gric_session_data *gsd);
	void	summarize_sessions_ibill(ibill_data *id);
	void	insert_time_band_detail(TimeBand &tb, TimeBandData tbd);
};

typedef map<string, bill_adjustment_type> BILL_ADJUSTMENT_TYPE_DEF;


class charge_summary
{
public:
	bool  open_bill_found;

	float brought_forward;		// B_F
	float payments;				// PAY
	float total_previous_month; // TOT_PM
	float monthly_services;		// M_SURV
	float misc_charges;			// MSC_CHG
	float contract_charges;		// CON_CHG
	float discount_surcharge;	// DISSUR_CHG  discounts+interest;	
	float taxable_value;
	float gst;
	float nsl;
	float tax;					// GOVTAX_TOT tax	
	float total_charges;		// CUR_CHG	total_current_charge()
	float total_due;			// AMT_DUE
	float rental;				// (pkg_rental_charge + service_rental)
	float pkg_rental;			// package rental - nominal
	float pkg_rental_charge;	// pkg rental charged after		(1) rental advance payments &
															//  (2) discounts - rental_waived
	float service_rental;		// connection services rental
	float pro_rate;				// PRO_RATE  for the within bill cycle services
	float pkg_change_pro_rate;
	float interest;				// INT_LATE late payment interest
	float adjustment;

	float discounts;			// DISCOUNT 1FOR1, value plus plus

	
	
	// for bill
	float	total_usage_peak;	// TOT_USG_P
	float	total_usage_off;	// TOT_USG_O
	float	free_usage_peak;	// FREE_USG_P
	float	free_usage_off;		// FREE_USG_O

	float	debit_notes;
	float	credit_notes;
	
	void init();
	void add_to_summary();

	//----------- bill_summary_items values calculated in prepare_db_log_state()
	float	tot_pay;			// TOT_PAY
	float	bill_amount;		// BILL_AMOUNT
	float	c_f;				// C_F
	//------------ end

	float	ser_email;			// Total rental for email service
	float	ser_http;			// Total rental for http service
	float	ser_fhttp;			// Total rental for fhttp service
	float	ser_gric;			// Total rental for GRIC service
	float	ser_other;			// Total rentals other than above 4

	BILL_ADJUSTMENT_TYPE_DEF	adjustment_items_value_map;
	float	taxable_adjustment;
	float	untaxable_adjustment;

	float	mail_box_rental;	// Charge for additional mail box capacity
};


class advance_payment
{
public:
	int		account_no;				
	string	client_code;		
	string	date_paid;				
	int	balance_months;	
	
};

typedef map<string,float> DISCOUNT_DETAIL_DEF;
typedef map<string,float> TAX_DETAIL_DEF;

class adjustment_item
{
public:
	string	adjustment_type;
	float	amount_adjusted;
	int		reference_no;
};

typedef multimap<int, adjustment_item> ADJUSTMENT_ITEM_DEF;

typedef map<string, float> ADJUSTMENT_DETAIL_DEF;			// Added on 10-09-2001


class connection_state
{
public:
	connection_detail		connection;
	call_summary			call;
	charge_summary			charge;
	DISCOUNT_DETAIL_DEF		discount_detail;
	TAX_DETAIL_DEF			tax_detail;
	ADJUSTMENT_DETAIL_DEF	adjustment_detail;				// Added on 10-09-2001
	add_to_summary();

	
	void	check_rental_aapplicability_for_disconnected_connections();	// 16-09-2002
	float get_and_set_taxable_value();
	float get_nsl_taxable_value();
	float get_gst_taxable_value();
	float total_current_charge();
	float get_total_due();
	float get_total_previous_month();
	float compute_tax();
	//----------------------------------
	float compute_package_rental();
	float compute_connection_services_rental(int u_account_no);
	float get_discountable_value();
	float get_taxable_value();
	
	void	set_total_rental();
	void	set_bill_amount();
	void	set_tot_pay();
	void	set_c_f();
	void	set_bill_item_values();
		
};


typedef map<int,connection_state, less<int> > CONNECTION_DEF;	// less<int> for sorting

// Added on 12-09-2002 for VAT implementation - start
class bill_summary_item
{
public:
	float amount;
	float vat_amount;
	bill_summary_item() { amount = 0.0; vat_amount = 0.0; }
	void init() { amount = 0.0; vat_amount = 0.0; }
};

typedef map<string,bill_summary_item> BILL_SUMMARY_DEF;

// VAT implementation - end

typedef map<int, advance_payment> RENTAL_ADVANCE_PAYMENTS_DEF;
typedef map<string, string> CLIENTS_DEF;



class connections
{
public:
	string	start_date;
	string	end_date; 
	string	due_date;
	string	session_date;
	string	sys_date;
	int start_ac_no;
	int end_ac_no;

	// Added on 16-09-2002
	reng_date 	reng_start_date;
	reng_date	reng_end_date; 
	reng_date	reng_sys_date;
	// end - 16-09-2002


public:
	string	debit_account_type;
	string	credit_account_type;
	string	debit_account_type_rental_adv_pay;
	string	credit_account_type_rental_adv_pay;
	int		cash_transaction_type;
	int		cash_transaction_type_rental_adv_pay;

	string	br_code;
	int		start_day;
	int		bill_grace_period;

	float default_quota;
	float extra_rental;	

	connection_state *current;
	CONNECTION_DEF::iterator i_current;

	CONNECTION_DEF conn;
	static	BILL_SUMMARY_DEF summary;
	RENTAL_ADVANCE_PAYMENTS_DEF rental_advance_payments_map;
	ADJUSTMENT_ITEM_DEF adjustment_item_multimap;
	CLIENTS_DEF clients_map;
	connections();
	BILL_ADJUSTMENT_TYPE_DEF	bill_adjustment_type_map;


	void	print();
	void	db_read_connections();


	void	db_read_fixed_cost();
	int		db_update_balance();
	bool	db_external_remitance();
	bool    db_is_value_plus_plus(string bill_date, int due_days);
	void	prepare_db_log_state();
	void	prepare_db_log_state_ibill();
	float   db_log_state();

	void	insert(int account_no, connection_detail &c_d );
	bool	set_current(int account_no);
	int		start();
	bool	next();
	bool	initalise(int start_ac, int end_ac);
	bool	initalise_temp();

	void	print_detail();

	// cal data records
	void	db_read_sessions();
	void	db_read_gric_sessions();
	void	db_insert_interim_bill_records_ibill();
	void	db_read_tap();
	void	db_read_anyware();
	
	void	db_read_package_rental();
	void	db_read_value_add_rental();
	void	db_read_payments();
	void	db_read_interest();
	void	db_read_adjustments();
	void	db_read_pro_rates();
	void	db_read_value_pp();
	void	db_read_bill_account_adjustments();
	void	db_read_rental_advance_payments();
	void 	db_insert_bill_master();
	void	db_update_bill_master();
	void	db_insert_bill_master_open();
	void	db_insert_bill_items();
	void	db_insert_bill_items_ibill();

	char*	get_invoice_no(char *buf);
	void	db_read_bill_master();
	void	db_read_bill_debts();
	void	db_update_rental_advance_payments(int account_no, string client_code,string date_paid);
	void	update_rental_advance_payments();
	void	db_update_interim_bill_records_ibill();
	void	truncate_interim_bill_summary_items();
	void	db_update_work_orders(int	work_order_no);
	void	db_read_invoice_numbers();
	void	db_update_invoice_numbers();
	void	db_read_bill_summary_item_defs();
	void	package_cash_account_transactions();
	void	db_read_billrun_definitions();
	void	db_read_billrun_definitions_for_interim_bill();
	void	set_billrun_dates(char* yearstr, char* monthstr, char* daystr);
	void	add_package_free_units();
	void	db_read_sessions_ibill_new();
	void	db_read_session_date();
	void	db_read_pro_rate_newcust();
	void	db_read_pro_rate_services();
	void	db_read_clients();
	void	check_open_bill_presence();
	void	db_update_bill_account_adjustments();
	void	update_rental_advance_payments_for_one_connection(int account_no);
	void	db_insert_bill_debts();
	void	db_update_bill_account_adjustments_for_one_connection(int account_no);
	void	db_insert_bill_month_definitions();
	void	db_insert_bill_master_raw();
	void	db_insert_bill_summary_items_raw();
	void	check_bill_master_raw();
	void	check_bill_summary_items_raw();
	void	db_read_bill_adjustment_types();
	float	get_vat_amount(float amount, float vat_rate);
	void	db_read_isp_services();
	void	calc_conn_serv_rental();

	void	truncate_bill_summary_items_i();
	void	truncate_bill_master_i();
	void	db_insert_bill_summary_items_i();
	void	db_insert_bill_master_i();
	void	db_read_connections_for_interim_bill();
	void	db_read_bill_master_for_interim_bill();
	void	db_read_clients_for_interim_bill();
	void	db_read_rental_advance_payments_for_interim_bill();
};

//ostream& operator<<(ostream& out, connection_detail x);

// Connections -- end ---------------------------------------------------------

// bill_master -- start ---------------------------------------------------------------

class bill_master
{
public:
	string	client_code;				
	int		account_no;		
	string	bill_no;					
	string	due_date;				
	string	bill_date;		
	string	bill_period_start;				
	string	bill_period_end;	
	float	balance_bf;		
	float	bill_amount;		
	float	balance_cf;		
	string	bill_run_code;
	float	bill_payments;
	int		run_no;
	string	printed;
	float	over_payment;
	
	void db_read_bill_master();
};


//ostream& operator<<(ostream& out, session_data x);

// bill_master -- end -----------------------------------------------------------------

// bill_cycle -- start ---------------------------------------------------------------

class bill_cycle
{
public:
	
	string bill_cycle_code;
	void set_bill_cycle_code(string b_r_c);
	string get_bill_cycle_code();
	int crypt(char *plain_text, char *cipher);
	int de_crypt(char *cipher, char *plain_text);

	
};

// bill_cycle -- end ---------------------------------------------------------------


// tax -- start ---------------------------------------------------------------

class tax_items
{
public:
	string tax_type_id;
	float	tax_slab;
	float	tax_rate;
};

typedef map<string,tax_items> TAX_ITEMS_DEF;

class tax_key
{
public:
	string	group;
	string	type;
	int		priority;
	float	slab;			// applicable to value and above
	bool operator < (const tax_key &s) const;
	void init();
};

typedef map<tax_key, float, less<tax_key> > TAX_DEF;
class taxes
{
public:
	TAX_ITEMS_DEF tax_items_map;	// Added by Chandika
	TAX_DEF taxation_rules;
	map<string, float> computed_taxes;
	bool insert(tax_key &c, float rate);
	float simple_tax_compute(connection_state *c_s);

	void db_read_tax_items();
	void db_read_tax_group_items();
	void print();
	float total();
};

ostream& operator<<(ostream& out, tax_key x);

// discount -- start ---------------------------------------------------------------

class discount_rule
{
public:
	string	discount_type;
	int		rule_number;
	float	percentage;
	float	rate;
	string	content_or_duration;
	string  rental_waived;
	float	upper_limit;
	float	lower_limit;
	TimeBand	time_band;
	int		rule_type;
};

typedef multimap<string, discount_rule> DISCOUNT_DEF;
typedef map<string, string> DISCOUNT_TYPE_DEF;
typedef multimap<int, string> CONNECTION_DISCOUNT_DEF;

class discounts
{
public:
	DISCOUNT_TYPE_DEF		discount_type_map;
	DISCOUNT_DEF			discount_rule_multimap;
	CONNECTION_DISCOUNT_DEF	connection_discount_multimap; 
		
	float discount_compute(connection_state *c_s);

	void db_read_connection_discounts();
	void db_read_discount_types();
	void db_read_discount_rules();
	void insert(string s,discount_rule dr);
	void insert_connection_discount(int i,string s);
};


#endif





