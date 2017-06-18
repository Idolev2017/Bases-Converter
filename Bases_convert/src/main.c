#include <stdio.h>
#include <stdlib.h>
#include "SPBufferset.h"
int cast_from_decimal(int num,int base);

int main(void) {
	SP_BUFF_SET();
	int base_a;
	int base_b;
	char c;
	int c_num;
	int decimalRep = 0;
	printf("Please enter the number's base:\n");
	scanf("%d",&base_a);
	if(base_a < 2 || 16 < base_a){
		printf("Invalid input base\n");
		return 1;
	}
	printf("Please enter the desired base:\n");
	scanf("%d",&base_b);
	if(base_b < 2 || 16 < base_b){
		printf("Invalid desired base\n");
		return 1;
	}
	printf("Please enter a number in base %d:\n",base_a);
	c = getchar();
	while(c == '\n') c = getchar();
	while(c != EOF && c != '\n'){
		if(c == ' '){
			c = getchar();
			continue;
		}
		if (97 <= c && c <= 102) {   //change from lower letter to decimal number.
			c_num = c-87;
		}
		else if(48 <= c && c <= 57) { //c is digit.
			c_num = c-48;
		}
		else if(65 <= c && c <= 70){ //change from Capital letter to decimal number.
			c_num = c-55;
		}
		else {                     // not in range a-f and not a digit;
			printf("Invalid number!\n");
			return 1;
		}
		if(base_a <= c_num){  //checking if c_num is in range [0,a] (should be a digit in base a)
			printf("Invalid number!\n");
			return 1;
		}

		decimalRep = base_a*decimalRep + c_num;   //convert to decimal number.
		c = getchar();
	}
	printf("The result is : ");
	if (base_b == 10)       //if b == 10 then the cast is irrelevant.
		printf("%d\n",decimalRep);
	else if(decimalRep == 0)     // (0)a = (0)b = 0 for all bases a,b.
		printf("0\n");
	else {
		cast_from_decimal(decimalRep,base_b);
		printf("\n");
	}
}
/* invariant num != 0
 * casting decimal number to b-base number.
 * the function print the b-base number.
 */
int cast_from_decimal(int num,int base){
	if(num == 0){
		return 1;
	}
	char nextchar;
	int mod;
	mod = num % base;
	nextchar = mod+48;
	if (mod >= 10)
		nextchar += 7;
	cast_from_decimal(num / base,base);
	printf("%c",nextchar);
	return 1;



}
