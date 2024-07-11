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

    const int length = static_cast<int> (parameter.size()); 	/* C style type casting works just fine, but it's more agressive and not preferable in C++
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

std::string Contact::display_parameter(const std::string &parameter)
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
	std::cout << "Enter the first name: ";
	getline(std::cin >> std::ws, first_name);
	std::cout << "Enter the last name: ";
	getline(std::cin >> std::ws , last_name);
	std::cout << "Enter the nickname: ";
	getline(std::cin >> std::ws ,nickname);
	std::cout << "Enter the phone number: ";
	getline(std::cin >> std::ws , phone_number);
	while (!has_digit(phone_number))
	{
		std::cout << "Enter the phone number: ";
		getline(std::cin >> std::ws , phone_number);
	}
	std::cout << "Enter the darkest secret: ";
	getline(std::cin >> std::ws , darkest_secret); 	// getline() instead of regular std::cin so it consider whitespaces
													// adding std::ws so it ignore leading whitespaces
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

//	Passing std::string by reference instead of value to avoid making a copy (expensive) ---> reference is just an alias to an object but in our case its const
//	so its value can't be changed withing the scope of the function

std::string	PhoneBook::display_contactparameter(int index, const std::string& parameter)
{
	return (contacts[index].display_parameter(parameter));
}

int main(void)
{

	PhoneBook 	user;

	std::string input = ""; 

	int contact_nb = 0;
	
	//	const int * : const value 
	//	int* const : const pointer

	int index = 0;

	while(1)
	{
		std::cout << "Choose a command:\tADD\tSEARCH\tEXIT" << "\n";
		getline(std::cin >> std::ws, input);
		if (!input.compare("ADD")) // Calling ".compare()" member function of string object
		{
			std::cout << "Contact number : " << contact_nb + 1 << "\n";
			user.addcontact(contact_nb);
			contact_nb = (contact_nb + 1) % 8;
		}
		else if (!input.compare("SEARCH"))
		{
			int i = 0;
			std::cout << "     index|first name| last name|  nickname\n";
			while ( i<8 && user.checkcontact(i))
			{
				std::cout << "         ";
				std::cout << (i + 1) ;
				std::cout << "|";
				if (user.display_contactparameter(i,"first name").size() <= 10)
				    std::cout << std::string(10 - user.display_contactparameter(i, "first name").size(), ' ') + 
				        user.display_contactparameter(i, "first name").substr(0 ,10) + "|";
				else
				    std::cout << user.display_contactparameter(i,"first name").substr(0,9) + "." + "|";
				if (user.display_contactparameter(i, "last name").size() < 10)
				    std::cout << std::string(10 - user.display_contactparameter(i, "last name").size(), ' ') + 
				        user.display_contactparameter(i,"last name").substr(0,10) + "|";
				else
				    std::cout << user.display_contactparameter(i,"last name").substr(0,9) + "." + "|";
				if (user.display_contactparameter(i, "nickname").size() < 10)
				    std::cout << std::string(10 - user.display_contactparameter(i, "nickname").size(), ' ') + 
				        user.display_contactparameter(i, "nickname").substr(0,10) + "|";
				else
				    std::cout << user.display_contactparameter(i, "nickname").substr(0,9) + ".";
				std::cout << std::endl;
				i++;
			}
			std::cout << "Enter the index :";
			while (std::getline(std::cin, input))
			{
				std::stringstream ss(input);
				if (ss >> index)
				{
					if (ss.eof() && index >=1 && index <= 8)
					{   
						break;
					}
				}
				std::cout << "Error!" << std::endl;
				std::cout << "Enter the index :";
			}
			user.displaycontact(index - 1);
		}
		else if (!input.compare("EXIT"))
		{
			break;
		}
	}
	return (0);
}
