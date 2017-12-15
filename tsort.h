#ifndef __TSORT_H__
#define __TSORT_H__

#include <iostream>
using namespace std;

template < typename T >
void Display (const T* beg, const T* end, char ofc = '\0')
{
  T *workp = (T*)beg;
  while(workp != end) 
  {
    if(ofc != '\0')
      std::cout << ofc;
    cout << *workp;
    workp++;
  }

}
  
template < typename T >
void InsertionSort (T* beg, T* end)
{
  T *i = (T*)beg + 1;
  while(i != end)
  {
    T savedValue = *i;
    T *j = i-1;
    while(savedValue < *j && j != beg - 1)
    {
      *(j+1) = *j;
      j--;
    }
    *(j+1) = savedValue;
    i++;

  }
}


#endif