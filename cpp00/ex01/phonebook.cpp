#include "phonebook.hpp"

int		Contact::check()
{
	if (first_name.empty())
		return (0);
	return (1);
}
int has_digit(std::string parameter)
{
    int i = 0;
    int length = (int)parameter.size();
    while (i < length)
    {
        if (parameter[i] < 48 || parameter[i] > 57)
            return 0;
        i++;
    }
    return 1;
}
std::string Contact::display_parameter(std::string parameter)
{
	if ( !parameter.compare("first name"))
		return first_name;
	else if ( !parameter.compare("last name"))
		return last_name;
	else if ( !parameter.compare("nickname"))
		return nickname;
	else if ( !parameter.compare("phone number"))
		return phone_number;
	return darkest_secret;
}

void 	Contact::add() {
	while ( first_name.empty() )
	{
    	std::cout << "Enter the first name: ";
    	getline(std::cin, first_name);
	}
	while ( last_name.empty() ) 
	{
    	std::cout << "Enter the last name: ";
    	getline(std::cin , last_name);	
	}
	while ( nickname.empty() )
	{
    	std::cout << "Enter the nickname: ";
    	getline(std::cin ,nickname);
	}
	while ( phone_number.empty() || !has_digit(phone_number))
	{
    	std::cout << "Enter the phone number: ";
    	getline(std::cin, phone_number);
	}
	while ( darkest_secret.empty() )
	{
    	std::cout << "Enter the darkest secret: ";
    	getline(std::cin , darkest_secret);
	}
}

void 	Contact::display() {
    std::cout << "\nContact Details:" << std::endl;
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

void	PhoneBook::addcontact(int index)
{
	contacts[index].add();
}

void	PhoneBook::displaycontact(int index)
{
	contacts[index].display();
}

int	PhoneBook::checkcontact(int index)
{
	if (contacts[index].check())
		return 1;
	return 0;
}

std::string	PhoneBook::display_contactparameter(int index, std::string parameter)
{
	return (contacts[index].display_parameter(parameter));
}

int main(void)
{
	PhoneBook user;
	std::string input;
	int contact_nb = 0;
	int index;
	while(1)
	{
		std::cout << "Choose a command:\tADD\tSEARCH\tEXIT" << std::endl;
		getline(std::cin, input);
		if (!input.compare("ADD"))
		{
			user.addcontact(contact_nb);
			contact_nb = (contact_nb + 1) % 8;
		}
		else if (!input.compare("SEARCH"))
		{
			int i = 0;
			while (user.checkcontact(i))
			{
				std::cout << "     index|first name| last name|  nickname\n";
				std::cout << "         ";
				std::cout << (i + 1) ;
				std::cout << "|";
				if (user.display_contactparameter(i,"first name").size() <= 10)
				    std::cout << std::string(10 - user.display_contactparameter(i,"first name").size(), ' ') + 
				        user.display_contactparameter(i,"first name").substr(0,10) + "|";
				else
				    std::cout << user.display_contactparameter(i,"first name").substr(0,9) + "." + "|";
				if (user.display_contactparameter(i,"last name").size() < 10)
				    std::cout << std::string(10 - user.display_contactparameter(i,"last name").size(), ' ') + 
				        user.display_contactparameter(i,"last name").substr(0,10) + "|";
				else
				    std::cout << user.display_contactparameter(i,"last name").substr(0,9) + "." + "|";
				if (user.display_contactparameter(i,"nickname").size() < 10)
				    std::cout << std::string(10 - user.display_contactparameter(i,"nickname").size(), ' ') + 
				        user.display_contactparameter(i,"nickname").substr(0,10) + "|";
				else
				    std::cout << user.display_contactparameter(i,"nickname").substr(0,9) + ".";
				std::cout << std::endl;
				i++;
			}
			std::cout << "Enter the index :";
			std::cin >> index;
			user.displaycontact(index - 1);
		}
		else if (!input.compare("EXIT"))
		{
			break;
		}
	}
	exit(0);
}
