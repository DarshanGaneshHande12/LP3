#include<bits/stdc++.h>
using namespace std;

int fibo(int indx){
    int a=0, b=1;
    cout<<a<<" "<<b<<" ";
    for(int i=3;i<=indx;i++){
        int c=a+b;
        a=b;
        b=c;
        cout<<b<<" ";
    }
    return b;
}

int main(){
    int n;
    cout<<"\n enter the kth term index:";
    cin>>n;
    int fiboNumber=fibo(n);
}




#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
   if(n==2) return 1;
   if(n==1) return 0;
   
   int fiboNacci = fibo(n-1)+fibo(n-2);
   
   return fiboNacci;
}

int main(){
    int n;
    cout<<"\n enter the kth term index:";
    cin>>n;
    int fiboNumber=fibo(n);
    cout<<fiboNumber;
}


// Approach	Time Complexity	Space Complexity
// Recursive	O(2ⁿ)	O(n)
// Iterative	O(n)	O(1)

   // Each call generates two more recursive calls:
   // fibo(n-1) and fibo(n-2).
   // This creates a recursive call tree with approximately
   // 2^n nodes in the worst-case analysis.
   // Therefore, Time Complexity = O(2^n).
