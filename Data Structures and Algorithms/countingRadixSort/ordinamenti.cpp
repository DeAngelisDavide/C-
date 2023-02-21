//
// Created by 39331 on 23/11/2021.
//

template<typename T>
void countingSortDecrescente(T *a, int n)
{
    int m = max(a, n)-min(a, n)+1;
    T c[m];
    T b[n];
    for (int i = 0; i < m; i++) {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++)
       c[a[i]]++;

    for (int i = 1; i < m; i++) {
        c[i] = c[i]+c[i-1];
    }

    for (int j = 0; j < n ; j--) {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }

}

template<typename T>
T max(T *a, int n)
{
    max = a[0];

    for (int i = 0; i < n; i++)
        if (a[i]>max)
            max = a[i];

    return max;
}

template<typename T>
T min(T *a, int n)
{
    min = a[0];

    for (int i = 0; i < n; i++)
        if (a[i]<min)
            min = a[i];

    return min;
}