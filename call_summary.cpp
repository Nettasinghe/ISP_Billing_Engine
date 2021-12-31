

/////////////////////////////////////////////////////////////////////
//
// call_summary.cpp: implementation of the call_summary class.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include <math.h>
#include <stdlib.h>
#include <algorithm>

extern connections	*gsm_connections;


void call_summary::init()
{
	adjustments		= 0;
	bytes_in		= 0;	
	bytes_out		= 0;
	charge			= 0;
	discounts		= 0;
	free_min		= 0;
	free_off		= 0;
	free_peak		= 0;
	free_usage_peak	= 0;
	free_usage_off	= 0;
	input_pkts		= 0;
	interest		= 0;
	misc_charges	= 0;
	no_of_units		= 0;
	output_pkts		= 0;
	taxes			= 0;
	time_duration	= 0;
	tot_off			= 0;
	tot_peak		= 0;
	total_usage_off = 0;
	total_usage_peak= 0;
	usage_bytes		= 0;
	usage_charges	= 0;				
	usage_duration	= 0;
	user_id			= ""; 
	balance_free_units	= 0;
	rental_waived	= 0;

	// Added by Arjuna Aryasinha - 2002.MAR.26
	gric_user_id		=	"";
	gric_time_duration	=	0;
	gric_no_of_units	=	0;	
	gric_charge			=	0;
	// End of addition by Arjuna Aryasinha - 2002.MAR.26

	//free_units		= package_free_units;

}

bool TimeBand::operator < (const TimeBand &s) const 
{
	if(time_band_group < s.time_band_group)
		return true;
	else if ((time_band_group == s.time_band_group) && (time_band_type < s.time_band_type))
		return true;
	else if ((time_band_group == s.time_band_group) && (time_band_type == s.time_band_type) && (day_id < s.day_id))
		return true;
	return false;
}

bool TimeBand::operator == (const TimeBand &s) const 
{
	if ((time_band_group == s.time_band_group) && (time_band_type == s.time_band_type) && (day_id == s.day_id))
		return true;
	return false;
}

void call_summary::insert_time_band_detail(TimeBand &tb, TimeBandData tbd)
{
	time_band_detail[tb]= tbd;
}

void call_summary::summarize_sessions(session_data *sd)
{
	sd->time_duration	 = sd->time_duration/60;	// To convert seconds to minutes

	user_id			 = sd->user_id;
	time_duration	+= sd->time_duration;
	bytes_in		+= sd->bytes_in;
	bytes_out		+= sd->bytes_out;
	input_pkts		+= sd->input_pkts;
	output_pkts		+= sd->output_pkts;
	no_of_units		+= sd->no_of_units;	
	//charge			+= sd->charge;

	// balance_free_units means (balance free minutes)
	// no_of_units is the rounded off units during rating

	if (balance_free_units == 0)
	{
		charge			+= sd->charge;
	}

	else if (balance_free_units >= sd->time_duration)
		{
			balance_free_units = balance_free_units - sd->time_duration;
		}

		else if (balance_free_units < sd->time_duration)
		{
			//int chargable_units = sd->no_of_units - balance_free_units;

			float chargable_units = sd->time_duration - balance_free_units;	// changed after - figure for tot_usg_chg
									
			//float session_charge = (sd->charge / sd->time_duration) * chargable_units;
			//int session_charge = (int)((sd->charge / sd->time_duration) * chargable_units);
			int int_session_charge = (int)((sd->charge / sd->time_duration) * chargable_units * 100);	// 100 is for filter sents for 2 digits
			double float_session_charge = (double)(int_session_charge / 100.0);
			// Rounded off on 25-04-2000 - Asela
			
			//cout << "session_charge : " << session_charge << endl;
			//charge			= charge + session_charge;
			charge			= charge + float_session_charge;
			
			balance_free_units = 0;
		}

	if (sd->peak_offpeak =="P")
	{
		total_usage_peak	+= sd->time_duration;
		free_usage_peak		+= sd->free_min;
	}
	
	if (sd->peak_offpeak =="O")
	{
		total_usage_off		+= sd->time_duration;
		free_usage_off		+= sd->free_min;
	}

	//cout << "session duration in minits : " << sd->time_duration << endl;
	//cout << "cumulative duration in minits : " << gsm_connections->current->call.time_duration << endl;

	//cout << "balance_free_units : " <<gsm_connections->current->call.balance_free_units << endl;
	//cout << "Total charge : " <<gsm_connections->current->call.charge << endl;


	
}

