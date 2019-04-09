#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int, int> mylist;
vector<int> adj[2500];
vector<int>*it;
long int dept [2500];
bool stk[2500];
void print(int n)
{
	dept[0]--;
	int m = 0;
	for (int i = 0; i < n; i++)
    {
		if (dept[m] < dept[i])
		{
			m = i;
		}
	}
	cout << dept[m] << " ";
	if (dept[m] != 0)
	{
		cout << m;
	}
	cout << endl;
}
void calculate(int u, int n)
{

	fill(stk, stk+n, false);
	fill(dept, dept+n, 0);
	queue<mylist> q;
	q.push((mylist){0, u});
	stk[u] = true;
		while (!q.empty())
            {
			long	int s = q.front().second;
			long	int d = q.front().first;
					q.pop();
 					dept[d]++;

		for(vector<int>::iterator it = adj[s].begin();it!=adj[s].end();++it)
        {
			int v = *it;
			if (!stk[v]) {
				q.push((mylist){d+1, v});
				stk[v] = true;
			}
		}
	}

	print(n);
}
int main()
{
	int n;
	cin >> n;
	int k;
	for (int i = 0; i < n; i++)
    {

		cin >> k;
		for (int j = 0; j < k; j++)
        {
			int v;
			cin >> v;
			adj[i].push_back(v);
		}
	}

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
    {
		int x;
		cin >> x;
		calculate(x,n);
	}
}



