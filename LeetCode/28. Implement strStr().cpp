class Solution {
public:
    int strStr (string haystack, string needle) {
	if (needle.empty ()) return 0;
	if (haystack.empty ()) return -1;

	vector<int> p(needle.size(),0);
	for (int i=1,j=0;i<needle.size();i++)
	{
		while (j>0 && needle[j]!=needle[i])
			j=p[j-1];
		if (needle[j]==needle[i])
			p[i]=++j;
		else
			p[i]=0;
	}

	for (int i=0,j=0;i<haystack.size();i++)
	{
		while (j && haystack[i]!=needle[j])
			j=p[j-1];
		if (haystack[i]==needle[j])
		{
			j++;
			if (j==needle.size())
				return i-j+1;
		}
	}
	return -1;
}
};
