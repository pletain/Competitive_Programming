#include<iostream>
#include<cmath>
using namespace std;

int n;
float w[16][16];
float xy[2][16];
int memo[16][1 << 16];

int tsp(int pos, int mask){
	if(mask == ((1 << n) - 1)){
		 if (w[pos][0] == 0)
            return 987654321;
		else
			return w[pos][0];
	}
	
	if(memo[pos][mask] != 0)
		return memo[pos][mask];

	int ans = 987654321;
	for(int nxt = 1; nxt < n; nxt++){
		if(((mask & (1 << nxt))) == 0 && (w[pos][nxt] != 0)){
				ans = min(ans, w[pos][nxt] + tsp(nxt, (mask | (1 << nxt))));
			}
		}
	return memo[pos][mask] = ans;
}

int input(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> xy[0][i];
		cin >> xy[1][i];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			w[i][j] = sqrt((pow(xy[0][i]-xy[0][j]),2)+pow((xy[1][i]-xy[1][j]),2));
		}
	}
}

int main(){

	
	cout << tsp(0,1) << endl;
	
	return 0;
}

