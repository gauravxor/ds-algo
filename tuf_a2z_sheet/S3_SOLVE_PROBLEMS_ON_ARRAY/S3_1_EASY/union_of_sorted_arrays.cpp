#include <iostream>
using namespace std;

int get_union(int *firstArr, int *secondArr, int firstLen, int secondLen, int *unionArr)
{
    int unionIndex = 0;
    int firstIndex = 0;
    int secondIndex = 0;

    while(firstIndex < firstLen && secondIndex < secondLen)
    {
        if(firstArr[firstIndex] <= secondArr[secondIndex])
        {
            if(unionIndex == 0 || (unionArr[unionIndex - 1] != firstArr[firstIndex]))
                unionArr[unionIndex++] = firstArr[firstIndex];
            firstIndex++;
        }
        else
        {
            if(unionIndex == 0 || (unionArr[unionIndex - 1] != secondArr[secondIndex]))
                unionArr[unionIndex++] = secondArr[secondIndex];
            secondIndex++;
        }
    }

    while(firstIndex < firstLen)
    {
        if(unionArr[unionIndex - 1] != firstArr[firstIndex])
            unionArr[unionIndex++] = firstArr[firstIndex];
        firstIndex++;
    }


    while(secondIndex < secondLen)
    {
        if(unionArr[unionIndex - 1] != secondArr[secondIndex])
            unionArr[unionIndex++] = secondArr[secondIndex];
        secondIndex++;
    }
    return unionIndex;
}



int main()
{
    int len1;
    cout << "Enter the size of the first array\n";
    cin >> len1;

    int arr1[len1];

    cout << "Enter the array elements of first array\n";
    for(int i = 0; i < len1; i++)
        cin >> arr1[i];


    int len2;
    cout << "Enter the size of the second array\n";
    cin >> len2;

    int arr2[len2];

    cout << "Enter the array elements of second array\n";
    for(int i = 0; i < len2; i++)
        cin >> arr2[i];

    int union_arr[len1 + len2];

    cout << "The union of both the arrays is\n";

    int index = get_union(arr1, arr2, len1, len2, union_arr);

    for(int i = 0; i < index; i++)
        cout << union_arr[i] << " ";
    cout << "\n";

    return 0;
}
