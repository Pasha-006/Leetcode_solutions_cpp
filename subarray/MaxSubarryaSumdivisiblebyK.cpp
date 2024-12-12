//https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
class Solution {
public:
    long long maxSubarraySum(std::vector<int>& nums, int k) {
        int n=nums.size();
        std::vector<long long> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=(pre[i]+nums[i]);
        }
        long long ans=LONG_LONG_MIN;
        for(int i=0;i<k;i++){
            long long sum=0;
            for(int j=i;(j+k)<=n;j+=k){
                long long use=pre[j+k]-pre[j];
                if(sum<0){
                    sum=use;
                }else{
                    sum+=use;
                }
                ans=std::max(ans,sum);
            }
        }
        return ans;
    }
};