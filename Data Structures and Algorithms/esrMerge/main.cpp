#include <iostream>
#include "merge.cpp"
#include <vector>
int main() {
    const int n=8;
    int a[n] = {10, 3, 15, 2, 1, 4, 9, 0};
    mergesort(a,0,n-1);

    for (auto x:a)
        std::cout<<x<<std::endl;


   // std::vector<int> b = { 10, 3, 15, 2, 1, 4, 9, 0};
    //std::vector<int>::iterator left = b.begin(), right = b.end();

    int b[n] = {10, 3, 15, 2, 1, 4, 9, 0};
    mergesortRI(b, 0, n-1);

    std::cout<<"Valori vector ordinato"<<std::endl;
    for (auto y:b)
         std::cout<<y<<std::endl;

    return 0;
}
