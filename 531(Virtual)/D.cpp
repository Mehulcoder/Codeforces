/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given a string ss consisting of exactly nn characters, and each character is either '0', '1' or '2'. Such strings are called ternary strings.

Your task is to replace minimum number of characters in this string with other characters to obtain a balanced ternary string (balanced ternary string is a ternary string such that the number of characters '0' in this string is equal to the number of characters '1', and the number of characters '1' (and '0' obviously) is equal to the number of characters '2').

Among all possible balanced ternary strings you have to obtain the lexicographically (alphabetically) smallest.

Note that you can neither remove characters from the string nor add characters to the string. Also note that you can replace the given characters only with characters '0', '1' and '2'.

It is guaranteed that the answer exists.

Input
The first line of the input contains one integer nn (3≤n≤3⋅1053≤n≤3⋅105, nn is divisible by 33) — the number of characters in ss.

The second line contains the string ss consisting of exactly nn characters '0', '1' and '2'.

Output
Print one string — the lexicographically (alphabetically) smallest balanced ternary string which can be obtained from the given one with minimum number of replacements.

Because nn is divisible by 33 it is obvious that the answer exists. And it is obvious that there is only one possible answer.
*/

#include <cstdio>
#include <vector>
 
using namespace std;
 
int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
 
    const int MAX = 3;
    vector <int> frequency(MAX, 0);
 
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%1d", &A[i]);
        frequency[A[i]]++;
    }
 
    for(int i = 1; i <= no_of_elements && frequency[0] < no_of_elements/3; i++)
    {
        if(A[i] != 0 && frequency[A[i]] > no_of_elements/3)
        {
            frequency[A[i]]--;
            frequency[0]++;
 
            A[i] = 0;
        }
    }
 
    for(int i = no_of_elements; i >= 1 && frequency[2] < no_of_elements/3; i--)
    {
        if(A[i] != 2 && frequency[A[i]] > no_of_elements/3)
        {
            frequency[A[i]]--;
            frequency[2]++;
 
            A[i] = 2;
        }
    }
 
    for(int i = 1; i <= no_of_elements && frequency[1] < no_of_elements/3 && frequency[2] > no_of_elements/3; i++)
    {
        if(A[i] == 2)
        {
            frequency[2]--;
            frequency[1]++;
 
            A[i] = 1;
        }
    }
 
    for(int i = no_of_elements; i >= 1 && frequency[1] < no_of_elements/3 && frequency[0] > no_of_elements/3; i--)
    {
        if(A[i] == 0)
        {
            frequency[0]--;
            frequency[1]++;
 
            A[i] = 1;
        }
    }
 
    for(int i = 1; i <= no_of_elements; i++)
    {
        printf("%d", A[i]);
    }
 
    return 0;
}