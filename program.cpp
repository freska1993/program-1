#include<string>
#include <iostream>
#include<limits>
#include<vector>
using namespace std;

struct student
{
	vector<string>name;
	vector<int>mark;
	int count = 0;

};

void AddMarkStudent(student& info)
{
	int numper = 0;
	cout << "pleace enter mark of student \n";
	cin >> numper;
	info.mark.push_back(numper);


}

void AddNameStudent(student& info)
{
	char agen = ' ';
	string name = " ";
	do
	{
		cout << "enter name of student \n";

		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		getline(cin, name);
		info.name.push_back(name);
		AddMarkStudent(info);


		info.count++;
		cout << "pleace enter you add more to studrnt ? y/n \n";
		cin >> agen;



	} while (agen == 'y' || agen == 'Y');



}

void ShowStudent(student& info)
{
	if (info.count == 0)
	{
		cout << "not add student yet \n";
		return;
	}
	cout << "-----------------student lest --------------" << endl;

	for (int i = 0;i < info.count;i++)
	{
		cout << "-----------------------" << endl;
		cout << "student [" << i + 1 << "] =" << endl;
		cout << "-----------------------" << endl;

		cout << "name of student is :   " << info.name[i];

		cout << "    and mark is : " << info.mark[i] << endl;


	}



}

void PrintMnuo()
{
	cout << "--------------------------------------\n";
	cout << "-------------- cose minuo ------------\n";
	cout << "--------------------------------------\n";
	cout << "     coes [1] = add for student\n ";
	cout << "     coes [2] = show all student\n ";
	cout << "     coes [3] = scan for student\n ";
	cout << "     coes [4] = out  program\n ";

}

void ScanStudint(student& info)
{
	if (info.count == 0)
	{
		cout << "not found data\n";
		return;
	}
	string scanname = " ";
	cout << "pleace enter name stusent for scaning \n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	getline(cin, scanname);
	for (int i = 0;i < info.count;i++)
	{
		if (info.name[i] == scanname)
		{
			cout << "-------------------------------------\n";
			cout << "name is " << info.name[i] << endl;

			cout << " mark is " << info.mark[i] << endl;
			cout << "-------------------------------------\n";

			return;
		}
	}
}

void OpenChoseInProgram(student& info)
{

	int coses = 0;
	do
	{
		PrintMnuo();

		cin >> coses;


		{
			switch (coses)
			{
			case 1:AddNameStudent(info);break;
			case 2:ShowStudent(info);break;
			case 3:ScanStudint(info);break;
			default: cout << "wrong choice\n";

			}
		}

	} while (coses != 4);
}

int main()
{
	student person1;
	OpenChoseInProgram(person1);


	return 0;
}