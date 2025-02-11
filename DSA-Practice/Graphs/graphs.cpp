#include <iostream>
#include <vector>

template<class T>
class queue
{
public:
	int size;
	int front;
	int rear;
	T *q;
	queue(int cap){size=cap;q=new T[size];rear=0;front=0;}
	~queue()=default;

	void enqueue(int x)
	{
		if((rear+1)%size==front){std::cerr<<"Queue is full, cannot insert element!\n";return;}
		else
		{
			rear=(rear+1)%size;
			q[rear]=x;
		}
	}
	int dequeue()
	{
		int deleted{-1};
		if(rear==front)std::cerr<<"Queue is empty, cannot delete any element!\n";
		else
		{
			front=(front+1)%size;
			deleted=q[front];
		}
		return deleted;
	}
	bool isFull(){return rear==size-1;}
	bool isEmpty(){return rear==front;}
	int back(){return q[rear];}
	int frnt(){return q[front+1];}
};


void BFS(std::vector<std::vector<int>> AdjMat,int start)
{
	int i=start,j;
	queue<int> q(AdjMat.size());
	std::vector<int> visited(AdjMat.size(),0);
	std::cout<<i<<" ";
	visited.at(i)=1;
	q.enqueue(i);
	while(!q.isEmpty())
	{
		j=q.dequeue();
		for(int x=1;x<AdjMat.size();x++)
		{
			if(AdjMat.at(j).at(x)==1 && visited.at(x)==0)
			{
				std::cout<<x<<" ";
				q.enqueue(x);
				visited.at(x)=1;
			}
		}
	}
}

void DFS(std::vector<std::vector<int>> AdjMat, int start)
{
	static std::vector<int> visited(AdjMat.size(),0);
	int j;
	if(visited.at(start)==0)
	{
		std::cout<<start<<" ";
		visited.at(start)=1;
		for(j=1;j<AdjMat.size();j++)
		{
			if(AdjMat.at(start).at(j)==1 && visited.at(j)==0) DFS(AdjMat,j);
		}
	}
}

int main()
{
	std::vector<std::vector<int>> adjmat = {{0,0,0,0,0,0,0,0},
											{0,0,1,1,1,0,0,0},
											{0,1,0,1,0,0,0,0},
											{0,1,1,0,1,1,0,0},
											{0,1,0,1,0,1,0,0},
											{0,0,0,1,1,0,1,1},
											{0,0,0,0,0,1,0,0},
											{0,0,0,0,0,1,0,0}};
	BFS(adjmat,3);
	std::cout<<"\n";
	DFS(adjmat,3);
	std::cout<<"\n";

	return 0;
}

