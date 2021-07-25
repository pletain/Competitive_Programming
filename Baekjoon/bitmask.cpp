#include<iostream>
#include<bitset>
using namespace std;


int main(){
	bitset<10> v;
	int v2[10];
	bool v3[10];
	double v4[10];
	int mask = 4;
	int ans = mask & (1 << 2);
	cout << (mask | (1 << 5)) << endl;
	cout << (1 << 1) << endl;
	cout << (1 << 2) << endl;
	cout << ans << endl; 

}
