

/////////////////////////////////////////////////////////////////////
//
// db.h: definitions for database related classes.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#ifndef DB
#define	DB

#pragma warning(disable:4786)
 
void	db_connect_isp(char *a);		// establish connection to database
void db_disconnect_isp(void);
void db_read_connection_services();
void db_read_packages();
//void db_read_bill_debts();

#endif