#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Inside Brain constructor !\n";
}

Brain::~Brain()
{
    std::cout << "Inside Brain destructor !\n";
}

Brain::Brain(const Brain& _copy)
{
    std::cout << "Inside Brain copy constructor !\n";
    *this = _copy;
}

Brain& Brain::operator=(const Brain& _copy)
{
    std::cout << "Inside Brain copy assignment operator !\n";
    if (this == &_copy)
        return *this;
    for(int i = 0;i < 100; i++)
        this->ideas[i] = _copy.ideas[i];
    return *this;
}