/** 
 * Sieve Of Eratoshthenes Algorithm to find the
 * prime number in the given range in O(nlog(logn))
 * 
 * 
 * Idea :-
 * ---------
 * Start from a number and cancel out all its multiples
 * except the number itself. At the end the remaining
 * numbers are the required prime numbers in the given 
 * range [2,N].
 * 
 * 
 * To keep track of the visited and non visited numbers,
 * we use a hash.
 * 
 * Facts :
 * 
 * 1) The largest multiple of a given number N is always
 *    N/2. If N = 50, then the max multiple will be 50/2
 *    i.e 25
 * 
 * 2) The largest prime number that may divide the given number
 *    N, is sqrt(N).
 * 
 * 
 * 
 * TC : O(nlog(logn)) | SC : O(n)
 **/  


#include <iostream>
#include <cstring>

using namespace std;
int main()
{
	int range;
	cin >> range;

	int prime[range + 1];
	memset(prime, 0, sizeof(prime));

	for(int i = 2; i * i <= range; i++)
	{
		if(prime[i] == 0)
		{
			for(int j = i * i; j <= range; j += i)
				prime[j] = 1;
		}
	}

	for(int i = 2; i <= range; i++)
		if(prime[i] == 0)
			cout << i << " ";
	cout << "\n";

	return 0;
}