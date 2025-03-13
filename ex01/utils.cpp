# include "Phonebook.hpp"
# include "Contact.hpp"

std::string tranc_str(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return std::string(10 - str.length(), ' ') + str;
}

int check_if_empty_isprint(std::string &str)
{
    size_t start_pos;
    size_t end_pos;

    start_pos = str.find_first_not_of(" \t\n\v\f\r");
    end_pos = str.find_last_not_of(" \t\n\v\f\r");
    for (size_t i = 0; i < str.size(); i++)
    {
        if (std::isprint(str[i]) == 0)
        {
            std::cout << "Characters non printable try again !!" << std::endl;
            return (1);
        }
    }
    if (start_pos == std::string::npos || end_pos == std::string::npos)
    {
        std::cout << "Field is empty try again !!" << std::endl;
        return (1);
    }
    str = str.substr(start_pos, end_pos - start_pos + 1);
    return (0);
}

int check_if_empty_isprint_isnum(std::string &str)
{
    if (check_if_empty_isprint(str))
        return(1);
    for (size_t i = 0; i < str.size(); i++){
        if (!(str[i] >= '0' && str[i] <= '9'))
        {
            std::cout << "Field non numeric value !!" << std::endl;
            return (1);
        }
    }
    return (0);
}

void get_input(std::string str, std::string &input)
{
    std::cout << str;
    std::getline(std::cin, input);
}

int get_search_index()
{
    std::string index;

    get_input("Enter index for more detailed infos :   ", index);
    while (check_if_empty_isprint_isnum(index))
        get_input("Enter index for more detailed infos :   ", index);
    int idx = std::atoi(index.c_str());
    return idx;
}