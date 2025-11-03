#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    // setting 1st element
    int previ = nums[0];
    for(int i = 0; i < nums.size() - 2; i++){
        int j = i + 1;
        int k = nums.size() - 1;
        int prevj = nums[j];
        
        // setting rest of elements
        while((i == 0 || nums[i] != previ) && j < k){
            if(j != i + 1 && nums[j] == prevj){
                j++;
            }else if(nums[i] + nums[j] + nums[k] == 0){
                vector<int> triplet = {nums[i], nums[j], nums[k]};
                ans.push_back(triplet);
                prevj = nums[j];
                j++;
                k--;
            }else if(nums[i] + nums[j] + nums[k] > 0){
                k--;
            }else if(nums[i] + nums[j] + nums[k] < 0){
                prevj = nums[j];
                j++;
            }
        }
        previ = nums[i];
    }
    return ans;
}