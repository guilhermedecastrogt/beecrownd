#include <iostream>

using namespace std;

int main(){
	
	int N, menor = 0;
	cin>>N;
	int R[N];
	
	for(int i = 0; i < N; i++){
		cin>>R[i];
		if(R[i] < R[i-1] and menor == 0 and i > 0){
			menor = i+1;
		}
	}
	cout<<menor<<endl;
	return 0;
}