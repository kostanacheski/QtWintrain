/* 
3. Да се открие и опише што работи следниот програм?
*/
/* Program vezba11_01.c
   Shto raboti sledniot program?*/
#include <stdio.h>
// int misterija( unsigned bitovi );
unsigned int misterija( unsigned int bitovi ); 
 
int main()
{ 
   unsigned x; 
   printf( "Vnesi cel broj: " );
   scanf( "%u", &x );
   printf( "Rezultatot e %d\n", misterija( x ) );
   return 0; 
} 
 //int misterija( unsigned bitovi ){}
unsigned int misterija( unsigned bitovi )
{ 
   unsigned i;              
   unsigned maska = 1 << 31; 
   unsigned total = 0;      
 
   for ( i = 1; i <= 32; i++, bitovi <<= 1 ) {
      if ( ( bitovi & maska ) == maska ) { 
         total++;
      } 
   } 
   return !( total % 2 ) ? 1 : 0;
} 