// Added by Arjuna Aryasinha - 2002.MAR.26
void call_summary::summarize_gric_sessions(gric_session_data *gsd)
{
	
	string	sMinuteIdent		=	"M";
	string	sSecondIdent		=	"S";
	int		iSeconndsToMinute	=	60;
	
	if ( gsd->time_unit == sMinuteIdent )
	// if the time units are in minutes, then to convert minutes to seconds
	{
		gsd->time_duration	 = gsd->time_duration * iSeconndsToMinute;
	}
	else if ( gsd->time_unit == sSecondIdent )
	// if the time units are in seconds, then to no need to convert
	{
		gsd->time_duration	 = gsd->time_duration;
	}

	gric_user_id		 = gsd->user_id;
	gric_time_duration	+= gsd->time_duration;
	gric_no_of_units	+= gsd->no_of_units;	
	gric_charge			+= gsd->charge;

}
// End of addition by Arjuna Aryasinha - 2002.MAR.26

void call_summary::summarize_sessions_ibill(ibill_data *id)
{
	user_id			 = id->user_id;

	time_duration	+= id->time_duration;
	bytes_in		+= id->bytes_in;
	bytes_out		+= id->bytes_out;
	input_pkts		+= id->input_pkts;
	output_pkts		+= id->output_pkts;
	//charge			+= id->charge;
	free_min		+= id->free_min;
	no_of_units		+= id->no_of_units;

	total_usage_peak	+= id->tot_peak;
	free_usage_peak		+= id->free_peak;

	total_usage_off		+= id->tot_off;
	free_usage_off		+= id->free_off;

	if (balance_free_units == 0)
	{
		charge			+= id->charge;
	}

	else if (balance_free_units >= id->no_of_units)
		{
			balance_free_units = balance_free_units - id->no_of_units;
			// charge is still zero
		}

		else if (balance_free_units < id->no_of_units)
		{
			int chargable_units = id->no_of_units - balance_free_units;

			double session_charge = (id->charge / id->no_of_units) * chargable_units;
			charge			= charge + session_charge;

			balance_free_units = 0;
		}
	
}


ostream& operator<<(ostream& out, session_data x)
{
	out<<
	"session_id = "<<x.session_id<<", "<<endl<<
	"account_no = "<<x.account_no<<", "<<endl<<
	"user_id = "<<x.user_id<<", "<<endl<<
	"ip_login="<<x.ip_login<<", "<<	
	"time_duration="<<x.time_duration<<", "<<	
	"start_time="<<x.start_time<<", "<<	
	"end_time="<<x.end_time<<", "<<
	"bytes_in="<<x.bytes_in<<", "<<	
	"bytes_out="<<x.bytes_out<<", "<<
	"input_pkts="<<x.input_pkts<<", "<<
	"output_pkts="<<x.output_pkts<<", "<<
	"service_type="<<x.service_type<<", "<<
	"charge="<<x.charge;	

	return out;
}

// Added by Arjuna Aryasinha - 2002.MAR.26
ostream& operator<<(ostream& out, gric_session_data x)
{
	out<<
	"client_code = "<<x.client_code<<", "<<endl<<
	"account_no = "<<x.account_no<<", "<<endl<<
	"service_type="<<x.service_type<<", "<<
	"record_type="<<x.record_type<<", "<<
	"gmt_start_date="<<x.gmt_start_date<<", "<<
	"gmt_start_time="<<x.gmt_start_time<<", "<<
	"local_start_date="<<x.local_start_date<<", "<<
	"local_start_date="<<x.local_start_date<<", "<<
	"user_id = "<<x.user_id<<", "<<endl<<
	"service_provider="<<x.service_provider<<", "<<	
	"time_unit="<<x.time_unit<<", "<<
	"time_duration="<<x.time_duration<<", "<<	
	"region_name="<<x.region_name<<", "<<
	"charge="<<x.charge<<", "<<
	"no_of_units="<<x.no_of_units<<", "<<
	"rated_date="<<x.rated_date<<", "<<	
	"file_id="<<x.file_id<<", "<<	
	"session_id = "<<x.session_id<<", "<<endl<<
	"nas_ip_login="<<x.nas_ip_login<<", "<<	
	"local_country="<<x.local_country;

	return out;
}
// End of addition by Arjuna Aryasinha - 2002.MAR.26

void call_summary::add_to_summary()
{
	usage_charges	= 0;				
	taxes			= 0;			
	discounts		= 0;			
	interest		= 0;		
	adjustments		= 0;			
	misc_charges	= 0;			
	usage_bytes		= 0;	
	usage_duration	= 0;		
}