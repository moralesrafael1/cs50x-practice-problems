// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string s);

int main(int argc, string argv[])
{
    // accept single command-line [x]
    while (argc != 2)
    {
        printf("Wrong usage! ./no-vowels [choose a word to eliminate vowes]\n");
        return 1;
    }
    printf("%s \n", replace (argv[1]));
}

string replace(string s)
{
// for loop para iterar entre todos os caracteres e checar vogais
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (s[i] == 'a')
        s[i] = '6';
        else if (s[i] == 'e')
        s[i] = '3';
        else if (s[i] == 'i')
        s[i] = '1';
        else if (s[i] == 'o')
        s[i] = '0';
    }
return s;
}
