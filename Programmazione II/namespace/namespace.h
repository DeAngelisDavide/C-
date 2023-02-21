//
// Created by 39331 on 02/05/2021.
//

#include <iostream>
#include <stdio.h>

#ifndef NAMESPACE_NAMESPACE_H
#define NAMESPACE_NAMESPACE_H

namespace funzioniUtili {

    template <typename x, typename y> bool isInRange(x val, y start, y end)
    {
        if(val >= start && val <= end)
            return true ;
        return false;
    }

    template <typename x> x sumOfArray(x *a, int n)
    {
        x sum = a[0];
        for(int i = 1 ; i < n ; i++)
            sum += a[i];

        return sum;
    }

}

#endif //NAMESPACE_NAMESPACE_H
