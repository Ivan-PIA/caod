#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# include <limits.h>

 int linear_search(char mass[80][80], char slovo[]){
     int i,k;
    if(slovo!=0){

        for(i=0;i<5;i++){
            if(strcmp(slovo,mass[i])==0) {
                printf("\nindex word %d\n",i);
                k=i;
            }
 
        }
        if(strcmp(slovo,mass[k])!=0)
            printf("word not found\n");
 
    }

}

int liner(char *p,char *s){
    int i;
    int str=strlen(p);
    int substr=strlen(s);

    for (i=0;i+substr<str;++i){
        if(memcmp(s,p+i,substr)==0)
            printf("index:%d ",i);
    } 
    return -1;
}



void computeLPSArray(char* pat, int M, int* lps);
  

void KMP(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
  
   
    int lps[M];
  
   
    computeLPSArray(pat, M, lps);
  
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
  
        if (j == M) {
            printf("Found at index %d ", i - j);
            j = lps[j - 1];
        }
  
        
        else if (i < N && pat[j] != txt[i]) {
            
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
        
    }
}
  

void computeLPSArray(char* pat, int M, int* lps)
{
    int len = 0;
  
    lps[0] = 0; 
  
    
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            
            if (len != 0) {
                len = lps[len - 1];
  
              
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
  




# define NO_OF_CHARS 256

int max (int a, int b) 
{ return (a > b)? a: b; }


void badCharHeuristic( char *str, int size,
            int badchar[NO_OF_CHARS])
{
  int i;

  
  for (i = 0; i < NO_OF_CHARS; i++)
    badchar[i] = -1;

  
  for (i = 0; i < size; i++)
    badchar[(int) str[i]] = i;
}


void search_bou_mur( char *txt, char *pat)
{
  int m = strlen(pat);
  int n = strlen(txt);

  int badchar[NO_OF_CHARS];

  
  badCharHeuristic(pat, m, badchar);

  int s = 0; 
       
  while(s <= (n - m))
  {
    int j = m-1;

 
    while(j >= 0 && pat[j] == txt[s+j])
      j--;

    
    if (j < 0)
    {
      printf("\n first index = %d", s);

      
      s += (s+m < n)? m-badchar[txt[s+m]] : 1;

    }

    else
      
      s += max(1, j - badchar[txt[s+j]]);
  }
}



int main(){

    char mass [80][80]={"nani", "vanu", "nada","very","garry"};
    char p[]="nanoneravenlanaluluna";
    char slovo[80];

    char s[]="ave";
    int i=0;
    

int f;

printf("Введите слово для поиска: ");
scanf("%s",slovo);
printf("Введите способ поиска\n1-кнут-морис-пратт\n2-боуера-мура\n3-линейный\n");

scanf("%d",&f);

if (f==1){
    
    KMP(slovo,p);
    }    // кнута мориса пратта
if (f==2)
    search_bou_mur(p,slovo);// боуера мура

if (f==3){
    //printf("index %d",liner(p,slovo));
    liner(p,slovo);
    }


}