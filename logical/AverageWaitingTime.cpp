//https://leetcode.com/problems/average-waiting-time/?envType=daily-question&envId=2024-07-09
#include<iostream>
#include<vector>


class Solution {
public:
    double averageWaitingTime(std::vector<std::vector<int>>& customers) {
         double startTime=customers[0][0]+customers[0][1];
         double waitedTime=startTime-customers[0][0];
         for(int i=1;i<customers.size();i++)
         {
            int currArrival=customers[i][0];
            int currTimeRequired=customers[i][1];
            if(currArrival>startTime)
            {
                startTime=currArrival+currTimeRequired;
            }
            else 
            {
                startTime+=currTimeRequired;
            }
            waitedTime+=startTime-currArrival;


         }
         return (double)waitedTime/customers.size();

    }
};