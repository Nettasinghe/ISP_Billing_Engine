
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned long magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[33];
};
static const struct sqlcxp sqlfpn =
{
    32,
    "C:\\ARJ_WKSPC\\BILL_ENG\\db_talk.pc"
};


static unsigned long sqlctx = 1434056877;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
            void  *sqhstv[20];
   unsigned int   sqhstl[20];
            int   sqhsts[20];
            void  *sqindv[20];
            int   sqinds[20];
   unsigned int   sqharm[20];
   unsigned int   *sqharc[20];
   unsigned short  sqadto[20];
   unsigned short  sqtdso[20];
} sqlstm = {10,20};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned long *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned long *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(char *, int *); }

 static const char *sq0006 = 
"select ADJUSTMENT_TYPE ,DATE_CREATED ,TAX  from BILL_ADJUSTMENT_TYPES       \
     ";

 static const char *sq0009 = 
"select SESSION_ID ,USER_ID ,IP_LOGIN ,TIME_DURATION ,START_TIME ,END_TIME ,B\
YTES_IN ,BYTES_OUT ,INPUT_PKTS ,OUTPUT_PKTS ,SERVICE_TYPE ,CHARGE ,ACCOUNT_NO \
,FREE_MINUTES ,NO_OF_UNITS  from RATED_SESSION_RECORDS where (TRUNC(START_TIME\
)>=to_date(:b0,'YYYYMMDD') and TRUNC(START_TIME)<=to_date(:b1,'YYYYMMDD')) ord\
er by START_TIME            ";

 static const char *sq0010 = 
"select CLIENT_CODE ,ACCOUNT_NO ,SERVICE_TYPE ,RECORD_TYPE ,GMT_DATE ,GMT_TIM\
E ,LOCAL_DATE ,LOCAL_TIME ,USER_ID ,SERVICE_PROVIDER ,TIME_UNIT ,SESSION_TIME \
,REGION_NAME ,CHARGE ,NO_OF_UNITS ,RATED_DATE ,FILE_ID ,SESSION_ID ,NAS_IP_LOG\
IN ,LOCAL_COUNTRY  from GRIC_RATED_SESSIONS where TRUNC(RATED_DATE) between TO\
_DATE(:b0,'YYYYMMDD') and TO_DATE(:b1,'YYYYMMDD')           ";

 static const char *sq0011 = 
"select ACCOUNT_NO ,PACKAGE_CODE ,CURRENT_STATUS_DATE ,TAX_GROUP_ID ,CORPORAT\
E_CODE ,CLIENT_CODE ,VAT_NO ,CONNECTION_STATUS  from MIRRORED_BILL_CONNECTIONS\
 where ((TRUNC(COMMENCEMENT_DATE)<=to_date(:b0,'YYYYMMDD') and ((CONNECTION_ST\
ATUS='CONNT' or CONNECTION_STATUS='TDISC') or (TRUNC(CURRENT_STATUS_DATE) betw\
een to_date(:b1,'YYYYMMDD') and to_date(:b0,'YYYYMMDD') and CONNECTION_STATUS=\
'PDISC'))) and TRUNC(BILL_PERIOD_START)=to_date(:b1,'YYYYMMDD'))           ";

 static const char *sq0012 = 
"select BR_CODE ,CLIENT_CODE  from MIRRORED_BILL_CLIENTS where TRUNC(BILL_PER\
IOD_START)=to_date(:b0,'YYYYMMDD')           ";

 static const char *sq0013 = 
"select CLIENT_CODE ,ACCOUNT_NO ,BILL_NO ,DUE_DATE ,BILL_DATE ,BILL_PERIOD_ST\
ART ,BILL_PERIOD_END ,BALANCE_BF ,BILL_AMOUNT ,BALANCE_CF ,BILL_RUN_CODE ,BILL\
_PAYMENTS ,RUN_NO ,PRINTED  from BILL_MASTER where (BILL_PERIOD_START=to_date(\
:b0,'YYYYMMDD') and BILL_PERIOD_END=to_date(:b1,'YYYYMMDD'))           ";

 static const char *sq0014 = 
"select RENTAL ,START_DATE ,END_DATE ,ACCOUNT_NO ,CLIENT_CODE ,SERVICE_CODE ,\
USER_USERNAME ,SERVICE_INSTANCE ,CONNECTION_STATUS ,ATTRIBUTION ,RATE_GROUP_ID\
 ,RENTAL_ACTV_DATE ,SERVICE_QUOTA  from MIRRORED_BILL_CONN_SERVICES where (TRU\
NC(RENTAL_ACTV_DATE)<=to_date(:b0,'YYYYMMDD') and TRUNC(BILL_PERIOD_START)=to_\
date(:b1,'YYYYMMDD'))           ";

 static const char *sq0015 = 
"select PACKAGE_CODE ,DESCRIPTION ,RENTAL ,FREE_APPLIED_ON ,FREE_IN_BYTES ,FR\
EE_OUT_BYTES ,FREE_MINUTES ,ACTIVATED_ON ,DEACTIVATED_ON ,PACKAGE_TYPE ,FREE_U\
NITS  from MIRRORED_BILL_PACKAGES where (PACKAGE_TYPE='O' and TRUNC(BILL_PERIO\
D_START)=to_date(:b0,'YYYYMMDD'))           ";

 static const char *sq0017 = 
"select TAX_TYPE_ID ,TAX_RATE ,TAX_SLAB  from TAX_ITEMS            ";

 static const char *sq0018 = 
"select TAX_GROUP_ID ,TAX_TYPE_ID ,PRIORITY  from TAX_GROUP_ITEMS            ";

 static const char *sq0019 = 
"select CLIENT_CODE ,DISCOUNT_TYPE ,ACCOUNT_NO  from CONNECTION_DISCOUNTS    \
        ";

 static const char *sq0020 = 
"select DISCOUNT_TYPE ,DESCRIPTION  from DISCOUNT_TYPES            ";

 static const char *sq0021 = 
"select DISCOUNT_TYPE ,RULE_NUMBER ,PERCENTAGE ,RATE ,CONTENT_OR_DURATION ,RE\
NTAL_WAIVED ,UPPER_LIMIT ,LOWER_LIMIT ,TIME_BAND_GROUP ,TIME_BAND_TYPE ,DAY_ID\
  from DISCOUNT_RULES            ";

 static const char *sq0022 = 
"select ACCOUNT_NO ,ADJUSTMENT_TYPE ,AMOUNT_ADJUSTED ,DISAPPROVED_REASON ,PRO\
CESSED ,REFERENCE_NO  from BILL_ACCOUNT_ADJUSTMENTS where (TRUNC(APPROVED_DATE\
)>=to_date(:b0,'YYYYMMDD') and TRUNC(APPROVED_DATE)<=to_date(:b1,'YYYYMMDD')) \
          ";

 static const char *sq0027 = 
"select CLIENT_CODE ,DATE_PAID ,NO_OF_MONTHS_FREE ,NO_OF_MONTHS_PAID ,ACCOUNT\
_NO ,BALANCE_MONTHS  from MIRRORED_BILL_RENT_ADV_PAYMTS where (TRUNC(DATE_PAID\
)<=to_date(:b0,'YYYYMMDD') and TRUNC(BILL_PERIOD_START)=to_date(:b1,'YYYYMMDD'\
)) order by DATE_PAID desc             ";

 static const char *sq0041 = 
"select INSTANCE ,CLIENT_CODE ,ACCOUNT_NO ,CHANGED_DATE ,AMOUNT ,OLD_PACKAGE_\
CODE ,NEW_PACKAGE_CODE ,PROCESSED ,PKG_PRORATE_AMT  from PRO_RATE_NEWCUST wher\
e (TRUNC(CHANGED_DATE)>=to_date(:b0,'YYYYMMDD') and TRUNC(CHANGED_DATE)<=to_da\
te(:b1,'YYYYMMDD')) order by INSTANCE            ";

 static const char *sq0042 = 
"select INSTANCE ,CLIENT_CODE ,ACCOUNT_NO ,DATE_CHANGED ,AMOUNT ,SERVICE_CODE\
 ,PROCESSED  from PRO_RATE_services where (TRUNC(DATE_CHANGED)>=to_date(:b0,'Y\
YYYMMDD') and TRUNC(DATE_CHANGED)<=to_date(:b1,'YYYYMMDD'))           ";

 static const char *sq0052 = 
"select ACCOUNT_NO ,PACKAGE_CODE ,CURRENT_STATUS_DATE ,TAX_GROUP_ID ,CORPORAT\
E_CODE ,CLIENT_CODE ,VAT_NO ,CONNECTION_STATUS  from CONNECTIONS where (TRUNC(\
COMMENCEMENT_DATE)<=to_date(:b0,'YYYYMMDD') and ((CONNECTION_STATUS='CONNT' or\
 CONNECTION_STATUS='TDISC') or (TRUNC(CURRENT_STATUS_DATE) between to_date(:b1\
,'YYYYMMDD') and to_date(:b0,'YYYYMMDD') and CONNECTION_STATUS='PDISC')))     \
      ";

 static const char *sq0053 = 
"select CLIENT_CODE ,ACCOUNT_NO ,BILL_NO ,DUE_DATE ,BILL_DATE ,BILL_PERIOD_ST\
ART ,BILL_PERIOD_END ,BALANCE_BF ,BILL_AMOUNT ,BALANCE_CF ,BILL_RUN_CODE ,BILL\
_PAYMENTS ,RUN_NO ,PRINTED  from BILL_MASTER where (BILL_DATE is null  and BIL\
L_PERIOD_START=to_date(:b0,'YYYYMMDD'))           ";

 static const char *sq0054 = 
"select BR_CODE ,CLIENT_CODE  from CLIENTS            ";

 static const char *sq0055 = 
"select CLIENT_CODE ,DATE_PAID ,NO_OF_MONTHS_FREE ,NO_OF_MONTHS_PAID ,ACCOUNT\
_NO ,BALANCE_MONTHS  from RENTAL_ADVANCE_PAYMENTS where TRUNC(DATE_PAID)<=to_d\
ate(:b0,'YYYYMMDD') order by DATE_PAID desc             ";

 static const char *sq0056 = 
"select PACKAGE_CODE ,DESCRIPTION ,RENTAL ,FREE_APPLIED_ON ,FREE_IN_BYTES ,FR\
EE_OUT_BYTES ,FREE_MINUTES ,ACTIVATED_ON ,DEACTIVATED_ON ,PACKAGE_TYPE ,FREE_U\
NITS  from PACKAGES where PACKAGE_TYPE='O'           ";

 static const char *sq0057 = 
"select RENTAL ,START_DATE ,END_DATE ,ACCOUNT_NO ,CLIENT_CODE ,SERVICE_CODE ,\
USER_USERNAME ,SERVICE_INSTANCE ,CONNECTION_STATUS ,ATTRIBUTION ,RATE_GROUP_ID\
 ,RENTAL_ACTV_DATE ,SERVICE_QUOTA  from CONNECTION_SERVICES            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{10,4146,178,0,0,
5,0,0,1,0,0,32,63,0,0,0,0,0,1,0,
20,0,0,2,0,0,32,74,0,0,0,0,0,1,0,
35,0,0,3,0,0,27,90,0,0,4,4,0,2,3,73,83,80,1,5,0,0,1,10,0,0,1,10,0,0,1,10,0,0,
69,0,0,4,57,0,1,93,0,0,0,0,0,2,3,73,83,80,
87,0,0,5,0,0,30,105,0,0,0,0,0,2,3,73,83,80,
105,0,0,6,81,0,9,161,0,0,0,0,0,2,3,73,83,80,
123,0,0,6,0,0,13,166,0,0,3,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,5,0,0,
153,0,0,6,0,0,15,210,0,0,0,0,0,2,3,73,83,80,
171,0,0,7,48,0,4,222,0,0,1,0,0,2,3,73,83,80,2,3,0,0,
193,0,0,8,55,0,4,242,0,0,1,0,0,2,3,73,83,80,2,3,0,0,
215,0,0,9,338,0,9,347,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
241,0,0,9,0,0,13,352,0,0,15,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,
5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,4,0,0,2,3,0,0,2,4,0,0,
2,3,0,0,
319,0,0,9,0,0,15,406,0,0,0,0,0,2,3,73,83,80,
337,0,0,10,370,0,9,516,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
363,0,0,10,0,0,13,521,0,0,20,0,0,2,3,73,83,80,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,5,0,0,2,4,0,
0,2,4,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
461,0,0,10,0,0,15,597,0,0,0,0,0,2,3,73,83,80,
479,0,0,11,463,0,9,686,0,0,4,4,0,2,3,73,83,80,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,
513,0,0,11,0,0,13,691,0,0,8,0,0,2,3,73,83,80,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,
5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
563,0,0,11,0,0,15,763,0,0,0,0,0,2,3,73,83,80,
581,0,0,12,121,0,9,814,0,0,1,1,0,2,3,73,83,80,1,5,0,0,
603,0,0,12,0,0,13,819,0,0,2,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,
629,0,0,12,0,0,15,847,0,0,0,0,0,2,3,73,83,80,
647,0,0,13,303,0,9,939,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
673,0,0,13,0,0,13,944,0,0,14,0,0,2,3,73,83,80,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,4,0,0,2,3,0,0,2,5,0,
0,
747,0,0,13,0,0,15,989,0,0,0,0,0,2,3,73,83,80,
765,0,0,14,342,0,9,1079,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
791,0,0,14,0,0,13,1084,0,0,13,0,0,2,3,73,83,80,2,4,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,
861,0,0,14,0,0,15,1149,0,0,0,0,0,2,3,73,83,80,
879,0,0,15,276,0,9,1229,0,0,1,1,0,2,3,73,83,80,1,5,0,0,
901,0,0,15,0,0,13,1234,0,0,11,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,4,0,0,2,5,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
963,0,0,15,0,0,15,1280,0,0,0,0,0,2,3,73,83,80,
981,0,0,16,97,0,3,1310,0,0,4,4,0,2,3,73,83,80,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,
1015,0,0,17,66,0,9,1344,0,0,0,0,0,2,3,73,83,80,
1033,0,0,17,0,0,13,1350,0,0,3,0,0,2,3,73,83,80,2,5,0,0,2,4,0,0,2,4,0,0,
1063,0,0,17,0,0,15,1359,0,0,0,0,0,2,3,73,83,80,
1081,0,0,18,76,0,9,1384,0,0,0,0,0,2,3,73,83,80,
1099,0,0,18,0,0,13,1390,0,0,3,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,3,0,0,
1129,0,0,18,0,0,15,1406,0,0,0,0,0,2,3,73,83,80,
1147,0,0,19,84,0,9,1456,0,0,0,0,0,2,3,73,83,80,
1165,0,0,19,0,0,13,1461,0,0,3,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,3,0,0,
1195,0,0,19,0,0,15,1484,0,0,0,0,0,2,3,73,83,80,
1213,0,0,20,66,0,9,1530,0,0,0,0,0,2,3,73,83,80,
1231,0,0,20,0,0,13,1535,0,0,2,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,
1257,0,0,20,0,0,15,1555,0,0,0,0,0,2,3,73,83,80,
1275,0,0,21,187,0,9,1631,0,0,0,0,0,2,3,73,83,80,
1293,0,0,21,0,0,13,1636,0,0,11,0,0,2,3,73,83,80,2,5,0,0,2,3,0,0,2,4,0,0,2,4,0,
0,2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
1355,0,0,21,0,0,15,1731,0,0,0,0,0,2,3,73,83,80,
1373,0,0,22,242,0,9,1798,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
1399,0,0,22,0,0,13,1803,0,0,6,0,0,2,3,73,83,80,2,3,0,0,2,5,0,0,2,4,0,0,2,5,0,0,
2,5,0,0,2,3,0,0,
1441,0,0,22,0,0,15,1858,0,0,0,0,0,2,3,73,83,80,
1459,0,0,23,114,0,5,1876,0,0,2,2,0,2,3,73,83,80,1,3,0,0,1,3,0,0,
1485,0,0,24,114,0,5,1902,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,3,0,0,
1511,0,0,25,320,0,3,1946,0,0,7,7,0,2,3,73,83,80,1,5,0,0,1,3,0,0,1,5,0,0,1,5,0,
0,1,5,0,0,1,4,0,0,1,5,0,0,
1557,0,0,26,379,0,3,2044,0,0,15,15,0,2,3,73,83,80,1,5,0,0,1,3,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,
5,0,0,1,5,0,0,
1635,0,0,27,271,0,9,2154,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
1661,0,0,27,0,0,13,2159,0,0,6,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,
1703,0,0,27,0,0,15,2192,0,0,0,0,0,2,3,73,83,80,
1721,0,0,28,195,0,5,2217,0,0,3,3,0,2,3,73,83,80,1,5,0,0,1,5,0,0,1,3,0,0,
1751,0,0,29,41,0,1,2234,0,0,0,0,0,2,3,73,83,80,
1769,0,0,30,58,0,5,2253,0,0,1,1,0,2,3,73,83,80,1,3,0,0,
1791,0,0,31,92,0,4,2278,0,0,1,0,0,2,3,73,83,80,2,3,0,0,
1813,0,0,32,100,0,4,2285,0,0,1,0,0,2,3,73,83,80,2,3,0,0,
1835,0,0,33,115,0,4,2303,0,0,3,1,0,2,3,73,83,80,2,5,0,0,2,5,0,0,1,3,0,0,
1865,0,0,34,115,0,4,2312,0,0,3,1,0,2,3,73,83,80,2,5,0,0,2,5,0,0,1,3,0,0,
1895,0,0,35,122,0,4,2368,0,0,4,1,0,2,3,73,83,80,2,5,0,0,2,3,0,0,2,3,0,0,1,5,0,
0,
1929,0,0,36,55,0,4,2390,0,0,1,0,0,2,3,73,83,80,2,5,0,0,
1951,0,0,37,88,0,4,2442,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
1977,0,0,38,88,0,4,2452,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
2003,0,0,39,89,0,4,2465,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
2029,0,0,40,77,0,4,2476,0,0,3,2,0,2,3,73,83,80,1,5,0,0,1,3,0,0,2,5,0,0,
2059,0,0,41,281,0,9,2583,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
2085,0,0,41,0,0,13,2588,0,0,9,0,0,2,3,73,83,80,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,
2,4,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,
2139,0,0,41,0,0,15,2621,0,0,0,0,0,2,3,73,83,80,
2157,0,0,42,224,0,9,2690,0,0,2,2,0,2,3,73,83,80,1,5,0,0,1,5,0,0,
2183,0,0,42,0,0,13,2695,0,0,7,0,0,2,3,73,83,80,2,3,0,0,2,5,0,0,2,3,0,0,2,5,0,0,
2,4,0,0,2,5,0,0,2,5,0,0,
2229,0,0,42,0,0,15,2724,0,0,0,0,0,2,3,73,83,80,
2247,0,0,43,51,0,4,2757,0,0,1,0,0,2,3,73,83,80,2,3,0,0,
2269,0,0,44,168,0,3,2781,0,0,7,7,0,2,3,73,83,80,1,3,0,0,1,5,0,0,1,3,0,0,1,5,0,
0,1,4,0,0,1,5,0,0,1,5,0,0,
2315,0,0,45,71,0,4,2814,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
2341,0,0,46,109,0,3,2823,0,0,3,3,0,2,3,73,83,80,1,5,0,0,1,5,0,0,1,5,0,0,
2371,0,0,47,93,0,4,2845,0,0,2,0,0,2,3,73,83,80,2,4,0,0,2,4,0,0,
2397,0,0,48,48,0,1,2863,0,0,0,0,0,2,3,73,83,80,
2415,0,0,49,41,0,1,2874,0,0,0,0,0,2,3,73,83,80,
2433,0,0,50,95,0,3,2910,0,0,4,4,0,2,3,73,83,80,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,
2467,0,0,51,377,0,3,2990,0,0,15,15,0,2,3,73,83,80,1,5,0,0,1,3,0,0,1,5,0,0,1,5,
0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,5,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,
5,0,0,1,5,0,0,
2545,0,0,52,394,0,9,3116,0,0,3,3,0,2,3,73,83,80,1,5,0,0,1,5,0,0,1,5,0,0,
2575,0,0,52,0,0,13,3121,0,0,8,0,0,2,3,73,83,80,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,
2625,0,0,52,0,0,15,3195,0,0,0,0,0,2,3,73,83,80,
2643,0,0,53,282,0,9,3286,0,0,1,1,0,2,3,73,83,80,1,5,0,0,
2665,0,0,53,0,0,13,3291,0,0,14,0,0,2,3,73,83,80,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,
0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,5,0,0,2,4,0,0,2,3,0,0,2,5,
0,0,
2739,0,0,53,0,0,15,3336,0,0,0,0,0,2,3,73,83,80,
2757,0,0,54,53,0,9,3384,0,0,0,0,0,2,3,73,83,80,
2775,0,0,54,0,0,13,3389,0,0,2,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,
2801,0,0,54,0,0,15,3417,0,0,0,0,0,2,3,73,83,80,
2819,0,0,55,210,0,9,3484,0,0,1,1,0,2,3,73,83,80,1,5,0,0,
2841,0,0,55,0,0,13,3489,0,0,6,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,
2883,0,0,55,0,0,15,3521,0,0,0,0,0,2,3,73,83,80,
2901,0,0,56,207,0,9,3601,0,0,0,0,0,2,3,73,83,80,
2919,0,0,56,0,0,13,3606,0,0,11,0,0,2,3,73,83,80,2,5,0,0,2,5,0,0,2,4,0,0,2,5,0,
0,2,3,0,0,2,3,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,
2981,0,0,56,0,0,15,3651,0,0,0,0,0,2,3,73,83,80,
2999,0,0,57,225,0,9,3736,0,0,0,0,0,2,3,73,83,80,
3017,0,0,57,0,0,13,3741,0,0,13,0,0,2,3,73,83,80,2,4,0,0,2,5,0,0,2,5,0,0,2,3,0,
0,2,5,0,0,2,5,0,0,2,5,0,0,2,3,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,5,0,0,2,4,0,0,
3087,0,0,57,0,0,15,3795,0,0,0,0,0,2,3,73,83,80,
3105,0,0,58,122,0,4,3823,0,0,4,1,0,2,3,73,83,80,2,5,0,0,2,3,0,0,2,3,0,0,1,5,0,
0,
3139,0,0,59,55,0,4,3845,0,0,1,0,0,2,3,73,83,80,2,5,0,0,
3161,0,0,60,88,0,4,3897,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
3187,0,0,61,88,0,4,3907,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
3213,0,0,62,85,0,4,3920,0,0,2,1,0,2,3,73,83,80,1,5,0,0,2,5,0,0,
3239,0,0,63,77,0,4,3931,0,0,3,2,0,2,3,73,83,80,1,5,0,0,1,3,0,0,2,5,0,0,
};


