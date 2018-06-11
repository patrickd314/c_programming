#include <stdio.h>
#include <stdlib.h>

// pointer method
/*
int * arrayMax(int * array, int n) {
    if (n == 0){return NULL;}
    int big_num = *array; // set var to 1st place in array
    //printf("%d\n", big_num);
    int *big_p = array;  // set pointer to same spot
    int * p = big_p;  // initialize a pointer which we will vary
    while(p < array + n){   // array + n will be 1 greater than final value
        if( *p > big_num){
            
            big_num = *p;  // swap
            big_p = p;
        }
    p += 1;  // move pointer p to next box
    }
  return big_p;
}
*/

// index method

int * arrayMax(int * array, int n) {
  if (n == 0){return NULL;}
  int big_num = array[0];
  int big_i = 0;  
  for (int i = 1;  i < n; i++){   
    if( array[i] > big_num){
      big_num = array[i];  // swap
      big_i = i;
    }
  }
  //int * big_p = &array[big_i];
    
  return &array[big_i];
}

void doTest(int * array, int n) {
  printf("arrayMax(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (int i =0; i < n; i++) {
      printf("%d", array[i]);
      if (i < n -1) {
        printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  int * p = arrayMax (array, n);
  if (p == NULL) {
    printf("NULL\n");
  }
  else {
    printf("%d\n", *p);
  }
}

int main(void) {
  int array1[] = { 77, 33, 19, 99, 42, 6, 27, 4};
  int array2[] = { -3, -42, -99, -1000, -999, -88, -77};
  int array3[] = { 425, 59, -3, 77, 0, 36};

  doTest (array1, 8);
  doTest (array2, 7);
  doTest (array3, 6);
  doTest (NULL, 0);
  doTest (array1, 0);
  
  return EXIT_SUCCESS;
}
