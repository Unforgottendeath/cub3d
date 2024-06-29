#include "phonebook.hpp"

int		Contact::check()
{
	if (first_name.empty())
		return (0);
	return (1);
}

int has_digit(std::string parameter)
{
    int i {0};

    const int length {static_cast<int> (parameter.size())}; 	/* C style type casting works just fine, but it's more agressive and not preferable in C++
																	C style initialization is more agressive on narrowing conversions brace initialization is more secure
																		length is declared constant cause its never changed later on ... we would use constexpr
																			if we iniatialized length with a const value */ 
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
    	getline(std::cin >> std::ws, first_name);
	}
	while ( last_name.empty() ) 
	{
    	std::cout << "Enter the last name: ";
    	getline(std::cin >> std::ws , last_name);	
	}
	while ( nickname.empty() )
	{
    	std::cout << "Enter the nickname: ";
    	getline(std::cin >> std::ws ,nickname);
	}
	while ( phone_number.empty() || !has_digit(phone_number))
	{
    	std::cout << "Enter the phone number: ";
    	getline(std::cin >> std::ws , phone_number);
	}
	while ( darkest_secret.empty() )
	{
    	std::cout << "Enter the darkest secret: ";
    	getline(std::cin >> std::ws , darkest_secret); 	// getline() instead of regular std::cin so it consider whitespaces
														// adding std::ws so it ignore leading whitespaces
	}
}

void 	Contact::display() {
    std::cout << "\nContact Details:" << "\n";	// prefers "\n" cause std::endl flushes our buffer every time we call it...
    std::cout << "First Name: " << first_name << "\n";
    std::cout << "Last Name: " << last_name << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone Number: " << phone_number << "\n";
    std::cout << "Darkest Secret: " << darkest_secret << "\n";
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

	PhoneBook 	user;

	std::string input; 	// preferable to use std::string_view for read_only strings so u don't have to make copies of string on every call
						// requires <string_view> library
	int contact_nb {0};
	
	int index;

	while(1)
	{
		std::cout << "Choose a command:\tADD\tSEARCH\tEXIT" << "\n";
		getline(std::cin >> std::ws, input);
		if (!input.compare("ADD")) // Calling ".compare()" member function of string object
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
				    std::cout << std::string(10 - user.display_contactparameter(i, "first name").size(), ' ') + 
				        user.display_contactparameter(i, "first name").substr(0 ,10) + "|";
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
			std::cin >> index; 		// can ignore whitespaces just fine
			user.displaycontact(index - 1);
		}
		else if (!input.compare("EXIT"))
		{
			break;
		}
	}
	exit(0);
}
