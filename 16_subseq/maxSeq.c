#include <stdio.h>
#include <stdlib.h>



size_t maxSeq(int * array, size_t n){
  //printf("n = %d\n", n);
  if((n == 0) || (n == 1)){return n;}
    
    
  int long_seq = 0;
  int idx = 0;
  int this_seq = 1;
  int high_seq = 1;
  int current_value = 0;
  int next_value = 0;
  //printf("idx = %d\n", idx);
  while(idx < n - 1){
    current_value = array[idx];
    next_value = array[idx + 1];
    //printf("%d %d\n", current_value, next_value);
    if(current_value < next_value){
      this_seq ++;
      //printf("This_seq = %d\n", this_seq);
      if(high_seq < this_seq){high_seq = this_seq;}
      idx++;
    }
    else{
      if(high_seq < this_seq){high_seq = this_seq;}
      this_seq = 1;
      idx++;
            
    }
  }
    
  return high_seq;
}
