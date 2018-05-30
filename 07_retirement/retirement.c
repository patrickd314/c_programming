#include <stdio.h>
#include <stdlib.h>

typedef struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
} retire_info;

void print_out(int age, double money){
  printf("Age %3d month %2d you have $%.2f\n", age/12, age %12, money);
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  
  double current_money = initial;
  int current_age = startAge;
  int retirement = 0;
  double rate = working.rate_of_return;
  double contrib = working.contribution;
  int terminate = working.months;
  while (retirement < 2){
    
    for(int i = 0; i < terminate; i ++){
      print_out(current_age, current_money);
      current_money = current_money * (1 + rate) + contrib;
      //printf("Current rate, contribtion = %f, %f", rate, contrib);
      current_age ++;
    }
    
    retirement ++;
    rate = retired.rate_of_return;
    contrib = retired.contribution;
    terminate = retired.months;
  }
}
int main(void){
  
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  int age = 327;
  double savings = 21345;

  retirement(age, savings, working, retired);
  return EXIT_SUCCESS;
}
