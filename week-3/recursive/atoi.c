#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    if (input[0] == '\0')                   //Base case: Quando o primeiro caractere for NULL '\0'
        return 0;

    int len = strlen(input);                //tamanho da string(input)
    int last = input[len - 1] - '0';        //último caractere [len-1] é convertido a int (-'0')
    input[len-1] = '\0';                    //Modifica o último valor para '\0'

    return (convert(input) * 10) + last;    //chamada recursiva, o que resta do input (input-1 char)
                                            //é jogado novamente na função até atingir o base case da linha 28;
}
