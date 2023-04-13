// Input:
// n=9, x=5
// arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
// Output:  2 5

// Method 1 : 
/// Approach : stop at 1st index value of x of either left or right and 
// continue the other side traversal and then check if 
// 1) both index has value 2) One index has value 3) none has value  

// Code :

vector<int> find(int arr[], int n , int x )
{
    // code here
    int l = 0 , r = n - 1 , ansl = -1 , ansr = -1 ;
    bool lfind = false , rfind = false ;
    while(l <= r)
    {
            if( arr[l] == x && !lfind )
            {
                lfind = true ; 
                ansl = l ;
            }
            if( arr[r] == x && !rfind )
            {
                rfind = true ;
                ansr = r ;
            }
            if(!lfind)
                l++;
            if(!rfind)
                r--;
            if(lfind && rfind)
                break ;
    }
    vector<int> ans ;
    if(ansl == -1 && ansr != -1)
    {
        ans.push_back(ansr);
        ans.push_back(ansr);
    }
    else if( ansl != -1 && ansr == -1 )
    {
        ans.push_back(ansl);
        ans.push_back(ansl);
    }
    else if( ansl != -1 && ansr != -1 )
    {
        ans.push_back(ansl);
        ans.push_back(ansr);
    }
    else 
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    
    return ans ;
    
}

// Method 2 : 
//Approach : Check from both the side and increment/decrement the index if value if not found 
// Only break the loop only when both the index has found the value 

//Code : 
vector<int> vec;
   int low = 0, high = n - 1;
   
   while(low <= high)
   {
       if(arr[low] != x) low++;
       if(arr[high] != x) high--;
       if(arr[low] == x && arr[high] == x) 
       {
           vec.push_back(low);
           vec.push_back(high);
           break;
       }
   }
   if(low > high)
       vec.push_back(-1),
       vec.push_back(-1);
       
   return vec;

// Method 3 : 
// Approach : Use binary search for first index and also for last index 

// Code :

int BS(int arr[],int i,int j,int x,char t){
    int res=-1;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(arr[mid]==x){
            res=mid;
            if(t=='f'){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        else if(arr[mid]<x){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
    }
    return res;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>v(n,-1);
    v[0]=BS(arr,0,n-1,x,'f');
    v[1]=BS(arr,0,n-1,x,'l');
    return v;
}