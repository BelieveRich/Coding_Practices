// 10/9/2022 HackerRank by Richard Chen
// https://www.hackerrank.com/contests/daily-challenge/challenges/subset-sum/problem
/*
You are given a list of N positive integers, A = {a[1], a[2], ..., a[N]} and another integer S. 
You have to find whether there exists a non-empty subset of A whose sum is greater than or equal to S.
You have to print the size of minimal subset whose sum is greater than or equal to S. 
If there exists no such subset then print -1 instead.
*/

#include <iostream>
#include <cstdint>
#include <thread>
#include <algorithm>

using namespace std;

// Pass by reference array of 4 int passed in by reference
int FindSubsetMin(int (&input)[4], int S)
{
    /* The solution here is to:
       1. sort the result  -> Now we get an incremental list of ints
       2. Loop and sum each index value, if sum exceeds target S, 
            return current index location which is the minimal subset
       3. If no sum greater than S, and index last of array of array, then return -1
    */
    std::sort(begin(input), end(input), std::greater<int>());  
               // 1. c-style array begin\end iterator, cbegin\cend() is for constant only
               // 2. std::less<Type>() makes the sortig incremental, std::greater<Type>() makes the sorting decremental
    
    // lambda + range loop
    auto printArray = [&](){
        cout << "New sorted input : " << endl;
        for (auto i : input)
        {
            cout << i << " ";
        }
    };

    printArray();

    // Step 2: Loop result
    int sum = 0, result = -1, location = 0;
    for (auto idx : input)
    {
        sum += idx;
        cout << "sum += " << sum << endl;
        location++;
        if (sum >= S)
        {
            cout << "Sum = " << sum << " is great than target S = " << S << endl;
            result = location;
            break;
        }
    }

    return result;
}

int main()
{
    // input array A:
    const int array_size = 4;
    const int TestCase_Sz = 4;
    int A[array_size] = {4, 8, 10, 12};
    int S[TestCase_Sz] = {4, 13, 30, 100};

    // Loop thru each test case and check result
    for (auto &TC_val : S)
    {
        cout << "Test case " << &TC_val - &S[0] << " begin, target = " << TC_val << endl;
        int result = FindSubsetMin(A, TC_val);
        cout << "Final result = " << result << endl;
        cout << "=====================================================================" << endl << endl;
    }
    
    return 0;
}