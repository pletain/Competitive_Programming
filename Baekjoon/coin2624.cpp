#include<iostream>
using namespace std;
int T, k;
int p[100];
int n[100];
int memo[]


void input(){
	cin >> T;
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> p[i];
		cin >> n[i];
	}
}

int ways(int type, int value, int cnt){
	if(value == 0){
		return 1;
	}
	if((value < 0) || (type == k)){
		return 0;
	}
	if(cnt==0)
		return ways(type+1, value, n[type+1]);
	return (ways(type,(value - p[type]), --cnt) + ways(type+1,value,n[type+1]));
}


int main(){
	input();
	cout << ways(0,T,n[0]) << endl;
}