#pragma warning(disable:4786)

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <oraca.h>
#include <sqlcpr.h>

#include <sqlda.h>
#include <sqlca.h>

/* EXEC SQL DECLARE ISP DATABASE; */ 





#ifndef ORA_PROC
	#include "db.h"
	#include "db_data_containers.h"
	#include "functions.h"
	#include "My_Debug.h"
	extern bill_cycle	*gsm_bill_cycle;
	extern package_map	*gsm_packages;
	extern connection_services_multimap	*gsm_connection_services;
	extern taxes		*gsm_taxes;
	extern discounts	*gsm_discounts;
	extern connections	*gsm_connections;
	extern FILE *logfile;
#endif



#define		BUF_LEN		   50
#define		SESSION_FETCH_SIZE		100
#define		FETCH_SIZE		2

/* EXEC SQL BEGIN DECLARE SECTION; */ 

char *login_isp;
/* EXEC SQL END DECLARE SECTION; */ 



/* EXEC SQL INCLUDE sqlda;
 */ 
/*
 * $Header: sqlda.h 31-jul-99.19:34:41 apopat Exp $ sqlda.h 
 */

/***************************************************************
*      The SQLDA descriptor definition                         *
*--------------------------------------------------------------*
*      VAX/3B Version                                          *
*                                                              *
*  Copyright (c) 1987, 1997, 1998, 1999 by Oracle Corporation                    *
***************************************************************/


/* NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************
*/

/*  MODIFIED
    apopat     07/31/99 -  [707588] TAB to blanks for OCCS
    lvbcheng   10/27/98 -  change long to int for sqlda
    lvbcheng   08/15/97 -  Move sqlda protos to sqlcpr.h
    lvbcheng   06/25/97 -  Move sqlda protos to this file
    jbasu      01/29/95 -  correct typo
    jbasu      01/27/95 -  correct comment - ub2->sb2
    jbasu      12/12/94 - Bug 217878: note this is an SOSD file
    Morse      12/01/87 - undef L and S for v6 include files
    Richey     07/13/87 - change int defs to long 
    Clare      09/13/84 - Port: Ch types to match SQLLIB structs
    Clare      10/02/86 - Add ifndef SQLDA
*/

#ifndef SQLDA_
#define SQLDA_ 1
 
#ifdef T
# undef T
#endif
#ifdef F
# undef F
#endif

#ifdef S
# undef S
#endif
#ifdef L
# undef L
#endif
 
struct SQLDA {
  /* ub4    */ int        N; /* Descriptor size in number of entries        */
  /* text** */ char     **V; /* Ptr to Arr of addresses of main variables   */
  /* ub4*   */ int       *L; /* Ptr to Arr of lengths of buffers            */
  /* sb2*   */ short     *T; /* Ptr to Arr of types of buffers              */
  /* sb2**  */ short    **I; /* Ptr to Arr of addresses of indicator vars   */
  /* sb4    */ int        F; /* Number of variables found by DESCRIBE       */
  /* text** */ char     **S; /* Ptr to Arr of variable name pointers        */
  /* ub2*   */ short     *M; /* Ptr to Arr of max lengths of var. names     */
  /* ub2*   */ short     *C; /* Ptr to Arr of current lengths of var. names */
  /* text** */ char     **X; /* Ptr to Arr of ind. var. name pointers       */
  /* ub2*   */ short     *Y; /* Ptr to Arr of max lengths of ind. var. names */
  /* ub2*   */ short     *Z; /* Ptr to Arr of cur lengths of ind. var. names */
  };
 
typedef struct SQLDA SQLDA;
 
#endif

/* ----------------- */
/* defines for sqlda */
/* ----------------- */

#define SQLSQLDAAlloc(arg1, arg2, arg3, arg4) sqlaldt(arg1, arg2, arg3, arg4) 

#define SQLSQLDAFree(arg1, arg2) sqlclut(arg1, arg2) 



/* EXEC SQL INCLUDE sqlca;
 */ 
/*
 * $Header: sqlca.h,v 1.3 1994/12/12 19:27:27 jbasu Exp $ sqlca.h 
 */

/* Copyright (c) 1985,1986, 1998 by Oracle Corporation. */
 
/*
NAME
  SQLCA : SQL Communications Area.
FUNCTION
  Contains no code. Oracle fills in the SQLCA with status info
  during the execution of a SQL stmt.
NOTES
  **************************************************************
  ***                                                        ***
  *** This file is SOSD.  Porters must change the data types ***
  *** appropriately on their platform.  See notes/pcport.doc ***
  *** for more information.                                  ***
  ***                                                        ***
  **************************************************************

  If the symbol SQLCA_STORAGE_CLASS is defined, then the SQLCA
  will be defined to have this storage class. For example:
 
    #define SQLCA_STORAGE_CLASS extern
 
  will define the SQLCA as an extern.
 
  If the symbol SQLCA_INIT is defined, then the SQLCA will be
  statically initialized. Although this is not necessary in order
  to use the SQLCA, it is a good pgming practice not to have
  unitialized variables. However, some C compilers/OS's don't
  allow automatic variables to be init'd in this manner. Therefore,
  if you are INCLUDE'ing the SQLCA in a place where it would be
  an automatic AND your C compiler/OS doesn't allow this style
  of initialization, then SQLCA_INIT should be left undefined --
  all others can define SQLCA_INIT if they wish.

  If the symbol SQLCA_NONE is defined, then the SQLCA variable will
  not be defined at all.  The symbol SQLCA_NONE should not be defined
  in source modules that have embedded SQL.  However, source modules
  that have no embedded SQL, but need to manipulate a sqlca struct
  passed in as a parameter, can set the SQLCA_NONE symbol to avoid
  creation of an extraneous sqlca variable.
 
MODIFIED
    lvbcheng   07/31/98 -  long to int
    jbasu      12/12/94 -  Bug 217878: note this is an SOSD file
    losborne   08/11/92 -  No sqlca var if SQLCA_NONE macro set 
  Clare      12/06/84 - Ch SQLCA to not be an extern.
  Clare      10/21/85 - Add initialization.
  Bradbury   01/05/86 - Only initialize when SQLCA_INIT set
  Clare      06/12/86 - Add SQLCA_STORAGE_CLASS option.
*/
 
#ifndef SQLCA
#define SQLCA 1
 
struct   sqlca
         {
         /* ub1 */ char    sqlcaid[8];
         /* b4  */ int     sqlabc;
         /* b4  */ int     sqlcode;
         struct
           {
           /* ub2 */ unsigned short sqlerrml;
           /* ub1 */ char           sqlerrmc[70];
           } sqlerrm;
         /* ub1 */ char    sqlerrp[8];
         /* b4  */ int     sqlerrd[6];
         /* ub1 */ char    sqlwarn[8];
         /* ub1 */ char    sqlext[8];
         };

#ifndef SQLCA_NONE 
#ifdef   SQLCA_STORAGE_CLASS
SQLCA_STORAGE_CLASS struct sqlca sqlca
#else
         struct sqlca sqlca
#endif
 
#ifdef  SQLCA_INIT
         = {
         {'S', 'Q', 'L', 'C', 'A', ' ', ' ', ' '},
         sizeof(struct sqlca),
         0,
         { 0, {0}},
         {'N', 'O', 'T', ' ', 'S', 'E', 'T', ' '},
         {0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0}
         }
#endif
         ;
#endif
 
#endif
 
/* end SQLCA */

/* EXEC ORACLE OPTION (ORACA=YES); */ 





void sql_error(char *msg)
{
    cout << endl << msg << endl;
    sqlca.sqlerrm.sqlerrmc[sqlca.sqlerrm.sqlerrml] = '\0';
    oraca.orastxt.orastxtc[oraca.orastxt.orastxtl] = '\0';
    oraca.orasfnm.orasfnmc[oraca.orasfnm.orasfnml] = '\0';
    cout << sqlca.sqlerrm.sqlerrmc << endl;
    cout << "in " << oraca.orastxt.orastxtc << endl;
    cout << "on line " << oraca.oraslnr << " of " << oraca.orasfnm.orasfnmc
         << endl << endl;

  //-- Roll back any pending changes and disconnect from Oracle.

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    exit(1);
}


void not_found_error(char *msg)
{
    cout << endl << msg << endl;
   
  //-- Roll back any pending changes and disconnect from Oracle.

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 0;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )20;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    exit(1);
}



// Connect to ORACLE.

