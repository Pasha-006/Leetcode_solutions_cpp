#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
class Solution {
public:
    void bfs(std::string word,std::string endWord, std::unordered_set<std::string> & uset,std::unordered_map<std::string,std::vector<std::string>> &map,int & ans)
    {
        std::cout<<word<<std::endl;
        if(word==endWord)
        {
            std::cout<<uset.size()<<std::endl;
            if(ans>uset.size())
            {
                ans=uset.size();
            }
            return ;
        }
        if(map.find(word)==map.end())
        {
            return;
        }
        for(std::string word1: map[word])
        {
            if(uset.find(word1)!=uset.end())
            {
                continue;
            }
            uset.insert(word1);
           
            bfs(word1,endWord,uset,map,ans);
            uset.erase(word1);

        }
        return ;
        
    }
    bool compare(std::string word1, std::string word2)
    {
        int diff=0;
        
        for(int i=0;i<word1.size();i++)
        {
            if(word1[i]!=word2[i])
            {
                diff++;

            }
            if(diff>1)
            {
                return false;
            }
        }
        if(diff==1)
        {
            return true ;
        }
        return false;
    }
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
    
      std::unordered_map<std::string,std::vector<std::string>> _map;
      std::unordered_set<std::string> _uset;
      std::string _word=beginWord;
      for(int i=0;i<wordList.size();i++)
      {
        if(compare(_word,wordList[i])==true )
        {
           
           _map[_word].emplace_back(wordList[i]);
        }            

      }
      for(int i=0;i<wordList.size();i++)
      {
        if(_map.find(wordList[i])==_map.end())
        {
                for(int j=0;j<wordList.size();j++)
                {
                    
                        if(compare(wordList[i],wordList[j])==true )
                    {
                    
                    _map[wordList[i]].emplace_back(wordList[j]);
                    }   

                }
        }
      }
      for(const auto & pair:_map)
      {
        std::cout<<pair.first<<": ";
        for(const std::string & c:pair.second)
        {
            std::cout<<c<<" ";
        }
        std::cout<<std::endl;
      }
  
      int ans=INT_MAX;
      bfs(beginWord,endWord,_uset,_map,ans);
      if(ans==INT_MAX)
      {
        ans=0;;
      }
      if(ans==0)
      {
        return 0;
      }
      return ans+1;
        
    }
};
int main()
{
    Solution s;
    std::vector<std::string> _v{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};

    std::cout<<s.ladderLength("qa","sq",_v);

    return 0;

}