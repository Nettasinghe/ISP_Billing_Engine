

/////////////////////////////////////////////////////////////////////
//
// connection_services_multimap.cpp: implementation of the 
// connection_services_multimap class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


void connection_services_multimap::insert(int k,connection_services cs)
{
	all_connection_services.insert(pair<int, connection_services>(k, cs));
	
}
