#include <iostream>
#include <string>
#include "Data.hpp"


using namespace std;

int test_1(void) {
	cout << "Test_1" << endl;
	Data base;
	string *test = base.readData("C:/Users/vdd/Documents/GitLab/IoTProject_wLocalGDB/IoTProject_wLocalGDB/TestFiles", "myfile");

}

int main(void) {
	cout << "Programstart" << endl;
	cout << test_1() << endl;

	return 0;
}