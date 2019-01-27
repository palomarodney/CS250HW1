#include <stdlib.h>
#include <stdio.h>

int recursion (int n){
	//base case
	if (n == 0){
		return 5; 
	}
	else{
		return 4*n + (2*recursion(n-1))+3;
	}
}


int main(int argc, char *argv[]){
	int n; 
	sscanf(argv[1],"%i", &n);
	printf("%i\n",recursion(n));
	return 0; 
}