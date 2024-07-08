#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <sstream>

class Contact {

private:
    std::string first_name ;
    std::string last_name ;
    std::string nickname ;
    std::string phone_number ;
    std::string darkest_secret ;

public:
    void 		add();
	int  		check();
	std::string display_parameter(const std::string &parameter); // getter function return by const reference
	void 		display();
};

class PhoneBook : public Contact{
    Contact contacts[8];

public:
    void        addcontact(int i) ;
    void        displaycontact(int i) ;
	int         checkcontact(int i);
	std::string display_contactparameter(int index, const std::string& parameter);
};

#endif
