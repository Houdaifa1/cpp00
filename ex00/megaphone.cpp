#include <iostream>

int main (int arc, char **arv)
{
    if (arc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    else
    {
        for (int i = 1; arv[i]; i++)
        {
            for(int j = 0; arv[i][j]; j++)
                std::cout << (char)toupper(arv[i][j]);
        }
        std::cout << std::endl;
    }
} 
