#include<iostream>
#include<vector>
#include<map>
#include<set>
//  https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15
class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
       std::map<int,int> winners;
    std::map<int,int> loosers;
    for(int i=0;i<matches.size();i++)
    {  
         if(loosers.find(matches[i][1])!=loosers.end())
        {
            loosers[matches[i][1]]+=1;
        }
        else
        {
            loosers[matches[i][1]]=1;
        }
         if(winners.find(matches[i][0])!=winners.end())
        {
            winners[matches[i][0]]+=1;
        }
        else
        {
            winners[matches[i][0]]=1;
        }
    }
    std::vector<std::vector<int>> ans;
    std::vector<int> wins;
    std::vector<int> runners;
    auto ptr=winners.begin();

    ptr=winners.begin();
    while(ptr!=winners.end())
    {
        if(loosers.find(ptr->first)==loosers.end())
        {
            wins.push_back(ptr->first);
        }        
        ++ptr;
    }
     auto ptr2=loosers.begin();

    while(ptr2!=loosers.end())
    {
        if(ptr2->second==1)
        {
            runners.push_back(ptr2->first);
        }
        ptr2++;
    }
    ans.push_back(wins);
    ans.push_back(runners);
    return ans; 
    }
};
int main()
{
    Solution s;
    int n;
    std::vector<std::vector<int>> matches;
    std::cout<<"Please enter the no.of matches Played : ";
    std::cin>>n;
    for(int i=0;i<n;i++)
    {
        std::vector<int> temp;
        std::cout<<i<<"match :\n"<<"Please enter winner id :";
        int winner;
        std::cin>>winner;
        temp.push_back(winner);
        int looser; 
        std::cout<<"enter loooser Id : ";
        std::cin>>looser;
        temp.push_back(looser);
        matches.push_back(temp);
    }
    std::vector<std::vector<int>>results=s.findWinners(matches);
    std::cout<<"winners Id :"<<std::endl;
    for(int i=0;i<results[0].size();i++)
    {
        std::cout<<results[0][i]<<" ";
    }
    std::cout<<std::endl;
     std::cout<<"Runners Id :"<<std::endl;
    for(int i=0;i<results[1].size();i++)
    {
        std::cout<<results[1][i]<<" ";
    }

}