#include <iostream>
#include <fstream>
#include <vector>
#include<string>
#include<map>
#include <algorithm>
using namespace std;
using std::string;

class Menu
{
public:
	Menu(int selection) {
		menuSelection = selection;
	};
	void menuText() {
		cout << "\nPlease chose a selection.(1-4)\n"
			<< "1. Change/Add file\n"
			<< "2. Combine files\n"
			<< "3. Exit\n";

	};
	void fileText() {
		cout << "\nPlease chose a selection.(1-4)\n"
			<< "1. Add File\n"
			<< "2. Delete File\n"
			<< "3. Main Menu\n";

	};
	void wordsText() {
		cout << "\nPlease chose a selection.(1-4)\n"
			<< "1. Confirm combine files\n"
			<< "2. Main Menu\n";


	};
	int updateSelection() {

		cin >> menuSelection;
		system("cls");
		return menuSelection;
	}
private:
	string name;
	int menuSelection;

};

class File
{
public:
	File(string file_location) {
		location = file_location;
	}
	string add_file() {
		cin >> location;
		return location;

	}
private:
	string location;
};



int main()
{
	bool run = true;
	bool cont = true;
	int selection = 0;
	vector<string>files;
	string location = "";

	File file1 = File(location);
	cout << "Available files: file1.txt, file2.txt, file3.txt, file4.txt, file5.txt\nPlease type the file you wish to combine:";
	files.push_back(file1.add_file());

	while (cont)
	{
		string input = "y";
		cout << files.size() << " of 5 \nWould you like to add another file? y/n";
		cin >> input;
		if (input == "n" || input == "N") {
			cont = false;
		}
		else {
			cout << "Available files: file1.txt, file2.txt, file3.txt, file4.txt, file5.txt\nPlease type the file you wish to combine:";
			files.push_back(file1.add_file());
		}
		if (files.size() == 5) {
			cont = false;
			cout << "5 is the maximum number of files";
		}



	}


	while (run)
	{
		system("cls");
		cout << "Files in use:" << endl;
		for (int i = 0; i < files.size(); i++)
		{
			cout << i << ": " << files[i] << " \n";
		}



		Menu mainMenu = Menu(selection);
		mainMenu.menuText();
		selection = mainMenu.updateSelection();
		if (selection == 0) {
			continue;
		}
		else if (selection == 1) {
			mainMenu.fileText();
			selection = mainMenu.updateSelection();
			if (selection == 1) {
				cout << "Please type the path to the file you wish to use:";
				files.push_back(file1.add_file());
			}
			else if (selection == 2) {
				for (int i = 0; i < files.size(); i++)
				{
					cout << i << ": " << files[i] << " \n";
				}
				cout << "Chose a file to delete" << endl;
				int del = 0;
				cin >> del;
				if (del > -1 && del < 5) {
					files.erase(files.begin() + del);
				}
				else {
					selection = 0;
				}

			}
			else {
				selection = 0;
			}
		}
		else if (selection == 2) {
			mainMenu.wordsText();
			selection = mainMenu.updateSelection();


			if (selection == 1) {
				//combine the files
				fstream myFile;
				fstream createdFile;
				string new_file;
				cout << "Select a name for the new file:";
				cin >> new_file;
				for (int i = 0; i < files.size(); i++)
				{
					myFile.open(files[i], ios::in);
					if (myFile.is_open()) {
						createdFile.open(new_file, ios::app);
						string line;
						while (getline(myFile, line)) {
							createdFile << line << "\n";

						}
						createdFile.close();

					}
					myFile.close();


				}
				cout << "Merge complete";
			}
			else {
				selection = 0;
			}
		}
		else {
			cout << "Input a number listed in the menu.";
			run = false;
		}




	}


}