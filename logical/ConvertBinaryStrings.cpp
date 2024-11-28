#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int CountMismatchBits(std::string& s1,std::string & s2,int size)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        if(s1[i]!=s2[i])
        {
            cnt+=1;
        }
    }
    return cnt;
}
int CountofOnes(std::string& s1, std::string & s2,int size)
{
    int cnt=0;
    for(int i=0;i<size;i++)
    {
        if(s1[i]=='1' && s1[i]!=s2[i])
        {
            cnt+=1;
        }
    }
    return cnt;
}
int CountOfOnes(std::string &s1,int size)
{

    int cnt=0;
    for(int i=0;i<size;i++)
    {
        if(s1[i]=='1')
        { 
            cnt+=1;

        }
    }
    return cnt;
}




int main() {
    int t;
    std::cin>>t;
    while(t>0)
    {
        std::string s1,s2;
        std::cin>>s1;
        std::cin>>s2; 
        int n=s1.length();
        int ones=CountOfOnes(s1,n);
  
        if(n==1 || ones==n || ones==0)
        {
            std::cout<<"NO"<<std::endl;
        }
        else
        {
            int misMatchcnt=CountMismatchBits(s1,s2,n);
            int countOnes=CountofOnes(s1,s2,n);
            int countZeros=misMatchcnt-countOnes;
            int operations=std::min(countOnes,countZeros);
            operations+=misMatchcnt-2*(std::min(countOnes,countZeros));
            std::cout<<operations<<std::endl;
                                              
        }
        
        
        
        

    
        t-=1;
    }
    return 0;
}
