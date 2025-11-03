#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> numsMap;
    vector<vector<int>>ans;
    for(int i = 0; i < nums.size(); i++){
        numsMap[nums[i]]++;
    }
    for(int i = 0; i < nums.size(); i++){
        if(numsMap[nums[i]] > 0){
            numsMap[nums[i]]--;
            unordered_set<int> visited;
            for(int j = i + 1; j < nums.size(); j++){
                if(numsMap[nums[j]] > 0){
                    numsMap[nums[j]]--;
                    if(visited.count(nums[j]) == 0 && numsMap[- nums[i] - nums[j]] > 0){
                        vector<int> triplet = {nums[i], nums[j], - nums[i] - nums[j]};
                        ans.push_back(triplet);
                        visited.insert(nums[j]);
                        visited.insert(- nums[i] - nums[j]);
                    }
                    numsMap[nums[j]]++;
                }
                
            }
            
        }
        numsMap[nums[i]] = 0;
    }
    return ans;
}