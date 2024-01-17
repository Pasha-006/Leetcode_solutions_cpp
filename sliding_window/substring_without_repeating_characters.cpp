https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_set<char> uset;
        int start=0;
        int end=0;
        int ans=0;
        int temp_ans=0;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(uset.find(c)!=uset.end())
            {
                temp_ans=uset.size();
                ans=max(ans,temp_ans);
                while(s[start]!=s[i])
                {
                    uset.erase(s[start]);
                    start++;
                }
                start++;
            }
            else
            {
                uset.insert(c);
            }
            end=i;
           
        }
        temp_ans=uset.size();
        ans=max(ans,temp_ans);
        return ans;
    }
};
