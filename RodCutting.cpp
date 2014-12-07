#include<iostream> 
using namespace std;

static int p[] = {0,1,5,8,9,10,17,17,20,24,30};
int r[20];


int cost (int len) {
    if (len == 0) {
       return 0;
    }
    if (r[len] >=0) {
       return r[len];
    }
    int q = -1;
    int s;
    for (int i=1; i<= len; i++) {
        s = p[i] + cost(len-i);
        if (q < s) {
           q = s;
        }
    }
    r[len] = q;
    return q;
}
    
int main() {
   int n;
   cout << "Enter the length of the rod:" << endl;
   cin >> n;   

   for (int i=0;i<20;i++)
       r[i] = -1;
 
   cout << "Maximum cost =" << cost(n) << endl;
   return 0;
}
