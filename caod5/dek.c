#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define N 5 //размер дека

typedef struct Deque
{
int data[N]; //массив данных
int last; //указатель на конец
}Deque;


void Creation(Deque *D) //создание дека
{ D->last=0; }
bool Full(Deque *D) {
if (D->last==0) 
    return true;
else 
    return false;
}


void AddL(Deque *D) //добавление элемента в начало
{
if (D->last==N){
    printf("\nДек заполнен\n\n");
    return; 
    }
int value;
printf("\nЗначение > "); 
scanf("%d",&value);

for (int i=D->last; i>0; i--)
D->data[i]=D->data[i-1];
D->data[0]=value;
D->last++;
printf("\nЭлемент добавлен\n\n");
}



void AddR(Deque *D) //добавление элемента в конец
{
if (D->last==N){
    printf("\nДек заполнен\n\n");
    return; 
}
int value;
printf("\nЗначение > ");
scanf("%d",&value);

D->data[D->last++]=value;
printf("\nЭлемент добавлен\n\n");
}


void DeleteL(Deque *D) //удаление первого элемента
{
for (int i=0; i<D->last; i++) //смещение элементов
D->data[i]=D->data[i+1]; D->last--;
}





	

int main() //главная функция
{

Deque D;
Creation(&D);
char number;
do
{
printf("1. Добавить элемент в начало\n");
printf("2. Добавить элемент в конец\n");
printf("3. Удалить первый элемент\n");


printf("0. Выйти\n");
printf("Номер команды > "); 

scanf("%s",&number);
switch (number)
{
case '1': AddL(&D);
break;
//-----------------------------------------------
case '2': AddR(&D);
break;
//-----------------------------------------------
case '3':
if (Full(&D)) printf("Дек пуст\n\n");
else
{
DeleteL(&D);
printf("Элемент удален из дека\n\n");
} break;

case '0': break;
default: printf("Команда не определена\n\n");
break;
}

}
 while(number!='0');
system("pause");

}