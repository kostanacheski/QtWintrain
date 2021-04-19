/*1.	Напиши функција pecatiListaNanazad која рекурзивно ги печати елементите од листа наназад.
 Елементите на листата се состојат од едно целоборјно поле broj и еден карактер кој се вика karakter. */

 #include <stdio.h>
#include <stdlib.h>

struct listNode {    
    int number;        
   char data; 
   struct listNode *nextPtr; 
}; 

typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 


void insert( ListNodePtr *sPtr,int number,char value );
char delete( ListNodePtr *sPtr,int number, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions( void );
void pecatiListaNanazad(ListNodePtr sPtr);

int main()
{ 
   ListNodePtr startPtr = NULL; 
   int choice; 
   int broj;
   char karakter;  

   instructions(); 
   printf( "? " );
   scanf( "%d", &choice );

  
   while ( choice != 4 ) { 

      switch ( choice ) { 

         case 1:
            printf( "Vnesi broj i  karakter: " );
            scanf( "\n%d%c",&broj, &karakter );
            insert( &startPtr,broj, karakter );
            printList( startPtr );
            break;

         case 2:

           
            if ( !isEmpty( startPtr ) ) { 
               printf( "Vnesi broj i karakter za brishenje: " );
               scanf( "\n%d%c",&broj, &karakter );

               
               if ( delete( &startPtr,broj, karakter ) ) { 
                  printf( "%c deleted.\n", karakter );
                  printList( startPtr );
               } 
               else {
                  printf( "%c ne e vo listata.\n\n", karakter);
               } 

            } 
            else {
               printf( "Listata e prazna.\n\n" );
            } 

            break;
        case 3:
        pecatiListaNanazad(startPtr);
        printf("\n");
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


void instructions( void )
{ 
   printf( "Vnesi izbor:\n"
      "   1 za vnesuvanje element vo lista.\n"
      "   2 za brishenje element od lista.\n"
      "   3 za Pechatenje nanazad.\n"
      "    4 za Kraj.\n" );
} 


void insert( ListNodePtr *sPtr,int number, char value )
{ 
   ListNodePtr newPtr;      
   ListNodePtr previousPtr; 
   ListNodePtr currentPtr;  

   newPtr = malloc( sizeof( ListNode ) ); 

   if ( newPtr != NULL ) { 
       newPtr->number=number;
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

char delete( ListNodePtr *sPtr,int number, char value )
{ 
   ListNodePtr previousPtr; 
   ListNodePtr currentPtr;  
   ListNodePtr tempPtr;     

   
   if ( value == ( *sPtr )->data && number==(*sPtr)->number) { 
      tempPtr = *sPtr; 
      *sPtr = ( *sPtr )->nextPtr; 
      free( tempPtr ); 
      return value;
   } 
   else { 
      previousPtr = *sPtr;
      currentPtr = ( *sPtr )->nextPtr;

      
      while ( currentPtr != NULL && currentPtr->data != value && currentPtr->number!=number ) { 
         previousPtr = currentPtr;        
         currentPtr = currentPtr->nextPtr;   
      } 

      
      if ( currentPtr != NULL ) { 
         tempPtr = currentPtr;
         previousPtr->nextPtr = currentPtr->nextPtr;
         free( tempPtr );
         return number,value;
      } 
     
   } 

   return '\0';

} 


int isEmpty( ListNodePtr sPtr )
{ 
   return sPtr == NULL;

} 


void printList( ListNodePtr currentPtr )
{ 

  
   if ( currentPtr == NULL ) {
      printf( "Listata e prazna.\n\n" );
   } 
   else { 
      printf( "Listata e:\n" );

      
      while ( currentPtr != NULL ) { 
         printf( "%d%c --> ",currentPtr->number, currentPtr->data );
         currentPtr = currentPtr->nextPtr;   
      } 

      printf( "NULL\n\n" );
   } 

} 
void pecatiListaNanazad(ListNodePtr sPtr){
    if(sPtr == NULL){
       printf("NULL\n\n");
    return;
    }
   pecatiListaNanazad(sPtr->nextPtr);
   printf("%d%c --> ",sPtr->number,sPtr->data);

}