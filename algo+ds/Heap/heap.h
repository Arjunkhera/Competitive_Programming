#ifndef __heap_H_INCLUDED__
#define __heap_H_INCLUDED__

#include<iostream>
#include<climits>
#include<vector>

int getMin(std::vector<int>&);
void balanceHeap(std::vector<int>&,int);
int removeMin(std::vector<int>&);
void insertElement(std::vector<int>&,int);
bool deleteElement(std::vector<int>&,int);

#endif
