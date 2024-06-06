#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * is_digit - checks if a string consists only of digits
 * @s: string to check
 *
 * Return: 1 if the string is composed only of digits
 */
int is_digit(char *s)
{
    for (int i = 0; s[i]; i++)
    {
        if (!isdigit(s[i]))
            return (0);
    }
    return (1);
}

/**
 * multiply - two numbers represented as strings
 * @num1: first number
 * @num2: second number
 */
void multiply(char *num1, char *num2)
{
    int len_numb1 = strlen(num1);
    int len_numb2 = strlen(num2);
    int len_result = len_numb1 + len_numb2;
    int *result = calloc(len_result, sizeof(int));

    for (int i = len_numb1 - 1; i >= 0; i--)
    {
        for (int j = len_numb2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    int i = 0;
    while (i < len_result && result[i] == 0)
        i++;

    if (i == len_result)
        printf("0");
    else
    {
        while (i < len_result)
            printf("%d", result[i++]);
    }
    printf("\n");

    free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if successful,
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return (98);
    }

    if (!is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("Error\n");
        return (98);
    }

    multiply(argv[1], argv[2]);

    return (0);
}
