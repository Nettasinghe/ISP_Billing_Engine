

/////////////////////////////////////////////////////////////////////
//
// My_Debug.h
// ISP Billing Engine
// header file for debug
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)
inline void debug (const char*); //

#ifdef MYDEBUG

inline void debug (const char * msg) //
{
	//cerr << "DEBUG> " << msg << endl; //
	cout << "DEBUG> " << msg << endl;
}

#else

inline void debug (const char * msg) { ; } //

#endif