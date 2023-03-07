#include<iostream>
using namespace std;
class Alph
{
private:
	int rep;
public:
	int getRepresentation() const
	{
		return rep;
	}
	Alph(char* string)
	{
		rep = 0;
		for (size_t i = 0; i < strlen(string); i++)
		{
			rep |= (1 << (int)(string[i] - 97));
		}
	}
	Alph(int rep)
	{
		this->rep = rep;
	}
	Alph()
	{
		rep = 0;
		for (int i = 0;i < 26;i++)
		{
			rep += (1 << i);
		}
	}

	Alph operator-(const Alph& a)
	{
		int res = this->getRepresentation() - a.getRepresentation();
		return Alph(res);
	}
};
ostream& operator<<(ostream& out, const Alph& i)
{
	int k = i.getRepresentation();
	int count = 0;
	while (k != 0)
	{
		if((k & 1))
		out<<(char)((k & 1)*(97+count));
		count++;
		k >>= 1;
	}
	return out;
}
int main(int argc, char* argv[])
{
	Alph a=Alph();
	Alph a1(argv[1]);
	Alph a3 = a - a1;
	cout << a3;
	cout << endl;
	system("pause");
	
}