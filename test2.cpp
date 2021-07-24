#include<bits/stdc++.h>
using namespace std;
	
int main()
{

    string str ;
    cin >> str ;
    sort(str.begin() , str.end() );
    vector<pair<int, int> > v( (2,3) , (0,1) ) ;
    sort(v.begin() , v.end() );
    for(int i = 0 ; i < v ; i++ )
    {
        //cout << v;
    };
    cout << v;
    //cout << v;cout << str ;
    return 0; 
}


{
    int stringToInteger(string str2)
    {
        int x = stoi(str2);
        return x ;
    }