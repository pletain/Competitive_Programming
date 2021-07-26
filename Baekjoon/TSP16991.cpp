#include<iostream>
#include<cmath>
using namespace std;

struct Point{
	int x, y;
};

int n;
float w[16][16];
Point xy[16];
int memo[16][1 << 16];



double Distance(const Point& p1, const Point& p2){
	double distance;
	distance = sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
	return distance;
}

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

void input(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> xy[i].x;
		cin >> xy[i].y;
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			w[i][j] = Distance(xy[i],xy[j]);
		}
	}
}

int main(){
	input();
	cout << tsp(0,1) << endl;
	
	return 0;
}

