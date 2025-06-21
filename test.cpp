#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string &S, string &T) {
    int n = S.size();
    vector<pair<int,int>> differences;
    for(int i = 0; i<n; ++i){
        if(S[i]!= T[i]) {
            differences.push_back({abs(S[i]-T[i]),i});
        }
    }
    sort(differences.rbegin(), differences.rend());
    int swaps = 0 ;
    vector<char> S_vec(S.begin(), S.end());
    vector<char> T_vec(T.begin(), T.end());

    for (auto &[diff,index] : differences){
        if(diff==0) continue;
        char s_digit = S_vec[index];
        char t_digit = T_vec[index];

        int best_reduction = 0;
        int best_swap_index = -1;

        for (int j = index + 1; j<n ; ++j){
            if(S_vec[j]!= T_vec[j]){
                int new_diff = abs(S_vec[j] -t_digit);
                int reduction = diff - new_diff;

                if(reduction > best_reduction){
                    best_reduction = reduction;
                    best_swap_index= j;

                }
            }
        }

        if(best_swap_index!= -1){
            swap(S_vec[index], S_vec[best_swap_index]);
            swap(T_vec[index], T_vec[best_swap_index]);
            swaps++;

        }


    }
    return swaps;


}

int main(){
    string S,T;
    cout << "Enter the first string of the digits (S) :" ;
    cin >>S ;
    cout << " Enter the second string of the digits (T) :";
    cin >> T;

    if(S.size()!= T.size()){
        cout<<"Error: The lengths of input strings must be equal. "<< endl;
    }else{
        cout<<"Minimum number of swaps needed : "<< solution(S,T)<<endl;
    }
    return 0;
}
