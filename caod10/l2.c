#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int hash_random(char *str){
    int kod;
    kod=str[0]+str[1];
    printf("%d\n",kod);
    if(rand() % 2 == 0){
        kod += rand()% (100 - kod);
        printf("%d",kod);    
    }
    else{
        kod -= rand() % kod;
        printf("%d",kod);
    }
    return kod;
}



int main(){
    srand(time(NULL));
    char *str="scssdfjbv";

    printf("%d",hash_random(str));

}