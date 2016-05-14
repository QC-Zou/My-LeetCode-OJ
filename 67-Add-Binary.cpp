/*
 * tges2.cpp
 *
 *  Created on: May 14, 2016
 *      Author: dragonegg
 */
#include <iostream>
#include <string>
using namespace std;
using std::string;

class Solution {
public:
	string addBinary(string a, string b) {
		string c;
		std::string::size_type sa, sb, sc, i;
		sa = a.size();
		sb = b.size();
		sc = sa >= sb ? sa : sb;
		c = sa >= sb ? a : b;
		int carry = 0;
		if (a.empty() || b.empty()) {
			return c = a.empty() ? a : b;
		} else {

			for (i = 0; i < sa && i < sb; i++) {
				if (a[sa - 1 - i] == '1' && b[sb - 1 - i] == '1') {
					if (carry == 0) {
						c[sc - 1 - i] = '0';
					} else {
						c[sc - 1 - i] = '1';
					}
					carry = 1;

				} else if (a[sa - 1 - i] == '0' && b[sb - 1 - i] == '0') {
					if (carry == 0) {
						c[sc - 1 - i] = '0';
					} else {
						c[sc - 1 - i] = '1';
					}
					carry = 0;
				} else {
					if (carry == 0) {
						c[sc - 1 - i] = '1';
						carry = 0;
					} else {
						c[sc - 1 - i] = '0';
						carry = 1;
					}

				}

			}
			while (carry == 1 && i < sc) {
				if (c[sc - 1 - i] == '0') {
					c[sc - 1 - i] = '1';
					carry = 0;
				} else {
					c[sc - 1 - i] = '0';
					carry = 1;
				}
				i++;
			}

			if (carry == 1) {
				c = "1" + c;
			}
			return c;
		}

	}
};

int main() {
	Solution add;
	string s1, s2, s3;
	cin >> s1;
	cin >> s2;
	cout << s1 << endl;
	cout << s2 << endl;
	s3 = add.addBinary(s1, s2);
	cout << s3 << endl;
	return 0;
}
