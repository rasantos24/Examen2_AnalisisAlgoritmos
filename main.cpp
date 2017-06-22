#include "Test.h"
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
using namespace std;

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int **memo;

/*int longestPalindromicSubsequence(string sequence, int begin, int end)
{
   if (begin == end)
     return 1;

   if (sequence[begin] == sequence[end] && begin + 1 == end)
     return 2;

   if (sequence[begin] == sequence[end])
      return longestPalindromicSubsequence(sequence, begin+1, end-1) + 2;

   return max( longestPalindromicSubsequence(sequence, begin, end-1),
           longestPalindromicSubsequence(sequence, begin+1, end) );
}*/

int longestPalindromicSubsequence(string sequence, int begin, int end)
{
    char* str;
    int n = strlen(str);
    int i, j, cl;
    int L[n][n];

    for(i = 0; i < n; i++)
        L[i][i] = 1;

    for (cl=2; cl<=n; cl++)
    {
        for (i=0; i<n-cl+1; i++)
        {
            j = i+cl-1;
            if (str[i] == str[j] && cl == 2)
               L[i][j] = 2;
            else if (str[i] == str[j])
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }

    return L[0][n-1];
}

int longestPalindromicSubsequence(string sequence)
{
    return longestPalindromicSubsequence(sequence, 0, sequence.size()-1);
}

int recorrer(int **DAG, int size, int source, int destination)
{
    if(source == destination)
        return 1;

    if(size <= 0)
        return 0;

    if(size == 1 && DAG[source][destination])
        return 1;

    int pasos = 0;
    for(int i = 0; i < size; ++i)
    {
        if(DAG[source][i] != -1)
        {
            if(memo[source][i] == -1)
            {
                int path = recorrer(DAG, size, i, destination);
                memo[source][i] = path;
                pasos += path;
            }
            else
            {
                pasos += memo[source][i];
            }
        }
    }

    return pasos;
}

vector<int> getPath(int **DAG, int size, int source, int destination)
{
    vector<int> answer;

/*    memo = new int*[size];

    for(int i = 0; i < size; i++)
    {
        memo[i] = new int[size];
        for(int j = 0; j < size; j++)
            memo[i][j] =- 1;
    }

    answer = recorrer(DAG, size, source, destination);
    memo = new int*[size];

    for(int i=0; i < size; i++)
    {
        memo[i] = new int[size];
        for(int j=0; j < size; j++)
            memo[i][j]=-1;
    }

    return recorrer(DAG, size, source, destination);*/
    return answer;
}

int main ()
{
    test();
    return 0;
}
