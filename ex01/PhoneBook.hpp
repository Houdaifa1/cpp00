# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"


class PhoneBook
{
private:
    Contact contacts[8];
    int currindex;
    int contactcount;

public:
    PhoneBook( void );
    void addcontact( Contact contact );
    int get_contactcount( void );
    void displaycontacts( void );
    void displaycontactdetails( int index );
};


std::string tranc_str(std::string str);
int     check_if_empty_isprint(std::string &str);
int     check_if_empty_isprint_isnum(std::string &str);
void    get_input(std::string str, std::string &input);
int     get_search_index();

# endif