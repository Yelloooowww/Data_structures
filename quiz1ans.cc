#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std ;
class Cfrac
{
    private:
        vector<int> data;
    public:
        Cfrac(int num,int den)
        {
            int temp;
            while(num!=1)
            {
                //轉為帶分數
                data.push_back(num/den);
                num%=den;

                //倒數
                temp=num;
                num=den;
                den=temp;
            }
        }

        friend ostream& operator<<(ostream& out,Cfrac& cfrac)
        {
            for(int i=0;i<cfrac.data.size();i++)
            {
                out<<cfrac.data[i]<<" ";
            }
            return out;
        }
};

int main()
{
    Cfrac cfrac(10,7);
    cout<<cfrac<<endl;

    return 0;
}
