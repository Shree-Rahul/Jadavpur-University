#include<stdio.h>
#include<unistd.h>

int main(){
 
  int i =0;
  do
  {
    if(fork()!=0)
        i+=2;
    else{
        printf("Hello\n");
        i+=3;
    }
  } while (i<=5);
}