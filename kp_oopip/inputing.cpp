#include "header.h"

void inputing::check_int(int max, int min, int& val, string message)
{
	cin >> val;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << message;
		cin >> val;
	}
	while (val < min || val > max)
	{
		cout << message;
		cin >> val;
	}
}
void inputing::check_double(double max, double min, double& val, string message)
{
	cin >> val;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << message;
		cin >> val;
	}

	while (val < min || val > max)
	{
		cin.clear();
		cin.ignore();
		cout << message;
		cin >> val;
	}
}
void inputing::write_str(string& str)
{
	if (char(cin.peek()) == '\n')
		cin.ignore();
	getline(cin, str);
}