void db_connect_isp(char *in_login)
{
	login_isp = in_login;  // a pointer assignment, in_login has the space acclocation

    /* EXEC SQL WHENEVER SQLERROR DO sql_error("ORACLE error--"); */ 

    //printf("\nConnecting to ORACLE as    : %s\n", login_isp);
	printf("\nConnecting to ORACLE "); 

    /* EXEC SQL CONNECT :login_isp AT ISP; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )10;
    sqlstm.offset = (unsigned int  )35;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)login_isp;
    sqlstm.sqhstl[0] = (unsigned int  )0;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	printf("\nConnected to ORACLE ");
	/* EXEC SQL AT ISP ALTER SESSION SET NLS_DATE_FORMAT="YYYYMMDD HH24:MI:SS"; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "alter SESSION SET NLS_DATE_FORMAT = \"YYYYMMDD HH24:MI:SS\"";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )69;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

	// added on 16-09-2002
	printf("\nChanged NLS_DATE_FORMAT ");
}


//-- exit with grace
void db_disconnect_isp()
{
	debug("\nDisconnect from ORACLE as  : ");
	debug(login_isp);
	//printf("\nDisconnect from ORACLE as  : %s\n", login_isp);
	printf("\nDisconnect from ORACLE ");
	/* EXEC SQL AT ISP COMMIT WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )87;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	printf("\nBill run successful ");
	fprintf(logfile, "%s",  "\nDisconnect from ORACLE ");
	fprintf(logfile, "%s",  "\nBill run successful\n ");
 
    //exit(EXIT_SUCCESS); 	
}

//-- bill_adjustment_types
void connections::db_read_bill_adjustment_types()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct bill_adjustment_types_t
	{
			char	adjustment_type[15];		// varchar2(10)			
			char	date_created[BUF_LEN];		// varchar2(1)	
			char	tax[2];					
	} *a;

	struct bill_adjustment_types_ind
	{ 
  			short	adjustment_type_ind;				
			short	date_created_ind;		
			short	tax_ind;					
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	
	bill_adjustment_type	bat;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new bill_adjustment_types_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_adjustment_types fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_bill_adjustment_types CURSOR FOR
	SELECT	ADJUSTMENT_TYPE,				
			DATE_CREATED,
			TAX		
	FROM	BILL_ADJUSTMENT_TYPES; */ 

	
       
    /* EXEC SQL AT ISP  OPEN c_bill_adjustment_types; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0006;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )105;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_bill_adjustment_types INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )123;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->adjustment_type;
  sqlstm.sqhstl[0] = (unsigned int  )15;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_adjustment_types_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->adjustment_type_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct bill_adjustment_types_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->date_created;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_adjustment_types_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->date_created_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct bill_adjustment_types_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->tax;
  sqlstm.sqhstl[2] = (unsigned int  )2;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill_adjustment_types_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->tax_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct bill_adjustment_types_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			strcpy(a[i].adjustment_type,
				  ((a_ind[i].adjustment_type_ind < 0) ? "UNDEF":a[i].adjustment_type));
			strcpy(a[i].date_created,
				  ((a_ind[i].date_created_ind < 0) ? "UNDEF":a[i].date_created));
			strcpy(a[i].tax,
				  ((a_ind[i].tax_ind < 0) ? "U":a[i].tax));
			
						
			bat.adjustment_type	= a[i].adjustment_type;

			if ( strcmp(a[i].tax,"Y")==0)
			{
				bat.tax			= true;
			}
			else
			{
				if ( strcmp(a[i].tax,"N")==0)
				{
					bat.tax			= false;
				}
				else
				{
					cout << "Undefined tax value in BILL_ADJUSTMENT_TYPES" << endl;
					cout << a[i].tax << "end" << endl;
				}
			}
				 
			bat.value			= 0;						
				
			gsm_connections->bill_adjustment_type_map[a[i].adjustment_type] = bat;

		}
	} 

	/* EXEC SQL AT ISP CLOSE c_bill_adjustment_types; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )153;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  c_bill_adjustment_types records read.\n\n",rows_before);
} 

//-- checking bill_master_raw_for_entries
void connections::check_bill_master_raw()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	int row_count=0;
	/* EXEC SQL END DECLARE SECTION; */ 

	
    /* EXEC SQL 
	AT ISP 
	SELECT COUNT(*) INTO :row_count FROM BILL_MASTER_RAW ; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(*)  into :b0  from BILL_MASTER_RAW ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )171;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&row_count;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	if (row_count >0 )
	{
		cout << "Entries already in bill_master_raw table" << endl;
		fprintf(logfile, "%s",  "\nEntries already in bill_master_raw table ");
		fprintf(logfile, "%s",  "\nExiting with Error ");
		cout <<"Exiting with Error" << endl;				
	}		
}

//-- checking bill_summary_items_raw_for_entries
void connections::check_bill_summary_items_raw()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	int row_count=0;
	/* EXEC SQL END DECLARE SECTION; */ 

	
    /* EXEC SQL 
	AT ISP 
	SELECT COUNT(*) INTO :row_count FROM BILL_SUMMARY_ITEMS_RAW ; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select count(*)  into :b0  from BILL_SUMMARY_ITEMS_RAW ";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )193;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&row_count;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	if (row_count >0 )
	{
		cout << "Entries already in bill_summary_items_raw table" << endl;
		fprintf(logfile, "%s",  "\nEntries already in bill_summary_items_raw table ");
		fprintf(logfile, "%s",  "\nExiting with Error ");
		cout <<"Exiting with Error" << endl;				
	}		
	
}

//-- sessions
void connections::db_read_sessions()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct session_t
	{
		char	session_id[BUF_LEN];				
		char	user_id[BUF_LEN];		
		char	ip_login[BUF_LEN];					
		int		time_duration;				
		char	start_time[BUF_LEN];		
		char	end_time[BUF_LEN];				
		int		bytes_in;	
		int		bytes_out;		
		int		input_pkts;		
		int		output_pkts;		
		char	service_type[BUF_LEN];
		float	charge;
		int		account_no;
		float	free_min;
		int		no_of_units;
	} *a;

	struct session_ind
	{
		short	session_id_ind;				
		short	user_id_ind;		
		short	ip_login_ind;					
		short	time_duration_ind;				
		short	start_time_ind;		
		short	end_time_ind;				
		short	bytes_in_ind;	
		short	bytes_out_ind;		
		short	input_pkts_ind;		
		short	output_pkts_ind;		
		short	service_type_ind;
		short	charge_ind;
		short	account_no_ind;
		short	free_min_ind;
		short	no_of_units_ind;
	}a_ind[SESSION_FETCH_SIZE];

	char t_start_date[20], t_end_date[20];
	char t_session_date[20];
	int t_start_ac, t_end_ac;
	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
	strcpy(t_session_date, session_date.c_str());
	t_start_ac = start_ac_no;
	t_end_ac = end_ac_no;
	session_data sd;

	rows_to_fetch = SESSION_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = SESSION_FETCH_SIZE; 

	if((a = new session_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for session fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_session CURSOR FOR 
	SELECT	SESSION_ID,				
			USER_ID,		
			IP_LOGIN,					
			TIME_DURATION,				
			START_TIME,		
			END_TIME,				
			BYTES_IN,	
			BYTES_OUT,		
			INPUT_PKTS,		
			OUTPUT_PKTS,		
			SERVICE_TYPE,
			CHARGE,
			ACCOUNT_NO,
			FREE_MINUTES,
			NO_OF_UNITS
	FROM	RATED_SESSION_RECORDS
	WHERE	TRUNC(START_TIME) >= to_date(:t_start_date,'YYYYMMDD') AND TRUNC(START_TIME) <= to_date(:t_end_date,'YYYYMMDD')
			ORDER BY START_TIME; */ 

			
    /* EXEC SQL AT ISP  OPEN c_session; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0009;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )215;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_end_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_session INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )241;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->session_id;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->session_id_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->user_id;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->user_id_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->ip_login;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->ip_login_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->time_duration;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->time_duration_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->start_time;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->start_time_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->end_time;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->end_time_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&a->bytes_in;
  sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->bytes_in_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->bytes_out;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->bytes_out_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&a->input_pkts;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->input_pkts_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&a->output_pkts;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->output_pkts_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->service_type;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->service_type_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&a->charge;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[11] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->charge_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->account_no;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)&a->free_min;
  sqlstm.sqhstl[13] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[13] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[13] = (         void  *)&a_ind->free_min_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)&a->no_of_units;
  sqlstm.sqhstl[14] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )sizeof(struct session_t);
  sqlstm.sqindv[14] = (         void  *)&a_ind->no_of_units_ind;
  sqlstm.sqinds[14] = (         int  )sizeof(struct session_ind);
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].session_id,
				  ((a_ind[i].session_id_ind < 0) ? "UNDEF":a[i].session_id));
			strcpy(a[i].user_id,
				  ((a_ind[i].user_id_ind < 0) ? "UNDEF":a[i].user_id));
			strcpy(a[i].ip_login,
				  ((a_ind[i].ip_login_ind < 0) ? "UNDEF":a[i].ip_login));
			strcpy(a[i].start_time,
				  ((a_ind[i].start_time_ind < 0) ? "UNDEF":a[i].start_time));
			strcpy(a[i].end_time,
				  ((a_ind[i].end_time_ind < 0) ? "UNDEF":a[i].end_time));
			strcpy(a[i].service_type,
				  ((a_ind[i].service_type_ind < 0) ? "UNDEF":a[i].service_type));
			a[i].time_duration = (a_ind[i].time_duration_ind < 0) ? 0.0 : a[i].time_duration;
			a[i].bytes_in = (a_ind[i].bytes_in_ind < 0) ? 0.0 : a[i].bytes_in;
			a[i].bytes_out = (a_ind[i].bytes_out_ind < 0) ? 0.0 : a[i].bytes_out;
			a[i].input_pkts = (a_ind[i].input_pkts_ind < 0) ? 0.0 : a[i].input_pkts;
			a[i].output_pkts = (a_ind[i].output_pkts_ind < 0) ? 0.0 : a[i].output_pkts ;
			a[i].charge = (a_ind[i].charge_ind < 0) ? 0.0 : a[i].charge ;
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no;
			a[i].free_min = (a_ind[i].free_min_ind < 0) ? 0.0 : a[i].free_min ;
			a[i].no_of_units = (a_ind[i].no_of_units_ind < 0) ? 0 : a[i].no_of_units;
			

			sd.session_id		= a[i].session_id;
			sd.user_id			= a[i].user_id;					
			sd.ip_login			= a[i].ip_login;	
			sd.time_duration	= a[i].time_duration;						
			sd.start_time		= a[i].start_time;						
			sd.end_time			= a[i].end_time;	
			sd.bytes_in			= a[i].bytes_in;					
			sd.bytes_out		= a[i].bytes_out;		
			sd.input_pkts		= a[i].input_pkts;		
			sd.output_pkts		= a[i].output_pkts; 
			sd.service_type		= a[i].service_type;
			sd.charge			= a[i].charge;
			sd.account_no		= a[i].account_no;
			sd.free_min			= a[i].free_min;
			sd.no_of_units		= a[i].no_of_units;	
		
			if(set_current(sd.account_no))
				current->call.summarize_sessions(&sd);
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_session; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )319;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  sessions records read.\n\n",rows_before);
}

//-- gric sessions
void connections::db_read_gric_sessions()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct gric_session_t
	{
		char	client_code[BUF_LEN];
		int		account_no;
		char	service_type[BUF_LEN];
		char	record_type[BUF_LEN];
		char	gmt_start_date[BUF_LEN];		
		char	gmt_start_time[BUF_LEN];		
		char	local_start_date[BUF_LEN];		
		char	local_start_time[BUF_LEN];		
		char	user_id[BUF_LEN];		
		char	service_provider[BUF_LEN];		
		char	time_unit[BUF_LEN];
		double	time_duration;				
		char	region_name[BUF_LEN];
		double	charge;
		float	no_of_units;
		char	rated_date[BUF_LEN];		
		int		file_id;
		char	session_id[BUF_LEN];				
		char	nas_ip_login[BUF_LEN];					
		char	local_country[BUF_LEN];					
	} *a;

	struct gric_session_ind
	{
		short	client_code_ind;
		short	account_no_ind;
		short	service_type_ind;
		short	record_type_ind;
		short	gmt_start_date_ind;		
		short	gmt_start_time_ind;		
		short	local_start_date_ind;		
		short	local_start_time_ind;		
		short	user_id_ind;		
		short	service_provider_ind;		
		short	time_unit_ind;
		short	time_duration_ind;				
		short	region_name_ind;
		short	charge_ind;
		short	no_of_units_ind;
		short	rated_date_ind;		
		short	file_id_ind;
		short	session_id_ind;				
		short	nas_ip_login_ind;					
		short	local_country_ind;					
	}a_ind[SESSION_FETCH_SIZE];

	char t_start_date[20], t_end_date[20];
	char t_session_date[20];
	int t_start_ac, t_end_ac;
	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
	strcpy(t_session_date, session_date.c_str());
	t_start_ac = start_ac_no;
	t_end_ac = end_ac_no;
	gric_session_data gsd;

	rows_to_fetch = SESSION_FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = SESSION_FETCH_SIZE; 

	if((a = new gric_session_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for GRIC session fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_gric_session CURSOR FOR 
	SELECT	CLIENT_CODE,
			ACCOUNT_NO, 
			SERVICE_TYPE, 	   
			RECORD_TYPE, 
			GMT_DATE,		
			GMT_TIME,		
			LOCAL_DATE,		
			LOCAL_TIME,		
			USER_ID,		
			SERVICE_PROVIDER,		
			TIME_UNIT,
			SESSION_TIME,				
			REGION_NAME,
			CHARGE,
			NO_OF_UNITS,
			RATED_DATE,		
			FILE_ID,
			SESSION_ID,				
			NAS_IP_LOGIN,					
			LOCAL_COUNTRY
	FROM	GRIC_RATED_SESSIONS
	WHERE	TRUNC(RATED_DATE) BETWEEN TO_DATE(:t_start_date,'YYYYMMDD') AND TO_DATE(:t_end_date,'YYYYMMDD'); */ 

			
    /* EXEC SQL AT ISP  OPEN c_gric_session; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0010;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )337;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_end_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_gric_session INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )363;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->service_type;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->service_type_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->record_type;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->record_type_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->gmt_start_date;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->gmt_start_date_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->gmt_start_time;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->gmt_start_time_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->local_start_date;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->local_start_date_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->local_start_time;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->local_start_time_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->user_id;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->user_id_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->service_provider;
  sqlstm.sqhstl[9] = (unsigned int  )50;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->service_provider_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->time_unit;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->time_unit_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&a->time_duration;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->time_duration_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)a->region_name;
  sqlstm.sqhstl[12] = (unsigned int  )50;
  sqlstm.sqhsts[12] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->region_name_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)&a->charge;
  sqlstm.sqhstl[13] = (unsigned int  )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[13] = (         void  *)&a_ind->charge_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)&a->no_of_units;
  sqlstm.sqhstl[14] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[14] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[14] = (         void  *)&a_ind->no_of_units_ind;
  sqlstm.sqinds[14] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (         void  *)a->rated_date;
  sqlstm.sqhstl[15] = (unsigned int  )50;
  sqlstm.sqhsts[15] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[15] = (         void  *)&a_ind->rated_date_ind;
  sqlstm.sqinds[15] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[15] = (unsigned int  )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (         void  *)&a->file_id;
  sqlstm.sqhstl[16] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[16] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[16] = (         void  *)&a_ind->file_id_ind;
  sqlstm.sqinds[16] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[16] = (unsigned int  )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (         void  *)a->session_id;
  sqlstm.sqhstl[17] = (unsigned int  )50;
  sqlstm.sqhsts[17] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[17] = (         void  *)&a_ind->session_id_ind;
  sqlstm.sqinds[17] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[17] = (unsigned int  )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (         void  *)a->nas_ip_login;
  sqlstm.sqhstl[18] = (unsigned int  )50;
  sqlstm.sqhsts[18] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[18] = (         void  *)&a_ind->nas_ip_login_ind;
  sqlstm.sqinds[18] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[18] = (unsigned int  )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (         void  *)a->local_country;
  sqlstm.sqhstl[19] = (unsigned int  )50;
  sqlstm.sqhsts[19] = (         int  )sizeof(struct gric_session_t);
  sqlstm.sqindv[19] = (         void  *)&a_ind->local_country_ind;
  sqlstm.sqinds[19] = (         int  )sizeof(struct gric_session_ind);
  sqlstm.sqharm[19] = (unsigned int  )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//start - handling null fetches

			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0 : a[i].account_no;
			strcpy(a[i].service_type,
				  ((a_ind[i].service_type_ind < 0) ? "UNDEF":a[i].service_type));
			strcpy(a[i].record_type,
				  ((a_ind[i].record_type_ind < 0) ? "UNDEF":a[i].record_type));
			strcpy(a[i].gmt_start_date,
				  ((a_ind[i].gmt_start_date_ind < 0) ? "UNDEF":a[i].gmt_start_date));
			strcpy(a[i].gmt_start_time,
				  ((a_ind[i].gmt_start_time_ind < 0) ? "UNDEF":a[i].gmt_start_time));
			strcpy(a[i].local_start_date,
				  ((a_ind[i].local_start_date_ind < 0) ? "UNDEF":a[i].local_start_date));
			strcpy(a[i].local_start_time,
				  ((a_ind[i].local_start_time_ind < 0) ? "UNDEF":a[i].local_start_time));
			strcpy(a[i].user_id,
				  ((a_ind[i].user_id_ind < 0) ? "UNDEF":a[i].user_id));
			strcpy(a[i].service_provider,
				  ((a_ind[i].service_provider_ind < 0) ? "UNDEF":a[i].service_provider));
			strcpy(a[i].time_unit,
				  ((a_ind[i].time_unit_ind < 0) ? "UNDEF":a[i].time_unit));
			a[i].time_duration = (a_ind[i].time_duration_ind < 0) ? 0 : a[i].time_duration;
			strcpy(a[i].time_unit,
				  ((a_ind[i].time_unit_ind < 0) ? "UNDEF":a[i].time_unit));
			strcpy(a[i].region_name,
				  ((a_ind[i].region_name_ind < 0) ? "UNDEF":a[i].region_name));
			a[i].charge = (a_ind[i].charge_ind < 0) ? 0.0 : a[i].charge ;
			a[i].no_of_units = (a_ind[i].no_of_units_ind < 0) ? 0 : a[i].no_of_units;
			a[i].file_id = (a_ind[i].file_id_ind < 0) ? 0 : a[i].file_id;
			strcpy(a[i].session_id,
				  ((a_ind[i].session_id_ind < 0) ? "UNDEF":a[i].session_id));
			strcpy(a[i].nas_ip_login,
				  ((a_ind[i].nas_ip_login_ind < 0) ? "UNDEF":a[i].nas_ip_login));
			strcpy(a[i].local_country,
				  ((a_ind[i].local_country_ind < 0) ? "UNDEF":a[i].local_country));
			// stop - handling null fetches


			gsd.client_code			=	a[i].client_code;
			gsd.account_no			=	a[i].account_no;
			gsd.service_type		=	a[i].service_type;
			gsd.record_type			=	a[i].record_type;
			gsd.gmt_start_date		=	a[i].gmt_start_date;
			gsd.gmt_start_time		=	a[i].gmt_start_time;
			gsd.local_start_date	=	a[i].local_start_date;
			gsd.local_start_time	=	a[i].local_start_time;
			gsd.user_id				=	a[i].user_id;
			gsd.service_provider	=	a[i].service_provider;
			gsd.time_unit			=	a[i].time_unit;
			gsd.time_duration		=	a[i].time_duration;
			gsd.region_name			=	a[i].region_name;
			gsd.charge				=	a[i].charge;
			gsd.no_of_units			=	a[i].no_of_units;
			gsd.rated_date			=	a[i].rated_date;
			gsd.file_id				=	a[i].file_id;
			gsd.session_id			=	a[i].session_id;
			gsd.nas_ip_login		=	a[i].nas_ip_login;
			gsd.local_country		=	a[i].local_country;

			if( set_current(gsd.account_no) )
			{
				current->call.summarize_gric_sessions(&gsd);
			}
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_gric_session; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )461;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  GRIC sessions records read.\n\n",rows_before);
}

//-- connections
void connections::db_read_connections()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_t
	{
		int		account_no;
		char	package_code[6];		// 6 instead of BUF_LEN // varchar2(5)
		char	current_status_date[BUF_LEN];
		char	tax_group_id[10];
		char	corporate_code[10];
		char	client_code[10];		// varchar2(8)
		char	vat_no[BUF_LEN];		//	varchar2(20)
		char	connection_status[BUF_LEN];
	} *a;

	struct connection_ind
	{ 
  		short	account_no_ind;
		short	package_code_ind;
		short	current_status_date_ind;
		short	tax_group_id_ind;
		short	corporate_code_ind;
		short	client_code_ind;
		short	vat_no_ind;
		short	connection_status_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	char ub_start_date[15];
	char ub_end_date[15];

/* EXEC SQL END DECLARE SECTION; */ 


/* EXEC ORACLE OPTION (char_map=string) ; */ 


	int i;
	strcpy(ub_start_date, start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	debug("ub_end_date :");
	debug(ub_end_date);
	cout << endl;
	connection_detail cd;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connection fetch"<<endl;
		exit(0);
	}
	    
	/* EXEC SQL 
	AT ISP 
	DECLARE  c_connection CURSOR FOR 
	SELECT	ACCOUNT_NO,				
			PACKAGE_CODE,		
			CURRENT_STATUS_DATE,					
			TAX_GROUP_ID,				
			CORPORATE_CODE,
			CLIENT_CODE,
			VAT_NO,
			CONNECTION_STATUS
	FROM	MIRRORED_BILL_CONNECTIONS
	WHERE	TRUNC(COMMENCEMENT_DATE) <= to_date(:ub_end_date,'YYYYMMDD')
	AND 
	(	
		CONNECTION_STATUS ='CONNT' OR CONNECTION_STATUS ='TDISC' OR 
		(
			(
				TRUNC(CURRENT_STATUS_DATE) BETWEEN 
				to_date(:ub_start_date,'YYYYMMDD') 
				AND 
				to_date(:ub_end_date,'YYYYMMDD')
			)
			AND
			( CONNECTION_STATUS ='PDISC' )
		)
	)
	AND	TRUNC(BILL_PERIOD_START) = to_date(:ub_start_date,'YYYYMMDD'); */ 
 
           
    /* EXEC SQL AT ISP  OPEN c_connection; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0011;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )479;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)ub_end_date;
    sqlstm.sqhstl[0] = (unsigned int  )15;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)ub_start_date;
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)ub_end_date;
    sqlstm.sqhstl[2] = (unsigned int  )15;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (         void  *)ub_start_date;
    sqlstm.sqhstl[3] = (unsigned int  )15;
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         void  *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned int  )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_connection INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )513;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->package_code;
  sqlstm.sqhstl[1] = (unsigned int  )6;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->package_code_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->current_status_date;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->current_status_date_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->tax_group_id;
  sqlstm.sqhstl[3] = (unsigned int  )10;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->tax_group_id_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->corporate_code;
  sqlstm.sqhstl[4] = (unsigned int  )10;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->corporate_code_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->client_code;
  sqlstm.sqhstl[5] = (unsigned int  )10;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->vat_no;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->vat_no_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->connection_status;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->connection_status_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0 : a[i].account_no ;
			strcpy(a[i].package_code,
				  ((a_ind[i].package_code_ind < 0) ? "UNDEF":a[i].package_code));
			strcpy(a[i].corporate_code,
				  ((a_ind[i].corporate_code_ind < 0) ? "UNDEF":a[i].corporate_code));
			strcpy(a[i].current_status_date,
				  ((a_ind[i].current_status_date_ind < 0) ? "20501225":a[i].current_status_date)); // 20501225 a far away date put for null entries
			strcpy(a[i].tax_group_id,
				  ((a_ind[i].tax_group_id_ind < 0) ? "UNDEF":a[i].tax_group_id));
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].vat_no,
				  ((a_ind[i].vat_no_ind < 0) ? "UNDEF":a[i].vat_no));
			strcpy(a[i].connection_status,
				  ((a_ind[i].connection_status_ind < 0) ? "UNDEF":a[i].connection_status));


			int posi = strcspn( a[i].client_code, " " );
			a[i].client_code[posi] = '\0';

			//assining values fetched from db to the connection_detail class
			cd.account_no		= a[i].account_no;					
			cd.package_code		= a[i].package_code;

			// cahnged on 16-09-2002
			a[i].current_status_date[8] = '\0';
			cd.current_status_date.set_date(a[i].current_status_date);	
			//cd.disconnected_date= a[i].disconnected_date;	
			// end - 16-09-2002
								
			cd.tax_group_id			= a[i].tax_group_id;						
			cd.corporate_code		= a[i].corporate_code;
			cd.client_code			= a[i].client_code;	
			cd.vat_no				= a[i].vat_no;	
			cd.connection_status	= a[i].connection_status;	
			

			CLIENTS_DEF::iterator i_current = gsm_connections->clients_map.find(a[i].client_code);
			
			if(i_current != gsm_connections->clients_map.end())
			{
				//cout <<"Client code matches >>>>>>>>>>>>>>>" << endl;

				if ( strcmp(gsm_bill_cycle->bill_cycle_code.c_str(), (*i_current).second.c_str())==0 )
				{
					//cout <<"Bill run code matches >>>>>>>>>>>>>>>" << endl;
					insert(a[i].account_no, cd);
					//print_detail();
				}
				else
				{
					//cout <<"Bill run code do not match >>>>>>>>>>>>>>>" << endl;
				}
			}
			else
			{
				//cout <<"Client code does not match >>>>>>>>>>>>>>>" << endl;
			}
			
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_connection; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )563;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  connection records read.\n\n",rows_before);
} 


//-- clients
void connections::db_read_clients()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct client_t
	{
		char	br_code[10];			// varchar2(5)
		char	client_code[10];		// varchar2(8)
	} *a;

	struct client_ind
	{ 
  		short	br_code_ind;
		short	client_code_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	char	t_start_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date, start_date.c_str());
	
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new client_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for client fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_client CURSOR FOR
	SELECT	BR_CODE,
			CLIENT_CODE		
	FROM	MIRRORED_BILL_CLIENTS
	WHERE	TRUNC(BILL_PERIOD_START) = to_date(:t_start_date,'YYYYMMDD'); */ 
 
	
       
    /* EXEC SQL AT ISP  OPEN c_client; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0012;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )581;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_client INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )603;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->br_code;
  sqlstm.sqhstl[0] = (unsigned int  )10;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct client_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->br_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct client_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->client_code;
  sqlstm.sqhstl[1] = (unsigned int  )10;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct client_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct client_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].br_code,
				  ((a_ind[i].br_code_ind < 0) ? "UNDEF":a[i].br_code));
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));

			int posi = strcspn( a[i].client_code, " " );
			a[i].client_code[posi] = '\0';

			int position = strcspn( a[i].br_code, " " );
			a[i].br_code[position] = '\0';

			

			clients_map[a[i].client_code] = a[i].br_code;
			
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_client; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )629;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  clients records read.\n\n",rows_before);
} 

//-- bill_master
void connections::db_read_bill_master()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct bill_master_t
	{
			char	client_code[BUF_LEN];				
			int		account_no;		
			char	bill_no[BUF_LEN];					
			char	due_date[BUF_LEN];				
			char	bill_date[BUF_LEN];		
			char	bill_period_start[BUF_LEN];				
			char	bill_period_end[BUF_LEN];	
			float	balance_bf;		
			float	bill_amount;		
			float	balance_cf;		
			char	bill_run_code[BUF_LEN];
			float	bill_payments;
			int		run_no;
			char	printed[BUF_LEN];
	} *a;

	struct bill_master_ind
	{ 
  		short	client_code_ind;
		short	account_no_ind;
		short	bill_no_ind;
		short	due_date_ind;
		short	bill_date_ind;
		short	bill_period_start_ind;
		short	bill_period_end_ind;
		short	balance_bf_ind;
		short	bill_amount_ind;
		short	balance_cf_ind;
		short	bill_run_code_ind;
		short	bill_payments_ind;
		short	run_no_ind;
		short	printed_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	char  ub_start_date[10];		// date 			not null
	char  ub_end_date[10];			// date				not null
	

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(ub_start_date, start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	bill_master bm;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new bill_master_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_master fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_bill_master CURSOR FOR 
	SELECT	CLIENT_CODE,				
			ACCOUNT_NO,		
			BILL_NO,					
			DUE_DATE,				
			BILL_DATE,		
			BILL_PERIOD_START,				
			BILL_PERIOD_END,	
			BALANCE_BF,		
			BILL_AMOUNT,		
			BALANCE_CF,		
			BILL_RUN_CODE,
			BILL_PAYMENTS,
			RUN_NO,
			PRINTED
	FROM	BILL_MASTER
	WHERE		BILL_PERIOD_START = to_date(:ub_start_date,'YYYYMMDD') 
	AND		BILL_PERIOD_END = to_date(:ub_end_date,'YYYYMMDD') ; */ 

	
       
    /* EXEC SQL AT ISP  OPEN c_bill_master; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0013;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )647;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)ub_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )10;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)ub_end_date;
    sqlstm.sqhstl[1] = (unsigned int  )10;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_bill_master INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )673;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->bill_no;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->bill_no_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->due_date;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->due_date_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->bill_date;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->bill_date_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->bill_period_start;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->bill_period_start_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->bill_period_end;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->bill_period_end_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->balance_bf;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->balance_bf_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&a->bill_amount;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[8] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->bill_amount_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&a->balance_cf;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->balance_cf_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->bill_run_code;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->bill_run_code_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&a->bill_payments;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[11] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->bill_payments_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->run_no;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->run_no_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)a->printed;
  sqlstm.sqhstl[13] = (unsigned int  )50;
  sqlstm.sqhsts[13] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[13] = (         void  *)&a_ind->printed_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no ;
			strcpy(a[i].bill_no,
				  ((a_ind[i].bill_no_ind < 0) ? "UNDEF":a[i].bill_no));
			strcpy(a[i].due_date,
				  ((a_ind[i].due_date_ind < 0) ? "UNDEF":a[i].due_date));
			strcpy(a[i].bill_date,
				  ((a_ind[i].bill_date_ind < 0) ? "UNDEF":a[i].bill_date));
			strcpy(a[i].bill_period_start,
				  ((a_ind[i].bill_period_start_ind < 0) ? "UNDEF":a[i].bill_period_start));
			strcpy(a[i].bill_period_end,
				  ((a_ind[i].bill_period_end_ind < 0) ? "UNDEF":a[i].bill_period_end));
			a[i].balance_bf = (a_ind[i].balance_bf_ind < 0) ? 0.0 : a[i].balance_bf;
			a[i].bill_amount = (a_ind[i].bill_amount_ind < 0) ? 0.0 : a[i].bill_amount;
			a[i].balance_cf = (a_ind[i].balance_cf_ind < 0) ? 0.0 : a[i].balance_cf ;
			strcpy(a[i].bill_run_code,
				  ((a_ind[i].bill_run_code_ind < 0) ? "UNDEF":a[i].bill_run_code));
			a[i].bill_payments = (a_ind[i].bill_payments_ind < 0) ? 0.0 : a[i].bill_payments;
			a[i].run_no = (a_ind[i].run_no_ind < 0) ? 0.0 : a[i].run_no;
			strcpy(a[i].printed,
				  ((a_ind[i].printed_ind < 0) ? "UNDEF":a[i].printed));
			

			
			if(set_current(a[i].account_no))
			{
				current->charge.payments += a[i].bill_payments; // payments during period
				current->charge.brought_forward = a[i].balance_bf;	
				current->connection.invoice_no = a[i].bill_no;
				current->charge.open_bill_found = 1;
			}
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_bill_master; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )747;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_master records read.\n\n",rows_before);
} 

  
//-- connection_services
void connection_services_multimap::db_read_connection_services()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_services_t
	{
			float	rental;				
			char	start_date[BUF_LEN];		
			char	end_date[BUF_LEN];					
			int		account_no;				
			char	client_code[BUF_LEN];		
			char	service_code[BUF_LEN];				
			char	user_username[BUF_LEN];		
			int		service_instance;		
			char	connection_status[BUF_LEN];		
			char	attribution[BUF_LEN];
			char	rate_group_id[BUF_LEN];
			char	rental_actv_date[BUF_LEN];
			float	service_quota;
	} *a;

	struct connection_services_ind
	{ 
  		short	rental_ind;
		short	start_date_ind;
		short	end_date_ind;
		short	account_no_ind;
		short	client_code_ind;
		short	service_code_ind;
		short	user_username_ind;
		short	service_instance_ind;
		short	connection_status_ind;
		short	attribution_ind;
		short	rate_group_id_ind;
		short	rental_actv_date_ind;
		short	service_quota_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	char t_start_date[20];
	char t_end_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	connection_services cs;

	strcpy(t_start_date,gsm_connections->start_date.c_str());
	strcpy(t_end_date, gsm_connections->end_date.c_str());

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_services_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connection_services fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_connection_services CURSOR FOR 
	SELECT	RENTAL,				
			START_DATE,		
			END_DATE,					
			ACCOUNT_NO,				
			CLIENT_CODE,		
			SERVICE_CODE,				
			USER_USERNAME,		
			SERVICE_INSTANCE,		
			CONNECTION_STATUS,		
			ATTRIBUTION,
			RATE_GROUP_ID,
			RENTAL_ACTV_DATE,
			SERVICE_QUOTA
	FROM	MIRRORED_BILL_CONN_SERVICES
	WHERE	TRUNC(RENTAL_ACTV_DATE) <= to_date(:t_end_date,'YYYYMMDD')	
	AND	TRUNC(BILL_PERIOD_START) = to_date(:t_start_date,'YYYYMMDD'); */ 
 	// 15th Jan 2002
	
	
       
    /* EXEC SQL AT ISP  OPEN c_connection_services; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0014;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )765;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_end_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_start_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_connection_services INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )791;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->rental;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->rental_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->start_date;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->start_date_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->end_date;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->end_date_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->account_no;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->client_code;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->service_code;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->service_code_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->user_username;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->user_username_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->service_instance;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->service_instance_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->connection_status;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->connection_status_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->attribution;
  sqlstm.sqhstl[9] = (unsigned int  )50;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->attribution_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->rate_group_id;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->rate_group_id_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)a->rental_actv_date;
  sqlstm.sqhstl[11] = (unsigned int  )50;
  sqlstm.sqhsts[11] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->rental_actv_date_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->service_quota;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->service_quota_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			a[i].rental = (a_ind[i].rental_ind < 0) ? 0.0 : a[i].rental ;
			strcpy(a[i].start_date,
				  ((a_ind[i].start_date_ind < 0) ? "UNDEF":a[i].start_date));

/*			strcpy(a[i].end_date,
				  ((a_ind[i].end_date_ind < 0) ? "UNDEF":a[i].end_date));
*/
//Arjuna
			strcpy(a[i].end_date,
				  ((a_ind[i].end_date_ind < 0) ? "20501225":a[i].end_date));
//Arjuna
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no ;
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].service_code,
				  ((a_ind[i].service_code_ind < 0) ? "UNDEF":a[i].service_code));
			strcpy(a[i].user_username,
				  ((a_ind[i].user_username_ind < 0) ? "UNDEF":a[i].user_username));
			a[i].service_instance = (a_ind[i].service_instance_ind < 0) ? 0.0 : a[i].service_instance ;
			strcpy(a[i].connection_status,
				  ((a_ind[i].connection_status_ind < 0) ? "UNDEF":a[i].connection_status));
			strcpy(a[i].attribution,
				  ((a_ind[i].attribution_ind < 0) ? "UNDEF":a[i].attribution));
			strcpy(a[i].rate_group_id,
				  ((a_ind[i].rate_group_id_ind < 0) ? "UNDEF":a[i].rate_group_id));
			strcpy(a[i].rental_actv_date,
				  ((a_ind[i].rental_actv_date_ind < 0) ? "UNDEF":a[i].rental_actv_date));
			a[i].service_quota = (a_ind[i].service_quota_ind < 0) ? 0.0 : a[i].service_quota ;

			
			//assining values fetched from db to the connection_detail class
			cs.rental			= a[i].rental;				
			cs.start_date		= a[i].start_date;		
			cs.end_date			= a[i].end_date;					
			cs.account_no		= a[i].account_no;				
			cs.client_code		= a[i].client_code;		
			cs.service_code		= a[i].service_code;				
			cs.user_username	= a[i].user_username;		
			cs.service_instance	= a[i].service_instance;		
			cs.connection_status= a[i].connection_status;		
			cs.attribution		= a[i].attribution;
			cs.rate_group_id	= a[i].rate_group_id;
			cs.rental_actv_date	= a[i].rental_actv_date;
			cs.service_quota	= a[i].service_quota;

			/* Added by Arjuna Aryasinha 2003-NOV-10 */
			a[i].end_date[8] = '\0';
			cs.reng_end_date.set_date(a[i].end_date); 
			/* End of addition by Arjuna Aryasinha 2003-NOV-10 */

			gsm_connection_services->insert(cs.account_no, cs);

		}
	} 

	/* EXEC SQL AT ISP CLOSE c_connection_services; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )861;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  connection_services records read.\n\n",rows_before);
} 

//-- packages
void package_map::db_read_packages()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct packages_t
	{
			char	package_code[6];		// 6 instead of BUF_LEN				
			char	description[BUF_LEN];		
			float	rental;					
			char	free_applied_on[BUF_LEN];				
			int		free_in_bytes;		
			int		free_out_bytes;				
			int		free_minutes;	
			char	activated_on[BUF_LEN];		
			char	deactivated_on[BUF_LEN];
			char	package_type[BUF_LEN];
			int		free_units;				// number(10)		
	} *a;

	struct packages_ind
	{ 
  		short	package_code_ind;				
		short	description_ind;		
		short	rental_ind;					
		short	free_applied_on_ind;				
		short	free_in_bytes_ind;		
		short	free_out_bytes_ind;				
		short	free_minutes_ind;	
		short	activated_on_ind;		
		short	deactivated_on_ind;
		short	package_type_ind;
		short	free_units_ind;	
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	char	t_start_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,gsm_connections->start_date.c_str());
	
	int i;
	packages p;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new packages_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for packages fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_packages CURSOR FOR
	SELECT	PACKAGE_CODE,				
			DESCRIPTION,
			RENTAL,		
			FREE_APPLIED_ON,					
			FREE_IN_BYTES,				
			FREE_OUT_BYTES,		
			FREE_MINUTES,				
			ACTIVATED_ON,	
			DEACTIVATED_ON,
			PACKAGE_TYPE,
			FREE_UNITS			
	FROM	MIRRORED_BILL_PACKAGES
	WHERE PACKAGE_TYPE = 'O'
	AND	TRUNC(BILL_PERIOD_START) = to_date(:t_start_date,'YYYYMMDD'); */ 
 
	       
    /* EXEC SQL AT ISP  OPEN c_packages; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0015;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )879;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_packages INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )901;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->package_code;
  sqlstm.sqhstl[0] = (unsigned int  )6;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->package_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->description;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->description_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->rental;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->rental_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->free_applied_on;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->free_applied_on_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&a->free_in_bytes;
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->free_in_bytes_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&a->free_out_bytes;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->free_out_bytes_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&a->free_minutes;
  sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->free_minutes_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->activated_on;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->activated_on_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->deactivated_on;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->deactivated_on_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->package_type;
  sqlstm.sqhstl[9] = (unsigned int  )50;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->package_type_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)&a->free_units;
  sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->free_units_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			strcpy(a[i].package_code,
				  ((a_ind[i].package_code_ind < 0) ? "UNDEF":a[i].package_code));
			strcpy(a[i].description,
				  ((a_ind[i].description_ind < 0) ? "UNDEF":a[i].description));
			a[i].rental = (a_ind[i].rental_ind < 0) ? 0.0 : a[i].rental ;
			strcpy(a[i].free_applied_on,
				  ((a_ind[i].free_applied_on_ind < 0) ? "UNDEF":a[i].free_applied_on));
			a[i].free_in_bytes = (a_ind[i].free_in_bytes_ind < 0) ? 0.0 : a[i].free_in_bytes ;
			a[i].free_out_bytes = (a_ind[i].free_out_bytes_ind < 0) ? 0.0 : a[i].free_out_bytes ;
			a[i].free_minutes = (a_ind[i].free_minutes_ind < 0) ? 0.0 : a[i].free_minutes ;
			strcpy(a[i].activated_on,
				  ((a_ind[i].activated_on_ind < 0) ? "UNDEF":a[i].activated_on));
			strcpy(a[i].deactivated_on,
				  ((a_ind[i].deactivated_on_ind < 0) ? "UNDEF":a[i].deactivated_on));
			strcpy(a[i].package_type,
				  ((a_ind[i].package_type_ind < 0) ? "UNDEF":a[i].package_type));
			a[i].free_units = (a_ind[i].free_units_ind < 0) ? 0.0 : a[i].free_units ;
			
			//assining values fetched from db to the packages class
			p.package_code			= a[i].package_code;				
			p.description			= a[i].description;		
			p.rental				= a[i].rental;					
			p.free_applied_on		= a[i].free_applied_on;				
			p.free_in_bytes			= a[i].free_in_bytes;		
			p.free_out_bytes		= a[i].free_out_bytes;				
			p.free_minutes			= a[i].free_minutes;	
			p.activated_on			= a[i].activated_on;		
			p.deactivated_on		= a[i].deactivated_on;
			p.package_type			= a[i].package_type;
			p.free_units			= a[i].free_units;	
			
			
			gsm_packages->all_packages[p.package_code] = p;
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_packages; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )963;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  packages records read.\n\n",rows_before);
} 

// file:db_useage_summary


void connections::db_insert_bill_summary_items_raw()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	char	b_BILL_NO[15];			//	NUMBER(10)
	char	b_ITEM_CODE[20];		//	VARCHAR2(10)
	float	b_VALUE;				//	NUMBER(12,2)
	float	b_VALUE_VAT;			//  ???
	/* EXEC SQL END DECLARE SECTION; */ 


	// initalise account number & invoice number common for all items in bill summary

	strncpy(b_BILL_NO, (current->connection.invoice_no).c_str(),10);

	b_BILL_NO[10] = '\0';

	for(BILL_SUMMARY_DEF::iterator i=summary.begin(); i!=summary.end(); i++)
	{
		strcpy(b_ITEM_CODE, (*i).first.c_str());
		b_VALUE		= (*i).second.amount;
		b_VALUE_VAT = (*i).second.vat_amount;

		/* EXEC SQL 
		AT ISP 
		INSERT INTO BILL_SUMMARY_ITEMS_RAW (BILL_NO,
		  ITEM_CODE, AMOUNT, VAT_AMOUNT) VALUES (:b_BILL_NO, :b_ITEM_CODE, :b_VALUE, :b_VALUE_VAT); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_SUMMARY_ITEMS_RAW (BILL_NO,ITEM_CODE,AMOUN\
T,VAT_AMOUNT) values (:b0,:b1,:b2,:b3)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )981;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)b_BILL_NO;
  sqlstm.sqhstl[0] = (unsigned int  )15;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)b_ITEM_CODE;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&b_VALUE;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&b_VALUE_VAT;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	}
	
	//printf("bill_summary_items updated ");

}


// file:db_taxes

void taxes::db_read_tax_items()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct tax_s 
	{ 
		 char tax_type_id[6];	//	VARCHAR2(5)		// 6 instead of BUF_LEN
		 float tax_rate;				//	NUMBER(5,2)
		 float tax_slab;				//	NUMBER(14,2)
	} a, *tp; 
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC ORACLE OPTION (char_map=string) ; */ 


	int i;
	tax_items	ti;		
	tp = &a;
 
    /* EXEC SQL AT ISP DECLARE c_tax CURSOR FOR 
	SELECT	TAX_TYPE_ID, TAX_RATE, TAX_SLAB 
	FROM	TAX_ITEMS; */ 

       
    /* EXEC SQL AT ISP OPEN c_tax; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0017;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1015;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

    for (i=0; ;i++) 
    { 
        /* EXEC SQL AT ISP FETCH c_tax INTO :tp; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 10;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1033;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)tp->tax_type_id;
        sqlstm.sqhstl[0] = (unsigned int  )6;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)&tp->tax_rate;
        sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&tp->tax_slab;
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

		ti.tax_type_id	= tp->tax_type_id;
		ti.tax_slab		= tp->tax_slab;
		ti.tax_rate		= tp->tax_rate;

		gsm_taxes->tax_items_map[ti.tax_type_id] = ti;
	} 

    /* EXEC SQL AT ISP CLOSE c_tax; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1063;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    printf("\n %d  tax items loaded.\n\n",i);
}

void taxes::db_read_tax_group_items()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	struct tax_group_s 
	{ 
		 char tax_group_id[BUF_LEN];	//	VARCHAR2(5)		
		 char tax_type_id[6];			//	VARCHAR2(5)		//  6 instead of BUF_LEN
		 int  priority;					//  NUMBER(1)
	} a, *tp; 
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC ORACLE OPTION (char_map=string) ; */ 


	int i;
	tp = &a;
 
    /* EXEC SQL AT ISP DECLARE c_tax_group CURSOR FOR 
	SELECT	TAX_GROUP_ID, TAX_TYPE_ID, PRIORITY 
	FROM	TAX_GROUP_ITEMS; */ 

       
    /* EXEC SQL AT ISP OPEN c_tax_group; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0018;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1081;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 
 

    for (i=0; ;i++) 
    { 
        /* EXEC SQL AT ISP FETCH c_tax_group INTO :tp; */ 

{
        struct sqlexd sqlstm;
        sqlorat((void **)0, &sqlctx, &oraca);
        sqlstm.sqlvsn = 10;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1099;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)256;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (         void  *)tp->tax_group_id;
        sqlstm.sqhstl[0] = (unsigned int  )50;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         void  *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned int  )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (         void  *)tp->tax_type_id;
        sqlstm.sqhstl[1] = (unsigned int  )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         void  *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned int  )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (         void  *)&tp->priority;
        sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         void  *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned int  )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

		
		tax_key tk;
		tk.type = tp->tax_type_id;
		tk.group = tp->tax_group_id;
		tk.priority = tp->priority;

		TAX_ITEMS_DEF::iterator it=gsm_taxes->tax_items_map.find(tk.type);

	
		tk.slab = (*it).second.tax_slab;
	
		insert(tk, (*it).second.tax_rate);
	} 

    /* EXEC SQL AT ISP CLOSE c_tax_group; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1129;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
 
    printf("\n %d  tax_group_items loaded.\n\n",i);
}


//-- connection_discounts
void discounts::db_read_connection_discounts()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_discounts_t
	{
		char	client_code[BUF_LEN];	// varchar2(8)
		char	discount_type[6];		// 6 instead of BUF_LEN	// varchar2(5)
		int		account_no;				// number(10)
	} *a;

	struct connection_discounts_ind
	{ 
  		short	client_code_ind;
		short	discount_type_ind;
		short	account_no_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_discounts_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connection_discounts fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_connection_discounts CURSOR FOR 
	SELECT	CLIENT_CODE,
			DISCOUNT_TYPE,		
			ACCOUNT_NO
	FROM	CONNECTION_DISCOUNTS; */ 
 
	       
    /* EXEC SQL AT ISP  OPEN c_connection_discounts; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0019;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1147;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_connection_discounts INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1165;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_discounts_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_discounts_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->discount_type;
  sqlstm.sqhstl[1] = (unsigned int  )6;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_discounts_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->discount_type_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_discounts_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->account_no;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_discounts_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_discounts_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].discount_type,
				  ((a_ind[i].discount_type_ind < 0) ? "UNDEF":a[i].discount_type));
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no;
			
			
			//Inserting to connection_discount_map

			insert_connection_discount(a[i].account_no, a[i].discount_type);
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_connection_discounts; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1195;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  connection_discounts records read.\n\n",rows_before);
}  

//-- discounts::discount_types
void discounts::db_read_discount_types()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct discount_types_t
	{
		char	discount_type[6];		// 6 instead of BUF_LEN
		char	description[BUF_LEN];
	} *a;

	struct discount_types_ind
	{ 
  		short	discount_type_ind;
		short	description_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new discount_types_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for discount_types fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_discount_types CURSOR FOR 
	SELECT	DISCOUNT_TYPE,				
			DESCRIPTION		
	FROM	DISCOUNT_TYPES; */ 
 
	       
    /* EXEC SQL AT ISP  OPEN c_discount_types; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0020;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1213;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_discount_types INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1231;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->discount_type;
  sqlstm.sqhstl[0] = (unsigned int  )6;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct discount_types_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->discount_type_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct discount_types_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->description;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct discount_types_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->description_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct discount_types_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].discount_type,
				  ((a_ind[i].discount_type_ind < 0) ? "UNDEF":a[i].discount_type));
			strcpy(a[i].description,
				  ((a_ind[i].description_ind < 0) ? "UNDEF":a[i].description));

			discount_type_map[a[i].discount_type] = a[i].discount_type;

		}
	} 

	/* EXEC SQL AT ISP CLOSE c_discount_types; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1257;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  discount_types records read.\n\n",rows_before);
}  


//-- discount_rules
void discounts::db_read_discount_rules()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct discount_rules_t
	{
		char	discount_type[6];		// 6 instead of BUF_LEN
		int		rule_number;
		float	percentage;
		float	rate;
		char	content_or_duration[2];	// 2 instead of BUF_LEN
		char	rental_waived[2];		// 2 instead of BUF_LEN
		float	upper_limit;			// number(14,2)
		float	lower_limit;
		char	time_band_group[BUF_LEN];
		char	time_band_type[BUF_LEN];
		char	day_id[BUF_LEN];
	} *a;

	struct discount_rules_ind
	{ 
  		short	discount_type_ind;
		short	rule_number_ind;
		short	percentage_ind;
		short	rate_ind;
		short	content_or_duration_ind;
		short	rental_waived_ind;
		short	upper_limit_ind;
		short	lower_limit_ind;
		short	time_band_group_ind;
		short	time_band_type_ind;
		short	day_id_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	TimeBand tb;
	discount_rule dr;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new discount_rules_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for discount_rules fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_discount_rules CURSOR FOR 
	SELECT	DISCOUNT_TYPE,				
			RULE_NUMBER,		
			PERCENTAGE,
			RATE,
			CONTENT_OR_DURATION,
			RENTAL_WAIVED,
			UPPER_LIMIT,
			LOWER_LIMIT,
			TIME_BAND_GROUP,
			TIME_BAND_TYPE,
			DAY_ID					
	FROM	DISCOUNT_RULES; */ 
 
	       
    /* EXEC SQL AT ISP  OPEN c_discount_rules; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0021;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1275;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_discount_rules INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1293;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->discount_type;
  sqlstm.sqhstl[0] = (unsigned int  )6;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->discount_type_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->rule_number;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->rule_number_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->percentage;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->percentage_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->rate;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->rate_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->content_or_duration;
  sqlstm.sqhstl[4] = (unsigned int  )2;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->content_or_duration_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->rental_waived;
  sqlstm.sqhstl[5] = (unsigned int  )2;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->rental_waived_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&a->upper_limit;
  sqlstm.sqhstl[6] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[6] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->upper_limit_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->lower_limit;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->lower_limit_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->time_band_group;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->time_band_group_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->time_band_type;
  sqlstm.sqhstl[9] = (unsigned int  )50;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->time_band_type_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->day_id;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct discount_rules_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->day_id_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct discount_rules_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].discount_type,
				  ((a_ind[i].discount_type_ind < 0) ? "UNDEF":a[i].discount_type));
			strcpy(a[i].rental_waived,
				  ((a_ind[i].rental_waived_ind < 0) ? "UNDEF":a[i].rental_waived));
			strcpy(a[i].content_or_duration,
				  ((a_ind[i].content_or_duration_ind < 0) ? "UNDEF":a[i].content_or_duration));
			strcpy(a[i].time_band_group,
				  ((a_ind[i].time_band_group_ind < 0) ? "UNDEF":a[i].time_band_group));
			strcpy(a[i].time_band_type,
				  ((a_ind[i].time_band_type_ind < 0) ? "UNDEF":a[i].time_band_type));
			strcpy(a[i].day_id,
				  ((a_ind[i].day_id_ind < 0) ? "UNDEF":a[i].day_id));
			a[i].rule_number = (a_ind[i].rule_number_ind < 0) ? 0.0 : a[i].rule_number;
			a[i].percentage = (a_ind[i].percentage_ind < 0) ? 0.0 : a[i].percentage;
			a[i].rate = (a_ind[i].rate_ind < 0) ? 0.0 : a[i].rate;
			a[i].upper_limit = (a_ind[i].upper_limit_ind < 0) ? 0.0 : a[i].upper_limit;
			a[i].lower_limit = (a_ind[i].lower_limit_ind < 0) ? 0.0 : a[i].lower_limit;

			//assining values fetched from db to the discount_rule class
			dr.discount_type	= a[i].discount_type;				
			dr.rental_waived	= a[i].rental_waived;		
			dr.rule_number		= a[i].rule_number;					
			dr.percentage		= a[i].percentage;
			dr.rate				= a[i].rate;
			dr.content_or_duration		= a[i].content_or_duration;
			dr.upper_limit		= a[i].upper_limit;
			dr.lower_limit		= a[i].lower_limit;	
			
			//assining values fetched from db to the TimeBand class
			tb.time_band_group	= a[i].time_band_group; 
			tb.time_band_type	= a[i].time_band_type;	
			tb.day_id			= a[i].day_id;
			
			fprintf(logfile, "%s%s", "\ntime_band_group : " , dr.time_band.time_band_group.c_str() );
			fprintf(logfile, "%s%s", "\ntime_band_type : " , dr.time_band.time_band_type.c_str() );
			fprintf(logfile, "%s%s", "\nday_id : " , dr.time_band.day_id.c_str() );
			

			//  rule_type clasification
			/*
			23-07-2000
			Table - discount_rules
			hierarchy day_id > time_band_group > time_band_type
			If content_or_duration 'M'							- rule_type = 1
			If time_band_type, time_band_group, day_id NOT NULL	- rule_type = 2
			If time_band_group, time_band_type NOT NULL	others NULL		- rule_type = 3
			If day_id NOT NULL others NULL						- rule_type = 4
			*/
			if (dr.content_or_duration == "M")
			{
				dr.rule_type = 1;
				fprintf(logfile, "%s", "\nrule_type = 1" );
			}
			else if (a_ind[i].time_band_type_ind == 0) 
				{
					dr.rule_type = 2;
					fprintf(logfile, "%s", "\nrule_type = 2" );
				}
				else if (a_ind[i].time_band_group_ind == 0)
					{
						dr.rule_type = 3;
						tb.time_band_type	= "WILD_CARD";
						fprintf(logfile, "%s","\nrule_type = 3" );
					}
					else if (a_ind[i].time_band_group_ind < 0)
						{
							dr.rule_type = 4;
							tb.time_band_group	= "WILD_CARD"; 
							tb.time_band_type	= "WILD_CARD";
							fprintf(logfile, "%s", "\nrule_type = 4" );
						}

			dr.time_band		= tb;

			insert(a[i].discount_type, dr);
			

			fprintf(logfile, "%s%d", "\nRule multimap size :" , discount_rule_multimap.size() );
			
			//cout <<"Discount type at rule : " << a[i].discount_type << endl;
		}
	} 

	fprintf(logfile, "%s%d", "\nRule multimap size :" , discount_rule_multimap.size() );

	/* EXEC SQL AT ISP CLOSE c_discount_rules; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1355;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  discount_rules records read.\n\n",rows_before);
}  

//-- bill_account_adjustments
void connections::db_read_bill_account_adjustments()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_t
	{
		int		account_no;
		char	adjustment_type[BUF_LEN];		
		float	amount_adjusted;
		char	disapproved_reason[BUF_LEN];
		char	processed[2];				// 2 instead of BUF_LEN
		int		reference_no;				// varchar2(10)
	} *a;

	struct connection_ind
	{ 
  		short	account_no_ind;
		short	adjustment_type_ind;
		short	amount_adjusted_ind;
		short	disapproved_reason_ind;
		short	processed_ind;
		short	reference_no_ind;
	}a_ind[FETCH_SIZE];

	int t_start_ac, t_end_ac;
	int rows_to_fetch, rows_before, rows_this_time;
	char t_start_date[20];
	char t_end_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	t_start_ac = start_ac_no;
	t_end_ac = end_ac_no;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
	
	
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connection fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_bill_account_adjustments CURSOR FOR 
	SELECT	ACCOUNT_NO,				
			ADJUSTMENT_TYPE,		
			AMOUNT_ADJUSTED,					
			DISAPPROVED_REASON,				
			PROCESSED,
			REFERENCE_NO
	FROM	BILL_ACCOUNT_ADJUSTMENTS 
	WHERE TRUNC(APPROVED_DATE) >= to_date(:t_start_date,'YYYYMMDD') AND TRUNC(APPROVED_DATE) <= to_date(:t_end_date,'YYYYMMDD'); */ 

       
    /* EXEC SQL AT ISP  OPEN c_bill_account_adjustments; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0022;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1373;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_end_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_bill_account_adjustments INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1399;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->adjustment_type;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->adjustment_type_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->amount_adjusted;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->amount_adjusted_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->disapproved_reason;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->disapproved_reason_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->processed;
  sqlstm.sqhstl[4] = (unsigned int  )2;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->processed_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&a->reference_no;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->reference_no_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].adjustment_type,
				  ((a_ind[i].adjustment_type_ind < 0) ? "UNDEF":a[i].adjustment_type));
			strcpy(a[i].disapproved_reason,
				  ((a_ind[i].disapproved_reason_ind < 0) ? "UNDEF":a[i].disapproved_reason));
			strcpy(a[i].processed,
				  ((a_ind[i].processed_ind < 0) ? "UNDEF":a[i].processed));
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no;
			a[i].amount_adjusted = (a_ind[i].amount_adjusted_ind < 0) ? 0.0 : a[i].amount_adjusted;
			a[i].reference_no = (a_ind[i].reference_no_ind < 0) ? 0 : a[i].reference_no;
			
			adjustment_item ai;
			ai.adjustment_type = a[i].adjustment_type;
			ai.amount_adjusted = a[i].amount_adjusted;
			ai.reference_no	   = a[i].reference_no;

			if(set_current(a[i].account_no))
			{
				
				gsm_connections->adjustment_item_multimap.insert(pair<int, adjustment_item>(a[i].account_no, ai));
				
				BILL_ADJUSTMENT_TYPE_DEF::iterator i = current->charge.adjustment_items_value_map.find(ai.adjustment_type);
				if ( i == current->charge.adjustment_items_value_map.end() )
				{
					cout << "Undefined adjustment type in BILL_ACCOUNT_ADJUSTMENTS table" << endl;
					cout << "Account no: " << current->connection.account_no << endl;
					cout << "Exiting with Error" << endl;
					exit(0);
				}
				else
				{
					(*i).second.value += ai.amount_adjusted;
					
					if ( (*i).second.tax == true )
					{
						current->charge.taxable_adjustment += ai.amount_adjusted;
					}
					else
					{
						current->charge.untaxable_adjustment += ai.amount_adjusted;
					}
				}
			}
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_bill_account_adjustments; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1441;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_account_adjustments records read.\n\n",rows_before);
} 


//-- bill_account_adjustments update
void connections::db_update_bill_account_adjustments()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	int t_start_ac, t_end_ac;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	t_start_ac = start_ac_no;
	t_end_ac = end_ac_no;

	/* EXEC SQL 
	AT ISP 
	UPDATE	bill_account_adjustments				
			SET PROCESSED = 'Y'
	WHERE	ACCOUNT_NO >= :t_start_ac AND  ACCOUNT_NO<= :t_end_ac 
	AND		PROCESSED = 'N'; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update bill_account_adjustments  set PROCESSED='Y' where ((A\
CCOUNT_NO>=:b0 and ACCOUNT_NO<=:b1) and PROCESSED='N')";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1459;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&t_start_ac;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&t_end_ac;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	printf("bill_account_adjustments records updated");
} 

//-- bill_account_adjustments update for one connection
void connections::db_update_bill_account_adjustments_for_one_connection(int account_no)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	
	int b_account_no;
	char b_bill_no[15];
	
	/* EXEC SQL END DECLARE SECTION; */ 


	b_account_no = account_no;
	strcpy(b_bill_no, current->connection.invoice_no.c_str());

	fprintf(logfile, "%s%d",  "\nb_account_no :",b_account_no );

	
	/* EXEC SQL 
	AT ISP 
	UPDATE	bill_account_adjustments				
			SET PROCESSED = 'Y',
			APPLIED_TO_BILL_NO = :b_bill_no
	WHERE	ACCOUNT_NO = :b_account_no 
	AND		PROCESSED = 'N'; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update bill_account_adjustments  set PROCESSED='Y',APPLIED_T\
O_BILL_NO=:b0 where (ACCOUNT_NO=:b1 and PROCESSED='N')";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1485;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)b_bill_no;
 sqlstm.sqhstl[0] = (unsigned int  )15;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&b_account_no;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	//printf("bill_account_adjustments records updated for one connection");
	fprintf(logfile, "%s",  "\nbill_account_adjustments records updated for one connection" );

} 

void connections::db_insert_bill_master_open()
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char  b_bill_no[20];		// varcahr2(10)		not null,
	char  b_client_code[50];	// varchar2(8)		not null,
 	int   b_account_no;			// number(10)		not null,
	char  b_start_date[10];		// date 			not null,
	char  b_end_date[10];		// date				not null,
	float b_balance_bf;			// number(14,2)		not null,
	char  b_br_code[50];		// varchar2(2)		not null,
	float b_balance_cf;			// number(14,2)		not null -- for next bill (bf-payments+bill_amount)
	int	  b_run_no;				// number(5)
/* EXEC SQL END DECLARE SECTION; */ 


