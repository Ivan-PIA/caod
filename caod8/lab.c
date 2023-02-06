#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int pc=0,c_qs=0;


int swap(char *a,char *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void QuickSort(char *A, int start, int end){
int sum=0;
c_qs+=1; 
    if(start>=end){
     
    return;}
    int key=start,i=start,j=end,temp;
    c_qs+=1;
    while(i<=j){
        
        while (i<=end && A[i]<=A[key]){
          
          i++;}c_qs+=1;
        while (j>start && A[j]>=A[key]){
          
          j--;}c_qs+=1;
          c_qs+=1;
        if(i>j){
          
          swap(&A[key],&A[j]);
          
          }
        else{  
          swap(&A[i],&A[j]);
          }
    }
    QuickSort(A,start,j-1);
    QuickSort(A,j+1,end);
  
}
//----
int mergeSort(char *a, int l, int r)
{ pc+=1;
  if (l == r) return 0; 
  int mid = (l + r) / 2; 
  
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  int i = l;  
  int j = mid + 1; 
  int *tmp = (int*)malloc(r * sizeof(int)); 
  for (int step = 0; step < r - l + 1; step++) 
  {
    pc+=2;
    if ((j > r) || ((i <= mid) && (a[i] < a[j]))) 
    {
      tmp[step] = a[i];
      i++;
    }
    else 
    {
      tmp[step] = a[j];
      j++;
    }
  }
  
  for (int step = 0; step < r - l + 1; step++)
    a[l + step] = tmp[step];
}

int sample(char *mass,int N){

int minPosition, tmp,c=0;
 
    for (int i = 0; i < N; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < N; j++)
            if (mass[minPosition] > mass[j])
                minPosition = j;
                c+=1;
        tmp = mass[minPosition];
        mass[minPosition] = mass[i];
        mass[i] = tmp;
    }
    return c;
}


int InsertionSort(char mass[], int n )
{
    int newElement, location,c=0;
 
    for (int i = 1; i < n; i++)
    {
        newElement = mass[i];
        location = i - 1;
        while(location >= 0 && mass[location] > newElement)
        {   c+=2;
            mass[location+1] = mass[location];
            location = location - 1;
        }
        mass[location+1] = newElement;
    }
    return c;
}
int bubble_sort(char *mass, int N)
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
        c+=1;
    }
    if (noSwap == 1){
        c+=1;
        break;}
}

return c;
}

int main(){
    
    int i,j;
    int n=50;
char arr[]="fsrblbgplkfsrblbgplkfsrblbgplkfsrblbgplkfsrblhvjkn";
printf("not sort arrey: ");
for(i=0;i<n;i++)
printf("%c",arr[i]);

printf(" \n   CHOICE SORT\nbubble_sort-1\nsample_sort-2\nmerge_sort-3\ninsertion_sort-4\nquick_sort-5\n");
scanf("%d",&j);
if(j==1){
    printf("bubble_sort: ");
    int c=bubble_sort(arr,n);
    printf("%d-comparison  ",c);
}
else if(j==2){
    printf("sample_sort: ");
    int s=sample(arr,n);
    printf("%d-comparison ",s);
}

else if(j==3){
    printf("merge_sort: ");
    mergeSort(arr,0,n-1);
    printf("%d-comprasion ",pc);
    
}

else if(j==4){
    printf("insertion_sort: ");
    int in=InsertionSort(arr,n);
    printf("%d-comparison ",in);
}

else if (j==5){
    printf("quick_sort: ");
    QuickSort(arr, 0, n);
    printf("%d ",c_qs);
}

i=0;
for(i=0;i<n;i++)
printf("%c",arr[i]);


}