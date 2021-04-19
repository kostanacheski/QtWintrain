/*2.	Напиши програма која внесува елементи со функцијата vnesi несортирано, на крајот на листата, 
ја користи функцијата sortOpagjanje која сортира елементи во опаѓачки редослед, 
функцијата sortRastenje која ги сортира елемнтите во растечки редослед, brisi која брише елемент со дадена содржина. 
Елементите на листата се целобројни елементи.
*/

#include <stdio.h>
#include <stdlib.h>


struct listNode {            
   int data; 
   struct listNode *nextPtr; 
}; 

typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 

void vnesi( ListNodePtr *sPtr,int value );//sortRastenje
void printList( ListNodePtr currentPtr );
int brisi( ListNodePtr *sPtr,int value );
int isEmpty( ListNodePtr sPtr );
void instructions( void );
//void sortRastenje(ListNodePtr sPtr);
void sortOpagjanje(ListNodePtr *sPtr,int value);
int main(){
ListNodePtr startPtr = NULL;
  int broj;
int choice; 
 instructions(); 
   printf( "? " );
   scanf( "%d", &choice );

   while ( choice != 5 ) { 

      switch ( choice ) { 

         case 1:
            printf( "Vnesi broj: " );
            scanf( "\n%d",&broj);
            vnesi( &startPtr,broj);
            printList( startPtr );
            break;

         case 2:

           
            if ( !isEmpty( startPtr ) ) { 
               printf( "Vnesi broj za brishenje: " );
               scanf( "\n%d%c",&broj);

               
               if ( brisi( &startPtr,broj) ) { 
                  printf( "%d deleted.\n",broj );
                  printList( startPtr );
               } 
               else {
                  printf( "%d ne e vo listata.\n\n", broj);
               } 

            } 
            else {
               printf( "Listata e prazna.\n\n" );
            } 

            break;
        case 3:
        printf("Vnesi broj: ");
        scanf("\n%d",&broj);
        sortOpagjanje(&startPtr,broj);
        printList(startPtr);

        break;
         default:
            printf( "Greshen izbor.\n\n" );
            instructions();
            break;
      
      } 

      printf( "? " );
      scanf( "%d", &choice );
   } 

   printf( "Kraj.\n" );

           
    return 0;
}

void vnesi( ListNodePtr *sPtr,int value )
{ 
   ListNodePtr newPtr;      
   ListNodePtr previousPtr; 
   ListNodePtr currentPtr;  

   newPtr = malloc( sizeof( ListNode ) ); 

   if ( newPtr != NULL ) { 
      newPtr->data = value; 
      newPtr->nextPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while ( currentPtr != NULL && value > currentPtr->data ) { 
         previousPtr = currentPtr;         
         currentPtr = currentPtr->nextPtr;  
      } 

     
      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } 
      else { 
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } 
   
   } 
   else {
      printf( "%c ne e vnesen. Nema dovolno memorija.\n", value );
   } 

} 

void printList( ListNodePtr currentPtr )
{ 

  
   if ( currentPtr == NULL ) {
      printf( "Listata e prazna.\n\n" );
   } 
   else { 
      printf( "Listata e:\n" );

      
      while ( currentPtr != NULL ) { 
         printf( "%d --> ", currentPtr->data );
         currentPtr = currentPtr->nextPtr;   
      } 

      printf( "NULL\n\n" );
   } 

} 

int brisi( ListNodePtr *sPtr,int value )
{ 
   ListNodePtr previousPtr; 
   ListNodePtr currentPtr;  
   ListNodePtr tempPtr;     

   
   if ( value == ( *sPtr )->data) { 
      tempPtr = *sPtr; 
      *sPtr = ( *sPtr )->nextPtr; 
      free( tempPtr ); 
      return value;
   } 
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      
      while ( currentPtr != NULL && currentPtr->data != value ) { 
         previousPtr = currentPtr;        
         currentPtr = currentPtr->nextPtr;   
      } 

      
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return value;
      } 
     
   } 

   return '\0';

} 


int isEmpty( ListNodePtr sPtr )
{ 
   return sPtr == NULL;

} 

void instructions( void )
{ 
   printf( "Vnesi izbor:\n"
      "   1 za vnesuvanje element vo rastechka lista.\n"
      "   2 za brishenje element od lista.\n"
      "   3 za vnesuvanje na elementite vo opagjachki redosled.\n"
      "    4 za Kraj.\n" );
} 
/*
void sortRastenje(ListNodePtr sPtr){
    ListNodePtr sortedPtr=NULL;
    ListNodePtr tempPtr=NULL;
    int tempvalue;
    sortedPtr=sPtr;

    while (sortedPtr != NULL)
    {
        tempPtr=sortedPtr;
        while (tempPtr->nextPtr != NULL)
        {
            if(tempPtr->data> tempPtr->nextPtr->data){
                tempvalue=tempPtr->data;
                tempPtr->data=tempPtr->nextPtr->data;
                tempPtr->nextPtr->data=tempvalue;
            }
            tempPtr=tempPtr->nextPtr;
        }
        sortedPtr=sortedPtr->nextPtr;
    }
    
}
*/
void sortOpagjanje(ListNodePtr *sPtr,int value){
     ListNodePtr newPtr;      
   ListNodePtr previousPtr; 
   ListNodePtr currentPtr;  

   newPtr = malloc( sizeof( ListNode ) ); 

   if ( newPtr != NULL ) { 
      newPtr->data = value; 
      newPtr->nextPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while ( currentPtr != NULL && value < currentPtr->data ) { 
         previousPtr = currentPtr;         
         currentPtr = currentPtr->nextPtr;  
      } 

     
      if ( previousPtr == NULL ) { 
         newPtr->nextPtr = *sPtr;
         *sPtr = newPtr;
      } 
      else { 
         previousPtr->nextPtr = newPtr;
         newPtr->nextPtr = currentPtr;
      } 
   
   } 
   else {
      printf( "%c ne e vnesen. Nema dovolno memorija.\n", value );
   } 

    
}