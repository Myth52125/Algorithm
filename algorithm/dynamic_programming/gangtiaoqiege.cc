#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>

int tmp = 0;

std::vector<int> lp{0,1,5,8,9,10,17,17,20,24,30};


//自底而下
int calB(const std::vector<int> lp, int len)
{
	int num(0);
	std::vector<int> p(len+1);            

	for(int i=1; i <= len; i++)
	{
		tmp = 0;
		if ( i <= 10 )
		{
			for(int j = 0 ; j <= i;j++)
			{
				num++;
				tmp  = tmp > lp[j] + lp[i-j] ? tmp : lp[j] + lp[i-j];	
			}
		}else{
			for(int j = 1 ; j < i/2 +1;j++)
			{
				num++;
				tmp  = tmp > p[j] + p[i-j] ? tmp : p[j] + p[i-j];	
			}
		
		}
		p[i] = tmp;
	}
	std::cout<<"num : "<<num<<std::endl;
	return p[len];
}

//子上而下
int cut(const std::vector<int> &lp, std::vector<int> &p ,int len)
{

	int tmp = 0;

	if(p[len] > 0) return p[len];
	if(len == 0) return 0;
	
	if(len <= 10)
	{
		for(int i = 0;i <= len; i++)
		{	
			tmp = std::max(tmp, lp[len-i]+lp[i]);
		}	
	}else{
	
		for(int i = 1 ;i <= len/2 +1 ; i++)
		{
			tmp = std::max(tmp,cut(lp,p,i)+cut(lp,p,len-i) );
			std::cout<<tmp<<std::endl;
		}
	}

	p[len]=tmp;
	std::cout<<"p len "<<len<<" :"<<p[len]<<std::endl;


	return p[len];
}
int calT(const std::vector<int> lp , int len)
{
	std::vector<int> p(len+1);
	
	return cut(lp,p,len);
}

int main()
{
	int len;
	std::cin>>len;
	std::cout<<"p :"<<calT(lp,len)<<std::endl;
}
