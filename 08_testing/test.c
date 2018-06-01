#include <stdio.h>

#include <stdlib.h>

int prime_correct(int a){
  

  /*  int p = 32;
  int s = system("isPrime-correct %d",p);
  printf("%d", s);
  return 0;
  */

  char command[100];  
  // a = 42;  
  sprintf(command, "./isPrime-correct %d", a);  
  int s = system(command);
  printf("%d", s);
  return s;
}

int main(){
  prime_correct(30);
  }

 
