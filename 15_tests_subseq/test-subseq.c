#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void) {
  int array1[] = {-1,2,3,5,7,2,4,6,9};
  int array2[] = {};
  int array3[] = {-1}; // 1
  int array4[] = {6,2}; // 1
  int array5[] = {-1,2};
  int array6[] = {-1,2,4,7}; // 4
  int array7[] = {-1,2,3,2,3,4,2,30,40,55}; //4
  int array8[] = {0}; // 1
  int array9[] = {-10, -10, -10, -10}; //1

  
  int max_seq1 = maxSeq(array1,9);
  int max_seq2 = maxSeq(array2,0);
  int max_seq3 = maxSeq(array3,1);
  int max_seq4 = maxSeq(array4,2);
  int max_seq5 = maxSeq(array5,2);
  int max_seq6 = maxSeq(array6,4);
  int max_seq7 = maxSeq(array7,10);
  int max_seq8 = maxSeq(array8,1);
  int max_seq9 = maxSeq(array9,4);

  int bool_1 = (max_seq1 == 5)&&(max_seq2 == 0)&&(max_seq3 == 1)&&(max_seq4 == 1)&&(max_seq5 == 2);
  int bool_2 = (max_seq6 == 4)&&(max_seq7 == 4)&&(max_seq8 == 1)&&(max_seq9 == 1);

 
  
    if(bool_1 && bool_2) {

  //  if(max_seq5 == 2){
    return EXIT_SUCCESS;
  }
  
  else{

    return EXIT_FAILURE;
  }

}
