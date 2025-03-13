
# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


#include <iostream>
#include <stdlib.h>
#include <iomanip>
# include "Contact.hpp"

std::string tranc_str(std::string str);

class Phonebook
{
private:
    Contact contacts[8];
    int currindex;
    int contactcount;

public:
    Phonebook() : currindex(0), contactcount(0) {}
    void addcontact(Contact contact)
    {
        if (contactcount == 8)
            currindex = currindex % 8;
        else
            contactcount++;
        contacts[currindex] = contact;
        currindex++;
    }

    int get_contactcount(){
        return contactcount;
    }

    void displaycontacts(){
        int contactnum = get_contactcount();

        for (int i = 0; i < contactnum; i++)
        {
            std::cout << std::setw(10) << i << '|'
            << tranc_str(contacts[i].get_first_name()) << '|'
            << tranc_str(contacts[i].get_last_name()) << '|'
            << tranc_str(contacts[i].get_nick_name()) << std::endl;
        } 
    }
    
    void displaycontactdetails(int index)
    {
        std::cout << "First Name     :   " << contacts[index].get_first_name() << std::endl;
        std::cout << "Last Name      :   " << contacts[index].get_last_name() << std::endl;
        std::cout << "Nick Name      :   " << contacts[index].get_nick_name() << std::endl;
        std::cout << "Phone Number   :   " << contacts[index].get_phone_number() << std::endl;
        std::cout << "Darkest Secret :   " << contacts[index].get_darkest_secret() << std::endl;
    }
};


std::string tranc_str(std::string str);
int     check_if_empty_isprint(std::string &str);
int     check_if_empty_isprint_isnum(std::string &str);
void    get_input(std::string str, std::string &input);
int     get_search_index();

# endif