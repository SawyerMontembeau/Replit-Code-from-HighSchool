#include <iostream>
using namespace std;
int main() {
  cout << "Hello World!\n";
  cout<<"Hello My name is Sawyer!"<< endl;//comments YAAAAAAY

  /*
  multiline comments
    hooray!
    */

  int x; // define a variable named x, of type int
  x = 5; //assign the value of 5 to x
  //int y = 6; // define and assign in one line
  //double z = 5.6;
  //cout << "Enter a Number 1-10: ";
  //cin >> x;
  //cout << "You entered " << x << endl;
  
  int a = 3;  
  int b = 3;  
  int c = a++;  
  int d = ++b;  
  // intermediate point  
  int the_answer = (--c + b++) * (--a + d); 
  cout << the_answer<<c<<b<<a<<d;
  
  
  return 0;
}