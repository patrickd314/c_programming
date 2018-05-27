#include <stdio.h>

#include <stdlib.h>



int max(int x, int y){
  if((x - y) > 0 ) {
  return x;
  }

  else {
return y;
  }
}

void squares(int size1, int x_offset, int y_offset, int size2) {

int w = max(size1, (x_offset + size2));
int h = max(size1, (y_offset + size2));

for(int y = 0; y < h; y++){ 

  for(int x = 0; x < w; x++){
 
    int m = (x_offset <= x)&&(x < (x_offset + size2));
    int n = y == y_offset || y == y_offset + size2 - 1;
    int o =  (y_offset <= y) && (y < (y_offset + size2));
    int p = x == x_offset || x == x_offset + size2 -1;
    int q = (x < size1) && (y == 0 || y == size1 - 1);
    int r = (y < size1) && (x == 0 || x == size1 - 1);

    if ((m && n) || (o && p)){
      printf("*");
    }

      else if (q || r) {
	printf("#");
      }

	else printf(" ");

      }

      printf("\n");

   }
 
 }
