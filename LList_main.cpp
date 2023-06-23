#include <iostream>
#include "LinkedList.cpp"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


int main()
{
	LinkedList<string> L;
	int choice = -1;




	while (choice != 0)
	{
		cout << endl << "====TEXT EDITOR====\n" << endl;
	cout << "Please choose what you want to do\n1.Add Line " << endl;
	cout << "2.Insert Line\n3.Get Line Text\n4.Delete Line " << endl;
	cout << "5.Update Line \n6.Find All\n7.Find and Replace\n8.Show" << endl;	
	cout << "9.Save To File" << endl;
	cout << "10.Retreive From File" << endl;
		cin >> choice;
		cout << endl;
		if (choice == 1)			//add a line
		{
			cout << "Enter line: ";
			string text;
			cin.ignore(1);
			getline(cin, text);
			L.Append(text);
	
		}
		else if (choice == 2)		//insert
		{
			int pos; 
			string text1;

			cout << "Enter position: ";
			cin >> pos;
			cout << "Enter line: ";
			cin.ignore(1);
			getline(cin, text1);
			L.InsertAt(pos, text1);


		}
		else if (choice == 3)		//get
		{
			int position;
			cout << "Line number: ";
			cin >> position;
			cout <<"Line at index " << position <<": " << L.At(position);
		}
		else if (choice == 4) //delete
		{
			int line_index;
			cout << "Enter the line number :";
			cin >> line_index;
			L.DeleteAt(line_index);

		}
		else if (choice == 5)		//Update all
		{
			int pos;
			string text;
			cout << "Enter the line you want to update :";
			cin >> pos;
			cout << "Enter the text : ";
			cin.ignore(1);
			getline(cin, text);
			L.DeleteAt(pos);
			L.InsertAt(pos, text);

		}
		
		else if (choice == 6)		//find
		{
			string k;
			cout << "Enter the text : ";
			cin >> k;
			L.findall(k);
			
		}
		else if (choice == 7) //find and replace
		{
			string x;
			string replaced;
			cout << "Enter the replaced word : ";
			cin >> x;
			cout << "Enter the placed word: ";
			cin>>replaced;
			L.replace(x , replaced);

		}
		else if (choice == 8) //display all
		{
			L.display_all();

		}
		else if (choice == 9) //save file
		{
			string x;
			cout << "enter file name \n";
			cin >> x;
			ofstream save_file(x+".txt");
			if (save_file.is_open())
			{
				int i = 0;
				while (L.Length()>i)
				{
						save_file <<L.At(i)<< "\n";
						i++;
				}
				save_file.close();
			}
		}
		else if (choice == 10)   //retrive the file
		{
		
			string x;
			string input;
			cout << "enter file name \n";
			cin >> x;
			ifstream save_file(x + ".txt");
			if (save_file.is_open())
			{
				while (getline(save_file, input))
				{
					L.Append(input);
				}
				save_file.close();
				
			}
			else
				cout << "couldn't find file";
		}
	}


	return 0;
}
