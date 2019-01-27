#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>



int main(int argc, char *argv[]){
	// int counter = 0; 
	int n; 
	// int* divisible = (int*)malloc(sizeof(int)*100) how to make the array large enough for any int n
	// printf("Please input an integer"); 
	sscanf(argv[1], "%i",&n);
	//if n is a negative integer
	
	//if n is not an integer -->HELP with this case
	// if (isdigit(n)==0 || n<0){
	// 	printf("Please input a positive integer\n");
	// }
	int j=1; //counts every number to n
	int counter = 0; //counts up to n integers
	while(counter<n ){
		 // case for if the inputed integer is 0 
		
		/*case for if the integer is divisble by both 7 and 11*/
		if (j%7==0 && j%11==0){
			printf("%i\n",j);
			counter ++;
			}
		/*case for if the integer is divisible by 7 but not 11*/
		if(j%7==0 && j%11!=0){
			printf("%i\n",j);
			counter ++;
		}
		/* case for if the integer is divisible by 11 but not 7*/

		if(j%11==0 && j%7!=0){
			printf("%i\n",j);
			counter ++;
		}
		j++ ;
		
	}
	// int k=0;
	// for (k=0; k<sizeof(divisible); k++){
	// 	printf("%i\n",divisible[k]);
	// }

	return 0;

}