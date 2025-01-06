#include<iostream>
#include<bitset>
#include<iomanip>

using namespace std;

int main()
{
	int a = 29;
	int b = 45;

	bitset<8> x(a);
	bitset<8> y(b);

	cout << setw(10) << "X = " << x << endl << endl;
	cout << setw(10) << "Y = " << y << endl << endl;
	cout << "-----------------------------------------------------\n";

	cout << setw(10) << "X AND Y = " << (x & y)  << endl << endl;
	cout << setw(10) << "X OR Y  = " <<  (x | y) << endl << endl;
	cout << setw(10) << "X XOR Y = " << (x ^ y)  << endl << endl;
	cout << setw(10) << "!X      = " << (~x)     << endl << endl;
	cout << setw(10) << "!Y      = " << (~y)    << endl << endl;

	//Operator << means SHIFT LEFT 
	//Operator >> means SHIFT RIGHT 

	cout << setw(10) << "X SHIFT LEFT 3 Times = " << (x << 3) << endl << endl;
	cout << setw(10) << "Y SHIFT RIGHT 3 Times = " << (y >> 3) << endl << endl;

	//SHIFT LEFT by 1 bit means multiplocation by 2
	//SHIFT RIGHT by 1 bit means division by 2
	cout << "-----------------------------------------------------\n";

	int c = 8;
	int d = 2;

	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	cout << "c SHIFT RIGHT 1 time = " << (c >> 1) << endl;
	cout << "d SHIFT LEFT 2 time = " << (d << 2) << endl;

	int e = ((c << 4) | d);

	cout << "e = (c SHIFT LEFT 4 times then OR d) = " << e << endl;

	cout << "--------------------------------------------------------\n";

	unsigned int pack;
	char ch1 = 'a'; //ASCII CODE of 'a' = 97
	char ch2 = 'b';  //ASCII CODE of 'b' = 98

	cout << "ch1 = " << ch1 << endl;
	cout << "ch2 = " << ch2 << endl;

	pack = ch1;
	pack = (pack << 8) | ch2;
	cout << "pack = "<<pack << endl;





	return 0;
}
