#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20 


typedef struct table{
    struct table *next;
    char *str;

}table;

//Хеш-функция

int hash(char *str){
    int  kod ;
    kod=str[0]+str[1];
    
    return kod;
}
//Рехеширование
int rehash(char *str, int N){
    int kod;
    kod=str[0]+str[1];
    
    if(rand() % 2 == 0)
        kod += rand()% (200 - kod);
    else
        kod -= rand() % kod;
    return kod;
}



//Генерация случайных слов для записывания напрямую в таблицу, от 4 to 20 
char *gener_str(){
    int N = rand() % (MAX- 4) + 4 , i;
    char *str = (char*)malloc(sizeof(char) * N);
    for(i = 0; i < N-1; ++i){
        str[i] = rand() % 26 + 65;
       
    }
    str[i] = '\0';
    return str;
}
//Печать данных
void print_mass(table *mass[], int N){
    int i;
    for(i = 0; i < N; ++i){
        if(mass[i]->str != NULL)
            printf("%d - %s\n", i, mass[i]->str);
    }
}



//Печать данных c коллизиями
void mass_kollise(table *mass[], int N){
    int i;
    table *ptr = NULL;
    int k1 = 0, k2 = 0, k3 = 0;
    for(i = 0; i < N; ++i){
        if(mass[i]->str != NULL){
            if(mass[i]->next == NULL){
                printf("%d - %s\n",i, mass[i]->str);
                k1++;
            }
            else{
                printf("%d - %s ", i, mass[i]->str);
                ptr = mass[i]->next;
                while(ptr != NULL){
                    printf("- %s ", ptr->str);
                    ptr = ptr->next;
                }
                printf("\n");
                k2++;
            }
        }
    }
    printf("k1 = %d, k2 = %d\n", k1, k2);
}
//заполнение таблицы
int mass_main(table *mass[], int N){
    int i;
    int K = 0;
    int ind, ind2;
    char *str;
    int count = 0;
    int c1;
    int max_ = 0;
    table *ptr1 = NULL;
    for(i = 0; i < N; ++i){
        str = gener_str();
        ind = hash(str);
        if(ind > N){
            printf("Error: ind = %d\n", ind);
            return -1;
        }
        if(mass[ind]->str == NULL){
            mass[ind]->str = str;
            count++;
        }
        else{
            ind2 = rehash(str, N);
            c1 = 1;
            while(mass[ind2]->str != NULL && c1 < N){
                    ind2 = rehash(str, N);
                    ++c1;
            }
            if(c1 > max_)
                    max_ = c1;
            if(c1 == N){
                    printf("The table done\n");
                    break;
            }
            if(ind2 >= N){
                printf("Error: %d\n", ind2);
                return -1;
            }
            if(mass[ind]->next == NULL){
                mass[ind]->next = mass[ind2];
                mass[ind2]->str = str;
                
								
                count++;
                K++;
            }
            else{
                ptr1 = mass[ind];
                while(ptr1 != NULL){
                    if(ptr1->next == NULL){
                        mass[ind2]->str = str;
                        ptr1->next = mass[ind2];
                        count++;
                        K++;
                        break;
                    }
                    else
                        ptr1 = ptr1->next;
                }
            }
        }
    }
    printf("max_ = %d\n", max_);
    printf("Kollize = %d\n", K);
    return 0;
}

//Зануление элементов таблицы
void table_make_null(table* mass[], int N){
    int i;
    for(i = 0; i < N; ++i){
        mass[i] =  (table*)malloc(sizeof(table) * N);
        mass[i]->next = NULL; mass[i]->str = NULL;
    }
}



int main(){
    srand(time(NULL));
    int N = 200, i;
    table *mass[N];
    table_make_null(mass, N);
    mass_main(mass, N);
    
    
    
	//print_mass(mass, N);
   
    
    mass_kollise(mass, N);
    
}