#include <iostream>
using namespace std;
class Foo{
  public:  
     Foo(){  cout <<"A"; }
     Foo(int x){  cout << "B";}
     Foo(Foo & foo){  cout << "C";}
};

int main () {
  Foo f1;
  Foo f2 = f1;
  Foo f3(1);
	return 0;
}
