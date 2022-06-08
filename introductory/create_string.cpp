#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	vector<string> perms;
	sort(s.begin(), s.end());
	do
	{
		perms.push_back(s);
	}
	while (next_permutation(s.begin(), s.end()));
	cout << perms.size() << endl;
	for (string perm : perms)
	{
		cout << perm << endl;
	}
}