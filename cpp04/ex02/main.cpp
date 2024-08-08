#include "Dog.hpp"

int main()
{
// Cat fred("Fred");
// Cat misty( "Misty" );
// Cat zeke( "Zeke" );

// Dog garbo( "Garbo") ;
// Dog pooky("Pooky" );
// Dog truffle( "Truffle" );

// // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
// Animal* animals[6] = {&fred, &garbo, &misty, &pooky, &truffle, &zeke };

// for (int i = 0; i< 6; i++){
//     std::cout << animals[i]->getType() << " says " ;animals[i]->makeSound(); std::cout << std::endl;
// }
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

return 0;
}