//#include <fstream>
#include <algorithm>
//#include <cmath>
//#include <numeric>

#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <limits>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <random>

using namespace std;

int count_same_hash(const vector<int>& arr1, const vector<int>& arr2) {
	const vector<int>& small = arr1.size() < arr2.size() ? arr1 : arr2;
	const vector<int>& big = arr1.size() < arr2.size() ? arr2 : arr1;
	unordered_set<int> hash(small.begin(), small.end());
	int counter = 0;
	for (int el : big)
	{
		if (hash.find(el) != hash.end())
		{
			counter++;
		}
	}
	return counter;
}

int count_same_quick_sort(const vector<int>& arr1c, const vector<int>& arr2c) {
	vector<int> arr1(arr1c.begin(), arr1c.end());
	vector<int> arr2(arr2c.begin(), arr2c.end());
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	auto it1 = arr1.begin();
	auto it2 = arr2.begin();
	int counter = 0;

	while (it1 != arr1.end() && it2 != arr2.end())
	{
		if (*it1 == *it2)
		{
			counter++;
			++it1;
			++it2;
		}
		else if (*it1 < *it2) ++it1;
		else ++it2;
	}

	return counter;
}

int count_same_set(const vector<int>& arr1c, const vector<int>& arr2c) {
	set<int> arr1(arr1c.begin(), arr1c.end());
	set<int> arr2(arr2c.begin(), arr2c.end());

	auto it1 = arr1.begin();
	auto it2 = arr2.begin();
	int counter = 0;

	while (it1 != arr1.end() && it2 != arr2.end())
	{
		if (*it1 == *it2)
		{
			counter++;
			++it1;
			++it2;
		}
		else if (*it1 < *it2) ++it1;
		else ++it2;
	}

	return counter;
}

int count_same_radix(const vector<int>& arr1, const vector<int>& arr2) {
	



	return 1;
}

int count_same_elements(const vector<int>& arr1, const vector<int>& arr2) {
	return count_same_hash(arr1, arr2);
}

void run_program_io(std::istream& in, std::ostream& out) {
	size_t size1, size2;
	in >> size1 >> size2;

	vector<int> arr1(size1);
	vector<int> arr2(size2);

	for (size_t i = 0; i < size1; i++) in >> arr1[i];
	for (size_t i = 0; i < size2; i++) in >> arr2[i];

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

	for (auto& [size1, size2, arr1, arr2, expected] : tests)
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

void run_rand_generated_test() {
	size_t size1 = 10000;
	size_t size2 = 990000;
	vector<int> arr1(size1);
	unordered_set<int> hash1(size1);
	vector<int> arr2(size2);
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution uni(0, INT32_MAX);
		
	clock_t start = clock();
	
	// first size1 are equal, so answer size1
	for (size_t i = 0; i < size1; i++)
	{
		int next = uni(rng);
		while (hash1.find(next) != hash1.end())
		{
			next = uni(rng);
		}
		arr1[i] = next;
		arr2[i] = next;
		hash1.emplace(next);
	}
	for (size_t i = size1; i < size2; i++)
	{
		int next = uni(rng);
		while (hash1.find(next) != hash1.end())
		{
			next = uni(rng);
		}
		arr2[i] = next;
		hash1.emplace(next);
	}
	cout << "generating data duration " << (clock() - start) / (double)CLOCKS_PER_SEC << " sec" << endl;
	
	start = clock();
	cout << endl << "hash" << endl;
	int res = count_same_hash(arr1, arr2);
	if (res == size1) cout << "OK" << endl;
	else cout << "FAIL" << endl;
	cout << "result: " << res << " expected: " << size1 << endl;
	cout << "duration " << (clock() - start) / (double)CLOCKS_PER_SEC << " sec" << endl;

	start = clock();
	cout << endl << "quick sort" << endl;
	res = count_same_quick_sort(arr1, arr2);
	if (res == size1) cout << "OK" << endl;
	else cout << "FAIL" << endl;
	cout << "result: " << res << " expected: " << size1 << endl;
	cout << "duration " << (clock() - start) / (double)CLOCKS_PER_SEC << " sec" << endl;

	start = clock();
	cout << endl << "set" << endl;
	res = count_same_set(arr1, arr2);
	if (res == size1) cout << "OK" << endl;
	else cout << "FAIL" << endl;
	cout << "result: " << res << " expected: " << size1 << endl;
	cout << "duration " << (clock() - start) / (double)CLOCKS_PER_SEC << " sec" << endl;

	start = clock();
	cout << endl << "radix" << endl;
	res = count_same_radix(arr1, arr2);
	if (res == size1) cout << "OK" << endl;
	else cout << "FAIL" << endl;
	cout << "result: " << res << " expected: " << size1 << endl;
	cout << "duration " << (clock() - start) / (double)CLOCKS_PER_SEC << " sec" << endl;
}

int main() {
	//run_simple_tests();
	run_rand_generated_test();
	//run_program_io(cin, cout);
	return 0;
}