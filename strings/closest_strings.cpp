https://leetcode.com/problems/determine-if-two-strings-are-close/
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> umap1;
        map<char,int> umap2;
        for(char c:word1)
        {
            umap1[c]++;
        }
        for(char c:word2)
        {
            umap2[c]++;
        }
        auto it=umap1.begin();
        auto it2=umap2.begin();
        int flag=0;
        if(umap1.size()==umap2.size())
        {
            while(it!=umap1.end() && it2!=umap2.end())
            {
                if(it->first!=it2->first)
                {
                    return false;
                }
                it++;
                it2++;
            }
            flag=1;
        }
        if(flag==1)
        {
            unordered_multiset<int> ms;
            unordered_multiset<int> ms2;
            for(auto key:umap1)
            {
                ms.insert(key.second);
            }
            for(auto key:umap2)
            {
                ms2.insert(key.second);
            }
            return ms==ms2;
        } 
        return false;


    }
};
