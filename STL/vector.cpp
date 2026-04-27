#include<iostream>
#include<vector>
using namespace std;

/*
    - Vectors vs arrays
    Arrays are static i.e their size remains constant throughout the life of a program. 
    Vectors are dynamic i.e. can change size in runtime
    Both store data in continuous format 

    - How is vector able to change the size in runtime?
    Behind the hood vector is cheating, i.e. it is initializing a new vector of size 2x sizof curr vector and its copying the data and adding the new data

    - vector has 2 properties : size and capacity
    size : num of elements a vector has
    capacity : num of elements the vector can hold - every time size x2 (only if capacity = size)
    e.g.
    []
    push_back(1)
    [1]
    push_back(2)
    [1 | 2]
    push_back(3)
    [1 | 2 | 3 | x]  => 1 empty space - size = 3 and capacity = 4

    - Each time a push_back is called the size doubles if the capacity of vector has been filled

    - Although push_back 2x the capacity of the vector when full, but pop_back() does not reduce the capacity

    Funcs       |   Size        |   Capacity        |   Time comp
    ----------------------------------------------------------------
    push_back   |   + 1         |   2x or same      |   O(1)
    pop_back    |   - 1         |   same            |   O(1)
    erase       |   - 1         |   same            |   O(n)
    insert      |   + 1         |   2x or same      |   O(n)

    - vec.begin() points to 1st elemnt of the vec. It returns the iterator to the 1st element. you can dereferance it as *(vec.begin()) to get the 1st element of vector
    - vec.end() points to value AFTER the last element (garbage value)
*/

int main()
{
    // vector<int> vec(3, -2) ; // creating a vector with size 3 and all elements as -2 
    vector<int> vec ; // creating a empty vector

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    cout << "Sizeof vector : " << vec.size() << endl;
    cout << "Capacity if vector : " << vec.capacity() << endl;
    
    vec.pop_back();
    
    vec.erase(vec.begin() + 1); // erasing a element at index 1

    vec.insert(vec.begin() + 1, 2); // inserting the erased value back

    // vec.clear(); // clears the vec (size = 0), but capacity stays the same
    // vec.empty(); // checks if vecs size = 0

    // cout << "Elements in Vector :    ";
    // for(int val : vec)
    // {
    //     cout << val << "  ";
    // }
    // cout << endl;

    // using iterator to loop through the vector:
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
    {
        cout << *(it) << "  ";
    }
    cout << endl;

    return 0;
}