
# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>



std::string tranc_str(std::string str);

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

public:
    void set_first_name(std::string first_name){
        this->first_name = first_name;
    }
    void set_last_name(std::string last_name){
        this->last_name = last_name;
    }
    void set_nick_name(std::string nick_name){
        this->nick_name = nick_name;
    }
    void set_phone_number(std::string phone_number){
        this->phone_number = phone_number;
    }
    void set_darkest_secret(std::string darkest_secret){
        this->darkest_secret = darkest_secret;
    }
    std::string get_first_name(){
        return first_name;
    }
    std::string get_last_name(){
        return last_name;
    }
    std::string get_nick_name(){
        return nick_name;
    }
    std::string get_phone_number(){
        return phone_number;
    }
    std::string get_darkest_secret(){
        return darkest_secret;
    }
};

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