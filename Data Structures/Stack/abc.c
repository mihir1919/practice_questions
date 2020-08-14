#include<bits/stdc++.h>
#include <omp.h>

using namespace std;

int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
    bool prime[n+1];
	memset(prime, true, sizeof(prime));
	int s=1;
    #pragma omp parallel for shared(prime, s)
	for (int p=2; p*p<=n; p++)
	{
		if (prime[p] == true)
		{
			for (int i=p*p; i<=n; i += p)
				prime[i] = false;
		}
	}
	// Print all prime numbers
	for (int p=2; p<=n; p++)
    {
        if (prime[p])
		s++;
    }
    cout<<s<<"\n";
	return 0;
}

