
1) Algorithm to manually converting a string to int:

int x = 0; // may take long long 
for(int i = 0; i < s.length(); i++)
    x = x * 10 + s[i] - '0';


2) Converting vector<int,vector<int> > to graph-of another type 
    Input : vector<int,vector<int> > prerequisites 
// numCourses = 2, prerequisites = [[1,0]]
// edge between a->b in prerequisites[i] = [a, b]
Method 1 : Using map

    unordered_map<int, vector<int>> um;
    for (auto p: prerequisites)
    {
        um[p[0]].push_back(p[1]);
    }
Method 2 : Using adjacency list
        vector<int> adj[n+1];
		for(auto itr : prerequisites)
		{
			adj[itr[0]].push_back( itr[1] );
		}
