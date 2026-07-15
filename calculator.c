#include<stdio.h>
#include<string.h>
#include<stdlib.h>
double result;
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
		  case 's':
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
		  case 'c':
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
		  case 'n':
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
		float term;
		char trigFunctions, responds;
		int n;
		printf("**********************Calculation of trigonometric functions**********************\n\nS- Sine\n\nC- Cosine\n\nT- Tangent\n\n");
		printf("Enter which trigonometric function to calculate: ");
		scanf(" %c", &trigFunctions);
	 	switch(trigFunctions){
			case 's':
		  	case 'S':
				printf("calculate the iverse of sine(y/n): \n");
				scanf(" %c", &responds);
				if((responds == 'N') || (responds == 'n')){
					printf("Enter the angle in degrees to find the sine: ");
					scanf("%f", &x);
					float radian = x * (PI/180.0); // converting user into radian
					result = 0.0;
					term = radian; // first term of the Jseries
					n = 1; // term index
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
						term = x; // first term of the series
						n = 1; // term index
						while((term > 0.00001) || (term < -0.00001)){ // repeat until the term value is <= 0.00001
							term *= ((x * x) * ((2 * n - 1) * (2 * n - 1)) / ((2 * n) * (2 * n + 1))); // calculate the next term in the series
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
			case 'c':
		  	case 'C':
				printf("Calcultate the inverse of cosine(y/n): \n");
				scanf(" %c", &responds);
				if(responds == 'N' || responds == 'n'){ // takes either a capital or lowercase letter
					printf("Enter the angle in degrees to find the cosine of: ");
				scanf("%f", &x);
				float radians = x * (PI/180.0);// converting user into radian
				result = 1.0; // first term of the series
				term = 1.0; // first term of the series
				n = 2; // cosine term index 
				while(term > 0.00001 || term < -0.00001){ // repeat until the term value is <= 0.00001
					 term *= -1.0 * radians * radians / (n * (n-1)); // calculate the next term in the series
					 result += term; // add
					 n += 2; // increment the term index by 2 for cosine series 
				}
				printf("The cosine of %.2f degrees is: %.4f\n", x, result);
				} else if((responds == 'Y') || (responds == 'y')){ // takes either a capital or lowercase letter
					printf("Enter the value to find the inverse cosine of: ");
					scanf("%f", &x);
					if(x > -1.0 && x < 1.0){
						// Calculate inverse sine using Taylor series
						result = x; // first term of the series approximation
						term = x; // first term of the series
						n = 1; // term index
						while((term > 0.00001) || (term < -0.00001)){ // repeat until the term value is <= 0.00001
							term *= ((x * x) * ((2 * n - 1) * (2 * n - 1)) / ((2 * n) * (2 * n + 1))); // calculate the next term in the series
							result += term; // add to result
							n++; // increment the term index by 1 for inverse sine series
						}
						result = (PI /2.0) - result; // convert the inverse of sine into cos since both works similarly
						result *= (180.0 / PI); // convert result from radians to degrees
						
						printf("The inverse of cosine of %.4f is: %.4f degrees\n", x, result);
					} else {
						printf("Invalid input. Please enter a value between -1 and 1.\n");
					}
				}

			break;
			case 't':
		  	case 'T':
			char response;
				printf("Do you want to calculate the inverse of tan(y/n): ");
				scanf("%s", &response);
				if(response =='N' || response =='n'){
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
				} else if(response == 'Y' || response == 'y'){
					printf("Enter the value of the inverse tan of: ");
					scanf("%f", &x);
					if(x > -1.0 && x < 1.0){
						//Calculate the arctan using taylor series
						result = x; // first term of the approximation
						term = x; // fitst term of the of the series
						n = 1; // term index
						while((term > 0.00001) || (term < -0.00001)){ // repeat until the term value is <= 0.00001
							term *= -1.0 * (x * x) * (2.0 * n - 1) / (2.0 * n + 1); //calculate the next term in the series
							result += term; // add to result
							n++; // increment the term index by 1 for inverse sine series
					}
					result *= (180.0 / PI); // convert result from radians to degrees

					printf("The inverse sine of %.4f is: %.4f degrees\n", x, result);
				} else {
						printf("Invalid input. Please enter a value between -1 and 1.\n");
					}
			break;
			default:
				printf("Invalid trigonometric function\n");
	 
	 	}
	}
}
// end of trig functions

// combination
int combination(float x, float y){
	printf("****************Combinations calculations********************\n\n");

	printf("Enter combination number: ");
	scanf("%f", &x);
	printf("Enter the set combine number: ");
	scanf("%f", &y);
	// checks if the combination number matches the rules for combination
	if(x >= y){
		float numerator = 1.0, denominator = 1.0;
		int i=1, decrement = x-y;
		while(x > decrement){
			numerator *= x;
			denominator *= i;
			x--;// makes the loop to finite value
			i++;// inrement to make the denominator reduces after each execution
		}
		result = numerator / denominator;
		printf("combination = %.4f\n\n", result);
	} else{
		printf("Mathematical error!");// returns this condition do not match
	}

}
// end of combination

// permutation
	int permutation(float x, float y){
		printf("*********Welcome to permutation\n");
		printf("Enter two number to calculate permutation: ");
		scanf("%f %f", &x, &y);
		if(x >= y){
			float initial = x;
			result = 1.0;
			while(y != 0){
				result *= x;
				x--;
				y--;
			}
			printf("Permutaion = %.4lf\n\n", result);
		} else{
			printf("Mathematical error!\n\n");
		}
	}
// end of permutation

// factorial
	int factorial(float x){
		printf("***********Welcome to factorial function***********\n\n");
		printf("Enter a factorial number: ");
		scanf("%f", &x);
		result = 1.0;
		while(x != 0){ // condtion stops when x reaches 0
			result *= x; // performs the factorial calculation
			x--;
		}
		printf("Factorial = %.2f\n\n", result);
	}
// end of factorial

// inverse function
int inverseFunction(float x){
	printf("*************welcome to inverse function*************\n\n");
	printf("Enter the inverse number: ");
	scanf("%f", &x);
	result = 1 / x;

	printf("Inverse = %.4f\n\n", result);
}
// end of inverse function

// logarithm function()
float logarithm(float x){
	float log;
	printf("*************welcome to loagarithm function*************\n\n");
	printf("Enter a number to calculate its Napenian log: ");
	scanf("%f", &x);
	if(x <= 0){
		printf("Math error!!!");
	} else{
		result = x / 2;// 2 is the root value we are trying to look for!!!
		int counter = 0;
		
		while(x > 1.5){
			x = result / 2.0; // Reusing x as the square root holder
			// conditions to calculate the square root of a number
			while(((x * x - result) > 0.00001) || ((result - x * x) > 0.00001)){ // repeat until result value is <= 0.00001

				x = (x + result / x) / 2.0;				
			}
			counter +=1;// give the number of times the square root was calculated
			// At the end of the "x > 1.5" block (around line 356)
			result = x;
			x = result; // Updates x so the while(x > 1.5) check can eventually become false!
			
		}
		while(x < 0.5){
			x = result / 2.0; // Reusing x as the square root holder
			// conditions to calculate the square root of a number
			while(((x * x - result) > 0.00001) || ((result - x * x) > 0.00001)){ // repeat until result value is <= 0.00001

				x = (x + result / x) / 2.0;			
			}
			counter ++;// give the number of times the square root was calculated	
			// At the end of the "x > 1.5" block (around line 356)
			result = x;
			x = result; // Updates x so the while(x > 1.5) check can eventually become false!
			
		}
		float z = result - 1.0;
		// Taylor series: z - (z^2)/2 + (z^3)/3
		result = z - (z * z) / 2.0 + (z * z * z) / 3.0 - (z * z * z * z) / 4.0 + (z * z * z * z * z) / 5.0;

		while(counter > 0){
    		result = result * 2.0;
    		counter-=1;
		}

			// logarithm
			// 3. Taylor Series calculation (z is calculated from the final scaled 'result')
		// Store the initial approximation in our new 'log' variable
		log = z - (z * z) / 2.0 + (z * z * z) / 3.0 - (z * z * z * z) / 4.0 + (z * z * z * z * z) / 5.0;

		// 4. Derive the final log by scaling 'log' instead of 'result'
		while (counter > 0) {
			log = log * 2.0;
			counter -= 1;
		}
		while (counter < 0) {
			log = log / 2.0;
			counter += 1;
		}
		// end of logarithm
	}
	
	printf("Napenian log = %.4f\n", result);
	printf("log result = %.4f\n", log);

}
// end of logarithm function


int main(){
	 int num1, num2;
	 char decision;

	 printf("Welcome to the calculator!\nchoose the option you want to perform:\n\nA-for arithmetic\n\nR-for root functions\n\nT- Trigonometric\n\nC-Combination\n\nP-Permutation\n\nF-Factorial\n\nI-Inverse\n\nL-Logarithm\n\nE-for exit\n\n");
	 printf("Enter what to calculate: ");
	 scanf(" %c", &decision);

	 switch(decision){
		  case 'a':
		  case 'A':
				printf("Enter a number: ");
				scanf("%d", &num1);
				printf("Enter another number: ");
				scanf("%d", &num2);
				arithmetic(num1, num2);
				break;
		  case 'r':
		  case 'R':
				rootFunctions((float)num1);
				break;
		  case 't':
		  case 'T':
				trigonometricFunctions((float) num1);
				break;
		 case 'c':
		  case 'C':
		       combination(num1, num2);
			   break;
		  case 'p':
		  case 'P':
		  		permutation(num1, num2);
				break;
		  case 'f':
		  case 'F':
		  		factorial(num1);
				break;
		  case 'i':
		  case 'I':
		  		inverseFunction(num1);
				break;
		  case 'l':
		  case 'L':
		  		logarithm(num1);
				break;
		  case 'e':
		  case 'E':
				printf("Exiting the calculator. Goodbye!\n");
				break;
		  default:
				printf("Invalid decision\n");
	 } 
	 
	 return 0;
}