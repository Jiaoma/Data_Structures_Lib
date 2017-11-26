#include<set>
#include<iostream>
using namespace std;
int main()
{
	//int a[] { 1,1,2 };
	//int b[] { 2,1 };
	set<int> testa;
	set<int> testb;
	testa.insert(1);
	testa.insert(1);
	testa.insert(2);
	testb.insert(2);
	testb.insert(1);
	set<int>::iterator it = testa.begin();
	set<int>::iterator it2 = testb.begin();
	while (it!=testa.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
	it2 = testb.begin();
	while (it2!=testb.end())
	{
		cout << *it2 << endl;
		it2++;
	}
	if (testa==testb)
	{
		cout << "true" << endl;
	}
	return 0;
}