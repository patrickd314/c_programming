#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


int main(void) {
card_t my_card = card_from_letters('7', 'h');
 
print_card(my_card);
 printf("\n");

 

 for(int i = 0; i < 52; i++){
   my_card = card_from_num(i);
   print_card(my_card);
   printf("\n");
   }
 //my_card = card_from_letters('%', 'h');
 //print_card(my_card);
 //printf("\n");
 




}
