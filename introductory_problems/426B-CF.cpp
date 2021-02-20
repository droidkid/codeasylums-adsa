#include<iostream>
using namespace std;
 
int arr[102][102] = {0};
 
int ans(int n, int m){
//	cout<<n<<endl;
	if( n%2 == 1){
		return n;
	}
	for(int i=0; i<n/2; i++){
		for(int j=0;j<m; j++){
			
			if(arr[i][j] != arr[n-i-1][j]){
				return n;
			}
 
		}		
	}
//	cout<<"YES"<<endl;
	return ans(n/2, m);
}
 
 
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	int a = ans(n,m);
	cout<<a<<endl;
}
	
 
