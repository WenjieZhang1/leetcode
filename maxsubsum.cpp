#include <iostream>

#include <string>

#include <vector>

#include <fstream>

#include <cstdlib>

#include <ctime>

using namespace std;


int max3 (int a, int b, int c)
{
	int temp=max(a, b);
	return max(temp, c);

}

int maxsubsum1 (const vector<int> & a)
{
	int maxSum=0;

	for (int i=0; i < a.size(); i++)
	{
		for (int j=i; j< a.size(); j++)
		{
			int tempsum=0;

			for(int k=i; k < j; k++)
				tempsum+= a[k];

			if (tempsum > maxSum)
				maxSum=tempsum;

		}
	}
	return maxSum;
} 


int maxsubsum2 (const vector<int> & a)
{
	int maxSum=0;

	for (int i=0; i < a.size(); i++)
	{
		int tempsum=0;

		for (int j=i; j< a.size(); j++)
		{
			tempsum+=a[j];

			if(tempsum > maxSum)
				maxSum=tempsum;
		}
	}
	return maxSum;
}

int maxsubsum3 (const vector<int> & a, int left, int right)
{
  if (left==right)
  {
  	if (a[left] > 0)
  		return a[left];
  	else 
  		return 0;
  }

  	int center=(left+right)/2;
  	int leftmax=maxsubsum3(a, left , center);
  	int rightmax=maxsubsum3(a, center+1 , right);
  	int leftbodermax=0; int leftbodersum=0;
    int rightbodermax=0;  int rightbodersum=0;
    for (int i=center; i > left; i--)
    {
    	leftbodersum+=a[i];
    	if(leftbodersum > leftbodermax)
    		leftbodermax=leftbodersum;

    }
    for (int j=center+1; j < right; j++)
    {
    	rightbodersum+=a[j];
    	if ( rightbodersum > rightbodermax)
    		rightbodermax=rightbodersum;
    }
    return max3(leftmax,rightmax, rightbodermax+leftbodermax);

}


int maxsubsum4 (const vector<int> & a)
{
	int maxsum=0; int tempsum=0;
	for (int i=0; i < a.size(); i++)
	{
		tempsum+=a[i];
		if (tempsum > maxsum)
			maxsum=tempsum;
		else if(tempsum < 0)
			tempsum=0;

	}
	return maxsum;
}