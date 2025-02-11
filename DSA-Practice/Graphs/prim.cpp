#include <iostream>
#include <vector>
#define I 32767



int main()
{
	std::vector<std::vector<int>> cost(8,std::vector<int>(8,I));
	std::vector<int> near(8,I);
	std::vector<std::vector<int>> t(2,std::vector<int>(6,0));

	cost.at(1).at(2)=25;
	cost.at(1).at(6)=5;
	cost.at(2).at(1)=25;
	cost.at(2).at(3)=12;
	cost.at(3).at(2)=12;
	cost.at(3).at(4)=8;
	cost.at(4).at(3)=8;
	cost.at(4).at(5)=16;
	cost.at(4).at(7)=14;
	cost.at(5).at(4)=16;
	cost.at(5).at(6)=20;
	cost.at(5).at(7)=20;
	cost.at(6).at(5)=20;
	cost.at(7).at(4)=14;
	cost.at(7).at(5)=18;

	int i,j,k,u,v,min=I,n=cost.size()-1;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(cost.at(i).at(j)<min){min=cost.at(i).at(j);u=i;v=j;}
		}
	}
	near.at(u)=near.at(v)=0;
	t.at(0).at(0)=u;
	t.at(1).at(0)=v;
	for(i=1;i<=n;i++)
	{
		if(near.at(i)!=0)
			{
				if(cost.at(i).at(u)<cost.at(i).at(v)) near.at(i)=u;
				else near.at(i)=v;
			}
	}
	for(i=1;i<n-1;i++)
	{
		min=I;
		for(j=1;j<=n;j++)
		{
			if(near.at(j)!=0 && cost.at(j).at(near.at(j))<min){min=cost.at(j).at(near.at(j));k=j;}
		}
		t.at(0).at(i)=k;
		t.at(1).at(i)=near.at(k);
		near.at(k)=0;
		for(j=1;j<=n;j++)
		{
			if(near.at(j)!=0 && cost.at(j).at(k)<cost.at(j).at(near.at(j))) near.at(j)=k;
		}
	}

	std::cout<<"Here is the Minimum spanning tree using Prim's Algorithm:\n";

	for(i=0;i<t.size();i++)
	{
		for(j=0;j<t.at(0).size();j++)
		{
			std::cout<<t.at(i).at(j)<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n";
	 return 0;
}


	



