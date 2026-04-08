#include<iostream>
using namespace std;

void ContainerWithMaxWater(int * arr, size_t size) // O(n^2)
{
    int lower = 0;
    int higher = 1;
    int maxArea = 0;
    
    for (int  i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if((min(arr[i] , arr[j]) * (j-i)) > maxArea)
            {
                maxArea = (min(arr[i] , arr[j]) * (j-i));
                lower = i;
                higher = j;
            }
        }
    }

    cout << "Lower index : " << lower << " With value : " << arr[lower] << endl; 
    cout << "Higher index : " << higher << " With value : " << arr[higher] << endl;    
}

void ContainerWithMaxWaterOptimized(int * arr, size_t size) // O(n) optimised approach
{
    int left = 0;
    int right = size - 1;

    int maxArea = 0;

    int lower = left;
    int higher = right;

    while (left < right)
    {
        int currentArea = min(arr[left], arr[right]) * (right - left);
        if(currentArea > maxArea)
        {
            maxArea = currentArea;
            lower = left;
            higher = right;
        }

        if(arr[left] < arr[right])
            left ++;
        else 
            right --;
    }

    cout << "Lower index : " << lower << " With value : " << arr[lower] << endl; 
    cout << "Higher index : " << higher << " With value : " << arr[higher] << endl;    
}

int main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};

    cout << "Ans with not optimized O(n^2) approach : " << endl;
    ContainerWithMaxWater(arr, sizeof(arr) / sizeof(int));

    cout << endl << "Ans with optimized O(n) approach : " << endl;
    ContainerWithMaxWaterOptimized(arr, sizeof(arr) / sizeof(int));

    return 0;
}