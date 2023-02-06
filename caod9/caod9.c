#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int c_sr=0;
int l_sr=0;

int create_rand(int mass[], int n){
    int i;
    for(i=0;i<n;i++){
        mass[i]=rand()%100;
    }

}

//---
int search(int mass[],int n, int a){
    int i,count=0;
    for(i=0;i<n;i++){
        l_sr+=1;
        if(a==mass[i]){
            count+=1;
            printf("index: %d\n",i+1);
        }
    }
    if(count==0){
        printf("\nNot number!\n");
    }
    else
        printf("quantity %d",count);
}
//---

void bubble_sort(int a[], int n) {

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            //c_sr+=1;
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int binarySearch(int array[], int x, int low, int high) {
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    c_sr+=1;
    if (array[mid] == x)
      return mid;
    c_sr+=1;
    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

void display(int a[],int n){
    printf("\n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);

}


int main(){
    int a,i,n,k;
    int l,m;
    srand(time(NULL));
    printf("Choice search\nBinary search-1\nLinear search-2\n");
    scanf("%d",&k);
    printf("Enter size arrey: ");
    scanf("%d",&n);
    int mass[n];
    
    
    if(k==1){
        create_rand(mass,n);
        bubble_sort(mass,n);
        int m=sizeof(mass)/sizeof(mass[0]);
       // display(mass,n);
        
        printf("Enter key: ");
        scanf("%d",&l);
        
        int result = binarySearch(mass, l, 0, m - 1);
        if (result == -1){
            printf("Not found\n");
            
        }
        else
            printf("Element is found at index %d\n", result);
        printf("amount sravnen: %d",c_sr);    
    
    }

    if(k==2){
        create_rand(mass,n);
    
    
        // for(i=0;i<n;i++){
        //     printf("%d ",mass[i]);
        // }

        printf("\nFind number: ");
        scanf("%d",&a);
    
        search(mass,n,a);
        printf("amount sravnen: %d",l_sr);
    }

}