// initalise account number & invoice number common for all items in bill summary

	
	b_bill_no[10] = '\0';
	strcpy(b_client_code, (current->connection.client_code).c_str());
	b_client_code[8] = '\0';
	b_account_no = current->connection.account_no;
	b_balance_cf = current->call.charge + current->charge.rental + current->charge.pro_rate + current->charge.adjustment - current->charge.discounts + current->charge.tax + current->charge.brought_forward - current->charge.payments;
	b_balance_bf = current->charge.c_f;	// This month's c/f is the next month's b/f
	b_run_no = 1;		// Should get from db_pre_bill() - refer following line
	strcpy(b_start_date,(gsm_connections->start_date).c_str());
	strcpy(b_end_date,(gsm_connections->end_date).c_str());
	strcpy(b_br_code,gsm_bill_cycle->bill_cycle_code.c_str());
	
	for(int i=0; i<1; i++)
	{
		/* EXEC SQL 
		AT ISP 
		INSERT INTO BILL_MASTER
		(
			CLIENT_CODE, 
			ACCOUNT_NO,
			BILL_NO,
			BILL_PERIOD_START,
			BILL_PERIOD_END, 
			BALANCE_BF,
			BILL_RUN_CODE,
			BILL_AMOUNT 
		)
			VALUES
		(
			:b_client_code,
			:b_account_no,
			:b_bill_no,
			to_date(to_char((ADD_MONTHS(to_date(:b_start_date,'YYYYMMDD'),+1)),'YYYYMMDD'),'YYYYMMDD'),
			to_date(to_char((ADD_MONTHS(to_date(:b_end_date,'YYYYMMDD'),+1)),'YYYYMMDD'),'YYYYMMDD'),
			:b_balance_bf,
			:b_br_code,
			 0
		); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_MASTER (CLIENT_CODE,ACCOUNT_NO,BILL_NO,BIL\
L_PERIOD_START,BILL_PERIOD_END,BALANCE_BF,BILL_RUN_CODE,BILL_AMOUNT) values (:\
b0,:b1,:b2,to_date(to_char(ADD_MONTHS(to_date(:b3,'YYYYMMDD'),(+1)),'YYYYMMDD'\
),'YYYYMMDD'),to_date(to_char(ADD_MONTHS(to_date(:b4,'YYYYMMDD'),(+1)),'YYYYMM\
DD'),'YYYYMMDD'),:b5,:b6,0)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1511;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)b_client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&b_account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)b_bill_no;
  sqlstm.sqhstl[2] = (unsigned int  )20;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)b_start_date;
  sqlstm.sqhstl[3] = (unsigned int  )10;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)b_end_date;
  sqlstm.sqhstl[4] = (unsigned int  )10;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&b_balance_bf;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)b_br_code;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	}
	//EXEC SQL AT ISP COMMIT; 

	//printf("bill master updated for open bill");
}

void connections::db_insert_bill_master_raw()
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char  ub_bill_no[50];			// varcahr2(10)		not null,
	char  ub_client_code[50];		// varchar2(8)		not null,
 	int   ub_account_no;			// number(10)		not null,
	char  ub_start_date[10];		// date 			not null,
	char  ub_end_date[10];			// date				not null,
	char  ub_due_date[10];			// date 			not null,
	float ub_balance_bf;			// number(14,2)		not null,
	float ub_bill_payments;			// number(14,2)		not null,
	char  ub_br_code[50];			// varchar2(2)		not null,
	float ub_total_bill_value;		// number(14,2)		not null,
	float ub_balance_cf;			// number(14,2)		not null -- for next bill (bf-payments+bill_amount)
	int	  ub_run_no;				// number(5)
	char  ub_user_id[20];			// varchar2(30)
	char  b_sys_date[10];			// sysdate  -  YYYYMMDD	
/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(b_sys_date, gsm_connections->sys_date.c_str());
	int position = strcspn( current->call.user_id.c_str(), " " );
	if ( position==0 ) 
	{
		current->call.user_id = current->call.user_id.substr(0,strcspn( current->call.user_id.c_str(), " " ));
	}
	else
	{
		current->call.user_id[position] = '\0';
	}
	
	strcpy(ub_user_id, current->call.user_id.c_str());
	strcpy(ub_bill_no, (current->connection.invoice_no).c_str());
	ub_bill_no[10] = '\0';
 	ub_account_no = current->connection.account_no;
	strcpy(ub_client_code, (current->connection.client_code).c_str());
	ub_client_code[8] = '\0';
	strcpy(ub_start_date, start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	strcpy(ub_due_date, due_date.c_str());
	strcpy(ub_br_code,gsm_bill_cycle->bill_cycle_code.c_str());
	ub_balance_bf = current->charge.brought_forward;
	ub_run_no = 1;		// Should get from db_pre_bill() - refer following line
	ub_total_bill_value = current->charge.bill_amount;
	ub_balance_bf = current->charge.brought_forward;
	ub_balance_cf = current->charge.c_f;
	ub_bill_payments = current->charge.payments;
	


	/*
	cout<<" ub_bill_no="<<ub_bill_no
		<<" ub_account_no="<<ub_account_no
		<<" ub_start_date="<<ub_start_date
		<<" ub_end_date="<<ub_end_date
		<<" ub_due_date="<<ub_due_date
		<<" ub_balance_bf="<<ub_balance_bf
		<<" ub_bill_payments="<<ub_bill_payments
		<<" ub_br_code="<<ub_br_code
		<<" ub_total_bill_value="<<ub_total_bill_value
		<<" ub_balance_cf="<<ub_balance_cf
		<<" ub_run_number="<<ub_run_no
		<<" ub_user_id="<<ub_user_id
		<<" ub_corporate_bill_code="<<ub_corporate_bill_code<<endl;
	*/
	

	
		/* EXEC SQL 
		AT ISP 
		INSERT INTO BILL_MASTER_RAW
		(
			CLIENT_CODE,
			ACCOUNT_NO,
			BILL_DATE,
			PROCESSED_DATE,
			BILL_PERIOD_START,
			BILL_PERIOD_END,
			DUE_DATE,
			BILL_RUN_CODE,
			BILL_AMOUNT,
			BALANCE_BF,
			BILL_PAYMENTS,
			BALANCE_CF,
			RUN_NO,
			USER_ID,
			BILL_NO 
		)
			VALUES
		(
			:ub_client_code,
			:ub_account_no,
			to_date(:ub_end_date,'YYYYMMDD'),
			to_date(:b_sys_date,'YYYYMMDD'),
			to_date(:ub_start_date,'YYYYMMDD'), 
			to_date(:ub_end_date,'YYYYMMDD'), 
			to_date(:ub_due_date,'YYYYMMDD'),
			:ub_br_code, 
			:ub_total_bill_value,
			:ub_balance_bf,
			:ub_bill_payments,
			:ub_balance_cf,
			:ub_run_no,
			:ub_user_id,
			:ub_bill_no 	 
		); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_MASTER_RAW (CLIENT_CODE,ACCOUNT_NO,BILL_DA\
TE,PROCESSED_DATE,BILL_PERIOD_START,BILL_PERIOD_END,DUE_DATE,BILL_RUN_CODE,BIL\
L_AMOUNT,BALANCE_BF,BILL_PAYMENTS,BALANCE_CF,RUN_NO,USER_ID,BILL_NO) values (:\
b0,:b1,to_date(:b2,'YYYYMMDD'),to_date(:b3,'YYYYMMDD'),to_date(:b4,'YYYYMMDD')\
,to_date(:b2,'YYYYMMDD'),to_date(:b6,'YYYYMMDD'),:b7,:b8,:b9,:b10,:b11,:b12,:b\
13,:b14)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1557;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)ub_client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&ub_account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)ub_end_date;
  sqlstm.sqhstl[2] = (unsigned int  )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)b_sys_date;
  sqlstm.sqhstl[3] = (unsigned int  )10;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)ub_start_date;
  sqlstm.sqhstl[4] = (unsigned int  )10;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)ub_end_date;
  sqlstm.sqhstl[5] = (unsigned int  )10;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)ub_due_date;
  sqlstm.sqhstl[6] = (unsigned int  )10;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)ub_br_code;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&ub_total_bill_value;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&ub_balance_bf;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)&ub_bill_payments;
  sqlstm.sqhstl[10] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&ub_balance_cf;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&ub_run_no;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         void  *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)ub_user_id;
  sqlstm.sqhstl[13] = (unsigned int  )20;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         void  *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)ub_bill_no;
  sqlstm.sqhstl[14] = (unsigned int  )50;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         void  *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	//printf("bill master updated -------------");
	fprintf(logfile, "%s",  "\nbill_master_rad inserted");


}





//-- rental_advance_payments
void connections::db_read_rental_advance_payments()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct rental_advance_payments_t
	{
			char	client_code[8];		// varchar2(8)			
			char	date_paid[BUF_LEN];			// date
			int		no_of_months_free;					
			int		no_of_months_paid;				
			int		account_no;		
			int		balance_months;				
	} *a;

	struct rental_advance_payments_ind
	{ 
  		short	client_code_ind;				
		short	date_paid_ind;		
		short	no_of_months_free_ind;					
		short	no_of_months_paid_ind;				
		short	account_no_ind;		
		short	balance_months_ind;				
	}a_ind[FETCH_SIZE];

	char t_start_date[20];
	int rows_to_fetch, rows_before, rows_this_time;
	char ub_end_date[15];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	advance_payment	ap;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new rental_advance_payments_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for rental_advance_payments fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_rental_advance_payments CURSOR FOR
	SELECT	CLIENT_CODE,				
			DATE_PAID,
			NO_OF_MONTHS_FREE,		
			NO_OF_MONTHS_PAID,					
			ACCOUNT_NO,				
			BALANCE_MONTHS		
	FROM	MIRRORED_BILL_RENT_ADV_PAYMTS
	WHERE	TRUNC(DATE_PAID) <= to_date(:ub_end_date,'YYYYMMDD')
	AND	TRUNC(BILL_PERIOD_START) = to_date(:t_start_date,'YYYYMMDD')
	ORDER BY DATE_PAID DESC; */ 
 
       
    /* EXEC SQL AT ISP  OPEN c_rental_advance_payments; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0027;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1635;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)ub_end_date;
    sqlstm.sqhstl[0] = (unsigned int  )15;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_start_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_rental_advance_payments INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )1661;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->client_code;
  sqlstm.sqhstl[0] = (unsigned int  )8;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->date_paid;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->date_paid_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->no_of_months_free;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->no_of_months_free_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->no_of_months_paid;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->no_of_months_paid_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&a->account_no;
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&a->balance_months;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->balance_months_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].date_paid,
				  ((a_ind[i].date_paid_ind < 0) ? "UNDEF":a[i].date_paid));
			a[i].no_of_months_free = (a_ind[i].no_of_months_free_ind < 0) ? 0.0 : a[i].no_of_months_free;
			a[i].no_of_months_paid = (a_ind[i].no_of_months_paid_ind < 0) ? 0.0 : a[i].no_of_months_paid;
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no;
			a[i].balance_months = (a_ind[i].balance_months_ind < 0) ? 0.0 : a[i].balance_months;
			

			if (a[i].balance_months > 0)
			{
				ap.account_no		= a[i].account_no;
				ap.client_code		= a[i].client_code;						
				ap.date_paid		= a[i].date_paid;						
				ap.balance_months	= a[i].balance_months;
							
				gsm_connections->rental_advance_payments_map[a[i].account_no] = ap;
			}

		}
	} 

	/* EXEC SQL AT ISP CLOSE c_rental_advance_payments; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1703;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  rental_advance_payments records read.\n\n",rows_before);
} 


//-- rental_advance_payments update
void connections::db_update_rental_advance_payments(int	account_no, string client_code,string date_paid)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	int		up_account_no;
	char	up_client_code[BUF_LEN];
	char	up_date_paid[BUF_LEN];

	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(up_client_code,client_code.c_str());
	strcpy(up_date_paid, date_paid.c_str());
	up_account_no = account_no;

	int  pos;
	pos = strcspn( up_client_code, " " );
	up_client_code[pos]='\0';
 
    /* EXEC SQL 
	AT ISP 
	UPDATE	RENTAL_ADVANCE_PAYMENTS				
			SET BALANCE_MONTHS = BALANCE_MONTHS-1
	WHERE	to_date(to_char(DATE_PAID,'DD-MON-YY'),'DD-MON-YY') = to_date(:up_date_paid,'DD-MON-YY') AND 
	CLIENT_CODE = :up_client_code AND
	ACCOUNT_NO = :up_account_no; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update RENTAL_ADVANCE_PAYMENTS  set BALANCE_MONTHS=(BALAN\
CE_MONTHS-1) where ((to_date(to_char(DATE_PAID,'DD-MON-YY'),'DD-MON-YY')=to_da\
te(:b0,'DD-MON-YY') and CLIENT_CODE=:b1) and ACCOUNT_NO=:b2)";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1721;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)up_date_paid;
    sqlstm.sqhstl[0] = (unsigned int  )50;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)up_client_code;
    sqlstm.sqhstl[1] = (unsigned int  )50;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)&up_account_no;
    sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	//printf("rental_advance_payments records updated");
	//cout << "rental_advance_payments records updated for account no: " << account_no << endl;
} 


//-- truncate interim_bill_summary_items
void connections::truncate_interim_bill_summary_items()
{
	
    /* EXEC SQL 
	AT ISP 
	TRUNCATE TABLE INTERIM_BILL_SUMMARY_ITEMS; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "truncate TABLE INTERIM_BILL_SUMMARY_ITEMS";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1751;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

				
			
	printf("interim_bill_summary_items truncated");
}

//-- work_orders update
void connections::db_update_work_orders(int	work_order_no)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	int		up_work_order_no;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	
	up_work_order_no = work_order_no;

    /* EXEC SQL 
	AT ISP 
	UPDATE	WORK_ORDERS				
			SET STATUS = 'N'
	WHERE	WORK_ORDER_NO = :up_work_order_no; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "update WORK_ORDERS  set STATUS='N' where WORK_ORDER_NO=:b\
0";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1769;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&up_work_order_no;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	//printf("work_orders updated");
}


//-- bill_summary_item_defs
void connections::db_read_bill_summary_item_defs()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	int cash_transact_type;
	int cash_transact_type_rental_adv_pay;
	char debit_acc_type[5];						// varchar2(5)
	char credit_acc_type[5];					// varchar2(5)
	char debit_acc_type_rental_adv_pay[5];		// varchar2(5)
	char credit_acc_type_rental_adv_pay[5];		// varchar2(5)
		
	/* EXEC SQL END DECLARE SECTION; */ 


	
    /* EXEC SQL 
	AT ISP 
	SELECT	CASH_TRANSACTION_TYPE
	INTO :cash_transact_type				
	FROM	BILL_SUMMARY_ITEM_DEFS 
	WHERE	ITEM_CODE = 'TOT_PAY'; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select CASH_TRANSACTION_TYPE into :b0  from BILL_SUMMARY_\
ITEM_DEFS where ITEM_CODE='TOT_PAY'";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )1791;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)&cash_transact_type;
    sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL 
	AT ISP 
	SELECT	CASH_TRANSACTION_TYPE
	INTO :cash_transact_type_rental_adv_pay				
	FROM	BILL_SUMMARY_ITEM_DEFS 
	WHERE	ITEM_CODE = 'RENT_ADV_DEDUCT'; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select CASH_TRANSACTION_TYPE into :b0  from BILL_SUMMARY_ITE\
M_DEFS where ITEM_CODE='RENT_ADV_DEDUCT'";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1813;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&cash_transact_type_rental_adv_pay;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	cout << "bill_summary_item_defs  read." << endl;
	fprintf(logfile, "%s", "\nbill_summary_item_defs  read.");

	fprintf(logfile, "%s%d","\ncash_transaction_type : " , cash_transact_type );
	fprintf(logfile, "%s%d","\ncash_transact_type_rental_adv_pay : " , cash_transact_type_rental_adv_pay );

	cash_transaction_type = cash_transact_type;
	cash_transaction_type_rental_adv_pay = cash_transact_type_rental_adv_pay;

	// allowed_cash_transactions
	
	/* EXEC SQL 
	AT ISP 
	SELECT	DEBIT_ACC_TYPE,
			CREDIT_ACC_TYPE
	INTO	:debit_acc_type,
			:credit_acc_type				
	FROM	ALLOWED_CASH_TRANSACTIONS 
	WHERE	CASH_TRANSACTION_TYPE = :cash_transact_type; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select DEBIT_ACC_TYPE ,CREDIT_ACC_TYPE into :b0,:b1  from AL\
LOWED_CASH_TRANSACTIONS where CASH_TRANSACTION_TYPE=:b2";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1835;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)debit_acc_type;
 sqlstm.sqhstl[0] = (unsigned int  )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)credit_acc_type;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&cash_transact_type;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL 
	AT ISP 
	SELECT	DEBIT_ACC_TYPE,
			CREDIT_ACC_TYPE
	INTO	:debit_acc_type_rental_adv_pay,
			:credit_acc_type_rental_adv_pay				
	FROM	ALLOWED_CASH_TRANSACTIONS 
	WHERE	CASH_TRANSACTION_TYPE = :cash_transact_type_rental_adv_pay; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select DEBIT_ACC_TYPE ,CREDIT_ACC_TYPE into :b0,:b1  from AL\
LOWED_CASH_TRANSACTIONS where CASH_TRANSACTION_TYPE=:b2";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1865;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)debit_acc_type_rental_adv_pay;
 sqlstm.sqhstl[0] = (unsigned int  )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)credit_acc_type_rental_adv_pay;
 sqlstm.sqhstl[1] = (unsigned int  )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&cash_transact_type_rental_adv_pay;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}




	cout << "allowed_cash_transactions  read." << endl;
	fprintf(logfile, "%s", "\nallowed_cash_transactions  read.");
	
	debit_acc_type[strcspn( debit_acc_type, " " )] = '\0';
	credit_acc_type[strcspn( credit_acc_type, " " )] = '\0';
	debit_acc_type_rental_adv_pay[strcspn( debit_acc_type_rental_adv_pay, " " )] = '\0';
	credit_acc_type_rental_adv_pay[strcspn( credit_acc_type_rental_adv_pay, " " )] = '\0';


	debit_account_type	= debit_acc_type;
	credit_account_type	= credit_acc_type;
	debit_account_type_rental_adv_pay	= debit_acc_type_rental_adv_pay;
	credit_account_type_rental_adv_pay	= credit_acc_type_rental_adv_pay;

	fprintf(logfile, "%s%s", "\ndebit_account_type  :" , debit_account_type.c_str() );
	fprintf(logfile, "%s%s", "\ncredit_account_type  :" , credit_account_type.c_str() );
	fprintf(logfile, "%s%s", "\ndebit_account_type_rental_adv_pay  :" , debit_account_type_rental_adv_pay.c_str() );
	fprintf(logfile, "%s%s","\ncredit_account_type_rental_adv_pay  :" , credit_account_type_rental_adv_pay.c_str() );

}



// billrun_definitions

void connections::db_read_billrun_definitions()
{

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	 char	br_br_code[10];			//	VARCHAR2(5)		
	 int	br_start_day;				//	NUMBER(2)
	 int	br_bill_grace_period;		//	NUMBER(3)
	 char	br_system_date[20];
	 char	br_temp_date[20];
	 char	br_start_date[20];
	 char	br_end_date[20];
	 char	br_due_date[20];
	 char	bill_cycle_code[6];			
			 
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(bill_cycle_code, gsm_bill_cycle->bill_cycle_code.c_str());

	/* EXEC SQL WHENEVER NOT FOUND DO not_found_error("No relevant entry in billrun_definitions"); */ 
 

	/* EXEC SQL 
	AT ISP 
	SELECT	BR_CODE, START_DAY, BILL_GRACE_PERIOD 
	INTO	:br_br_code, 
			:br_start_day, 
			:br_bill_grace_period
	FROM	BILLRUN_DEFINITIONS
	WHERE BR_CODE = :bill_cycle_code
	AND ACTIVE = 'Y'; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select BR_CODE ,START_DAY ,BILL_GRACE_PERIOD into :b0,:b1,:b\
2  from BILLRUN_DEFINITIONS where (BR_CODE=:b3 and ACTIVE='Y')";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1895;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_br_code;
 sqlstm.sqhstl[0] = (unsigned int  )10;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&br_start_day;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&br_bill_grace_period;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)bill_cycle_code;
 sqlstm.sqhstl[3] = (unsigned int  )6;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	br_br_code[strcspn( br_br_code, " " )] = '\0';

	br_code = br_br_code;
	start_day = br_start_day;
	bill_grace_period = br_bill_grace_period;

	cout << "billrun_definitions  read." << endl;
	cout << "br_code : " << br_code ;
	//cout << "start_day : " << start_day << endl;
	//cout << "bill_grace_period : " << bill_grace_period << endl;
	
     
	/* EXEC SQL 
	AT ISP 
	SELECT	to_char(sysdate,'YYYYMMDD')
	INTO	:br_system_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(sysdate,'YYYYMMDD') into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1929;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	//cout << "Sysdate : " << br_system_date << endl;

	char sysday[2];

	sysday[0]	= br_system_date[6];
	sysday[1]	= br_system_date[7];
	sysday[2]	= '\0';

	//cout << "sysday :" << sysday <<"END" << endl;

	int IntSysday = atoi(sysday);

	//cout << "IntSysday :" << IntSysday <<"END" << endl;


	char buf[30];
	char day[2];
	
	strncpy(buf, br_system_date, 6);
	
	if (start_day >9)
	{
		myitoa(start_day, day);
		strncpy( buf + 6, day, 2 );
	}
	else
	{
		char pad[1];
		pad[0] = '0';
		strncpy( buf + 6, pad, 1 );
		myitoa(start_day, day);
		strncpy( buf + 7, day, 1 );
	}

	buf[8] = '\0'; 
	
	//cout << "buf : " << buf;

	strcpy(br_temp_date, buf);

	br_temp_date[8] = '\0'; 

	//cout << "br_temp_date  : " << br_temp_date ;

	if (IntSysday >= br_start_day)
	{
		/* EXEC SQL 
		AT ISP 
		SELECT	to_char((ADD_MONTHS(to_date(:br_temp_date,'YYYYMMDD'),-1)),'YYYYMMDD')
		INTO	:br_start_date
		FROM	DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char(ADD_MONTHS(to_date(:b0,'YYYYMMDD'),(-1)),'YY\
YYMMDD') into :b1  from DUAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1951;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)br_temp_date;
  sqlstm.sqhstl[0] = (unsigned int  )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)br_start_date;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



		//cout <<"up"<<endl;
	}
	else
	{
		/* EXEC SQL 
		AT ISP 
		SELECT	to_char((ADD_MONTHS(to_date(:br_temp_date,'YYYYMMDD'),-2)),'YYYYMMDD')
		INTO	:br_start_date
		FROM	DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char(ADD_MONTHS(to_date(:b0,'YYYYMMDD'),(-2)),'YY\
YYMMDD') into :b1  from DUAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1977;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)br_temp_date;
  sqlstm.sqhstl[0] = (unsigned int  )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)br_start_date;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



		//cout <<"down"<<endl;
	}

	br_start_date[8] = '\0'; 

	//cout << "br_start_date  : " << br_start_date ;

	/* EXEC SQL 
	AT ISP 
	SELECT	to_char((ADD_MONTHS(to_date(:br_start_date,'YYYYMMDD'),1)-1),'YYYYMMDD') //For Month End billing
	//SELECT	to_char(ADD_MONTHS(to_date(:br_start_date,'YYYYMMDD'),1),'YYYYMMDD')  // For Interim Billing
	INTO	:br_end_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char((ADD_MONTHS(to_date(:b0,'YYYYMMDD'),1)-1),'YY\
YYMMDD') into :b1  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2003;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)br_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	br_end_date[8] = '\0'; 

	//cout << "End date : " << br_end_date ;

	/* EXEC SQL 
	AT ISP 
	SELECT	to_char((to_date(:br_end_date ,'YYYYMMDD')+:br_bill_grace_period),'YYYYMMDD')
	INTO	:br_due_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char((to_date(:b0,'YYYYMMDD')+:b1),'YYYYMMDD') int\
o :b2  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2029;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_end_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&br_bill_grace_period;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)br_due_date;
 sqlstm.sqhstl[2] = (unsigned int  )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	br_due_date[8] = '\0'; 

	//cout << "Due date : " << br_due_date ;

	// Dates hardcode start - hack
	/*
	strcpy(br_start_date,"20011201");
    br_start_date[8] = '\0'; 
    strcpy(br_end_date,"20011231");
    br_end_date[8] = '\0'; 
    strcpy(br_due_date,"20020115");
    br_due_date[8] = '\0';
	*/

	// Dates hardcode end - hack 

	gsm_connections->start_date = br_start_date;
	gsm_connections->end_date = br_end_date;
	gsm_connections->due_date = br_due_date;

	gsm_connections->sys_date = br_system_date;

	// Added on 16-09-2002
	reng_start_date.set_date(br_start_date);
	reng_end_date.set_date(br_end_date); 
	reng_sys_date.set_date(br_system_date);
	// end - 16-09-2002
	  
}


