#include <iostream>
#include <string>
#include <vector>


struct Walze
{
	char ring = 0;
	char pos = 0;
	const char mark = 0;
	std::vector<char> kabel;
	Walze(char mark, std::vector<char> kabel, char ring = 1,  char pos = 'A') : ring(ring - 1), pos(pos - 'A'), mark(mark - 'A')
	{
		for(char & c : kabel)
		{
			this->kabel.push_back(c - 'A');
		}
	}
	Walze(std::vector<char> kabel) : ring(0), pos(0)
	{
		for(char i = 0; i < 26; i++)
		{
			this->kabel.push_back(i);
		}
		for(char & c : kabel)
		{
			c -= 'A';
		}
		for(char i = 0; i < kabel.size() / 2; i++)
		{
			this->kabel[kabel[2 * i]] = kabel[2 * i + 1];
			this->kabel[kabel[2 * i + 1]] = kabel[2 * i];
		}
	}
	Walze setup(char ring, char pos)
	{
		this->ring = ring - 1;
		this->pos = pos - 'A';
		return *this;
	}
	char operator[](char i)
	{
		return (kabel[(26 + i + pos - ring) % 26] + 26 - pos + ring) % 26;
	}
	char operator()(char c)
	{
		c = (c + 26 + pos - ring) % 26;
		char index = 0;
		for(char& z : kabel)
		{
			if(z == c)
			{
				return (index + 26 - pos + ring) % 26;
			}
			index++;
		}
	}
	bool operator<<(bool mark)
	{
		if(mark)
		{
			pos = ++pos % 26;
			return this->mark == pos;
		}
		return false;
	}
};

int main()
{
	//                      {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}
	Walze rotorI =    {'P', {'E','K','M','F','L','G','D','Q','V','Z','N','T','O','W','Y','H','X','U','S','P','A','I','B','R','C','J'}};
	Walze rotorII =   {'D', {'A','J','D','K','S','I','R','U','X','B','L','H','W','T','M','C','Q','G','Z','N','P','Y','F','V','O','E'}};
	Walze rotorIII =  {'U', {'B','D','F','H','J','L','C','P','R','T','X','V','Z','N','Y','E','I','W','G','A','K','M','U','S','Q','O'}};
	Walze rotorIV =   {'I', {'E','S','O','V','P','Z','J','A','Y','Q','U','I','R','H','X','L','N','F','T','G','K','D','C','M','W','B'}};
	Walze rotorV =    {'Y', {'V','Z','B','R','G','I','T','Y','U','P','S','D','N','H','L','X','A','W','M','J','Q','O','F','E','C','K'}};
	Walze ukwA =      {'A', {'E','J','M','Z','A','L','Y','X','V','B','W','F','C','R','Q','U','O','N','T','S','P','I','K','H','G','D'}};
	Walze ukwB =      {'A', {'Y','R','U','H','Q','S','L','D','P','X','N','G','O','K','M','I','E','B','F','Z','C','W','V','J','A','T'}};
	Walze ukwC =      {'A', {'F','V','P','J','I','A','O','Y','E','D','R','Z','X','W','G','C','T','K','U','Q','S','B','N','M','H','L'}};
	Walze plugboard = {{'A','D','C','N','E','T','F','L','G','I','J','V','K','Z','P','U','Q','Y','W','X',}};
	
	std::string m;
	std::cout << "M:";
	std::cin >> m;

	Walze rotorA = rotorIII.setup(8, 'Z');
	Walze rotorB = rotorIV.setup(26, 'T');
	Walze rotorC = rotorI.setup(16, 'R');
	Walze ukw = ukwB;

	std::string c;
	for (char z : m)
	{
		rotorC << (rotorB << (rotorA << true));
		z -= 'A';
		printf("Eingabe: %c ", z + 'A');
		z = plugboard[z];
		printf("Plugboard: %c ", z + 'A');
		z = rotorA[z];
		printf("Rotor-A: %c ", z + 'A');
		z = rotorB[z];
		printf("Rotor-B: %c ", z + 'A');
		z = rotorC[z];
		printf("Rotor-C: %c ", z + 'A');
		z = ukw[z];
		printf("UKW: %c ", z + 'A');
		z = rotorC(z);
		printf("Rotor-C: %c ", z + 'A');
		z = rotorB(z);
		printf("Rotor-B: %c ", z + 'A');
		z = rotorA(z);
		printf("Rotor-A: %c ", z + 'A');
		z = plugboard(z);
		printf("Plugboard: %c \n", z + 'A');
		c.push_back(z + 'A');
	}
	std::cout << "C:" << c << std::endl;
}
