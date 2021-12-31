
/*

  major changes after ver 2


26 june 2001 2.0.1
	a) This is for month end billing without start & end account #s

01 july 2001 2.0.2
	a) Hardcode for rental advance payment recognition removed from db_talk.pc

06 august 2001 2.0.3
	a) Encryption of database connect string is introduced

10 sept 2001 2.0.4
	a) ADJUSTMENT_DETAIL_DEF added for adjustmets calculations

12 jan 2002 2.0.5
	a) Interim bill merged to month end bill with #define INTERIM_BILL
	b) All ledger entries removed

26 mar 2002 2.0.6
	a) GRIC implementation by Arjuna Aryasinghe

12 sept 2002 2.0.7
	a) VAT implementation

23 jan 2003 2.0.8
	a) introdused new bill item for mail box changes 

04 apr 2003 2.0.9
	a) Fixed the bug in GRIC rental charge

08 apr 2003 2.0.10
	a) Added "SER_FHTTP" bill item for fhttp rental

26 may 2003 2.0.11
	a) When loading PRO_RATE_NEWCUST, amount is added instead of pkg_prorate_amt

10 nov 2003 2.0.12
	a) Arjuna Aryasinha
		Modified connections::prepare_db_log_state() to take into account the connection status
		of services, when calculating rental.  Earlier, this was not considered 
		in rental calculation.

05 DEC 2003 2.0.13
	a) Arjuna Aryasinha
		Modified the bill engine further as some bugs that were carried forward from 2.0.12 
		were fixed.

26 JAN 2004 2.0.14
	a) Arjuna Aryasinha
		Modified the VAT rate to 1.15 in cVatRate variable, in connections.cpp.

30 JAN 2004 2.0.15
	a) Arjuna Aryasinha
		Modified connections::get_vat_amount method in connections.cpp to rectify a 
		truncation error in values.
  



*/