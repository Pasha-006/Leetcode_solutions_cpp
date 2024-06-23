#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string> words, int maxWidth) {
        std::vector<std::string> res;
        int count=0;
        int start=0;

       for(int i=0;i<words.size();i++)
       {
         int currentLength=words[i].size();
         int diff=maxWidth-(count+currentLength+1);
         if(diff==-1)
         {
                 int div,rem; 
                 std::cout<<words[i]<<std::endl;
            bool oneWord=false;
            diff=maxWidth-(count-1);
            std::cout<<"size is "<<diff<< "start" <<start<<"count is "<<count<<"i is "<<i<<std::endl;
            std::string ans="";
            if(i-start==1)
            {
                oneWord=true;
                div=maxWidth-count-1;
                rem=0;
            }
            else 
            {
                div=diff/(i-start-1);
                rem=diff%(i-start-1);
            }
            if(oneWord==true)
            { 
                ans+=words[start];
                
                    ans+=" ";
                ans+=words[i];
                
                res.emplace_back(ans);
            }
             else 
            {
                for(int k=start;k<i;k++)
                {
                   ans+=words[k];
                    ans+=" ";
                }
                ans+=words[i];
                res.emplace_back(ans);
            }
            start=i+1;
          
            count=0;

         }
         else
         if(diff<0)
         {
            int div,rem; 
            bool oneWord=false;
            diff=maxWidth-(count-1);
            std::cout<<"size is "<<diff<< "start" <<start<<"count is "<<count<<"i is "<<i<<std::endl;
            std::string ans="";
            if(i-start==1)
            {
                oneWord=true;
                div=maxWidth-count-1;
                rem=0;
            }
            else 
            {
                div=diff/(i-start-1);
                rem=diff%(i-start-1);
            }
            if(oneWord==true)
            { 
                ans+=words[start];
                for(int m=0;m<=div+1;m++)
                {
                    ans+=" ";
                }
                res.emplace_back(ans);
            }
             else 
            {
                int extra=0;
                for(int k=start;k<i-1;k++)
                {
                   ans+=words[k];
                   for(int m=0;m<div+1;m++)
                   {
                    ans+=" ";
                   }
                   if(extra<rem)
                   {
                    ans+=" ";
                    extra+=1;
                   }
                }
                ans+=words[i-1];
                res.emplace_back(ans);
            }
            start=i;
            i=i-1;
            count=0;

         }
         else 
         {
            count+=currentLength+1;
            
         }
         


       }
       if(count!=0)
       {
        int div,rem; 
            bool oneWord=false;
            int diff=maxWidth-count-1;
            std::string ans="";
            int i=words.size();
            if(i-start==1)
            {
                oneWord=true;
                div=maxWidth-(count-1);
                rem=0;
            }
            else 
            {
                div=diff/(i-start-1);
                rem=diff%(i-start-1);
            }
            if(oneWord==true)
            { 
                ans+=words[start];
                for(int m=0;m<div;m++)
                {
                    ans+=" ";
                }
                res.emplace_back(ans);
            }
             else 
            {
                int extra=0;
                for(int k=start;k<i-1;k++)
                {
                   ans+=words[k];
                   
                    ans+=" ";
                   
                }
                ans+=words[i-1];
                diff=maxWidth-ans.length();
                while(diff>0)
                {
                    ans+=" ";
                    diff-=1;
                }
                res.emplace_back(ans);
            }
       }
       for(std::string temp: res)
       {
        std::cout<<temp.length()<<std::endl;
       }
     
     
       
        return res;
    }
};



    