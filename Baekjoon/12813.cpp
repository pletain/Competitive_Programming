#include <iostream>
#include <bitset>
using namespace std;


int main()
{
	bitset<100000> A;
	bitset<100000> B;
	cin >> A >> B;
	
	cout << (A & B) << endl;
	cout << (A | B) << endl;
	cout << (A ^ B) << endl;
	cout << (~A) << endl;
	cout << (~B) << endl;
	
	return 0;
}
