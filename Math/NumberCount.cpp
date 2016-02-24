#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

long long *numberCnt (long long n, int base)
{
	long long *cnt=(long long*)calloc(sizeof(long long), base);
	long long npow=1, m=0;

	n++;
	string str=to_string (n);
	int l=str.size()-1;

	for (int i=l; i>=0; i--, npow*=base)
	{
		for (int j=(i==0); j<str[i]-48; j++)
			cnt[j]+=npow;
		for (int j=0; j<base; j++)
			cnt[j]+=(str[i]-48) * (l-i) * (npow/base);

		cnt[str[i]-48]+=m;
		m+=(str[i]-48)*npow;
		cnt[0]-=npow/base;
	}
	return cnt;
}
