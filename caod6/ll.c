#include <stdio.h>

int def(int arr[],int n){
    int i;
    //for(i=0;i<12;i++)
    //printf("%d\n",arr[i]);
int kor2=1, kor3=kor2, kor4=kor2;
    printf("kor2:%d, kor3:%d kor4:%d",kor2,kor3,kor4);
}


int main(){

    int arr[6][2]={
            {1,2},
            {1,3},
            {1,4},
            {4,6},
            {3,5},
            {6,5}
            };
def(arr,12);
}