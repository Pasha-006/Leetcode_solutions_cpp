//https://leetcode.com/problems/hand-of-straights/

class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        std::map<int,int> freq;
        for(int i=0;i<hand.size();i++)
        {
            freq[hand[i]]+=1;
        }
    b   
        while(freq.size()!=0)
        {b
            int key=freq.begin()->first;
           for(int i=key;i<groupSize+key;i++)
           {
            std::cout<<i<<std::endl;
            if(freq.count(i)==0)
            {
                return false;
            }
            freq[i]-=1;
            
            if(freq[i]==0)
            {
                freq.erase(i);
            }
           }
            
        }
        
        
     return true;
    }
};