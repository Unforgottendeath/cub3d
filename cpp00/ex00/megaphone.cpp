#include <iostream>

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i = 1;
		while ( av[i])
		{
			int j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && av[i][j] <= 'z')
					std::cout << (char)(av[i][j] - 32);
				else
					std::cout << av[i][j];
				j++;
			}
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
}

