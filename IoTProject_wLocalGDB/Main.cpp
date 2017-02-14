#include <iostream>
#include <string>
#include "Data.hpp"


using namespace std;

int test_1(void) {
	cout << "Test_1" << endl;
	Data base;

	// 4 bit und dann 32 bit

	string *test = base.readData("C:/Users/vdd/Source/Repos/IoTProject_wLocalGDB/IoTProject_wLocalGDB/TestFiles", "myfile");
	return 0;
}

int main(void) {
	cout << "Programstart" << endl;
	cout << test_1() << endl;

	return 0;
}

