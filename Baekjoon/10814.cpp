#include <iostream>
#include <string>
using namespace std;

int N, age[10000];
string name[10000];

void quickSort(int i, int j)
{
	if(i>=j) return;
	int pivot = age[(i+j)/2];
	int left = i;
	int right = j;
	
	while(left<=right)
	{
		while(age[left]<pivot) left++;
		while(age[right]>pivot) right--;
		if(left<=right)
		{
			swap(age[left],age[right]);
			swap(name[left],name[right]);
			left++; right--;
		}
	}
	quickSort(i,right);
	quickSort(left,j);
}


int main(){
	for(int i=0; i<N; i++){
		cin >> age[i];
		cin >> name[i];
	}
	
	quickSort(0,N-1);
	for(int i=0; i<N; i++){
		cout << age[i] << " " << name[i] << endl;
	}
	 
}
