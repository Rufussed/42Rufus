#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

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

void remove_brackets(char *str, int pos, int min_found)
{
    // If we reached the end, check if it's balanced
    if (pos == ft_strlen(str))
    {
        int balance = check_balance(str);
        if (balance >= 0 && balance == min_found)
        {
            write(1, str, ft_strlen(str));
            write(1, " $\n", 3);
        }
        return;
    }

    // Skip spaces and move to next position
    if (str[pos] == '_' || str[pos] == ' ')
    {
        remove_brackets(str, pos + 1, min_found);
        return;
    }

    // Try keeping current bracket
    remove_brackets(str, pos + 1, min_found);

    // Try removing current bracket
    char temp = str[pos];
    str[pos] = '_';
    remove_brackets(str, pos + 1, min_found);
    str[pos] = temp;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        puts("Error: expected 1 str string with only brackets ()");
        return 1;
    }

    char str[1024];
    int i = 0;
    while (argv[1][i])
    {
        str[i] = argv[1][i];
        i++;
    }
    str[i] = '\0';

    // Find minimum spaces needed
    char temp[1024];
    int j;
    int min_spaces = ft_strlen(str);
    
    // Try all possibilities to find minimum first
    for (i = 0; i < (1 << ft_strlen(str)); i++)
    {
        j = 0;
        while (argv[1][j])
        {
            temp[j] = (i & (1 << j)) ? '_' : argv[1][j];
            j++;
        }
        temp[j] = '\0';
        int balance = check_balance(temp);
        if (balance >= 0 && balance < min_spaces)
            min_spaces = balance;
    }

    // Then find all solutions with that minimum
    remove_brackets(str, 0, min_spaces);
    return 0;
}
