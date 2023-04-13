 bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
       int a[256]={0};
       int b[256]={0};
       bool flag=true;
       if(str1.length()!=str2.length()) return 0;
       for(int i=0;i<str1.length();i++){
           a[str1[i]-'0']++;
           if(b[str2[i] - '0']+1 == a[str1[i]-'0']){
               b[str2[i]-'0']++;
           } 
           else{
               flag=false;
               break;
           }
       }
       return flag;
        
    }
