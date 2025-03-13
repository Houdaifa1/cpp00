# include "Phonebook.hpp"
# include "Contact.hpp"



int check_if_commande_valid(std::string commande)
{
    if (commande == "ADD")
        return (1);
    else if (commande == "SEARCH")
        return (2);
    else if (commande == "EXIT")
        exit(0);
    return (3);
}

void add_operation(std::string &first_name, std::string &last_name,
                   std::string &nick_name, std::string &phone_number, std::string &darkest_secret)
{
    get_input("Enter First Name :   ", first_name);
    while (check_if_empty_isprint(first_name))
        get_input("Enter First Name :   ", first_name);
    get_input("Enter Last Name :   ", last_name);
    while (check_if_empty_isprint(last_name))
        get_input("Enter Last Name :   ", last_name);
    get_input("Enter Nick Name :   ", nick_name);
    while (check_if_empty_isprint(nick_name))
        get_input("Enter Nick Name :   ", nick_name);
    get_input("Enter Phone Number :   ", phone_number);
    while (check_if_empty_isprint(phone_number))
        get_input("Enter Phone Number :   ", phone_number);
    get_input("Enter Drakest Secret :   ", darkest_secret);
    while (check_if_empty_isprint(darkest_secret))
        get_input("Enter Darkest Secret :   ", darkest_secret);
}


void search_operation(Phonebook &phonebook)
{
    if (phonebook.get_contactcount() == 0)
    {
        std::cout << "No Added Contacts Yet !!" << std::endl;
        return;
    }
    phonebook.displaycontacts();
    int idx = get_search_index();
    while (idx >= phonebook.get_contactcount())
    {
        std::cout << "Index out of range !!" << std::endl;
        idx = get_search_index();
    }
    phonebook.displaycontactdetails(idx);
}

void do_operation(int oper_num, Phonebook &phonebook)
{
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

    if (oper_num == 3)
    {
        std::cout << "Please enter one of these commands ADD or SEARCH or EXIT !!" << std::endl;
        return;
    }
    if (oper_num == 1)
    {
        add_operation(first_name, last_name, nick_name, phone_number, darkest_secret);
        Contact contact;
        contact.set_first_name(first_name);
        contact.set_last_name(last_name);
        contact.set_nick_name(nick_name);
        contact.set_phone_number(phone_number);
        contact.set_darkest_secret(darkest_secret);
        phonebook.addcontact(contact);
    }
    if (oper_num == 2)
        search_operation(phonebook);
}

int main()
{
    Phonebook phonebook;
    std::string commande;

    while (1)
    {
        get_input("Enter ADD or SEARCH or EXIT :   ", commande);
        do_operation(check_if_commande_valid(commande), phonebook);
    }
    return (0);
}