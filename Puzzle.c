#include <stdio.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

#define EXIT    0
#define UP 	    1
#define DOWN	2
#define LEFT	3
#define RIGHT 	4


void rule();
void setdata (int a[][4]);
void showdata(int a[][4]);
int check_win( int a[][4]);
int ip_key();
int shift_down(int a[][4]);
int shift_up(int a[][4]);
int shift_right(int a[][4]);
int shift_left(int a[][4]);



int main()
{
  int a[4][4], move = 500;
  rule();
  setdata(a);
  while(move)
  {
     printf("Your step Live count...... \n\t Left Step : - %d",move);
    showdata(a);
  
   if (check_win(a))
   {
   	
   	printf("Tebrikler Kazandiniz\n");
   	printf("Cikis yapmak icin herhangi bir tusa  basabilirsiniz");
   	getch();
   	exit(0);
   }
  
  
   switch(ip_key())
   {
   	   case EXIT:
   	   	exit(0);
        	
   	 case UP:
   	 	if(!shift_up(a))
   	 	move++;
   	 	break;
   	 	
   	 case DOWN:
   	 	if(!shift_down(a))
   	 	move++;
   	 	break;
			
	case LEFT:
   	 	if(!shift_left(a))
   	 	move++;
   	 	break;
			
	case RIGHT:
   	 	if(!shift_right(a))
   	 	move++;
   	 	break;					
    default:
   	  move++;
   }
   
    system("cls");
    move--;
  
  
  
  
  
  }
  
  
  getch();
  
}

void rule()
{
 printf("Welcome to this game \n\n Game\'s Some Rules : ");
 printf("-> Left Shift press Left on your keypboard\n\n");
 printf("-> Right Shift press Right on your keypboard\n\n");
 printf("-> UP Shift press UP on your keypboard\n\n");
 printf("-> Down Shift press Down on your keypboard\n\n");
 printf("Press any key to continue");
 getch();


}


void setdata (int a[][4])
{
int x[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int i,j,index,max = 14;
srand(time(NULL));

for(i=0;i<4;i++) //  a dizisini karýþtýrdýk
{
  for(j=0;j<4;j++) 
  {
     if (max>=0) 
     {
     	index = rand() % (max + 1);
     	a[i][j] = x[index];
     	x[index] = x [max];
     	max--;
     	
	 }
     
    else {
    	
    	a[i][j] = 0;
	}
  
  }
  
  
  }


}


void showdata(int a[][4]){
	
	int i,j;
	
	printf("\n ---------------------------------------------\n");
	
	for(i=0;i<4;i++)
	{
	  for(j=0;j<4;j++) {
	  
	  if (a[i][j] != 0 )
     {
     	printf("%2d || ", a[i][j] );
     	
		   }	 
    else {
    	
    	
    	printf("  || ");
	} 
	  

	  
	  }
	  
	  	printf("\n ---------------------------------------------\n");
	
	if ( i == 3)
{   
      printf(" ");
	}	
	  
		
	}
	
	
	
	
	
}

int check_win( int a[][4])
{
	int i,j,k = 0;
	
	for( i = 0; i<4 ;i++ ) 
	{
	  for( j = 0; j<4; j++ )
	  {
	     k<15 ? k++ : (k = 0);
	     
	     if(a[i][j] != k ) 
		 { 
		  
		  return 0;
		 }
		 
	    
	  
	  
	  }
	  
	}
	
   return 1;	
}

int ip_key(){
	
	char c;
	c = _getch();
	
	if(c == -32)
	c = _getch();
	
	
  switch (c)
  {
    case 27:
    	return(EXIT);
    case 72:
    	return(UP);
     case 80:
    	return(DOWN);
     case 75:
    	return(LEFT);
     case 77:
    	return(RIGHT);
    default:
    	return(10);
  
  
  }
  
	
	
	
}

int shift_up(int a[][4])
 {
 	int i,j, temp,zero_found = 0;
 	 
 	 for( i=0; i<4; i++)
 	 {
 	 	
 	 	for(j=0; j<4; j++ ){
 	 		
 	 		if(a[i][j] == 0 )
 	 		{
 	 			zero_found = 1;
 	 			break;
			  }
 	 		
		  }
		if(zero_found)
		{
			break;
		}
	  }
	
	 if ( i == 0 ) return 0;
	 
	 else
	 {
	 	temp = a[i][j];
	 	a[i][j] = a[i-1][j];
	 	a[i-1][j] = temp;
	 	return 1 ;
	 }
	 
 	
 	
 }
 
 int shift_down(int a[][4])
 {
 	int i,j, temp,zero_found = 0;
 	 
 	 for( i=0; i<4; i++)
 	 {
 	 	
 	 	for(j=0; j<4; j++ ){
 	 		
 	 		if(a[i][j] == 0 )
 	 		{
 	 			zero_found = 1;
 	 			break;
			  }
 	 		
		  }
		if(zero_found)
		{
			break;
		}
	  }
	
	 if ( i == 3 ) return 0;
	 
	 else
	 {
	 	temp = a[i][j];
	 	a[i][j] = a[i+1][j];
	 	a[i+1][j] = temp;
	 	return 1 ;
	 }
	 
 	
 	
 }
 
 int shift_left(int a[][4])
 {
 	int i,j, temp,zero_found = 0;
 	 
 	 for( i=0; i<4; i++)
 	 {
 	 	
 	 	for(j=0; j<4; j++ ){
 	 		
 	 		if(a[i][j] == 0 )
 	 		{
 	 			zero_found = 1;
 	 			break;
			  }
 	 		
		  }
		if(zero_found)
		{
			break;
		}
	  }
	
	 if ( j == 0 ) return 0;
	 
	 else
	 {
	 	temp = a[i][j];
	 	a[i][j] = a[i][j - 1] ;
	 	a[i][j - 1] = temp;
	 	return 1 ;
	 }
	 
 	
 	
 }
 
 int shift_right(int a[][4])
 {
 	int i,j, temp,zero_found = 0;
 	 
 	 for( i=0; i<4; i++)
 	 {
 	 	
 	 	for(j=0; j<4; j++ ){
 	 		
 	 		if(a[i][j] == 0 )
 	 		{
 	 			zero_found = 1;
 	 			break;
			  }
 	 		
		  }
		if(zero_found)
		{
			break;
		}
	  }
	
	 if ( j == 3 ) return 0;
	 
	 else
	 {
	 	temp = a[i][j];
	 	a[i][j] = a[i][j + 1];
	 	a[i][j + 1] = temp;
	 	return 1 ;
	 }
	 
 	
 	
 }
