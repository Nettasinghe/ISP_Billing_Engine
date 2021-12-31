

/////////////////////////////////////////////////////////////////////
//
// package_map.cpp: implementation of the package_map class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


// sets the current pointer to correct package_code
/*
bool package_map::set_current(string package_code)
{
	i_current_package = all_packages.find(package_code);
	if(i_current_package != all_packages.end())
	{
		current=&(*i_current_package).second;
		return true;
	}
	return false;
}


bool package_map::print()
{
	for(PACKAGE_DEF::iterator i=all_packages.begin(); i!=all_packages.end(); i++)
	{
		cout<<"index-pkg code :"<<(*i).first<<endl;
		cout<<"pkg code :"<<(*i).second.package_code<< endl;				
		cout << "rental :" << (*i).second.rental<<endl;		
		cout << endl;
	}
	return true;
}
*/
