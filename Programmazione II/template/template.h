//
// Created by 39331 on 01/05/2021.
//

#ifndef TEMPLATE_TEMPLATE_H
#define TEMPLATE_TEMPLATE_H

template <typename x, typename y> int valGrater(x a, y b){
    if( a > b)
        return 0;
    if( a < b)
        return 1;

    return -1;

};

template <typename x> x maxArray(x *a, int n){
    x max = a[0];
    for (int i = 0; i < n; i++)
        if ( a[i] > max)
            max = a[i];

    return max;
}

#endif //TEMPLATE_TEMPLATE_H
