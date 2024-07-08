//https://leetcode.com/problems/max-points-on-a-line/
class Solution {
public:

    int maxPoints(vector<vector<int>>& points) {
        int maxans=0;
        
        int curr=0;
        float x,y;
       
        for(int i=0;i<points.size();i++)
        {
            x=points[i][0];
            y=points[i][1];
             std::unordered_map<float,int> map;
            for(int j=i+1;j<points.size();j++)
            {
                float x2,y2;
                x2=points[j][0];
                y2=points[j][1];

                 if(x2==x)
                 {
                    map[INT_MAX]+=1;
                 }
                 else 
                 {
                    map[(y2-y)/(x2-x)]+=1;
                 }
            }
            for(const auto & pair:map)
            {
               // std::cout<<pair.first<<std::endl;
                if(pair.second>maxans)
                {
                    maxans=pair.second;
                }
            }
        }
        
        return maxans+1;
    }
};