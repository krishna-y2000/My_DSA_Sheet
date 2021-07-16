#include <iostream>
#include <string>
#define NO_OF_CHARS 256

using namespace std;
		// while(left <= right  )
        //    
    // {
void pzz(int n)
{
    if(n == 0  )
        return ;
    cout << "Pre " <<  n << endl ;
    pzz(n-1) ;
    cout << "In " << n << endl ;
    pzz(n-1) ;
    cout << "Post " << n << endl ; 
}

int main()
{
    int n = 3 ;
    pzz(n) ;
    return 0 ;
}