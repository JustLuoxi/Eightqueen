//8 queen problem
//author: Just Luo
//date: 2016.9.28
//----------------------------

#include <iostream>
#include <vector>
using namespace std;

int count_;								//store the number of right solutions
vector<unsigned char> posi;						//store the whole position in each solution

void PrintBit(unsigned char A)
{
	for (int n = 0; n < 8; n++)
	{
		cout << (A / 0x80) << " ";
		A = A << 1;
	}
	cout << endl;
}

void PrintSolu()
{
	cout << "The "<< count_<<" solution is: " << endl;
	int size_ = posi.size();
	for (size_t i = 8; i >0; i--)
	{
		PrintBit(posi[size_-i]);
	}
}

void EightQueen(unsigned char A, unsigned char B, unsigned char C) //B: the column     A: left diagonal     C: right diagonal
{
	if (B==255)
	{
		count_++;
		PrintSolu();
		return;
	}
	unsigned char D =( ~(A|B|C));
	while (D)
	{
		unsigned char bit = D & -D;
		D -= bit;
		posi.push_back(bit);
		EightQueen((A|bit) << 1, B|bit, (C|bit) >> 1);
		posi.pop_back();
	}
}

int main(void)
{
	cout << "The results of 8 queen problem:"<< endl;				
	EightQueen(0, 0, 0);
}
