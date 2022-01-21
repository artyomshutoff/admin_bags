#include <iostream>
#include <set>
#include <string>
#include <typeinfo>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;

int main() {
	std::set <string> bags;
	for (int i = 0; i < 1000; i++) {
		string bolshe5;
		string menshe5;
		string j = std::to_string(i);
		if (j.size() == 1) {
			j = "00" + j;
		} 
		else if (j.size() == 2) {
			j = "0" + j;
		}
		for (auto n : j) {
			int s = n - '0';
			if (s >= 5) {
				bolshe5 += n;
			}
			else {
				menshe5 += n;
			}
		}
		if (bolshe5.size() == 3 or menshe5.size() == 3) {
			if (bolshe5.size() == 3) {
				bolshe5 = bolshe5.substr(0, 2);
				bags.insert(bolshe5);
			}
			else {
				menshe5 = menshe5.substr(0, 2);
				bags.insert(menshe5);
			}
		}
		else if (bolshe5.size() > menshe5.size()) {
			bags.insert(bolshe5);
		}
		else {
			bags.insert(menshe5);
		}
	}
	cout << bags.size() << ": ";
	for (auto m : bags) {
		cout << m << ", ";
	}
	return 0;
}