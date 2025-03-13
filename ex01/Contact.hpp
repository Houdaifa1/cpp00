
# ifndef CONTACT_HPP
# define CONTACT_HPP

# include "Phonebook.hpp"



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

# endif