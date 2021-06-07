/**************************************************************************** 
 * helpers.c
 *
 * CC50
 * Pset 3
 *
 * Helper functions for Problem Set 3.
 ***************************************************************************/
       
#include <cc50.h>
#include <stdio.h>
#include "helpers.h"


/*
 * Returns true if value is in array of n values, else false.
 */

bool
mergesearch(int value, int array[], int size, int pos)
{
    if (pos > size)
	return false;
    int mid = (pos+size)/2;
    if (value < array[mid])
	return mergesearch(value, array, mid-1, pos);
    else if (value > array[mid])
	return mergesearch(value, array, size, mid+1);

    return true;
}

bool 
search(int value, int array[], int n)
{
    return mergesearch(value, array, n-1, 0);
}

/*
 * Sorts array of n values.  Returns true if
 * successful, else false.
 */
bool 
mergesort(int values[], int pos, int size, int aux[] )
{
    if (size<=pos) 
        return true;     // the subsection is empty or a single element
    
    int mid = (pos + size)/2;
    
    mergesort(values, pos, mid, aux);
    mergesort(values, mid+1, size, aux);

    int pl = pos;
    int pr = mid + 1;
    
    for (int k= pos; k<= size; k++) {
	if ( pl == mid + 1 )
	    aux[k]=values[pr++];
	else if ( pr == size + 1 )
	    aux[k]=values[pl++];
	else if ( values[pl] <= values[pr])
	    aux[k]=values[pl++];
	else 
	    aux[k]=values[pr++];
    }

    for (int k = pos; k <= size; k++)
	values[k] = aux[k];

    return true;
    
}

bool
sort(int values[], int size)
{ 
    int aux[size + 1];
    return mergesort(values, 0, size - 1, aux);
}

