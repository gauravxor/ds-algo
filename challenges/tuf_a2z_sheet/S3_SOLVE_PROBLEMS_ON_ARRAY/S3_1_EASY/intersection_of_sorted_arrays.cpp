#include <iostream>
using namespace std;

int get_intersection(int *firstArr, int *secondArr, int firstLen, int secondLen, int *intersect)
{
    int interIndex = 0;
    int firstIndex = 0;
    int secondIndex = 0;
    while(firstIndex < firstLen && secondIndex < secondLen)
    {
        if(firstArr[firstIndex] == secondArr[secondIndex])
        {
            if(interIndex == 0 || (intersect[interIndex - 1] != firstArr[firstIndex]))
                intersect[interIndex++] = firstArr[firstIndex];
            firstIndex++;
            secondIndex++;
        }
        else
        {
            if(firstArr[firstIndex] < secondArr[secondIndex])
                firstIndex++;
            else
                secondIndex++;
        }
    }
    return interIndex;
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

    int intersect[min(len1, len2)];

    cout << "The intersection of both the arrays is\n";

    int index = get_intersection(arr1, arr2, len1, len2, intersect);

    for(int i = 0; i < index; i++)
        cout << intersect[i] << " ";
    cout << "\n";

    return 0;
}
