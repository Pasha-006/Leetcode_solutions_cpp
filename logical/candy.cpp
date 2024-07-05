class Solution {
public:
    int candy(vector<int>& ratings) {
        int prefix[ratings.size()];
  
        prefix[0]=0;
        for(int i=1;i<ratings.size();i++) 
        {
            if(ratings[i]>ratings[i-1])
            {
                prefix[i]=prefix[i-1]+1;
            }
            else 
            {
                prefix[i]=0;
            }
        }
         int suffix[ratings.size()];
        suffix[ratings.size()-1]=0;
        for(int i=ratings.size()-2;i>=0;i--) 
        {
            if(ratings[i]>ratings[i+1])
            {
                suffix[i]=suffix[i+1]+1;
            }
            else 
            {
                suffix[i]=0;
            }
        }
        int ans=0;
        for(int i=0;i<ratings.size();i++)
        {
            std::cout<<"prefix long"<< prefix[i]<< "\n suffix value si s"<<suffix[i]<<std::endl;
        }
        for(int i=0;i<ratings.size();i++)
        {
            ans+=max(prefix[i],suffix[i])+1;
        }
        return ans;


    }
};