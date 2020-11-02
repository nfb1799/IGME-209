#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	string s = "supercalifragilistic";
	string e = "expialidocious";
	int count = 0;
	cout << "There are " << s.size() << " letters in " << s << endl;
	cout << s.append(e) << endl;

	for (int i = 0; i < s.size(); i++)
	{
		if (s.at(i) == 'i')
			count++;
	}

	cout << "There are " << count << " \'i\' characters in " << s;

}