#include <iostream> 
using namespace std; 

int arr[10][10]; 

int main() { 

	int r, c; 
	cin>>r>>c; 



	// INPUT PART. 
	for (int i=0; i<r; i++) { 
		string s; cin>>s; 
		for (int j=0; j<c; j++) { 
			if (s[j] == '.') { 
				arr[i][j] = 0; 
			} 
			if (s[j] == 'S') { 
				arr[i][j] = 1; 
			} 
		} 
	} 

	// TRY TO EAT EVERY ROW. 
	for (int i=0; i<r; i++) { 
		// YOU CAN ONLY EAT IF NO STRAWBERRIES. 
		int can_eat = 1; 
		for (int j=0; j<c; j++) { 
			if (arr[i][j] == 1) can_eat = 0; 
		} 

		if (!can_eat) continue; 
		// IM GOING TO MARK CELLS AS EATEN. 
		for (int j=0; j<c; j++) { 
			arr[i][j] = 2; // 2 is for eaten. 
		} 
	} 

	// TRY TO EAT EVERY COL. 
	for (int j=0; j<c; j++) { 
		int can_eat = 1; 
		for (int i=0; i < r; i++) { 
			if (arr[i][j] == 1) can_eat = 0; 
		} 

		if (!can_eat) continue; 
		for (int i=0; i < r; i++) { 
			arr[i][j] = 2; // 2 is for eaten. 
		} 
	} 

	// COUNT ALL EATEN CELLS. 
	int count = 0; 
	for (int i=0; i<r; i++) { 
		for (int j=0; j<c; j++) { 
			if (arr[i][j] == 2) count++; 
		} 
	} 

	// OUTPUT. 
	cout<<count<<endl; 
} 