//-- pro_rate_newcust
void connections::db_read_pro_rate_newcust()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct pro_rate_newcust_t
	{
			int		instance;						// number(1)
			char	client_code[8];					// varchar2(8)
			int		account_no;						// number(10)				
			char	changed_date[BUF_LEN];			// date
			float	amount;							// number(14,2)
			char	old_package_code[BUF_LEN];		// varchar2(5)
			char	new_package_code[BUF_LEN];		// varchar2(5)
			char	processed[2];					// varchar2(1)
			float	pkg_prorate_amt;				// number(14,2)
	} *a;

	struct pro_rate_newcust_ind
	{ 
  		short	instance_ind;				
		short	client_code_ind;		
		short	account_no_ind;					
		short	changed_date_ind;				
		short	amount_ind;		
		short	old_package_code_ind;
		short	new_package_code_ind;				
		short	processed_ind;		
		short	pkg_prorate_amt_ind;				
	}a_ind[FETCH_SIZE];

	char t_start_date[20], t_end_date[20];
	int rows_to_fetch, rows_before, rows_this_time;
	int t_start_ac, t_end_ac;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
	t_start_ac = start_ac_no;
	t_end_ac = end_ac_no;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new pro_rate_newcust_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for pro_rate_newcust fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_pro_rate_newcust CURSOR FOR
	SELECT	INSTANCE,
			CLIENT_CODE,
			ACCOUNT_NO,				
			CHANGED_DATE,
			AMOUNT,
			OLD_PACKAGE_CODE,
			NEW_PACKAGE_CODE,
			PROCESSED,
			PKG_PRORATE_AMT
	FROM	PRO_RATE_NEWCUST
	WHERE TRUNC(CHANGED_DATE) >= to_date(:t_start_date,'YYYYMMDD') AND TRUNC(CHANGED_DATE) <= to_date(:t_end_date,'YYYYMMDD')
	ORDER BY INSTANCE; */ 

			
       
    /* EXEC SQL AT ISP  OPEN c_pro_rate_newcust; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0041;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2059;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_end_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_pro_rate_newcust INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2085;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->instance;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->instance_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->client_code;
  sqlstm.sqhstl[1] = (unsigned int  )8;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->account_no;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->changed_date;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->changed_date_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&a->amount;
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->amount_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->old_package_code;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->old_package_code_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->new_package_code;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->new_package_code_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->processed;
  sqlstm.sqhstl[7] = (unsigned int  )2;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->processed_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&a->pkg_prorate_amt;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[8] = (         int  )sizeof(struct pro_rate_newcust_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->pkg_prorate_amt_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct pro_rate_newcust_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].changed_date,
				  ((a_ind[i].changed_date_ind < 0) ? "UNDEF":a[i].changed_date));
			strcpy(a[i].old_package_code,
				  ((a_ind[i].old_package_code_ind < 0) ? "UNDEF":a[i].old_package_code));
			strcpy(a[i].new_package_code,
				  ((a_ind[i].new_package_code_ind < 0) ? "UNDEF":a[i].new_package_code));
			strcpy(a[i].processed,
				  ((a_ind[i].processed_ind < 0) ? "UNDEF":a[i].processed));
			a[i].instance = (a_ind[i].instance_ind < 0) ? 0 : a[i].instance;
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0 : a[i].account_no;
			a[i].amount = (a_ind[i].amount_ind < 0) ? 0.0 : a[i].amount;
			a[i].pkg_prorate_amt = (a_ind[i].pkg_prorate_amt_ind < 0) ? 0.0 : a[i].pkg_prorate_amt;
			
			if(set_current(a[i].account_no))
			{
				current->charge.pro_rate += a[i].amount;
			}
			
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_pro_rate_newcust; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2139;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  pro_rate_newcust records read.\n\n",rows_before);
} 


//-- pro_rate_services
void connections::db_read_pro_rate_services()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct pro_rate_services_t
	{
			int		instance;						// number(2)
			char	client_code[10];				// varchar2(10)
			int		account_no;						// number(10)				
			char	date_changed[BUF_LEN];			// date
			float	amount;							// number(14,2)
			char	service_code[BUF_LEN];			// varchar2(5)
			char	processed[2];					// varchar2(1)
	} *a;

	struct pro_rate_services_ind
	{ 
  		short	instance_ind;				
		short	client_code_ind;		
		short	account_no_ind;					
		short	date_changed_ind;				
		short	amount_ind;		
		short	service_code_ind;
		short	processed_ind;		
	}a_ind[FETCH_SIZE];

	char t_start_date[20], t_end_date[20];
	int rows_to_fetch, rows_before, rows_this_time;
	int t_start_ac, t_end_ac;

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());
	strcpy(t_end_date, end_date.c_str());
	t_start_ac = start_ac_no;
	t_end_ac = end_ac_no;
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new pro_rate_services_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for pro_rate_services fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_pro_rate_services CURSOR FOR
	SELECT	INSTANCE,
			CLIENT_CODE,
			ACCOUNT_NO,				
			DATE_CHANGED,
			AMOUNT,
			SERVICE_CODE,
			PROCESSED			
	FROM	PRO_RATE_services
	WHERE TRUNC(DATE_CHANGED) >= to_date(:t_start_date,'YYYYMMDD') AND TRUNC(DATE_CHANGED) <= to_date(:t_end_date,'YYYYMMDD'); */ 

			 
       
    /* EXEC SQL AT ISP  OPEN c_pro_rate_services; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0042;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2157;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)t_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )20;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)t_end_date;
    sqlstm.sqhstl[1] = (unsigned int  )20;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_pro_rate_services INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2183;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->instance;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->instance_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->client_code;
  sqlstm.sqhstl[1] = (unsigned int  )10;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->account_no;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->date_changed;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->date_changed_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&a->amount;
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->amount_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->service_code;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->service_code_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->processed;
  sqlstm.sqhstl[6] = (unsigned int  )2;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct pro_rate_services_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->processed_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct pro_rate_services_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].date_changed,
				  ((a_ind[i].date_changed_ind < 0) ? "UNDEF":a[i].date_changed));
			strcpy(a[i].service_code,
				  ((a_ind[i].service_code_ind < 0) ? "UNDEF":a[i].service_code));
			strcpy(a[i].processed,
				  ((a_ind[i].processed_ind < 0) ? "UNDEF":a[i].processed));
			a[i].instance = (a_ind[i].instance_ind < 0) ? 0 : a[i].instance;
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0 : a[i].account_no;
			a[i].amount = (a_ind[i].amount_ind < 0) ? 0.0 : a[i].amount;
			
			
			if(set_current(a[i].account_no))
			{
				current->charge.pro_rate += a[i].amount;
			}
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_pro_rate_services; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2229;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  pro_rate_services records read.\n\n",rows_before);
} 

//bill_debts
FILE* fp;
void connections::db_insert_bill_debts()
{
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char  b_client_code[50];	// varchar2(8)		
 		int   b_account_no;			// number(10)		
		char  b_bill_no[20];		// varcahr2(10)		
		float b_amount;				// number(14,2)
		char  b_bill_date[10];		// date				
		char  b_due_date[10];		// date
		int	  b_serial_no;			// number(10) 
		short b_serial_no_ind;		// indicator variable for b_serial_no			
		//char  ca_bill_date[14];
	/* EXEC SQL END DECLARE SECTION; */ 


	/*
	fp = fopen("./billdate.txt","r");
	if(!fp)
	{
		cout<<"\nERROR OPENING THE ./billdate.txt"<<endl;
		exit(0);
	}
	fgets( ca_bill_date,14,fp);
	*/
	

	/* EXEC SQL 
	AT ISP 
	SELECT MAX(SERIAL_NO) INTO :b_serial_no INDICATOR :b_serial_no_ind FROM BILL_DEBTS; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select max(SERIAL_NO) into :b0:b1  from BILL_DEBTS ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2247;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&b_serial_no;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&b_serial_no_ind;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	b_serial_no = (b_serial_no_ind < 0) ? 1 : (b_serial_no+1);
	
	//cout <<"b_serial_no : " << b_serial_no << endl; 

	strcpy(b_client_code, (current->connection.client_code).c_str());
	b_account_no = current->connection.account_no;
	strncpy(b_bill_no, (current->connection.invoice_no).c_str(),10);
	b_bill_no[10] = '\0';
	strcpy(b_due_date, due_date.c_str());
	strcpy(b_bill_date, end_date.c_str());

	if ( (current->charge.c_f > 0) && (current->charge.brought_forward >= 0) ) b_amount = current->charge.bill_amount;
	if ( (current->charge.c_f > 0) && (current->charge.brought_forward < 0) ) b_amount = current->charge.c_f;
	if (current->charge.c_f <= 0)  b_amount = 0;
	

	fprintf(logfile, "%s",  "\nb_client_code : " , b_client_code );
	fprintf(logfile, "%s", "\nb_account_no : " , b_account_no );
	fprintf(logfile, "%s","\nb_bill_no : " , b_bill_no );
	
	/* EXEC SQL 
	AT ISP 
	INSERT INTO BILL_DEBTS (SERIAL_NO, CLIENT_CODE, ACCOUNT_NO, BILL_NO, AMOUNT, BILL_DATE,
	 DUE_DATE) VALUES (:b_serial_no, :b_client_code, :b_account_no, :b_bill_no, :b_amount, to_date(:b_bill_date,'YYYYMMDD'), to_date(:b_due_date,'YYYYMMDD')); */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into BILL_DEBTS (SERIAL_NO,CLIENT_CODE,ACCOUNT_NO,BIL\
L_NO,AMOUNT,BILL_DATE,DUE_DATE) values (:b0,:b1,:b2,:b3,:b4,to_date(:b5,'YYYYM\
MDD'),to_date(:b6,'YYYYMMDD'))";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2269;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&b_serial_no;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)b_client_code;
 sqlstm.sqhstl[1] = (unsigned int  )50;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&b_account_no;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)b_bill_no;
 sqlstm.sqhstl[3] = (unsigned int  )20;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)&b_amount;
 sqlstm.sqhstl[4] = (unsigned int  )sizeof(float);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (         void  *)b_bill_date;
 sqlstm.sqhstl[5] = (unsigned int  )10;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         void  *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned int  )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (         void  *)b_due_date;
 sqlstm.sqhstl[6] = (unsigned int  )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         void  *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned int  )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



