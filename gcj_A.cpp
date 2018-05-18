#include "iostream"
using namespace std;
int main2()
{
	string a;
	cin >> a;
	int k;
	cin >> k;
	int c = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] == '-')
		{
			c++;
			if (k > a.size() - i) {
				cout << "IMPOSSIBLE";
				return 0;
			}
			for (int j = 0; j < k; ++j)
			{
				a[i+j] = a[i+j] == '+' ? '-' : '+';
			}
		}
	}
	cout << c;
	return 0;

}

int main(int argc, char const *argv[])
{
	int n ;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Case #" << i+1 << ": ";
		main2(); 
		cout << endl;
	}
	return 0;
}