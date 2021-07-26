#include<iostream>
using namespace std;

int n, k;
int w[101], v[101];
int memo[101][100001];
int val(int id, int remW){
	if((remW==0) || (id==n))
		return 0;
	if(w[id] > remW)
		return val(id+1,remW);
	if(memo[id][remW] !=0)
		return memo[id][remW];
	return memo[id][remW] = max(val(id+1,remW),v[id]+val(id+1,(remW-w[id])));
}

int main(){
	cin >> n;
	cin >> k;
	for(int i=0; i<n; i++){
		cin >> w[i];
		cin >> v[i];
	}
	cout << val(0,k) << endl;
	
	return 0;
}
