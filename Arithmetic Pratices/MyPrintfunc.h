#pragma once
#define GET_ARRAY_ELEMENTS_NUM(a) (sizeof(a) / sizeof(a[0]))
using namespace std;
template <class T>
void PrintArray(const T a[], int n, char* title);
template<class T>
inline void PrintArray(const T a[], int n, char * title)
{
	cout << title << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}
