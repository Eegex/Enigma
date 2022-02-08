#include <iostream>
#include <string>
#include <vector>

char index(std::vector<char>* vec, char c)
{
	char index = 0;
	for (char& z : *vec)
	{
		if (z == c)
		{
			return index;
		}
		index++;
	}
}

int main()
{
	short posA = 0;
	short posB = 0;
	short posC = 0;           // {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}
	std::vector<char> rotorI = { 'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J' };
	std::vector<char> rotorII = { 'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E' };
	std::vector<char> rotorIII = { 'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O' };
	std::vector<char> rotorIV = { 'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B' };
	std::vector<char> rotorV = { 'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K' };
	std::vector<char> ukwA = { 'E','J','M','Z','A','L','Y','X','V','B','W','F','C','R','Q','U','O','N','T','S','P','I','K','H','G','D' };
	std::vector<char> ukwB = { 'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T' };
	std::vector<char> ukwC = { 'F','V','P','J','I','A','O','Y','E','D','R','Z','X','W','G','C','T','K','U','Q','S','B','N','M','H','L' };
	std::vector<char> plugboard = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	//Setup
	{
		for (char& c : rotorI)
		{
			c -= 'A';
		}
		for (char& c : rotorII)
		{
			c -= 'A';
		}
		for (char& c : rotorIII)
		{
			c -= 'A';
		}
		for (char& c : rotorIV)
		{
			c -= 'A';
		}
		for (char& c : rotorV)
		{
			c -= 'A';
		}
		for (char& c : ukwA)
		{
			c -= 'A';
		}
		for (char& c : ukwB)
		{
			c -= 'A';
		}
		for (char& c : ukwC)
		{
			c -= 'A';
		}
		for (char& c : plugboard)
		{
			c -= 'A';
		}
	}

	std::string m;
	std::cout << "M:";
	std::cin >> m;

	std::vector<char>* rotorA = &rotorI;
	std::vector<char>* rotorB = &rotorII;
	std::vector<char>* rotorC = &rotorIII;
	std::vector<char>* ukw = &ukwB;

	std::string c;

	for (char z : m)
	{
		posA = (posA + 1) % 26;
		if (!posA)
		{
			posB = (posB + 1) % 26;
			if (!posB)
			{
				posC = (posC + 1) % 26;
			}
		}
		std::cout << posA << " " << posB << " " << posC;
		z -= 'A';
		printf("Eingabe: %c ", z + 'A');
		z = plugboard.at(z);
		printf("Plugboard: %c ", z + 'A');
		z = (rotorA->at((z + posA) % 26) + 26 - posA) % 26;
		printf("Rotor A: %c ", z + 'A');
		z = (rotorB->at((z + posB) % 26) + 26 - posB) % 26;
		printf("Rotor B: %c ", z + 'A');
		z = (rotorC->at((z + posC) % 26) + 26 - posC) % 26;
		printf("Rotor C: %c ", z + 'A');
		z = ukw->at(z);
		printf("UKW: %c ", z + 'A');
		z = (index(rotorC, (z + posC) % 26) + 26 - posC) % 26;
		printf("Rotor C: %c ", z + 'A');
		z = (index(rotorB, (z + posB) % 26) + 26 - posB) % 26;
		printf("Rotor B: %c ", z + 'A');
		z = (index(rotorA, (z + posA) % 26) + 26 - posA) % 26;
		printf("Rotor A: %c ", z + 'A');
		z = index(&plugboard, z);
		printf("Plugboard: %c \n", z + 'A');
		c.push_back(z + 'A');
	}
	std::cout << "C:" << c << std::endl;
}
