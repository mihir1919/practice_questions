#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int main()
{
    #pragma omp parallel
    {
        printf("Hello thread->%d\n",omp_get_thread_num());
    }
}
