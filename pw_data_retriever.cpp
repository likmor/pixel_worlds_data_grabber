#include "WinReg.hpp"
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::pair;
using std::vector;
using std::wcout;
using std::wstring;

using winreg::RegKey;
using winreg::RegException;
using winreg::RegExpected;
using namespace std;
int main() {
	string out = "";
	const wstring testSubKey = L"SOFTWARE\\Kukouri\\Pixel Worlds";
	RegKey keyy{ HKEY_CURRENT_USER, testSubKey };
	auto values = keyy.EnumValues();
	for (const auto& s : values)
	{
		std::string str(s.first.begin(), s.first.end());
		if (str.find("CognitoIdentity") != -1) {
			auto k = keyy.GetBinaryValue(s.first);
			for (auto a : k) {
				wcout << (char)a;
				out += (char)a;
			}
			out += '\n';
			wcout << L'\n';
		}
		else if (str.find("lastLoginKey") != -1) {
			auto k = keyy.GetBinaryValue(s.first);
			for (auto a : k) {
				wcout << (char)a;
				out += (char)a;
			}

		}
	}
	ofstream s("data.txt");
	s << out;
	s.close();
}
