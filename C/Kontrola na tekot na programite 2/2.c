/*2.      Програмот p05_03.c преработи 
го така да колонската репрезентација на вредностите на депозитот за секоја година биде порамнет одлево.*/

/* Program p05_03.c
   Presmetuvanje kamata */
#include <stdio.h>
#include <math.h>  
 
/* zapochnuva izvrshuvanjeto na programot */
int main()
{
   double amount;             /* vrednost na depozitot */
   double principal = 1000.0; /* pochetna suma */
   double rate = .05;         /* godishna kamatna stapka */
   int year;                  /* brojach na godini */
 
   /* Ispechati zaglavie na tabelata */
   printf( "%4s%13s\n","Vrednost na depozitot","Godina" );
 
   /* presmetaj ja vrednosta na depozitot za sekoja od desette godini */
   for ( year = 1; year <= 10; year++ ) {
 
      /* presmetaj ja novata vrednost za tekovnata godina */
      amount = principal * pow( 1.0 + rate, year );
 
      /* ispecati nov red vo tabelata */
      printf( "%.2f%25d\n", amount,year );   
   } /* kraj for */
 
   return 0; /* programot zavrshil uspeshno */
 
} /* kraj na main */
