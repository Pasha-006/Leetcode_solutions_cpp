#include<unordered_set>
#include<iostream>
long NumberswithoutRepeatingDigitsCount(long start,long end)
{
    long count=0;
    for(long i=start;i<=end;i++)
    {
        std::unordered_set<int> _set;
        long value=i;
        bool flag=true;
        while(value>0)
        {
            int rem=value%10;
            std::cout<<rem<<std::endl;
            if(_set.find(rem)!=_set.end())
            {
                flag=false;
                break;
            } 
            _set.insert(rem);
            value/=10;     
        }
        std::cout<<"Im outsied bro"<<std::endl;
        std::cout<<"--------"<<flag<<std::endl;
        if(flag==true)
        {
            count=count+1;
        }
    }
    return count;
}
int main()
{
    long start,end;
    std::cout<<"Enter start  and end positions : ";
    std::cin>>start>>end;
    long count=NumberswithoutRepeatingDigitsCount(start,end);
    std::cout<<"Numebrs without Repeating digits are : "<<count<<std::endl;

}
