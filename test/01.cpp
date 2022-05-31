#include <functional>
#include <iostream>

int fn(int x){
    return x*2;
}

std::function<int(int)> f (){
    return fn;
} 
int main(){
    std::function<int(int)> p = f();
    std::cout << p(2) << std::endl;
    return 0;
}
