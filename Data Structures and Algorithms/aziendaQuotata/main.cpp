#include <iostream>
#include <vector>

int verificaGiorniConsecutivi( std::vector<int>, int st, int ed);
#define n 9

int main() {
    std::vector<int> qt= {21, 22, 20 , 12 , 20, 18, 17, 22, 22};

    std::cout<<"Il numero di volte in cui a[i] < a[i+1]: "<<verificaGiorniConsecutivi(qt, 0, n)<<std::endl;



}

int verificaGiorniConsecutivi( std::vector<int> a , int st, int ed)
{

    if (st == ed)
        return 0;

    if (ed-st == 1 )
        if (a[st] < a[ed])
            return 1;
        else
            return 0;

        int mid = (st + ed)/2;
        return verificaGiorniConsecutivi(a, st, mid) + verificaGiorniConsecutivi(a, mid + 1, ed) + verificaGiorniConsecutivi(a, mid, mid + 1) ;

}
