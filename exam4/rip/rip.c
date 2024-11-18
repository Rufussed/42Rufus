#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

/*
the return  tells us:
-1: This string is impossible to balance or still unbalanced
≥0: The string is balanced and the number tells us how many brackets were removed
*/
int check_balance(char *str)
{
    int dif = 0;
    int spaces = 0;
    int i = 0;
    while (str[i])
    {
        if (str[i] == '(')
            dif++;
        if (str[i] == ')')
            dif--;
        if (str[i] == '_')
            spaces++;
        if (dif < 0)
            return -1;
        i++;
    }
    if (dif == 0)
        return spaces;
    return -1;
}

void remove_brackets(char *str, int pos)
{
    static int min_spaces = 1024;
    static int first_pass = 1;
    
    if (pos == ft_strlen(str))
    {
        int balance = check_balance(str);
        if (balance >= 0)
        {
            if (first_pass)
            {
                if (balance < min_spaces)
                    min_spaces = balance;
            }
            else if (balance == min_spaces)
            {
                write(1, str, ft_strlen(str));
                write(1, "\n", 1);
            }
        }
        return;
    }

    // Try keeping current bracket
    remove_brackets(str, pos + 1);

    // Try removing current bracket
    if (str[pos] != '_')
    {
        char temp = str[pos];
        str[pos] = '_';
        remove_brackets(str, pos + 1);
        str[pos] = temp;
    }
    
    if (pos == 0 && first_pass)
    {
        first_pass = 0;
        remove_brackets(str, 0);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        puts("Error: expected 1 str string with only brackets ()");
        return 1;
    }
    remove_brackets(argv[1], 0);    
    return 0;
}