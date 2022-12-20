#include <iostream>
#include <stdlib.h>
#include <cctype>

class MyClass {     // The class
  public:           // Access specifier
    MyClass() {     // Constructor
	std::cout << "Hello World!";
    }

    int tambah(int a, int b){
	return a + b;
    }
};

class Player {
  
};

int main(){
  MyClass myObj;

  int hasil = myObj.tambah(4, 5);

  std::cout << "\n" << hasil;

  std::cout<<"\n";
  return 0;
}



