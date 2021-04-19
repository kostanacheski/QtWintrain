/* 1.	Напиши програм кој внесува линија текст и користи стек за да се испечати текстот во обратен дерослед. 
Текстот да содржи и празни места.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top=-1;
int item;
char stack_stiring[MAX];

void push(char item);
char pop(void);
int isEmpty(void);
int isFull(void);

int main(){
char str[MAX];
int i;

printf("Vnesi linija tekst: ");
scanf("%[^\n]s",str);

for(i=0;i<strlen(str);i++){
    push(str[i]);
}
for(i=0;i<strlen(str);i++){
    str[i]=pop();
}
printf("Tekstot prevrten e : %s \n",str);
return 0;
}

void push(char item){
    if(isFull()){
        printf("\nStekot e poln\n");
        return;
    }
    top=top+1;
    stack_stiring[top]=item;
}
char pop(){

    if(isEmpty()){
        printf("\nStekot e prazen.\n");
        return 0;
    }
    item =stack_stiring[top];
    top=top-1;
    return item;
}
int isEmpty()
{
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}