/*	INSERT INTO BILL_DEBTS (SERIAL_NO, CLIENT_CODE, ACCOUNT_NO, BILL_NO, AMOUNT, BILL_DATE,
	 DUE_DATE) VALUES (:b_serial_no, :b_client_code, :b_account_no, :b_bill_no, :b_amount, to_date(:ca_bill_date,'YYYYMMDD'), to_date(:b_due_date,'YYYYMMDD'));
*/	
	//printf("bill_debts inserted ");
	fprintf(logfile, "%s","\nbill_debts inserted " );
	//fclose(fp);
}


void connections::db_insert_bill_month_definitions()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	char	b_TEMP_BILL_MONTH[9];			//	VARCHAR2(8)
	char	b_BILL_RUN_DATE[20];		//	DATE
	char	b_BR_CODE[30];				//	VARCHAR2(5)
	char	b_BILL_MONTH[9];
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(b_BILL_RUN_DATE, gsm_connections->sys_date.c_str());
	strcpy(b_BR_CODE,gsm_bill_cycle->bill_cycle_code.c_str());
	strcpy(b_TEMP_BILL_MONTH,gsm_connections->start_date.c_str());

	
	b_TEMP_BILL_MONTH[8] = '\0';
	

	
	/* EXEC SQL
	AT ISP
	SELECT TO_CHAR(TO_DATE(:b_TEMP_BILL_MONTH, 'YYYYMMDD'), 'YYYY-MON')
	INTO	:b_BILL_MONTH	
	FROM DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select TO_CHAR(TO_DATE(:b0,'YYYYMMDD'),'YYYY-MON') into :b1 \
 from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2315;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)b_TEMP_BILL_MONTH;
 sqlstm.sqhstl[0] = (unsigned int  )9;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)b_BILL_MONTH;
 sqlstm.sqhstl[1] = (unsigned int  )9;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	b_BILL_MONTH[8] = '\0';
	//cout << b_BILL_MONTH << "end" << endl;

	/* EXEC SQL 
	AT ISP 
	INSERT INTO BILL_MONTH_DEFINITION (BILL_MONTH,
		  BILL_RUN_DATE, BR_CODE) VALUES (
		  :b_BILL_MONTH, to_date(:b_BILL_RUN_DATE,'YYYYMMDD'), :b_BR_CODE); */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "insert into BILL_MONTH_DEFINITION (BILL_MONTH,BILL_RUN_DATE,\
BR_CODE) values (:b0,to_date(:b1,'YYYYMMDD'),:b2)";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2341;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)b_BILL_MONTH;
 sqlstm.sqhstl[0] = (unsigned int  )9;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)b_BILL_RUN_DATE;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)b_BR_CODE;
 sqlstm.sqhstl[2] = (unsigned int  )30;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	
	
	printf("\nbill_month_definitions updated ");

}


//-- read isp_services
void connections::db_read_isp_services()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	float b_default_quota;
	float b_extra_rental;
	
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL 
	AT ISP
	SELECT DEFAULT_QUOTA, EXTRA_RENTAL 
	INTO :b_default_quota, :b_extra_rental
	FROM ISP_SERVICES
	WHERE	service_code = 'EMAIL'; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select DEFAULT_QUOTA ,EXTRA_RENTAL into :b0,:b1  from ISP_SE\
RVICES where service_code='EMAIL'";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2371;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&b_default_quota;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(float);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&b_extra_rental;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(float);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	/* EXEC SQL WHENEVER NOT FOUND DO not_found_error("No relevant entry for service EMAIL in ISP_SERVICES"); */ 


	default_quota	= b_default_quota;
	extra_rental	= b_extra_rental;
	
	printf("\nisp_services read ");
}   

