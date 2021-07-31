#include<iostream>
#include<string>
using namespace std;
int T;
int R;
string S;

int main(){
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> R;
		cin >> S;
		for(int i=0; i<S.length(); i++){
			for(int j=0; j<R; j++){
				cout << S[i];
			}
		}
		cout << endl;
	}
	
	
}
