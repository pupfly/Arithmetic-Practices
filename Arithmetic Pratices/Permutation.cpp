#include "Permutation.h"

void RecursivePermutation(string s)
{
	RecursivePermutation(s, 0, (int)(s.length() - 1));
}

void RecursivePermutation(string & s, int start, int end)
{
	if (start == end){
		cout << s << endl;
	}
	else {
		for (int i = start; i <= end; i++)
		{
			char t = s[i];
			s[i] = s[start];
			s[start] = t;
			RecursivePermutation(s, start + 1, end);
			t = s[i];
			s[i] = s[start];
			s[start] = t;
		}
	}
}