//-- truncate bill_summary_items_i
void connections::truncate_bill_summary_items_i()
{
    /* EXEC SQL 
	AT ISP 
	TRUNCATE TABLE BILL_SUMMARY_ITEMS_I DROP STORAGE; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "truncate TABLE BILL_SUMMARY_ITEMS_I DROP STORAGE";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2397;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

				

	printf("bill_summary_items_i truncated");
}


//-- truncate bill_master_i
void connections::truncate_bill_master_i()
{
    /* EXEC SQL 
	AT ISP 
	TRUNCATE TABLE BILL_MASTER_I DROP STORAGE; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "truncate TABLE BILL_MASTER_I DROP STORAGE";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2415;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

				
			
	printf("bill_master_i truncated");
}

void connections::db_insert_bill_summary_items_i()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	char	b_BILL_NO[15];			//	NUMBER(10)
	char	b_ITEM_CODE[20];		//	VARCHAR2(10)
	float	b_VALUE;				//	NUMBER(12,2)
	float	b_VALUE_VAT;			//  NUMBER(12,2)
	/* EXEC SQL END DECLARE SECTION; */ 


	// initalise account number & invoice number common for all items in bill summary

	strncpy(b_BILL_NO, (current->connection.invoice_no).c_str(),10);

	b_BILL_NO[10] = '\0';

	for(BILL_SUMMARY_DEF::iterator i=summary.begin(); i!=summary.end(); i++)
	{
		strcpy(b_ITEM_CODE, (*i).first.c_str());
		b_VALUE		= (*i).second.amount;
		b_VALUE_VAT = (*i).second.vat_amount;

		/*
		cout << "b_BILL_NO :	" << b_BILL_NO << endl;
		cout << "b_ITEM_CODE :	" << b_ITEM_CODE << endl;
		cout << "b_VALUE :		" << b_VALUE << endl;
		cout << "b_VALUE_VAT :	" << b_VALUE_VAT << endl;
		*/

		/* EXEC SQL 
		AT ISP 
		INSERT INTO BILL_SUMMARY_ITEMS_I (BILL_NO,
		  ITEM_CODE, AMOUNT, VAT_AMOUNT) VALUES (:b_BILL_NO, :b_ITEM_CODE, :b_VALUE, :b_VALUE_VAT); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_SUMMARY_ITEMS_I (BILL_NO,ITEM_CODE,AMOUNT,\
VAT_AMOUNT) values (:b0,:b1,:b2,:b3)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2433;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)b_BILL_NO;
  sqlstm.sqhstl[0] = (unsigned int  )15;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)b_ITEM_CODE;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&b_VALUE;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&b_VALUE_VAT;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) not_found_error("No relevant entry for service EMAIL in ISP_SERVICES");
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}


	}
	
	//printf("bill_summary_items_i updated ");

}

void connections::db_insert_bill_master_i()
{

/* EXEC SQL BEGIN DECLARE SECTION; */ 

	char  ub_bill_no[50];		// varcahr2(10)		not null,
	char  ub_client_code[50];	// varchar2(8)		not null,
 	int   ub_account_no;		// number(10)		not null,
	char  ub_start_date[10];	// date 			not null,
	char  ub_end_date[10];		// date				not null,
	char  ub_due_date[10];		// date 			not null,
	float ub_balance_bf;		// number(14,2)		not null,
	float ub_bill_payments;		// number(14,2)		not null,
	char  ub_br_code[50];		// varchar2(2)		not null,
	float ub_total_bill_value;	// number(14,2)		not null,
	float ub_balance_cf;		// number(14,2)		not null -- for next bill (bf-payments+bill_amount)
	int	  ub_run_no;			// number(5)
	char  ub_user_id[20];		// varchar2(30)
	char  b_sys_date[10];		// sysdate  -  YYYYMMDD	
/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(b_sys_date, gsm_connections->sys_date.c_str());
	int position = strcspn( current->call.user_id.c_str(), " " );
	if ( position==0 ) 
	{
		current->call.user_id = current->call.user_id.substr(0,strcspn( current->call.user_id.c_str(), " " ));
	}
	else
	{
		current->call.user_id[position] = '\0';
	}
	
	strcpy(ub_user_id, current->call.user_id.c_str());

	strcpy(ub_bill_no, (current->connection.invoice_no).c_str());
	ub_bill_no[10] = '\0';
 	ub_account_no = current->connection.account_no;
	strcpy(ub_client_code, (current->connection.client_code).c_str());

	
	ub_client_code[8] = '\0';
	strcpy(ub_start_date, start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	strcpy(ub_due_date, due_date.c_str());
	strcpy(ub_br_code,gsm_bill_cycle->bill_cycle_code.c_str());
	ub_balance_bf = current->charge.brought_forward;
	ub_run_no = 1;		// Should get from db_pre_bill() - refer following line

	ub_total_bill_value = current->charge.bill_amount;
	ub_balance_bf = current->charge.brought_forward;
	ub_balance_cf = current->charge.c_f;
	ub_bill_payments = current->charge.payments;

	
	/*
	cout<<" ub_bill_no="<<ub_bill_no
		<<" ub_account_no="<<ub_account_no
		<<" ub_start_date="<<ub_start_date
		<<" ub_end_date="<<ub_end_date
		<<" ub_due_date="<<ub_due_date
		<<" ub_balance_bf="<<ub_balance_bf
		<<" ub_bill_payments="<<ub_bill_payments
		<<" ub_br_code="<<ub_br_code
		<<" ub_total_bill_value="<<ub_total_bill_value
		<<" ub_balance_cf="<<ub_balance_cf
		<<" ub_run_number="<<ub_run_no
		<<" ub_user_id="<<ub_user_id<<endl;
	*/
	
		
	
		/* EXEC SQL 
		AT ISP 
		INSERT INTO BILL_MASTER_I
		(
			CLIENT_CODE,
			ACCOUNT_NO,
			BILL_DATE,
			PROCESSED_DATE,
			BILL_PERIOD_START,
			BILL_PERIOD_END,
			DUE_DATE,
			BILL_RUN_CODE,
			BILL_AMOUNT,
			BALANCE_BF,
			BILL_PAYMENTS,
			BALANCE_CF,
			RUN_NO,
			USER_ID,
			BILL_NO 
		)
			VALUES
		(
			:ub_client_code,
			:ub_account_no,
			to_date(:ub_end_date,'YYYYMMDD'),
			to_date(:b_sys_date,'YYYYMMDD'),
			to_date(:ub_start_date,'YYYYMMDD'), 
			to_date(:ub_end_date,'YYYYMMDD'), 
			to_date(:ub_due_date,'YYYYMMDD'),
			:ub_br_code, 
			:ub_total_bill_value,
			:ub_balance_bf,
			:ub_bill_payments,
			:ub_balance_cf,
			:ub_run_no,
			:ub_user_id,
			:ub_bill_no 	 
		); */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "insert into BILL_MASTER_I (CLIENT_CODE,ACCOUNT_NO,BILL_DATE\
,PROCESSED_DATE,BILL_PERIOD_START,BILL_PERIOD_END,DUE_DATE,BILL_RUN_CODE,BILL_\
AMOUNT,BALANCE_BF,BILL_PAYMENTS,BALANCE_CF,RUN_NO,USER_ID,BILL_NO) values (:b0\
,:b1,to_date(:b2,'YYYYMMDD'),to_date(:b3,'YYYYMMDD'),to_date(:b4,'YYYYMMDD'),t\
o_date(:b2,'YYYYMMDD'),to_date(:b6,'YYYYMMDD'),:b7,:b8,:b9,:b10,:b11,:b12,:b13\
,:b14)";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )2467;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)ub_client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&ub_account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)ub_end_date;
  sqlstm.sqhstl[2] = (unsigned int  )10;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)b_sys_date;
  sqlstm.sqhstl[3] = (unsigned int  )10;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)ub_start_date;
  sqlstm.sqhstl[4] = (unsigned int  )10;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         void  *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)ub_end_date;
  sqlstm.sqhstl[5] = (unsigned int  )10;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         void  *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)ub_due_date;
  sqlstm.sqhstl[6] = (unsigned int  )10;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         void  *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)ub_br_code;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         void  *)0;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&ub_total_bill_value;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         void  *)0;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&ub_balance_bf;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         void  *)0;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)&ub_bill_payments;
  sqlstm.sqhstl[10] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         void  *)0;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&ub_balance_cf;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         void  *)0;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&ub_run_no;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         void  *)0;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)ub_user_id;
  sqlstm.sqhstl[13] = (unsigned int  )20;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         void  *)0;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (         void  *)ub_bill_no;
  sqlstm.sqhstl[14] = (unsigned int  )50;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         void  *)0;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned int  )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) not_found_error("No relevant entry for service EMAIL in ISP_SERVICES");
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 

	//printf("bill master updated -------------");
	fprintf(logfile, "%s",  "\nbill_master_i inserted");
}

