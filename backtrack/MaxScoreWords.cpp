
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
   class Solution {
public:
    int solve(int index,std::vector<std::string>& words,std::map<char,int> & freq,std::vector<int> & score)
    {
    
        std::cout<<"im insed the function";
        if(index==words.size())
        {
            return 0;
        }
        int wordScore=0;
        int max_ans=0;
        for(int i=index;i<words.size();i++)
        {
            int flag=0;
            int index=0;
            for(int j=0;j<words[i].length();j++)
            {
                
                if(freq[words[i][j]]==0)
                {
                    
                    flag=1;
                    break;
                }
                index=j;
                wordScore+=score[words[i][j]-'a'];
                freq[words[i][j]]-=1;

            }
            if(flag==0)
            {
                std::cout<<words[i]<<std::endl;
                int justNow=solve(i+1,words,freq,score);
                 max_ans=std::max(justNow+wordScore,max_ans);
            }
            for(int j=0;j<=index;j+=1)
            {
                freq[words[i][j]]+=1;
            }
            
        }
        return max_ans;

    }
    int maxScoreWords(std::vector<std::string>& words, std::vector<char>& letters,
                      std::vector<int>& score) {
        std::map<char, int> freq;
        for (int i = 0; i < letters.size(); i++) {
            freq[letters[i]]+=1;
        }
        return solve(0,words,freq,score);  
    }
};

int main()
{
    std::vector<std::string> words;
    words.emplace_back("dog");
    words.emplace_back("cat");
    words.emplace_back("dad");
    words.emplace_back("good");
    std::vector<char> letters;
    letters.emplace_back('a');
    letters.emplace_back('a');
    letters.emplace_back('c');
    letters.emplace_back('d');
    letters.emplace_back('d');
    letters.emplace_back('d');
    letters.emplace_back('g');
    letters.emplace_back('o');
    letters.emplace_back('o');
    std::vector<int>score(26);
    score[0]=1;
    score[2]=9;
    score[3]=5;
    score[6]=3;
    score[14]=2;

    Solution s;
    std::cout<<s.maxScoreWords(words,letters,score);


    return 0;
}
