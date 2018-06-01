#include <stdio.h>
#include <stdlib.h>

int prime_correct(int num, int test){
  char command[100];
  
  switch (test){
  case 1:
    sprintf(command, "./isPrime-broken1 %d", num);
    break;
  case 2:
    sprintf(command, "./isPrime-broken2 %d", num);
    break;
  case 3:
    sprintf(command, "./isPrime-broken3 %d", num);
    break;
  case 4:
    sprintf(command, "./isPrime-broken4 %d", num);
    break;
  case 10:
    sprintf(command, "./isPrime-correct %d", num);
    break;
  }
    
  //printf("Test %d: \n", test);
  system(command);

  
  return EXIT_SUCCESS;
}

int main(){
  for(int i = 10000; i < 100000; i ++){
  prime_correct(i, 10);
  //printf("pr %d\n", pr);
  }
  return EXIT_SUCCESS;
}
