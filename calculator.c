#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int arithmetic(int x, int y){
	 char operation;
	 printf("Enter an operation (+, -, *, /, %%): ");
	 scanf(" %c", &operation);
	 switch(operation){

		  case '+':
				printf("The sum is: %d\n", x + y);
				break;
		  case '-':
				printf("The difference is: %d\n", x - y);
				break;
		  case '*':
				printf("The product is: %d\n", x * y);
				break;
		  case '/':
				if(y != 0){
					 printf("The quotient is: %d\n", x / y);
				}
				else{
					 printf("Cannot divide by zero\n");
				}
		  case '%':
				if(y != 0){
					 printf("The modulus is: %d\n", x % y);
				}
				else{                
					 printf("Cannot divide by zero\n");
				}  
				break;
		  default:
				printf("Invalid operation\n");
	 }
}
int rootFunctions(float x){
	 float result;
	 char roots;
	 printf("**********************Calculation of rots**********************\n\nS- Square root\n\nC- Cube root\n\nN- Nth root\n\n");
	 printf("Enter which root to calculate: ");
	 scanf(" %c", &roots);
	 switch(roots){
		  case 'S':
				printf("Enter the number to find the square root of: ");
				scanf("%f", &x);
				if(x > 0){
					 float result = x / 2;// 2 is the root value we are trying to look for!!!
					 // conditions to calculate the square root of a number
					 while(((result * result - x) > 0.00001) || ((x - result * result) > 0.00001)){ // repeat until result value is <= 0.00001

						  result = (result + x / result) / 2;
					 }
					 printf("The square root is =  %f\n", result);
				}
				else{
					 printf("Cannot calculate square root of a negative number\n");
				}
				break;
				// end of square root condition
		  case 'C':
					 printf("Enter the number to find the cube root of: ");
					 scanf("%f", &x);
					 if(x > 0){
						  result =  x / 3; // 3 is the root value we are trying to look for!!!
						  // conditions to calculate the cube root of a number
						  while(((result * result * result - x) > 0.00001) || ((x - result * result * result) > 0.00001)){ //repeat until result value is <= 0.00001
								result = (2 * result + x / (result * result)) / 3;
						  }
						  printf("The cube root is = %f\n", result);
					 }
					 else{
						  printf("Cannot calculate cube root of a negative number\n");
					 }
					 // end of cube root condition
				break;
		  case 'N':
					 int n ;
					 printf("Enter the nth root: ");
					scanf("%d", &n);
					 if(n > 0){
						  printf("Enter the root to perform: ");
						  scanf("%f", &x);
						  if(x > 0){
								result = x / n; // n is the root value we are trying to look for!!!
								float guessValue = 0;
									 while(!guessValue){ // Does the check so the loop execute
										  float currentPower = 1.0; // default value to make the power of the root
										  float powerMinus1 = 1.0; // power deduction
										  for(int i = 1; i <= n; i++){ // keeping the power at a state of result update
												currentPower *= result; // executes untill the loop stop and stores the final value in currentpower
										  }
										  for(int J = 1; J <= n-1; J++){ // reverse the function to decrease the number the number of execution in n
													 powerMinus1 *= result; // holds final result value after the loop stops
												}
										  float difference = currentPower - x;
										  if(difference < 0){
												difference *= -1; // make sure to always turn the value difference to be positive in order to perform the difference value calculations
										  }
										  if(difference <= 0.0001){ // testing our acurate guess value to question
												guessValue = 1;
										  } else{
												result = (((n-1) * result) + (x/powerMinus1)) / n; // final result value is examine in the else statement
										  }
									 }
								printf("The %dth root is: %f\n\n", n, result); // output the final root answer
						  }
					 }
				break;
		  
		  default:
				printf("Invalid math function\n");
	 }
}
// trigonometric functions are calculated using the taylor series expansion for sine, cosine and tangent functions. The series is repeated until the term value is less than or equal to 0.00001 to ensure accuracy of the result.
int trigonometricFunctions(float x){
		#define PI 3.14159
		float result;
		char trigFunctions;
		printf("**********************Calculation of trigonometric functions**********************\n\nS- Sine\n\nC- Cosine\n\nT- Tangent\n\n");
		printf("Enter which trigonometric function to calculate: ");
		scanf(" %c", &trigFunctions);
	 	switch(trigFunctions){
		  	case 'S':
				char responds;
				printf("calculate the iverse of sine(y/n): \n");
				scanf(" %c", &responds);
				if((responds == 'N') || (responds == 'n')){
					printf("Enter the angle in degrees to find the sine: ");
					scanf("%f", &x);
					float radian = x * (PI/180.0); // converting user into radian
					result = 0.0;
					float term = radian; // first term of the Jseries
					int n = 1; // term index
					while((term > 0.00001) || (term < -0.00001)){ // repeat until the term value is <= 0.00001
						result += term; // add to result
						term *= -1.0 * radian * radian / ((n + 1) * (n + 2)); // calculate the next term in the series
						n += 2; // increment the term index by 2 for sine series
					}
					printf("The sine of %.2f degrees is: %.4f\n", x, result);
				} else if((responds == 'Y') || (responds == 'y')){
					printf("Enter the value to find the inverse sine of: ");
					scanf("%f", &x);
					if(x > -1.0 && x < 1.0){
						// Calculate inverse sine using Taylor series
						result = x; // first term of the series approximation
						float term = x; // first term of the series
						int n = 1; // term index
						while((term > 0.00001) || (term < -0.00001)){ // repeat until the term value is <= 0.00001
							term *= ((x * x) * ((float)(2 * n - 1)) / (2 * n)); // calculate the next term in the series
							result += term; // add to result
							n++; // increment the term index by 1 for inverse sine series
						}
						result *= (180.0 / PI); // convert result from radians to degrees
						
						printf("The inverse sine of %.4f is: %.4f degrees\n", x, result);
					} else {
						printf("Invalid input. Please enter a value between -1 and 1.\n");
					}
				}
				
			break;
		  	case 'C':
				printf("Enter the angle in degrees to find the cosine of: ");
				scanf("%f", &x);
				float radians = x * (PI/180.0);// converting user into radian
				result = 1.0; // first term of the series
				float term = 1.0; // first term of the series
				int n = 2; // cosine term index 
				while(term > 0.00001 || term < -0.00001){ // repeat until the term value is <= 0.00001
					 term *= -1.0 * radians * radians / (n * (n-1)); // calculate the next term in the series
					 result += term; // add
					 n += 2; // increment the term index by 2 for cosine series 
				}
				printf("The cosine of %.2f degrees is: %.4f\n", x, result);
			break;
		  	case 'T':
				printf("Enter the angle in degrees to find the tangent of: ");
				scanf("%f", &x);
				float radianz = x * (PI/180.0); // converting user into radian
				// Calculate sine and cosine using the same method as above
				float sineResult = 0.0;
				float cosineResult = 1.0;
				term = radianz; // first term for sine
				n = 1; // term index for sine
				while(term > 0.00001 || term < -0.00001){ // repeat until the term value is <= 0.00001
					 sineResult += term; // add to sine result
					 term *= -1.0 * radianz * radianz / ((n + 1) * (n + 2)); // calculate the next term in the sine series
					
					 n += 2; // increment the term index by 2 for sine series
				}
				term = 1.0; // first term for cosine
				n = 2; // term index for cosine
				while(term > 0.00001 || term < -0.00001){ // repeat until the term value is <= 0.00001
					 term *= -1.0 * radianz * radianz / (n * (n-1)); // calculate the next term in the cosine series
					 cosineResult += term; // add to cosine result
					 n += 2; // increment the term index by 2 for cosine series
				}
				if(cosineResult > 0.00001 || cosineResult < -0.00001){
					 result = (sineResult / cosineResult); // calculate tangent as sine/cosine
					 printf("cosine %f and sine %f\n", cosineResult, sineResult);
					 printf("The tangent of %f degrees is: %.4f\n", x, result);
				}
				else{
					 printf("Tangent is undefined for this angle (cosine is zero)\n");
				}
			break;
			default:
				printf("Invalid trigonometric function\n");
	 
	 	}
}
// end of trig functions


int main(){
	 int num1, num2;
	 char decision;

	 printf("Welcome to the calculator!\nchoose the option you want to perform:\n\nA-for arithmetic\n\nR-for root functions\n\nT- Trigonometric\n\nE-for exit\n\n");
	 printf("Enter what to calculate: ");
	 scanf(" %c", &decision);

	 switch(decision){
		  case 'A':
				printf("Enter a number: ");
				scanf("%d", &num1);
				printf("Enter another number: ");
				scanf("%d", &num2);
				arithmetic(num1, num2);
				break;
		  case 'R':
				rootFunctions((float)num1);
				break;
		  case 'E':
				printf("Exiting the calculator. Goodbye!\n");
				break;
		  case 'T':
				trigonometricFunctions((float) num1);
				break;
		  default:
				printf("Invalid decision\n");
	 } 
	 
	 return 0;
}