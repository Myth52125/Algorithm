#include <limits.h>
#include <iostream>
#include <algorithm>
#include <vector>

int mulM(const std::vector<int> vec)
{
	int len = vec.size();
	int tmp = 0;
	int vecNum = len - 1;
	std::vector<std::vector<int>> memo(len);
	
	for(int i = 0 ;i < memo.size() ; i++)
	{
			memo[i].resize(len);
	}

	for(int len = 2 ;len <=  vecNum  ; len++)
	{
			for(int start = 1 ; start <= vecNum - len + 1 ;start++ )
			{
				tmp=INT_MAX;
				int end = start + len -1;
				
				for(int k =  start ; k <= end -1  ; k++)
				{
					int	memo1=memo[start][k];
					int	memo2=memo[k+1][end];
					
					std::cout<<"len "<<len<<"  start "<<start<<" k "<<k<<" mul:"<<vec[start-1] <<" * " <<vec[k]<<" * " <<vec[start+len-1] <<" + memo1  "<<memo1 <<"+ memo2 "<< memo2
						<<" = "<<vec[start-1]*vec[k]*vec[start+len-1]+memo1+memo2<<std::endl;
					tmp = std::min(tmp,vec[start-1] * vec[k] * vec[start+len-1] + memo1 + memo2);
					
					memo[start][end] = tmp;
				}
				
			}
		

	}
	for(int i = 0 ;i <= memo.size()-1 ; i++)
	{
		std::cout<<std::endl;
		for(int j = 0 ; j < memo[i].size(); j++)
		{
			std::cout<<memo[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return memo[1][vecNum];
}


int main()
{
	std::vector<int> vec{30,35,15,5,10,20,25};
	std::cout<<"result"<<mulM(vec)<<std::endl;

}

