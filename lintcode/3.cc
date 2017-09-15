#include <iostream>
using namespace std;
int digitCounts(int n, int k)
{
    int counts{0};
    int ten{1};
    int l{0};
    int c{0};
    int r{0};
    while(n/ten != 0)
    {
        c=(n/ten)%10;
        l=n/(ten*10);
        r=n-n/ten*ten;
        cout<<"handle c: "<<c<<" ten: "<<ten<<" l: "<<l<<" r: "<<r<<endl;

        if(k>c)
        {
            counts=counts + l*ten ; 
        }else if(k<c)
        {
                counts=counts +  (l + 1)/10;
        }else if(k=c){
            counts=counts + l*ten + r +1;
        }
        ten*=10;
        
    }
    return counts;

}

int main ()
{
    int k;
    int n;
    cout<<" "<<(13/1)%10<<endl;
    cin>>k>>n;
    cout<<"reslut :"<<digitCounts(n,k)<<endl;
}