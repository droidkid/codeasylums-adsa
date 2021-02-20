#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 
vector<int> apartment; 
vector<int> applicant; 

int main() { 

        // INPUT 
        int n,m,k; 
        cin>>n>>m>>k; 

        for (int i=0; i<n; i++) { 
                int x; 
                cin>>x; 
                applicant.push_back(x); 
            } 
        for (int i=0; i<m; i++) { 
                int x; 
                cin>>x; 
                apartment.push_back(x); 
            } 
        // SORT. CRUX of the problem. 
        sort(apartment.begin(), apartment.end()); 
        sort(applicant.begin(), applicant.end()); 

        int ap_idx = 0; 
        int count = 0; 

        // Let's try to go applicant wise. 
        // Try to give first applicant an house, then the second one ...  
        for (int i=0; i<n; i++) { 
            // I will search as much as possible to give this person an apartment 
            while (true) { 
                // I've run out of houses. 
                    if (ap_idx >= m) { 
                        break; 
                     } 
                     int cur_ap = apartment[ap_idx]; 
                     // The current house is too small for the ith applicant.  
                     // It will be too small for future applicants. 
                     // Skip this house, go to the next one. 
                     if (cur_ap < applicant[i] - k) { 
                        ap_idx++; 
                        continue; 
                     } 

                    // The current house is too big for the ith applicant. 
                    // Future houses will also be too big. 
                    // All the smaller are already taken (given to people) 
                    // You can't help this person anymore, so forget him. 
                    if (cur_ap > applicant[i] + k) { 
                        break; 
                    } 
                    // Ok, the current house is a good fit for this applicant.  
                    // Just give it away. 
                    count++; 
                    ap_idx++; 
                    break;
        } 
    } 
    cout<<count<<endl; 
} 
