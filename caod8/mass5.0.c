#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>

int creat(int a[],int b[],int n, int m){
    int i;
    for(i=0;i<m;i++)
    a[i]=rand()%40-10;

    for(i=0;i<m;i++)
    b[i]=rand()%40-10;

}

void bubble_sort(int *mass, int N)
{
int tmp;
int c=0;
bool noSwap;

for (int i = N - 1; i >= 0; i--)
{
    noSwap = 1;
    for (int j = 0; j < i; j++)
    {
        if (mass[j] > mass[j + 1])
        {
            tmp = mass[j];
            mass[j] = mass[j + 1];
            mass[j + 1] = tmp;
            noSwap = 0;
        } 
        
    }
    if (noSwap == 1){
        
        break;
        }
}
}

int merge_(int a[], int b[]) { 
int i=10, j=10, end=20;
while (j >= 0) {
    if (i >= 0 && a[i] > b[j]) {
      a[end] = a[i];
      i--;
    } else {
      a[end] = b[j];
      j--;
    }
    end--;
  }
}



int main(){
      srand(time(NULL));
    int i,n=10,m=10;
    int end=20;
    int a[20];
    int b[m];
    creat(a,b,n,m);
    bubble_sort(a,m);
    for(i=0;i<10;i++)
        printf("%d ",a[i]);

    printf("\n");
    bubble_sort(b,m);
    for(i=0;i<10;i++)
        printf("%d ",b[i]);
        printf("\n");

        merge_(a,b);
  for(i=0;i<end;i++)
        printf("%d ",a[end]);

}