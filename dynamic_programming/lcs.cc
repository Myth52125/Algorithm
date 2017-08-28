#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

std::string lcs(const std::string &l,const std::string &r)
{
	
	int ll = l.size();
	int rl = r.size();

	std::vector<std::vector<int> > memo(ll+1,std::vector<int>(rl+1));
	std::vector<std::vector<int> > memoRebuild(ll+1,std::vector<int>(rl+1));
	
	for(int inL = 1; inL <= ll ;inL ++)
	{
		for(int inR = 1; inR <= rl ;inR ++)
		{
			if(l[inL-1] == r[inR-1])
			{
				memo[inL][inR] = memo[inL-1][inR-1]+1;
				memoRebuild[inL][inR]=3;
			}else if(memo[inL][inR-1] > memo[inL-1][inR]){
				memo[inL][inR]=memo[inL][inR-1];
				memoRebuild[inL][inR]=2;
			
			}else{
				memo[inL][inR]=memo[inL-1][inR];
				memoRebuild[inL][inR]=1;
			
			}
		}
		
	}

	for(int i = 0;i<memoRebuild.size();i++)
	{

		std::cout<<std::endl;			
		for(int j =0 ;j < memoRebuild[i].size();j++)
		{
			std::cout<<memoRebuild[i][j]<<" ";			
		}
		std::cout<<std::endl;			
	}

	int reL = memoRebuild.size()-1;
	int reR = memoRebuild[0].size()-1;
	
	std::string re;
	while(reL >= 0 &&  reR >= 0)
	{
		if(memoRebuild[reL][reR]==3)
		{
			re.push_back(l[reL-1]);
			reL--;
			reR--;
		
		}else if(memoRebuild[reL][reR] == 1)
		{
			reL--;
		
		}else{
			reR--;
		}
	
	}
	std::cout<<"result ; "<<re<<std::endl;
	return re;
}

int main()
{
	std::string l("sxcqswvetrjtmyluorqeiop");
	std::string r("qweqsedrftgyhjukiqtewlolp");
	std::string ll("abcbdab");
	std::string rr("bdcaba");
	lcs(l,r);


}
