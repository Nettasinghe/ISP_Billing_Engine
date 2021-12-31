

/////////////////////////////////////////////////////////////////////
//
// functions.h: utility functions implementation.
// ISP Billing Engine
// developer - Chandika Nettasinghe
// development - 2000 September
//
//////////////////////////////////////////////////////////////////////


#ifndef FUNCTIONS
#define	FUNCTIONS

#pragma warning(disable:4786)


void reverse(char s[])
{
        int c, i, j;

        for (i=0, j=strlen(s)-1; i<j; i++, j--)
        {
                c = s[i];
                s[i] = s[j];
                s[j] = c;
        }
}

void myitoa(int n, char s[])
{
        int i, sign;
 
        if ((sign = n) < 0)
        n = -n;
 
        i = 0;
        do
        {
                s[i++] = n % 10 + '0';
        }
        while
        ((n /= 10) > 0);
 
        if (sign<0)
        s[i++] = '-';
        s[i] = '\0';
        reverse(s);
}

#endif