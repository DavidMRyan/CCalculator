#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "main.h"
#include "src/math.h"

int main()
{
    char cont[1] = {0};
    char operation[1] = {0};
    int iter = 0;

    do
    {
        if(iter > 0)
        {
            switch(tolower(cont[0]))
            {
                case 'y':
                    operation[0] = get_operation();
                    handle_operation(operation[0]);
                    break;
                case 'n':
                default:
                    printf("\nYou successfully did %d operation(s)!\n", iter);
                    return 0;
            }
        }
        else
        {
            operation[0] = get_operation();
            handle_operation(operation[0]);
        }
        iter++;

        printf("Would you like to continue? (Y or N)\n");
        fflush(stdin);
        cont[0] = fgets(cont, 2, stdin)[0];
    }
    while(cont[0] == 'y');

    return 0;
}

char get_operation()
{
    char selection[1] = {0};
    printf("Please select an operation:\n");
    printf("1) Addition\n2) Subtraction\n3) Multiplication\n4) Division\n");

    fflush(stdin);
    return fgets(selection, 2, stdin)[0];
}

void handle_operation(char operation)
{
    char first_num[128] = {0};
    char second_num[128] = {0};

    fflush(stdin);
    printf("Please enter the first number:\n");
    fgets(first_num, sizeof(first_num), stdin);

    fflush(stdin);
    printf("Please enter a second number:\n");
    fgets(second_num, sizeof(second_num), stdin);

    // @todo: figure out conditional to check for floating point numbers, defaulting to integers for now.
    switch(operation)
    {
        case '1':
            printf("\nResult: %d\n", add_i(atoi(first_num), atoi(second_num)));
            break;
        case '2':
            printf("\nResult: %d\n", subtract_i(atoi(first_num), atoi(second_num)));
            break;
        case '3':
            printf("\nResult: %d\n", mul_i(atoi(first_num), atoi(second_num)));
            break;
        case '4':
            printf("\nResult: %d\n", div_i(atoi(first_num), atoi(second_num)));
            break;
        default:
            printf("Warning: Your selection is not valid, please select a valid operation!\n");
            break;
    }
}