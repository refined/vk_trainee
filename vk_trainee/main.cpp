#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <iomanip> 
#include <map>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdlib> // atoi
#include <cmath>
#include <limits>
#include <queue>
#include <stack>
#include <numeric>
#include <unordered_set>

#include <string>
#include <ctime>

using namespace std;

int count_same_elements(const vector<int>& arr1, const vector<int>& arr2) {

	return 1;
}

void run_program_io(std::istream& in, std::ostream& out) {
	vector<int> arr1;
	vector<int> arr2;

	out << count_same_elements(arr1, arr2);
}

void run_simple_tests() {
	tuple<int, int, string, string, string> tests[5]{
		{3, 2, "10 11 12", "1 23", "0"},
		{3, 1, "10 11 12", "10", "1"},
		{1, 3, "10", "11 12 10", "1"},
		{0, 0, "", "", "0"},
		{7, 3, "900000 1000003 1 2 3 4 1000002", "1000003 1000001 1000002", "2"},
	};

	for (auto&[size1, size2, arr1, arr2, expected] : tests)
	{
		std::ostringstream out_stream;
		std::istringstream in_stream(to_string(size1) + " " + to_string(size2) + "\n" + arr1 + "\n" + arr2);

		clock_t start = clock();
		run_program_io(in_stream, out_stream);
		string result = out_stream.str();

		double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
		if (result == expected) cout << "OK" << endl;
		else cout << "FAIL" << endl;
		cout << in_stream.str() << endl << "result: " << result << " expected: " << expected << endl;
		cout << "duration " << duration << " sec" << endl << endl;
	}
}

int main() {
	run_simple_tests();
	//run_program_io(cin, cout);
	return 0;
}