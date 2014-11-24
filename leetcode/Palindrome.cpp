#include <iostream>
using namespace std;

int digits(int num) {
    int digit =1;
    while (num >10 ) {
        num = num/10;
        digit++;
    }
return digit;
}

int main() {

   int number;
   cin >> number;
   if (number < 0) {
       cerr << "Number cannot be negative" << endl;
       return 1;
   }
   int pow10 =1;
   for (int j=1 ; j< digits(number) ; j++) {
       pow10 = pow10 * 10;
   }
   int flag = 0;
   while (number > 10) {
         int lval = number/pow10;
         int rval = number%10;
         if (lval != rval) {
             flag = 1;
             break;
         }
         number = number - lval*pow10;
         number = number/10;
         pow10 = pow10/100;
   }
   if (flag == 0) {
      cout << "Is a Palindrome" << endl;
   } else {
      cout << "Not a Plaindrome." << endl;
   }      
         
    return 1;   
}
