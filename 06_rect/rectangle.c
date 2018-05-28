

#include <stdio.h>

#include <stdlib.h>

//I've provided "min" and "max" functions in

//case they are useful to you

int min (int a, int b) {
  
  if (a < b) {
    
    return a;
    
  }
  
  return b;
  
}

int max (int a, int b) {
  
  if (a > b) {
    
    return a;
    
  }
  
  return b;
  
}



//Declare your rectangle structure here!

typedef struct {
  
  int x;
  
  int y;
  
  int width;
  
  int height;
  
}rectangle;





rectangle canonicalize(rectangle r) {
  
  if(r.width < 0){
    
    r.x = r.x + r.width;
    
    r.width = abs(r.width);
    
  }
  
  if(r.height < 0){
    
    r.y = r.y + r.height;
    
    r.height = abs(r.height);
    
  }
  
  //WRITE THIS FUNCTION
  
  return r;
  
}

rectangle intersection(rectangle r1, rectangle r2) {
  
  //WRITE THIS FUNCTION
  r1 = canonicalize(r1);
  
  r2 = canonicalize(r2);
  int r1x = r1.x;
  
  int r2x = r2.x;
  
  int r1y = r1.y;
  
  int r2y = r2.y;
  
  int r1x_ur = r1.x + r1.width;
  
  int r2x_ur = r2.x + r2.width;
  
  int r1y_ur = r1.y + r1.height;
  
  int r2y_ur = r2.y + r2.height;
  
  int new_x = max(r1x, r2x);
  
  int new_y = max(r1y, r2y);
  
  int new_x_ur = min(r1x_ur, r2x_ur);
  
  int new_y_ur = min(r1y_ur, r2y_ur);
  
  int new_width = new_x_ur - new_x;
  
  int new_height = new_y_ur - new_y;

  if(new_width < 0 || new_height <0){new_height = 0; new_width = 0;}
  
  rectangle new_r;
  
  new_r.x = new_x;
  
  new_r.y = new_y;
  
  new_r.width = new_width;
  
  new_r.height = new_height;
  

  
  new_r = canonicalize(new_r);
  

  
  return new_r;
}



//You should not need to modify any code below this line

void printRectangle(rectangle r) {
  
  r = canonicalize(r);
  
  if (r.width == 0 && r.height == 0) {
    
    printf("<empty>\n");
    
  }
  
  else {
    
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y,
	   
	   r.x + r.width, r.y + r.height);
    
  }
  
}



int main (void) {
  
  rectangle r1;
  
  rectangle r2;
  
  rectangle r3;
  
  rectangle r4;
  

  
  r1.x = 2;
  
  r1.y = 3;
  
  r1.width = 5;
  
  r1.height = 6;
  
  printf("r1 is ");
  
  printRectangle(r1);
  

  
  r2.x = 4;
  
  r2.y = 5;
  
  r2.width = -5;
  
  r2.height = -7;
  
  printf("r2 is ");
  
  printRectangle(r2);
  

  
  r3.x = -2;
  
  r3.y = 7;
  
  r3.width = 7;
  
  r3.height = -10;
  
  printf("r3 is ");
  
  printRectangle(r3);
  

  
  r4.x = 0;
  
  r4.y = 7;
  
  r4.width = -4;
  
  r4.height = 2;
  
  printf("r4 is ");
  
  printRectangle(r4);
  

  
  //test everything with r1
  
  rectangle i = intersection(r1,r1);
  
  printf("intersection(r1,r1): ");
  
  printRectangle(i);
  

  
  i = intersection(r1,r2);
  
  printf("intersection(r1,r2): ");
  
  printRectangle(i);
  

  
  i = intersection(r1,r3);
  
  printf("intersection(r1,r3): ");
  
  printRectangle(i);
  

  
  i = intersection(r1,r4);
  
  printf("intersection(r1,r4): ");
  
  printRectangle(i);
  

  
  //test everything with r2
  
  i = intersection(r2,r1);
  
  printf("intersection(r2,r1): ");
  
  printRectangle(i);
  

  
  i = intersection(r2,r2);
  
  printf("intersection(r2,r2): ");
  
  printRectangle(i);
  

  
  i = intersection(r2,r3);
  
  printf("intersection(r2,r3): ");
  
  printRectangle(i);
  

  
  i = intersection(r2,r4);
  
  printf("intersection(r2,r4): ");
  
  printRectangle(i);
  

  
  //test everything with r3
  
  i = intersection(r3,r1);
  
  printf("intersection(r3,r1): ");
  
  printRectangle(i);
  

  
  i = intersection(r3,r2);
  
  printf("intersection(r3,r2): ");
  
  printRectangle(i);
  

  
  i = intersection(r3,r3);
  
  printf("intersection(r3,r3): ");
  
  printRectangle(i);
  

  
  i = intersection(r3,r4);
  
  printf("intersection(r3,r4): ");
  
  printRectangle(i);
  

  
  //test everything with r4
  
  i = intersection(r4,r1);
  
  printf("intersection(r4,r1): ");
  
  printRectangle(i);
  

  
  i = intersection(r4,r2);
  
  printf("intersection(r4,r2): ");
  
  printRectangle(i);
  

  
  i = intersection(r4,r3);
  
  printf("intersection(r4,r3): ");
  
  printRectangle(i);
  

  
  i = intersection(r4,r4);
  
  printf("intersection(r4,r4): ");
  
  printRectangle(i);
  

  

  
  return EXIT_SUCCESS;
  
}
