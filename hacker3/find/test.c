#include <stdbool.h>
#include <stdio.h>

bool 
mergesort(int values[], int pos, int size, int aux[] )
{
    if (size<=pos) 
        return false;     // the subsection is empty or a single element
    
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

    for (int k = pos; k <= size; k++) {      // copy the elements from aux[] to a[]
        values[k] = aux[k];
    }

    return true;


    
}


int main() {
  int a[100], aux[100], n, i, d, swap;
 
  printf("Enter number of elements in the array:\n");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
 
  mergesort(a, 0, n - 1, aux);
 
  printf("Printing the sorted array:\n");
 
  for (i = 0; i < n; i++)
     printf("%d\n", a[i]);
 
  return 0;
}
