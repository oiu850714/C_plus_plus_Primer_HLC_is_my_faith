#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::istringstream;
using std::vector;
using std::string;
using std::ifstream;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string line, word; // will hold a line and word from input, respectively
	vector<PersonInfo> people; // will hold all the records from the input
	// read the input a line at a time until cin hits end-of-file (or another
	// error)

	istringstream record; // bind record to the line we just read

	while (getline(cin, line)) {
		record.clear(); // should reset stream state
		record.str(line);
		PersonInfo info;       // create an object to hold this record’s data
		record >> info.name;   // read the name
		while (record >> word) // read the phone numbers
			info.phones.push_back(word); // and store them
		people.push_back(info);        // append this record to people
	}

	for (const auto &e : people) {
		cout << e.name << " ";
		for (const auto &phone : e.phones)
		{
			cout << phone << " ";
		}
		cout << endl;
	}
}