#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : currindex(0), contactcount(0) {}

void PhoneBook::addcontact(Contact contact)
{
    if (contactcount == 8)
        currindex = currindex % 8;
    else
        contactcount++;
    contacts[currindex] = contact;
    currindex++;
}

int PhoneBook::get_contactcount(void) { return contactcount; }

void PhoneBook::displaycontacts(void)
{
    int contactnum = get_contactcount();

    for (int i = 0; i < contactnum; i++)
    {
        std::cout << std::setw(10) << i << '|'
                  << tranc_str(contacts[i].get_first_name()) << '|'
                  << tranc_str(contacts[i].get_last_name()) << '|'
                  << tranc_str(contacts[i].get_nick_name()) << std::endl;
    }
}

void PhoneBook::displaycontactdetails ( int index )
{
    std::cout << "First Name     :   " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name      :   " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nick Name      :   " << contacts[index].get_nick_name() << std::endl;
    std::cout << "Phone Number   :   " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret :   " << contacts[index].get_darkest_secret() << std::endl;
}