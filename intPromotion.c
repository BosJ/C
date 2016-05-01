#include <stdio.h>

int main()
{
  unsigned int   ui_one       =  1 ;
  signed   int   i_one        =  1 ;
  signed   short s_minus_one  = -1 ;

  if( s_minus_one > ui_one)
    printf("-1 > 1 \n");

  if( s_minus_one < i_one) 
    printf("-1 < 1 \n"); 
}
