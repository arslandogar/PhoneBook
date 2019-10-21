#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int arr[20000];
int temp[20000];
void print(int* arr,int length);
void Merge_Sort_Algo(int* arr, int low, int high);
int* Bubble_Sort_Algo(int* A, int length);
int* Insertion_Sort_Algo(int* A, int length);
int* Selection_Sort_Algo(int* A, int length);
//void Merge_Sort_Algo(int *a, int low, int high);
void Merge(int *a, int low, int high, int mid);
int main()
{
  char name[200];
  cout<<"Enter File Name to Sorted: ";
  cin>>name;
  ifstream infile;
  infile.open(name);
  char c;
  int i = 0;
  int j, k = 0, p = 0;
  int h = 0;
  infile.get(c);
  while(!infile.eof())
  {
    if(c == '\n')
    {
      arr[i] = k;
      h++;
      k = 0;
      i++;
    }
    else
    {
      p++;
      j = (int)c;
      j = j - 48;
      k = k*10 + j;
    }
    infile.get(c);
  }
  //print(arr, h);
int clo = clock();
Merge_Sort_Algo(arr, 0, h);
//print(arr, h);
cout<<"Time Taken for Merge Sort Algoritm: "<< (clock() - clo)<<" milli-seconds"<<endl;

clo = clock();
Bubble_Sort_Algo(arr, h);
cout<<"Time Taken for Bubble Sort Algoritm: "<< (clock() - clo)<<" milli-seconds"<<endl;

clo = clock();
Selection_Sort_Algo(arr, h);
cout<<"Time Taken for Selection Sort Algoritm: "<< (clock() - clo)<<" milli-seconds"<<endl;

}
void print(int* arr,int length)
{
  for(int i = 0; i < length; i++)
  {
    cout<<arr[i]<<endl;
  }
  cout<<endl;
}
void Merge(int *a, int low, int high, int mid)
{
	int i, j, k;
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}


void Merge_Sort_Algo(int *a, int low, int high)
{
	int mid;
  mid=(low+high)/2;
	if (low < high)
	{

		Merge_Sort_Algo(a, low, mid);
		Merge_Sort_Algo(a, mid+1, high);
		Merge(a, low, high, mid);
	}
}
int* Bubble_Sort_Algo(int* A, int length)
{
  for(int i = length - 1; i > 0; i--)
  {
    for(int j = 0; j < i; j++)
    {
      if(A[j] > A[j + 1])
      {
        int temp = A[j];
        A[j] = A[j + 1];
        A[j + 1] = temp;
      }
    }
  }
  return A;
}
int* Insertion_Sort_Algo(int* A, int length)
{
  for(int i = 1; i < length; i++)
  {
    int item = A[i];
    int j = i - 1;
    while(A[j] > item)
    {
      A[j + 1] = A[j];
      j--;
      if(j < 0)
      {
        break;
      }
    }
    A[j + 1] = item;
  }
  return A;
}
int* Selection_Sort_Algo(int* A, int length)
{
  int i;
  int j;
  int k;
  int n1 = length - 1;
  int smallest;

  for(i = 0; i < n1; i++)
  {
    k = i;
    smallest = A[i];
    for(j = i + 1; j < length; j++)
    {
      if(smallest > A[j])
      {
        k = j;
        smallest = A[k];
      }
    }
    A[k] = A[i];
    A[i] = smallest;
  }
  return A;
}
