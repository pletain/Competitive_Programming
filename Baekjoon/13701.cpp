#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
	bitset<33554432> A;
	int n;
	
	while (~scanf("%d", &n))
    {
		if(!A[n])
			cout << n << " ";
		A[n] = 1;
	}
	
	return 0;
}
