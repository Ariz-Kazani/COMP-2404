#include <iostream>

void power(int a, int b, int& c);

int main() {
    int a, b, c;
    std::cout<<"Please enter two integers: ";
    std::cin>>a>>b;
    power(a, b, c);
    std::cout<<a<<" to the power of "<<b<<" is "<<c<<"!"<<std::endl; 
    return 0;
}