//-- connections - interim bill
void connections::db_read_connections_for_interim_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_t
	{
		int		account_no;
		char	package_code[6];		// 6 instead of BUF_LEN // varchar2(5)
		char	current_status_date[BUF_LEN];
		char	tax_group_id[10];
		char	corporate_code[10];
		char	client_code[10];		// varchar2(8)
		char	vat_no[BUF_LEN];		//	varchar2(20)
		char	connection_status[BUF_LEN];
	} *a;

	struct connection_ind
	{ 
  		short	account_no_ind;
		short	package_code_ind;
		short	current_status_date_ind;
		short	tax_group_id_ind;
		short	corporate_code_ind;
		short	client_code_ind;
		short	vat_no_ind;
		short	connection_status_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	char ub_start_date[15];
	char ub_end_date[15];

/* EXEC SQL END DECLARE SECTION; */ 


/* EXEC ORACLE OPTION (char_map=string) ; */ 


	int i;
	strcpy(ub_start_date, start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	debug("ub_end_date :");
	debug(ub_end_date);
	cout << endl;
	connection_detail cd;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connection fetch"<<endl;
		exit(0);
	}
	    
	/* EXEC SQL 
	AT ISP 
	DECLARE  c_connection_i CURSOR FOR 
	SELECT	ACCOUNT_NO,				
			PACKAGE_CODE,		
			CURRENT_STATUS_DATE,					
			TAX_GROUP_ID,				
			CORPORATE_CODE,
			CLIENT_CODE,
			VAT_NO,
			CONNECTION_STATUS
	FROM	CONNECTIONS
	WHERE	TRUNC(COMMENCEMENT_DATE) <= to_date(:ub_end_date,'YYYYMMDD')
	AND 
	(	
		CONNECTION_STATUS ='CONNT' OR CONNECTION_STATUS ='TDISC' OR 
		(
			(
				TRUNC(CURRENT_STATUS_DATE) BETWEEN 
				to_date(:ub_start_date,'YYYYMMDD') 
				AND 
				to_date(:ub_end_date,'YYYYMMDD')
			)
			AND
			( CONNECTION_STATUS ='PDISC' )
		)
	); */ 
 
           
    /* EXEC SQL AT ISP  OPEN c_connection_i; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0052;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2545;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)ub_end_date;
    sqlstm.sqhstl[0] = (unsigned int  )15;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (         void  *)ub_start_date;
    sqlstm.sqhstl[1] = (unsigned int  )15;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         void  *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned int  )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (         void  *)ub_end_date;
    sqlstm.sqhstl[2] = (unsigned int  )15;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         void  *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned int  )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_connection_i INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2575;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->account_no;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->package_code;
  sqlstm.sqhstl[1] = (unsigned int  )6;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->package_code_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->current_status_date;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->current_status_date_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->tax_group_id;
  sqlstm.sqhstl[3] = (unsigned int  )10;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->tax_group_id_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->corporate_code;
  sqlstm.sqhstl[4] = (unsigned int  )10;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->corporate_code_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->client_code;
  sqlstm.sqhstl[5] = (unsigned int  )10;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->vat_no;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->vat_no_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->connection_status;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct connection_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->connection_status_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct connection_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0 : a[i].account_no ;
			strcpy(a[i].package_code,
				  ((a_ind[i].package_code_ind < 0) ? "UNDEF":a[i].package_code));
			strcpy(a[i].corporate_code,
				  ((a_ind[i].corporate_code_ind < 0) ? "UNDEF":a[i].corporate_code));
			strcpy(a[i].current_status_date,
				  ((a_ind[i].current_status_date_ind < 0) ? "20501225":a[i].current_status_date)); // 20501225 a far away date put for null entries
			strcpy(a[i].tax_group_id,
				  ((a_ind[i].tax_group_id_ind < 0) ? "UNDEF":a[i].tax_group_id));
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].vat_no,
				  ((a_ind[i].vat_no_ind < 0) ? "UNDEF":a[i].vat_no));
			strcpy(a[i].connection_status,
				  ((a_ind[i].connection_status_ind < 0) ? "UNDEF":a[i].connection_status));


			int posi = strcspn( a[i].client_code, " " );
			a[i].client_code[posi] = '\0';

			

			//assining values fetched from db to the connection_detail class
			cd.account_no		= a[i].account_no;					
			cd.package_code		= a[i].package_code;

			// cahnged on 16-09-2002
			a[i].current_status_date[8] = '\0';
			cd.current_status_date.set_date(a[i].current_status_date);	
			//cd.disconnected_date= a[i].disconnected_date;	
			// end - 16-09-2002
								
			cd.tax_group_id			= a[i].tax_group_id;						
			cd.corporate_code		= a[i].corporate_code;
			cd.client_code			= a[i].client_code;	
			cd.vat_no				= a[i].vat_no;	
			cd.connection_status	= a[i].connection_status;	
			

			CLIENTS_DEF::iterator i_current = gsm_connections->clients_map.find(a[i].client_code);
			
			if(i_current != gsm_connections->clients_map.end())
			{
				//cout <<"Client code matches >>>>>>>>>>>>>>>" << endl;

				if ( strcmp(gsm_bill_cycle->bill_cycle_code.c_str(), (*i_current).second.c_str())==0 )
				{
					//cout <<"Bill run code matches >>>>>>>>>>>>>>>" << endl;
					insert(a[i].account_no, cd);
					//print_detail();
				}
				else
				{
					//cout <<"Bill run code do not match >>>>>>>>>>>>>>>" << endl;
				}
			}
			else
			{
				//cout <<"Client code does not match >>>>>>>>>>>>>>>" << endl;
			}
		}
	} 


	/* EXEC SQL AT ISP CLOSE c_connection_i; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2625;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  connection records read.\n\n",rows_before);
} 

//-- bill_master for interim bill
void connections::db_read_bill_master_for_interim_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct bill_master_t
	{
			char	client_code[BUF_LEN];				
			int		account_no;		
			char	bill_no[BUF_LEN];					
			char	due_date[BUF_LEN];				
			char	bill_date[BUF_LEN];		
			char	bill_period_start[BUF_LEN];				
			char	bill_period_end[BUF_LEN];	
			float	balance_bf;		
			float	bill_amount;		
			float	balance_cf;		
			char	bill_run_code[BUF_LEN];
			float	bill_payments;
			int		run_no;
			char	printed[BUF_LEN];
	} *a;

	struct bill_master_ind
	{ 
  		short	client_code_ind;
		short	account_no_ind;
		short	bill_no_ind;
		short	due_date_ind;
		short	bill_date_ind;
		short	bill_period_start_ind;
		short	bill_period_end_ind;
		short	balance_bf_ind;
		short	bill_amount_ind;
		short	balance_cf_ind;
		short	bill_run_code_ind;
		short	bill_payments_ind;
		short	run_no_ind;
		short	printed_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	char  ub_start_date[10];		// date 			not null
	char  ub_end_date[10];			// date				not null
	

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(ub_start_date, start_date.c_str());
	strcpy(ub_end_date, end_date.c_str());
	bill_master bm;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new bill_master_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for bill_master fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_bill_master_i CURSOR FOR 
	SELECT	CLIENT_CODE,				
			ACCOUNT_NO,		
			BILL_NO,					
			DUE_DATE,				
			BILL_DATE,		
			BILL_PERIOD_START,				
			BILL_PERIOD_END,	
			BALANCE_BF,		
			BILL_AMOUNT,		
			BALANCE_CF,		
			BILL_RUN_CODE,
			BILL_PAYMENTS,
			RUN_NO,
			PRINTED
	FROM	BILL_MASTER
	WHERE	BILL_DATE IS NULL
	AND		BILL_PERIOD_START = to_date(:ub_start_date,'YYYYMMDD'); */ 
 
       
    /* EXEC SQL AT ISP  OPEN c_bill_master_i; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0053;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2643;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)ub_start_date;
    sqlstm.sqhstl[0] = (unsigned int  )10;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_bill_master_i INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2665;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->client_code;
  sqlstm.sqhstl[0] = (unsigned int  )50;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&a->account_no;
  sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->bill_no;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->bill_no_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->due_date;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->due_date_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->bill_date;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->bill_date_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->bill_period_start;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->bill_period_start_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->bill_period_end;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->bill_period_end_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->balance_bf;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->balance_bf_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)&a->bill_amount;
  sqlstm.sqhstl[8] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[8] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->bill_amount_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)&a->balance_cf;
  sqlstm.sqhstl[9] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[9] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->balance_cf_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->bill_run_code;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->bill_run_code_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)&a->bill_payments;
  sqlstm.sqhstl[11] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[11] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->bill_payments_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->run_no;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->run_no_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (         void  *)a->printed;
  sqlstm.sqhstl[13] = (unsigned int  )50;
  sqlstm.sqhsts[13] = (         int  )sizeof(struct bill_master_t);
  sqlstm.sqindv[13] = (         void  *)&a_ind->printed_ind;
  sqlstm.sqinds[13] = (         int  )sizeof(struct bill_master_ind);
  sqlstm.sqharm[13] = (unsigned int  )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no ;
			strcpy(a[i].bill_no,
				  ((a_ind[i].bill_no_ind < 0) ? "UNDEF":a[i].bill_no));
			strcpy(a[i].due_date,
				  ((a_ind[i].due_date_ind < 0) ? "UNDEF":a[i].due_date));
			strcpy(a[i].bill_date,
				  ((a_ind[i].bill_date_ind < 0) ? "UNDEF":a[i].bill_date));
			strcpy(a[i].bill_period_start,
				  ((a_ind[i].bill_period_start_ind < 0) ? "UNDEF":a[i].bill_period_start));
			strcpy(a[i].bill_period_end,
				  ((a_ind[i].bill_period_end_ind < 0) ? "UNDEF":a[i].bill_period_end));
			a[i].balance_bf = (a_ind[i].balance_bf_ind < 0) ? 0.0 : a[i].balance_bf;
			a[i].bill_amount = (a_ind[i].bill_amount_ind < 0) ? 0.0 : a[i].bill_amount;
			a[i].balance_cf = (a_ind[i].balance_cf_ind < 0) ? 0.0 : a[i].balance_cf ;
			strcpy(a[i].bill_run_code,
				  ((a_ind[i].bill_run_code_ind < 0) ? "UNDEF":a[i].bill_run_code));
			a[i].bill_payments = (a_ind[i].bill_payments_ind < 0) ? 0.0 : a[i].bill_payments;
			a[i].run_no = (a_ind[i].run_no_ind < 0) ? 0.0 : a[i].run_no;
			strcpy(a[i].printed,
				  ((a_ind[i].printed_ind < 0) ? "UNDEF":a[i].printed));
			

			
			if(set_current(a[i].account_no))
			{
				current->charge.payments += a[i].bill_payments; // payments during period
				current->charge.brought_forward = a[i].balance_bf;	
				current->connection.invoice_no = a[i].bill_no;
				current->charge.open_bill_found = 1;
			}
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_bill_master_i; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2739;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  bill_master records read.\n\n",rows_before);
} 

//-- clients - interim bill
void connections::db_read_clients_for_interim_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct client_t
	{
		char	br_code[10];			// varchar2(5)
		char	client_code[10];		// varchar2(8)
	} *a;

	struct client_ind
	{ 
  		short	br_code_ind;
		short	client_code_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	char	t_start_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date, start_date.c_str());
	
	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new client_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for client fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_client_i CURSOR FOR
	SELECT	BR_CODE,
			CLIENT_CODE		
	FROM	CLIENTS; */ 

       
    /* EXEC SQL AT ISP  OPEN c_client_i; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0054;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2757;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_client_i INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2775;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->br_code;
  sqlstm.sqhstl[0] = (unsigned int  )10;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct client_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->br_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct client_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->client_code;
  sqlstm.sqhstl[1] = (unsigned int  )10;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct client_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct client_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches
			
			strcpy(a[i].br_code,
				  ((a_ind[i].br_code_ind < 0) ? "UNDEF":a[i].br_code));
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));

			int posi = strcspn( a[i].client_code, " " );
			a[i].client_code[posi] = '\0';

			int position = strcspn( a[i].br_code, " " );
			a[i].br_code[position] = '\0';

			

			clients_map[a[i].client_code] = a[i].br_code;
			
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_client_i; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2801;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  clients records read.\n\n",rows_before);
} 


//-- rental_advance_payments - interim bill
void connections::db_read_rental_advance_payments_for_interim_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct rental_advance_payments_t
	{
			char	client_code[8];		// varchar2(8)			
			char	date_paid[BUF_LEN];			// date
			int		no_of_months_free;					
			int		no_of_months_paid;				
			int		account_no;		
			int		balance_months;				
	} *a;

	struct rental_advance_payments_ind
	{ 
  		short	client_code_ind;				
		short	date_paid_ind;		
		short	no_of_months_free_ind;					
		short	no_of_months_paid_ind;				
		short	account_no_ind;		
		short	balance_months_ind;				
	}a_ind[FETCH_SIZE];

	char t_start_date[20];
	int rows_to_fetch, rows_before, rows_this_time;
	char ub_end_date[15];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	strcpy(t_start_date,start_date.c_str());

	strcpy(ub_end_date, end_date.c_str());
	advance_payment	ap;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new rental_advance_payments_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for rental_advance_payments fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_rental_advance_payments_i CURSOR FOR
	SELECT	CLIENT_CODE,				
			DATE_PAID,
			NO_OF_MONTHS_FREE,		
			NO_OF_MONTHS_PAID,					
			ACCOUNT_NO,				
			BALANCE_MONTHS		
	FROM	RENTAL_ADVANCE_PAYMENTS
	WHERE	TRUNC(DATE_PAID) <= to_date(:ub_end_date,'YYYYMMDD')
	ORDER BY DATE_PAID DESC; */ 
 
       
    /* EXEC SQL AT ISP  OPEN c_rental_advance_payments_i; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0055;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2819;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (         void  *)ub_end_date;
    sqlstm.sqhstl[0] = (unsigned int  )15;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         void  *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned int  )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_rental_advance_payments_i INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2841;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->client_code;
  sqlstm.sqhstl[0] = (unsigned int  )8;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->date_paid;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->date_paid_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->no_of_months_free;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->no_of_months_free_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->no_of_months_paid;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->no_of_months_paid_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&a->account_no;
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&a->balance_months;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct rental_advance_payments_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->balance_months_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct rental_advance_payments_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].date_paid,
				  ((a_ind[i].date_paid_ind < 0) ? "UNDEF":a[i].date_paid));
			a[i].no_of_months_free = (a_ind[i].no_of_months_free_ind < 0) ? 0.0 : a[i].no_of_months_free;
			a[i].no_of_months_paid = (a_ind[i].no_of_months_paid_ind < 0) ? 0.0 : a[i].no_of_months_paid;
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no;
			a[i].balance_months = (a_ind[i].balance_months_ind < 0) ? 0.0 : a[i].balance_months;
			

			if (a[i].balance_months > 0)
			{
				ap.account_no		= a[i].account_no;
				ap.client_code		= a[i].client_code;						
				ap.date_paid		= a[i].date_paid;						
				ap.balance_months	= a[i].balance_months;
				
				gsm_connections->rental_advance_payments_map[a[i].account_no] = ap;
			}
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_rental_advance_payments_i; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2883;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  rental_advance_payments records read.\n\n",rows_before);
} 


//-- packages - interim bill
void package_map::db_read_packages_for_interim_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct packages_t
	{
			char	package_code[6];		// 6 instead of BUF_LEN				
			char	description[BUF_LEN];		
			float	rental;					
			char	free_applied_on[BUF_LEN];				
			int		free_in_bytes;		
			int		free_out_bytes;				
			int		free_minutes;	
			char	activated_on[BUF_LEN];		
			char	deactivated_on[BUF_LEN];
			char	package_type[BUF_LEN];
			int		free_units;				// number(10)		
	} *a;

	struct packages_ind
	{ 
  		short	package_code_ind;				
		short	description_ind;		
		short	rental_ind;					
		short	free_applied_on_ind;				
		short	free_in_bytes_ind;		
		short	free_out_bytes_ind;				
		short	free_minutes_ind;	
		short	activated_on_ind;		
		short	deactivated_on_ind;
		short	package_type_ind;
		short	free_units_ind;	
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;

	char	t_start_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(t_start_date,gsm_connections->start_date.c_str());
	
	int i;
	packages p;

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new packages_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for packages fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_packages_i CURSOR FOR
	SELECT	PACKAGE_CODE,				
			DESCRIPTION,
			RENTAL,		
			FREE_APPLIED_ON,					
			FREE_IN_BYTES,				
			FREE_OUT_BYTES,		
			FREE_MINUTES,				
			ACTIVATED_ON,	
			DEACTIVATED_ON,
			PACKAGE_TYPE,
			FREE_UNITS			
	FROM	PACKAGES
	WHERE PACKAGE_TYPE = 'O'; */ 

	       
    /* EXEC SQL AT ISP  OPEN c_packages_i; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0056;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2901;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_packages_i INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )2919;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)a->package_code;
  sqlstm.sqhstl[0] = (unsigned int  )6;
  sqlstm.sqhsts[0] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->package_code_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->description;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->description_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&a->rental;
  sqlstm.sqhstl[2] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[2] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->rental_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)a->free_applied_on;
  sqlstm.sqhstl[3] = (unsigned int  )50;
  sqlstm.sqhsts[3] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->free_applied_on_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)&a->free_in_bytes;
  sqlstm.sqhstl[4] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->free_in_bytes_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)&a->free_out_bytes;
  sqlstm.sqhstl[5] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->free_out_bytes_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)&a->free_minutes;
  sqlstm.sqhstl[6] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->free_minutes_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)a->activated_on;
  sqlstm.sqhstl[7] = (unsigned int  )50;
  sqlstm.sqhsts[7] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->activated_on_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->deactivated_on;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->deactivated_on_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->package_type;
  sqlstm.sqhstl[9] = (unsigned int  )50;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->package_type_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)&a->free_units;
  sqlstm.sqhstl[10] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )sizeof(struct packages_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->free_units_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct packages_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			strcpy(a[i].package_code,
				  ((a_ind[i].package_code_ind < 0) ? "UNDEF":a[i].package_code));
			strcpy(a[i].description,
				  ((a_ind[i].description_ind < 0) ? "UNDEF":a[i].description));
			a[i].rental = (a_ind[i].rental_ind < 0) ? 0.0 : a[i].rental ;
			strcpy(a[i].free_applied_on,
				  ((a_ind[i].free_applied_on_ind < 0) ? "UNDEF":a[i].free_applied_on));
			a[i].free_in_bytes = (a_ind[i].free_in_bytes_ind < 0) ? 0.0 : a[i].free_in_bytes ;
			a[i].free_out_bytes = (a_ind[i].free_out_bytes_ind < 0) ? 0.0 : a[i].free_out_bytes ;
			a[i].free_minutes = (a_ind[i].free_minutes_ind < 0) ? 0.0 : a[i].free_minutes ;
			strcpy(a[i].activated_on,
				  ((a_ind[i].activated_on_ind < 0) ? "UNDEF":a[i].activated_on));
			strcpy(a[i].deactivated_on,
				  ((a_ind[i].deactivated_on_ind < 0) ? "UNDEF":a[i].deactivated_on));
			strcpy(a[i].package_type,
				  ((a_ind[i].package_type_ind < 0) ? "UNDEF":a[i].package_type));
			a[i].free_units = (a_ind[i].free_units_ind < 0) ? 0.0 : a[i].free_units ;
			
			//assining values fetched from db to the packages class
			p.package_code			= a[i].package_code;				
			p.description			= a[i].description;		
			p.rental				= a[i].rental;					
			p.free_applied_on		= a[i].free_applied_on;				
			p.free_in_bytes			= a[i].free_in_bytes;		
			p.free_out_bytes		= a[i].free_out_bytes;				
			p.free_minutes			= a[i].free_minutes;	
			p.activated_on			= a[i].activated_on;		
			p.deactivated_on		= a[i].deactivated_on;
			p.package_type			= a[i].package_type;
			p.free_units			= a[i].free_units;	
			
			gsm_packages->all_packages[p.package_code] = p;
		}
	} 

	/* EXEC SQL AT ISP CLOSE c_packages_i; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )2981;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  packages records read.\n\n",rows_before);
} 

//-- connection_services - interim bill
void connection_services_multimap::db_read_connection_services_for_interim_bill()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	struct connection_services_t
	{
			float	rental;				
			char	start_date[BUF_LEN];		
			char	end_date[BUF_LEN];					
			int		account_no;				
			char	client_code[BUF_LEN];		
			char	service_code[BUF_LEN];				
			char	user_username[BUF_LEN];		
			int		service_instance;		
			char	connection_status[BUF_LEN];		
			char	attribution[BUF_LEN];
			char	rate_group_id[BUF_LEN];
			char	rental_actv_date[BUF_LEN];
			float	service_quota;
	} *a;

	struct connection_services_ind
	{ 
  		short	rental_ind;
		short	start_date_ind;
		short	end_date_ind;
		short	account_no_ind;
		short	client_code_ind;
		short	service_code_ind;
		short	user_username_ind;
		short	service_instance_ind;
		short	connection_status_ind;
		short	attribution_ind;
		short	rate_group_id_ind;
		short	rental_actv_date_ind;
		short	service_quota_ind;
	}a_ind[FETCH_SIZE];

	int rows_to_fetch, rows_before, rows_this_time;
	char t_start_date[20];
	char t_end_date[20];

/* EXEC SQL END DECLARE SECTION; */ 


	int i;
	connection_services cs;

	strcpy(t_start_date,gsm_connections->start_date.c_str());
	strcpy(t_end_date, gsm_connections->end_date.c_str());

	rows_to_fetch = FETCH_SIZE;		// number of rows in each "batch"  
	rows_before = 0;				   // previous value of sqlerrd[2]   
	rows_this_time = FETCH_SIZE; 

	if((a = new connection_services_t[rows_to_fetch])==NULL)
	{
		cout<<" cant allocate memeory for connection_services fetch"<<endl;
		exit(0);
	}

 
    /* EXEC SQL 
	AT ISP 
	DECLARE  c_connection_services_i CURSOR FOR 
	SELECT	RENTAL,				
			START_DATE,		
			END_DATE,					
			ACCOUNT_NO,				
			CLIENT_CODE,		
			SERVICE_CODE,				
			USER_USERNAME,		
			SERVICE_INSTANCE,		
			CONNECTION_STATUS,		
			ATTRIBUTION,
			RATE_GROUP_ID,
			RENTAL_ACTV_DATE,
			SERVICE_QUOTA
	FROM	CONNECTION_SERVICES; */ 

       
    /* EXEC SQL AT ISP  OPEN c_connection_services_i; */ 

{
    struct sqlexd sqlstm;
    sqlorat((void **)0, &sqlctx, &oraca);
    sqlstm.sqlvsn = 10;
    sqlstm.arrsiz = 20;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0057;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )2999;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)256;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	/* EXEC SQL WHENEVER NOT FOUND CONTINUE; */ 
 

	while (rows_this_time == rows_to_fetch) 
	{ 
		/* EXEC SQL AT ISP FOR :rows_to_fetch FETCH c_connection_services_i INTO :a INDICATOR :a_ind; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )rows_to_fetch;
  sqlstm.offset = (unsigned int  )3017;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)&a->rental;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[0] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[0] = (         void  *)&a_ind->rental_ind;
  sqlstm.sqinds[0] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)a->start_date;
  sqlstm.sqhstl[1] = (unsigned int  )50;
  sqlstm.sqhsts[1] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[1] = (         void  *)&a_ind->start_date_ind;
  sqlstm.sqinds[1] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)a->end_date;
  sqlstm.sqhstl[2] = (unsigned int  )50;
  sqlstm.sqhsts[2] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[2] = (         void  *)&a_ind->end_date_ind;
  sqlstm.sqinds[2] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)&a->account_no;
  sqlstm.sqhstl[3] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[3] = (         void  *)&a_ind->account_no_ind;
  sqlstm.sqinds[3] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (         void  *)a->client_code;
  sqlstm.sqhstl[4] = (unsigned int  )50;
  sqlstm.sqhsts[4] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[4] = (         void  *)&a_ind->client_code_ind;
  sqlstm.sqinds[4] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[4] = (unsigned int  )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (         void  *)a->service_code;
  sqlstm.sqhstl[5] = (unsigned int  )50;
  sqlstm.sqhsts[5] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[5] = (         void  *)&a_ind->service_code_ind;
  sqlstm.sqinds[5] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[5] = (unsigned int  )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (         void  *)a->user_username;
  sqlstm.sqhstl[6] = (unsigned int  )50;
  sqlstm.sqhsts[6] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[6] = (         void  *)&a_ind->user_username_ind;
  sqlstm.sqinds[6] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[6] = (unsigned int  )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (         void  *)&a->service_instance;
  sqlstm.sqhstl[7] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[7] = (         void  *)&a_ind->service_instance_ind;
  sqlstm.sqinds[7] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[7] = (unsigned int  )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (         void  *)a->connection_status;
  sqlstm.sqhstl[8] = (unsigned int  )50;
  sqlstm.sqhsts[8] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[8] = (         void  *)&a_ind->connection_status_ind;
  sqlstm.sqinds[8] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[8] = (unsigned int  )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (         void  *)a->attribution;
  sqlstm.sqhstl[9] = (unsigned int  )50;
  sqlstm.sqhsts[9] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[9] = (         void  *)&a_ind->attribution_ind;
  sqlstm.sqinds[9] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[9] = (unsigned int  )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (         void  *)a->rate_group_id;
  sqlstm.sqhstl[10] = (unsigned int  )50;
  sqlstm.sqhsts[10] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[10] = (         void  *)&a_ind->rate_group_id_ind;
  sqlstm.sqinds[10] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[10] = (unsigned int  )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (         void  *)a->rental_actv_date;
  sqlstm.sqhstl[11] = (unsigned int  )50;
  sqlstm.sqhsts[11] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[11] = (         void  *)&a_ind->rental_actv_date_ind;
  sqlstm.sqinds[11] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[11] = (unsigned int  )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (         void  *)&a->service_quota;
  sqlstm.sqhstl[12] = (unsigned int  )sizeof(float);
  sqlstm.sqhsts[12] = (         int  )sizeof(struct connection_services_t);
  sqlstm.sqindv[12] = (         void  *)&a_ind->service_quota_ind;
  sqlstm.sqinds[12] = (         int  )sizeof(struct connection_services_ind);
  sqlstm.sqharm[12] = (unsigned int  )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 		 

		rows_this_time = sqlca.sqlerrd[2] - rows_before; 
		rows_before = sqlca.sqlerrd[2]; 
		//printf(" this=%d before=%d \n", rows_this_time, rows_before);

		for(i=0; i<rows_this_time; i++)
		{
			//handling null fetches

			a[i].rental = (a_ind[i].rental_ind < 0) ? 0.0 : a[i].rental ;
			strcpy(a[i].start_date,
				  ((a_ind[i].start_date_ind < 0) ? "UNDEF":a[i].start_date));
			strcpy(a[i].end_date,
				  ((a_ind[i].end_date_ind < 0) ? "UNDEF":a[i].end_date));
			a[i].account_no = (a_ind[i].account_no_ind < 0) ? 0.0 : a[i].account_no ;
			strcpy(a[i].client_code,
				  ((a_ind[i].client_code_ind < 0) ? "UNDEF":a[i].client_code));
			strcpy(a[i].service_code,
				  ((a_ind[i].service_code_ind < 0) ? "UNDEF":a[i].service_code));
			strcpy(a[i].user_username,
				  ((a_ind[i].user_username_ind < 0) ? "UNDEF":a[i].user_username));
			a[i].service_instance = (a_ind[i].service_instance_ind < 0) ? 0.0 : a[i].service_instance ;
			strcpy(a[i].connection_status,
				  ((a_ind[i].connection_status_ind < 0) ? "UNDEF":a[i].connection_status));
			strcpy(a[i].attribution,
				  ((a_ind[i].attribution_ind < 0) ? "UNDEF":a[i].attribution));
			strcpy(a[i].rate_group_id,
				  ((a_ind[i].rate_group_id_ind < 0) ? "UNDEF":a[i].rate_group_id));
			strcpy(a[i].rental_actv_date,
				  ((a_ind[i].rental_actv_date_ind < 0) ? "UNDEF":a[i].rental_actv_date));
				a[i].service_quota = (a_ind[i].service_quota_ind < 0) ? 0.0 : a[i].service_quota ;

			
			//assining values fetched from db to the connection_detail class
			cs.rental			= a[i].rental;				
			cs.start_date		= a[i].start_date;		
			cs.end_date			= a[i].end_date;					
			cs.account_no		= a[i].account_no;				
			cs.client_code		= a[i].client_code;		
			cs.service_code		= a[i].service_code;				
			cs.user_username	= a[i].user_username;		
			cs.service_instance	= a[i].service_instance;		
			cs.connection_status= a[i].connection_status;		
			cs.attribution		= a[i].attribution;
			cs.rate_group_id	= a[i].rate_group_id;
			cs.rental_actv_date	= a[i].rental_actv_date;
			cs.service_quota	= a[i].service_quota;

			gsm_connection_services->insert(cs.account_no, cs);

		}
	} 

	/* EXEC SQL AT ISP CLOSE c_connection_services_i; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3087;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}

 
	delete a;
	printf("%d  connection_services records read.\n\n",rows_before);
}  

// billrun_definitions - ibill

void connections::db_read_billrun_definitions_for_interim_bill()
{

	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	 char	br_br_code[10];			//	VARCHAR2(5)		
	 int	br_start_day;				//	NUMBER(2)
	 int	br_bill_grace_period;		//	NUMBER(3)
	 char	br_system_date[20];
	 char	br_temp_date[20];
	 char	br_start_date[20];
	 char	br_end_date[20];
	 char	br_due_date[20];
	 char	bill_cycle_code[6];			
			 
	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy(bill_cycle_code, gsm_bill_cycle->bill_cycle_code.c_str());

	/* EXEC SQL WHENEVER NOT FOUND DO not_found_error("No relevant entry in billrun_definitions"); */ 
 

	/* EXEC SQL 
	AT ISP 
	SELECT	BR_CODE, START_DAY, BILL_GRACE_PERIOD 
	INTO	:br_br_code, 
			:br_start_day, 
			:br_bill_grace_period
	FROM	BILLRUN_DEFINITIONS
	WHERE BR_CODE = :bill_cycle_code
	AND ACTIVE = 'Y'; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select BR_CODE ,START_DAY ,BILL_GRACE_PERIOD into :b0,:b1,:b\
2  from BILLRUN_DEFINITIONS where (BR_CODE=:b3 and ACTIVE='Y')";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3105;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_br_code;
 sqlstm.sqhstl[0] = (unsigned int  )10;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&br_start_day;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&br_bill_grace_period;
 sqlstm.sqhstl[2] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)bill_cycle_code;
 sqlstm.sqhstl[3] = (unsigned int  )6;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	br_br_code[strcspn( br_br_code, " " )] = '\0';

	br_code = br_br_code;
	start_day = br_start_day;
	bill_grace_period = br_bill_grace_period;

	cout << "billrun_definitions  read." << endl;
	cout << "br_code : " << br_code ;
	//cout << "start_day : " << start_day << endl;
	//cout << "bill_grace_period : " << bill_grace_period << endl;
	
     
	/* EXEC SQL 
	AT ISP 
	SELECT	to_char(sysdate,'YYYYMMDD')
	INTO	:br_system_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(sysdate,'YYYYMMDD') into :b0  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3139;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_system_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	//cout << "Sysdate : " << br_system_date << endl;

	char sysday[2];

	sysday[0]	= br_system_date[6];
	sysday[1]	= br_system_date[7];
	sysday[2]	= '\0';

	//cout << "sysday :" << sysday <<"END" << endl;

	int IntSysday = atoi(sysday);

	//cout << "IntSysday :" << IntSysday <<"END" << endl;


	char buf[30];
	char day[2];
	
	strncpy(buf, br_system_date, 6);
	
	if (start_day >9)
	{
		myitoa(start_day, day);
		strncpy( buf + 6, day, 2 );
	}
	else
	{
		char pad[1];
		pad[0] = '0';
		strncpy( buf + 6, pad, 1 );
		myitoa(start_day, day);
		strncpy( buf + 7, day, 1 );
	}

	buf[8] = '\0'; 
	
	//cout << "buf : " << buf;

	strcpy(br_temp_date, buf);

	br_temp_date[8] = '\0'; 

	//cout << "br_temp_date  : " << br_temp_date ;

	if (IntSysday >= br_start_day)
	{
		/* EXEC SQL 
		AT ISP 
		SELECT	to_char((ADD_MONTHS(to_date(:br_temp_date,'YYYYMMDD'),-1)),'YYYYMMDD')
		INTO	:br_start_date
		FROM	DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char(ADD_MONTHS(to_date(:b0,'YYYYMMDD'),(-1)),'YY\
YYMMDD') into :b1  from DUAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3161;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)br_temp_date;
  sqlstm.sqhstl[0] = (unsigned int  )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)br_start_date;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



		//cout <<"up"<<endl;
	}
	else
	{
		/* EXEC SQL 
		AT ISP 
		SELECT	to_char((ADD_MONTHS(to_date(:br_temp_date,'YYYYMMDD'),-2)),'YYYYMMDD')
		INTO	:br_start_date
		FROM	DUAL; */ 

{
  struct sqlexd sqlstm;
  sqlorat((void **)0, &sqlctx, &oraca);
  sqlstm.sqlvsn = 10;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char(ADD_MONTHS(to_date(:b0,'YYYYMMDD'),(-2)),'YY\
YYMMDD') into :b1  from DUAL ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )3187;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)256;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)br_temp_date;
  sqlstm.sqhstl[0] = (unsigned int  )20;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)br_start_date;
  sqlstm.sqhstl[1] = (unsigned int  )20;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
  if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



		//cout <<"down"<<endl;
	}

	br_start_date[8] = '\0'; 

	//cout << "br_start_date  : " << br_start_date ;

	/* EXEC SQL 
	AT ISP 
	//SELECT	to_char((ADD_MONTHS(to_date(:br_start_date,'YYYYMMDD'),1)-1),'YYYYMMDD') //For Month End billing
	SELECT	to_char(ADD_MONTHS(to_date(:br_start_date,'YYYYMMDD'),1),'YYYYMMDD')  // For Interim Billing
	INTO	:br_end_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char(ADD_MONTHS(to_date(:b0,'YYYYMMDD'),1),'YYYYMM\
DD') into :b1  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3213;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_start_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)br_end_date;
 sqlstm.sqhstl[1] = (unsigned int  )20;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	br_end_date[8] = '\0'; 

	//cout << "End date : " << br_end_date ;

	/* EXEC SQL 
	AT ISP 
	SELECT	to_char((to_date(:br_end_date ,'YYYYMMDD')+:br_bill_grace_period),'YYYYMMDD')
	INTO	:br_due_date
	FROM	DUAL; */ 

{
 struct sqlexd sqlstm;
 sqlorat((void **)0, &sqlctx, &oraca);
 sqlstm.sqlvsn = 10;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select to_char((to_date(:b0,'YYYYMMDD')+:b1),'YYYYMMDD') int\
o :b2  from DUAL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )3239;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)256;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)br_end_date;
 sqlstm.sqhstl[0] = (unsigned int  )20;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&br_bill_grace_period;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)br_due_date;
 sqlstm.sqhstl[2] = (unsigned int  )20;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode == 1403) not_found_error("No relevant entry in billrun_definitions");
 if (sqlca.sqlcode < 0) sql_error("ORACLE error--");
}



	br_due_date[8] = '\0'; 

	//cout << "Due date : " << br_due_date ;

	// Dates hardcode start - hack
	/*
	strcpy(br_start_date,"20011201");
    br_start_date[8] = '\0'; 
    strcpy(br_end_date,"20011231");
    br_end_date[8] = '\0'; 
    strcpy(br_due_date,"20020115");
    br_due_date[8] = '\0';
	*/

	// Dates hardcode end - hack 

	//For Interim Bill
	gsm_connections->start_date = br_end_date;
	gsm_connections->end_date = br_system_date;
	
	gsm_connections->due_date = br_due_date;
	gsm_connections->sys_date = br_system_date;

	// Added on 16-09-2002
	reng_start_date.set_date(br_start_date);
	reng_end_date.set_date(br_end_date); 
	reng_sys_date.set_date(br_system_date);
	// end - 16-09-2002
	  
}