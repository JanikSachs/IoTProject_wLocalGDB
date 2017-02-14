#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <streambuf>
#include <vector>


using namespace std;

struct stat info;

class Data
{
public:
	Data();
	~Data();
	string* readData(string path, string fname);
	//int readLineData(string path, string fname);
private:
	
	int checkIfDirectory(string pfname);
	int makeDirectory(string pfname);
};

Data::Data()
{
}

Data::~Data()
{
}

string* Data::readData(string path, string fname)
{
	ifstream myFile;
	char ch;
	string dataString, dataArr[4];
	int speed, engrot, wattertmp;

	if (checkIfDirectory(path) > 0) {
		myFile.open((path + "/" + fname).c_str());

		int ix = 0;
		char delimeter('\n');
		ofstream jsonfile(".\\TestFiles\\jsondata.json");
		string str((istreambuf_iterator<char>(myFile)),
					istreambuf_iterator<char>());

		while (getline(myFile, dataString, delimeter))
		{
			
			dataArr[ix] = dataString;
			ix++;
		}
		
		myFile.close();
		
		//still have to find the length
		for (int i = 0; i < 3; i++) {
			cout << "loop" << i << endl;
			int temp;
			char * ptr;
			string identifier = dataArr[i].substr(0, 4);
			string value = dataArr[i].substr(4, 36);
			cout << "id: " << identifier << endl;
			cout << "val: " << strtol(identifier.c_str(), &ptr, 2) << endl;
			temp = strtol(identifier.c_str(), &ptr, 2);
			switch (temp)
			{
			case 8: //speed
				speed = strtol(value.c_str(), &ptr, 2);
				break;
			case 2: //engrot
				engrot = strtol(value.c_str(), &ptr, 2);
				break;
			case 4: //wattertmp
				wattertmp = strtol(value.c_str(), &ptr, 2);
				break;
			case 7:
				break;
			default:
				break;
			}
			
		}
		
		jsonfile << "{ \"Werte\": { \"Geschwindigkeit\":" << speed << ", " << "\"Enginrotation\":" << engrot << ", " << "\"Wassertemperatur\":" << wattertmp << "}";
		jsonfile.close();

	}
	else {
		return NULL;
	}
}

int Data::checkIfDirectory(string pfname)
{
	if (stat(pfname.c_str(), &info) != 0) {
		cout << "cannot access " << pfname << endl;
		return -1;
	}
	else if (info.st_mode & S_IFDIR) {
		cout << pfname << "is a directory " << endl;
		return 1;
	}
	else {
		cout << pfname << "is not a directory " << endl;
		return 0;
	}
}


int Data::makeDirectory(string pfname)
{
	return system(("mkdir " + pfname).c_str());
}