#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  //  printf("card val %d card suit %d  ", c.value, c.suit);
  int val = (2 <= c.value) && (c.value <= VALUE_ACE);
  int st = (SPADES <= c.suit) && (c.suit <= CLUBS);
  //if(!(val && st)){printf("Assert failure!");}
  //else{printf("assert passed!");}
  
    assert( val && st);      
}

const char * ranking_to_string(hand_ranking_t r) {
  const char *out_str;
  switch(r){
     case  STRAIGHT_FLUSH:
       out_str = "STRAIGHT_FLUSH";
       break;
     case  FOUR_OF_A_KIND:
       out_str = "FOUR_OF_A_KIND";
       break;
     case  FULL_HOUSE:
       out_str = "FULL_HOUSE";
       break;
     case  FLUSH:
       out_str = "FLUSH";
       break;
     case  STRAIGHT:
       out_str = "STRAIGHT";
       break;
     case  THREE_OF_A_KIND:
       out_str = "THREE_OF_A_KIND";
       break;
     case  TWO_PAIR:
       out_str = "TWO_PAIR";
       break;
     case PAIR:
       out_str = "PAIR";
       break;
     case  NOTHING:
       out_str = "NOTHING";
       break;
  }

  return out_str;
}

char value_letter(card_t c) {
  char val_let;
  if(c.value < 10){val_let = ('0' + c.value);}
  else{
    switch(c.value){
       case 10:
	 val_let = '0';
	 break;
       case VALUE_JACK:
	 val_let = 'J';
	 break;
       case VALUE_QUEEN:
	 val_let = 'Q';
	 break;
       case VALUE_KING:
	 val_let = 'K';
	 break;
       case VALUE_ACE:
	 val_let = 'A';
	 break;
    }
  }
  return val_let;
}


char suit_letter(card_t c) {
  char suit_let;
  switch(c.suit){
     case SPADES:
       suit_let = 's';
       break;
     case HEARTS:
       suit_let = 'h';
       break;
     case DIAMONDS:
       suit_let = 'd';
       break;
     case CLUBS:
       suit_let = 'c';
       break;
     case NUM_SUITS:
       return EXIT_FAILURE;
    
  }
  return suit_let;
  
}

void print_card(card_t c) {
  char v = value_letter(c);
  char s = suit_letter(c);
  printf("%c", v);
  printf("%c", s);
}

card_t card_from_letters(char value_let, char suit_let) {
   int  value_int = value_let - 48;
   card_t temp;
   if (2 <= value_int && value_int <= 9){
     temp.value = value_int;
   }
   else if(value_int == 0){temp.value = 10;}
   else{ // assuming val_int == 0 now    
     switch (value_let){
       case 'J':
	 temp.value = 11;
	 break;
       case 'Q':
	 temp.value = 12;
	 break;
       case 'K':
	 temp.value = 13;
	 break;
       case 'A':
	 temp.value = 14;
	 break;
       default:	 
	 temp.value = 24;
	 break;
	 //return EXIT_FAILURE;	(bad return type)   
       }    
   }
   switch (suit_let){
       case 's':
	 temp.suit = SPADES;
	 break;
       case 'h':
	 temp.suit = HEARTS;
	 break;
       case 'd':
	 temp.suit = DIAMONDS;
	 break;
       case 'c':
	 temp.suit = CLUBS;
	 break;
       default:
	 temp.suit = NUM_SUITS;
	 break;
   }
   assert_card_valid(temp);   
   return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  // printf("%d\n",c);
  temp.suit = c/13;  
  temp.value = (c % 13)+2;
  //printf("suit = %d  value = %d \n ", temp.suit, temp.value);
  assert_card_valid(temp);
  return temp;
}
