https://leetcode.com/problems/zigzag-conversion/
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int index=0;
        int n=numRows;
        if(n==1)
        {
            return s;
        }
        
        index=0;

        while(index<s.size())
        {
            ans+=s[index];
            cout<<ans;
            index=index+(n-1)*2;
            cout<<index<<endl;

        }
        
        for(int i=1;i<n-1;i++)
        {
            index=i;
            int count=0;

            while(index<s.size())
            {
              ans+=s[index];
              if(count%2==0)
               index=index+(n-i-1)*2;
              else 
               index=index+(i*2);
              count+=1;

            }
        }
        index=n-1;

        while(index<s.size())
        {
            ans+=s[index];
            cout<<ans;
            index=index+(n-1)*2;
            cout<<index<<endl;

        }

        return ans;
    }
};
