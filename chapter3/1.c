/*
Our binary search makes two tests inside the loop, when one would sufficent
(at the price of more tests outside.) Write a version with only one test
inside the loop and measure the difference in run-time.
*/

#include <stdio.h>
#include <time.h>
#define MAXA 10

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[],int n);

main()
{
	int n, x, r, s;
	clock_t t0, t1;	
	int v[10] ={1,2,3,4,5,6,7,8,9,10};
 
        printf("Enter value of x:");
        scanf("%d", &x);

	t0 = clock();	

        r = binsearch(x, v, 10);
	if(r<0)
		printf("not found\n");
	else
		printf("binsearch1 found\n");
	t0 = clock()-t0;
	
		double elapsed1 =((double)t0) /(CLOCKS_PER_SEC);
	printf("Avg elapsed time: %f ms\n\n", elapsed1);
	t1 = clock();
        s = binsearch(x, v, 10);
        if(s<0)
                printf("not found\n");
        else
                printf("binsearch2 found\n");

	t1 = clock()-t1;
	double elapsed2 =((double) t1) / (CLOCKS_PER_SEC);
	printf("Avg elapsed time: %f ms\n\n", elapsed2);
}


int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;

	while (low <= high) {
		mid =(low+ high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else
			/* found match */
			return mid;

	}
		return -1;
	
	/* no match */
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while ((low <= high)&&(x != v[mid])) {

		mid =(low+ high)/2;
		if (x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		
        }
	if(x== v[mid])
		return mid;
	else
                return -1;
        /* no match */
}

