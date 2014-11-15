#include <iostream>
#include <cstring>
using namespace std;
int main () {
    char sent[] = "My name is Neha Tilak.";
    int len = strlen(sent);
     cout << "Length = " << len << endl; // does not count null character.
     cout << "Length = " << sizeof(sent)/sizeof(char) << endl; // counts null character.
     return 1;
}
