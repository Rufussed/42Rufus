#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int calculate_min_removals(char *str)
{
    int dif = 0;
    int remove = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '(')
            dif++;
        else if (str[i] == ')')
        {
            if (dif > 0)
                dif--;
            else
                remove++;
        }
        i++;
    }
    return dif + remove;
}

void remove_brackets(char *str, int pos, int min_removals)
{
    if (pos == ft_strlen(str))
    {
        int balance = calculate_min_removals(str);
        if (balance == 0 && min_removals == 0)
        {
            write(1, str, ft_strlen(str));
            write(1, "\n", 1);
        }
        return;
    }
    remove_brackets(str, pos + 1, min_removals);  // Try keeping current bracket
    if (str[pos] != '_'  && str[pos] != ' ') // Try removing current bracket
    {
       char temp = str[pos];
        str[pos] = '_'; // Remove bracket
        remove_brackets(str, pos + 1, min_removals - 1);
        str[pos] = temp; // Backtrack
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1, "Error: Expected 1 argument with only parentheses.\n", 51);
        return 1;
    }
    char *input = argv[1];

    int min_removals = calculate_min_removals(input);
    remove_brackets(input, 0, min_removals);
    return 0;
}
