
//https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/
#include<vector>
#include<iostream>
#include<algorithm>
class Solution {
public:
    int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {

     std::sort(seats.begin(),seats.end());
     std::sort(students.begin(),students.end());

     int count=0;
     for(int i=0;i<seats.size();i++)
     {
        count+=abs(students[i]-seats[i]);
     }
     return count;

    }
};