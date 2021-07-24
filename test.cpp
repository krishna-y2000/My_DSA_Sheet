#include <iostream>
#include <string>
#include <sstream>  
using namespace std;


#include<sstream>
    template <typename T>
    std::string to_string(T value)
    {
      std::ostringstream os ;
      os << value ;
      return os.str() ;
    }

int StringChallenge(int num) {
  
  // code goes here  
  string valString = to_string(num );
  for(int i = 0 ; i < valString.size() - 1 ; i++ )
  {
    int numtemp1 =  valString[i] - '0';
    int numtemp2 = valString[i+1] - '0';
    if( (numtemp1 != 0 && numtemp2 != 0) && (numtemp1 % 2 == 0) && (numtemp2 % 2 == 0)  )
    {
      string temp = valString.substr(i);
      valString[i+1] = '*';
      valString.insert(i+2 , temp) ;
    }
    else if( (numtemp1 % 2 == 1) && (numtemp2 % 2 == 1) )
    {
      string temp = valString.substr(i);
      valString[i+1] ='-';
      valString.insert(i+2 , temp) ;
    }
  } 
  num = stoi(valString);
  return num ;

}

int main(void) { 
   
  // keep this function call here
  cout << StringChallenge(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}