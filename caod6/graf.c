#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h>

int visitedv(int d[],int n, int v){
int i;
    if(n!=0){
        for(i=0;i<n;i++){
            if(d[i]==v)
                return 0;

        }
        return 1;
    }
    return 1;

}

int search(int *arrey, int n, int elemnt1, int elemnt2){
    int i, i2=0, i3=0,i4;
    

    int *was = malloc(sizeof(int)*n);
    int *wasnot = malloc(sizeof(int)*n);
    wasnot[i3]=elemnt1;
    //i3++;
    int root1=0, root2=1, root3=root2, root4=root2;
    while(1){
        for(i=root1;i<root2;++i){
            for(i4=0;i4<n;++i4){
                if (i4!=0 && i4%2==0 && arrey[i4]!=arrey[i4+1] && arrey[i4]==wasnot[i]){
                    if(visitedv(was, i2, arrey[i4])==1){
                        wasnot[root4]=arrey[i4+1];
                        //printf("arr%d\n",arr[i4+1]);
                        root4++;
                        if(arrey[i4+1]==elemnt2){
                            //printf("el2%d\n",elemnt2);
                            return 1;
                        }

                    }
                }
            }
        }
        if(root4==root2)
            return 0;
        for(i=root1;i<root2;++i){
            was[i]=wasnot[i];
            i2++;
        }
        root1=root2;
        root2=root4;
    }

}

int main(){
    
int arrey[6][2]={
            {1,2},
            {1,3},
            {1,4},
            {4,6},
            {3,5},
            {6,5}
            };
    if (search(&arrey[0][0],12,4,3))
        printf("There is a way!\n");
    else
        printf("No way!\n");
}