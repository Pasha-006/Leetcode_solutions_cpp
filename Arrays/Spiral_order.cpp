
#include<iostream>
#include<vector>

class Solution
{
   void SpiralOrder(std::vector<std::vector<int>> &vect)
   {
    int start_col=0;
    int end_col=vect[0].size();
    int count=0;
    int rows=vect.size();
    int cols=vect[0].size();
    if(rows%2==0)
    {
        count=rows/2;
    }
    else 
    {
        count=(rows/2)+1;
    }
    for(int i=0;i<count;i++)
    {

      

    }
      
   }



};