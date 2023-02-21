//
// Created by 39331 on 24/10/2021.
//
#include <vector>

#ifndef ESRMERGE_MERGE_H
#define ESRMERGE_MERGE_H


//--------MERGE SEMPLICE------------
void mergesort( int [], int  , int );
void merge(int [], int , int , int );


//-------MERGE CON VECTOR---------

void mergesort( std::vector<int> & ,std::vector<int>::iterator, std::vector<int>::iterator );
void merge(std::vector<int> &, std::vector<int>::iterator , std::vector<int>::iterator , std::vector<int>::iterator );
std::vector<int>::iterator it_center(std::vector<int>::iterator , std::vector<int>::iterator);


//------MERGE RICORSIVO---------
void mergeRI(int [], int , int , int );
#endif //ESRMERGE_MERGE_H

