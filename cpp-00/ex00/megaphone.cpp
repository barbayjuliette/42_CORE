#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) 
{
	int i = 1;
	int	j;

	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			cout << (char)toupper(argv[i][j]);
			j++;
		}
		// if (i != argc - 1)
		// 	cout << " ";
		++i;
	}
	cout << endl;
	return (0);
} 