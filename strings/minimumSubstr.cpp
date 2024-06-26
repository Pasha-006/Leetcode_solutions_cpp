#include<iostream> 
#include<unordered_map>
bool MapCompare(std::unordered_map<char,int> & sfreq, std::unordered_map<char,int> & tfreq)
{
   for(auto & pair: tfreq)
   {
        if(sfreq.find(pair.first)!=sfreq.end())
        { 
            if(sfreq[pair.first]<pair.second)
            {
                return false;
            }

        }
   }
   return true;
}
std::string minWindow(std::string s, std::string t)
{ 

   std::unordered_map<char,int> tFreq;
   for(char & c: t)
   {
    tFreq[c]+=1;
   }

   std::unordered_map<char,int> slide;
   int start=0;
   int subStringLength=0;
   int MinsubstringLength=s.length();
   for(int i=0;i<s.length();i++)
   {
     slide[s[i]]+=1;
     while(MapCompare(slide,tFreq)==true)
     {
        slide[s[start++]]-=1;
     }
     subStringLength=i-start+1;
     if(MinsubstringLength>subStringLength)
     {
        MinsubstringLength=subStringLength;
     }


   }
   std::cout<<MinsubstringLength<<std::endl;

} 
        
           
    