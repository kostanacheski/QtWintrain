/*2. Напиши програм кој чита датум во обликот 14/06/2005 и враќа датум во обликот 14 juni 2005. 
Корисникот да има можност да внесува колку што сака датуми кои треба да бидат конвертирани во другиот излез.
*/
#include <stdio.h>
#include <string.h>

int main(){
char date[20];
char *tokenPtr;
printf("Vnesi datum vo oblik dd/mm/year: \n");
gets(date);
char day[3]={0};
char month[3]={0};
char year[5]={0};
tokenPtr=strtok(date,"/");
if(tokenPtr!= NULL){
    strncat(day,tokenPtr,sizeof day-1);

}
tokenPtr=strtok(NULL,"/");
if(tokenPtr !=NULL){
    strncat(month,tokenPtr,sizeof month-1);
}
tokenPtr=strtok(NULL,"/");
if(tokenPtr!= NULL){
    strncat(year,tokenPtr,sizeof year-1);
}
puts(day);
puts(month);
puts(year);

int m;
m=atoi(month);

switch (m)
{
case 1:
printf("%s januari %s",day,year);
    break;
case 2:
printf("%s fevruari %s",day,year);
    break;
case 3:
printf("%s mart %s",day,year);
    break;    
    case 4:
printf("%s april %s",day,year);
    break;
case 5:
printf("%s maj %s",day,year);
    break;    
    case 6:
printf("%s juni %s",day,year);
    break;
    case 7:
printf("%s juli %s",day,year);
    break;
    case 8:
printf("%s avgust %s",day,year);
    break;
    case 9:
printf("%s septemvri %s",day,year);
    break;
    case 10:
printf("%s oktomvri %s",day,year);
    break;
    case 11:
printf("%s noemvri %s",day,year);
    break;
    case 12:
printf("%s dekemvri %s",day,year);
    break;
default:
    break;
}
    return 0;
}