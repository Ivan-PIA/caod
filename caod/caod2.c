#include <stdio.h> //программа выдает список людей , вы говорите под каким номером он находится, она выдает вам его возраст

#include <stdlib.h>
			
			
#define N 5

struct base {

char *name;

char *lastname;

int age;

};

void list (struct base *);

void ages (struct base base_1[N]);

void main () {

struct base base_1[N]= {

"Ivan", "Popovich", 19,

"Oleg", "Sokolov", 35,

"Polina", "Romanova", 18 ,

"Ibragim", "Donirov", 23 ,

"Big", "Guy", 13

};

list(base_1);

ages(base_1);


//free(base_1);
}

void list (struct base *pbase) {

int i;

for (i=0; i < N; i++, pbase++)

printf("%2d) %s %s\n", i+1, pbase->name, pbase->lastname);

}

void ages (struct base base_1[N]) {

int i,j ;

printf("Введите номер человека у которого хотите узнать возраст: ");

scanf("%d", &i);
for (j=0; j < N; j++ ){
if (i==1){
printf("Возраст: ");
printf("%d",base_1[j].age);
break;}

if (i==2){
printf("Возраст: ");
printf("%d",base_1[j+1].age);
break;}
if (i==3){
printf("Возраст: ");
printf("%d ",base_1[j+2].age);
break;}

if (i==4){
printf("Возраст: ");
printf("%d",base_1[j+3].age);
break;}
if (i==5){
printf("Возраст: ");
printf("%d",base_1[j+4].age);
break;}

}

}
