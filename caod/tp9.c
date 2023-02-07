#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    float z[20];
    float sum;

    for(int i=0;i<20;i++){
        z[i]=pow(1.2,2*i)/(2*i);
        printf("%f ",z[i]);
        
    }

    for (int j=1;j<8;j++){
        sum=sum+z[j];

    }
    printf("----%f",sum);
    printf("Chooo");
}