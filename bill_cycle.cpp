

/////////////////////////////////////////////////////////////////////
//
// bill_cycle.cpp: implementation of the bill_cycle class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"


void bill_cycle::set_bill_cycle_code(string b_r_c)
{
	bill_cycle_code = b_r_c;
}


string bill_cycle::get_bill_cycle_code()
{
	return bill_cycle_code;
}


int bill_cycle::crypt(char *plain_text, char *cipher)

{

        int i;

        //for(i=0; *(plain_text+i) != NULL; i++)
		i=0;
		while( *(plain_text+i) )


        {
                *(cipher+i) = *(plain_text+i)+1;
				i++;

        }

        *(cipher+i)=NULL;

        if (i > 50) 

                cout<<" login strings are too long"<<endl;

        return i;

}


int bill_cycle::de_crypt(char *cipher, char *plain_text)

{

        int i;

        //for(i=0; *(cipher+i) != NULL; i++)
		i=0;
		while( *(cipher+i) )
        {
                *(plain_text+i) = *(cipher+i)-1;
				i++;
        }

        if (i > 50) 

                cout<<" login strings are too long"<<endl;

        *(plain_text+i)=NULL;

        return i;

}