#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// hash method
vector<vector<int>> threeSum(vector<int>& nums) {
    // create hash map
    unordered_map<int, int> freq;
    for(int i = 0; i < nums.size(); i++){
        freq[nums[i]]++;
    }
    
    vector<vector<int>> ans;
    // setting 1st element
    for(int i = 0; i < nums.size(); i++){
        int a = nums[i];
        if(freq[a] >= 1){
            freq[a]--;
            unordered_set<int> visitedj;
            //setting 2nd and 3rd
            for(int j = i + 1; j < nums.size(); j++){
                int b = nums[j];
                if(freq[b] >= 1){
                    int c = - a - b;
                    freq[b]--;
                    if(freq[c] >= 1){
                        if(!visitedj.count(b)){
                            vector<int> triplet = {a, b, c};
                            ans.push_back(triplet);
                            visitedj.insert(b);
                            visitedj.insert(c);
                        }
                    }
                    freq[b]++;
                }
            }
            
            freq[a] = 0;
        }
    }
    
    return ans;
}