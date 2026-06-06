#include<stdio.h>
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
int main(){
    int num1, num2;
    
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter another number: ");
    scanf("%d", &num2);
    
    arithmetic(num1, num2);
    return 0;
}