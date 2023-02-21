#include <iostream>
#include <fstream>
#include <vector>
const int n = 9;
const int uscita = 27;
const int autonomiaPieno = 10;

void inizializza(std::ifstream *f, int *a);
bool fermate(int *,int ,int , int , std::vector<int> &);

int main()
{
    std::ifstream *f = new std::ifstream ("dati.txt");
    if (f->fail())
        return 1;

    int *stazioni = new int[n];
    inizializza(f, stazioni);

    std::vector<int> soluzione;

    if(fermate(stazioni, n, autonomiaPieno, uscita, soluzione))
    {
        std::cout << "Le fermate da effettuare sono:" << std::endl;
        for (auto x: soluzione)
            std::cout << stazioni[x] << std::endl;
    }
    else
        std::cout<<"Non e'possibile arrivare all'uscita"<<std::endl;

    return 0;
}

void inizializza(std::ifstream *f, int *a)
{
    std::string buffer;
    std::getline( *f, buffer);
    for (int i = 0, j = 0; j < buffer.length(); j++)
        if (buffer[j] != ' ')
            if (buffer[j-1] == ' ')
            {
                a[i] = std::stoi(buffer.substr(j));
                i++;
            }
}
//stazioni, autonomia,km uscita, soluzione
bool fermate(int *s, int n, int a, int ku, std::vector<int> &sol )
{
    int km = 0, i = 0;

    while(km + a < ku && i < n)
    {
        if(km + a < s[i])
        {
            i--;
            sol.push_back(i);
            km = s[i];
        }
        i++;
    }

    if (km + a < ku && i == n)
        return false;
    return true;

}
