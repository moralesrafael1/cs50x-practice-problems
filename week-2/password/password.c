// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string password);
bool check_lower (string password);
bool check_symbol (string password);
bool check_number (string password);
bool check_upper (string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    if (check_lower(password) && check_symbol(password) && check_number(password) && check_upper(password))
        return true;
    return false;
}

bool check_lower (string password)
{
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (islower(password[i]))
            return true;
    }
    return false;
}
bool check_symbol (string password)
{
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (ispunct(password[i]))
            return true;
    }
    return false;
}

bool check_number (string password)
{
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (isdigit(password[i]))
            return true;
    }
    return false;
}

bool check_upper (string password)
{
    for (int i = 0, len = strlen(password); i < len; i++)
    {
        if (isupper(password[i]))
            return true;
    }
    return false;
}
