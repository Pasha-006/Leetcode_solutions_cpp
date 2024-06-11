#include<iostream>
//statemetn is 
/* 

your given a string where it might contain consecutive continues integers but if atmost one integer  return that integer 
else 
return -1
*/
int solve(std::string s,int index,int digit,int skip,int missingNumber)
{
   if(skip==2)
   {
     return 0;
   }
   if(index==s.length())
   {
        if(skip==0) return 0;
        
        return missingNumber;
   }
  
    std::string digitString="";
    for(int i=index;i<s.length();i++)
    { 
        digitString+=s[i];
        int num=std::stoi(digitString);
        
        if(num<digit) continue;

        if(num-digit>2)  return 0;
        else 
        if(num-digit==2) 
        {
            skip+=1;
           missingNumber=num-1;  
        }

        return solve(s,i+1,num,skip,missingNumber);    
    }
    return 0;
}

int MissingNumber(std::string s)
{
    
    std::string digitString="";
    int ans=0;
    for(int i=0;i<s.length()/2;i++)
    {
        digitString+=s[i];
        int num=std::stoi(digitString);
        ans=ans | solve(s,i+1,num,0,0);   
    }
    return ans;
}

int main()
{
    std::string s;
    std::cin>>s;
    std::cout<<MissingNumber(s);


    return 0;
}