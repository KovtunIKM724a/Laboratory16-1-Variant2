#include <iostream>
#include <string>
using namespace std;


const int NUM_GRADES = 3;
const int NUM_ABITURIENTS = 5;

class Abiturient
{
private:
	string Surname;
	string Name;
	string FatherName;
	string Adress;
	int ListMarks[NUM_GRADES];

public:
	void set(string Surname, string Name, string FatherName, string Adress, int Mark[])
	{
		this->Surname = Surname;
		this->Name = Name;
		this->FatherName = FatherName;
		this->Adress = Adress;
		for (int i = 0; i < NUM_GRADES; i++)
			ListMarks[i] = Mark[i];
	}


	int getTotalScore() const {
		int sum = 0;
		for (int i = 0; i < NUM_GRADES; i++)
			sum += ListMarks[i];
		return sum;
	}

	void displayInfo() const
	{
		cout << Surname << " " << Name << " " << FatherName << endl;
		cout << "Adress: " << Adress << endl;
		cout << "List of marks: ";
		for (int i = 0; i < NUM_GRADES; i++)
			cout << ListMarks[i] << " ";
		cout << endl;
	}

	bool hasUnsatisfactoryGrades() const {
		for (int i = 0; i < NUM_GRADES; i++)
			if (ListMarks[i] < 60) return true;
		return false;
	}

	bool hasHalfsatisfactoryGrades() const {
		for (int i = 0; i < NUM_GRADES; i++)
			if (ListMarks[i] < 60 && ListMarks[i] > 50) return true;
		return false;
	}
};

int main()
{
	Abiturient abiturients[NUM_ABITURIENTS];

	int g1[] = {96, 78, 81};
	int g2[] = {42, 60, 80};
	int g3[] = {30, 45, 12};
	int g4[] = {55, 70, 95};
	int g5[] = {100, 65, 80};

	abiturients[0].set("Ivanenko", "Oleg", "Ivanovych", "Kyiv", g1);
	abiturients[1].set("Petrenko", "Maria", "Oleksandrivna", "Lviv", g2);
	abiturients[2].set("Sydorenko", "Iryna", "Petrovna", "Kharkiv", g3);
	abiturients[3].set("Tkachuk", "Andriy", "Mykolayovych", "Odesa", g4);
	abiturients[4].set("Miller", "Anna", "Vitaliivna", "Dnipro", g5);

	cout << "Applicants with unsatisfactory grades: "<< endl;
	for (int i = 0; i < NUM_ABITURIENTS; i++) {
		if (abiturients[i].hasUnsatisfactoryGrades()) {
			abiturients[i].displayInfo();
			cout << endl;
		}
	}

	int a = 200;
	cout << "Applicants with a total score of at least " << a << ":"<< endl;
	for (int i = 0; i < NUM_ABITURIENTS; i++) {
		if (abiturients[i].getTotalScore() >= a) {
			abiturients[i].displayInfo();
			cout << endl;
		}
	}

	int N = 3;
	for (int i = 0; i < NUM_ABITURIENTS - 1; i++) {
		for (int j = i + 1; j < NUM_ABITURIENTS; j++) {
			if (abiturients[i].getTotalScore() < abiturients[j].getTotalScore()) {
				Abiturient temp = abiturients[i];
				abiturients[i] = abiturients[j];
				abiturients[j] = temp;
			}
		}
	}
	cout << "Top " << N << " applicants by total points: " << endl;;
	for (int i = 0; i < N && i < NUM_ABITURIENTS; i++) {
		abiturients[i].displayInfo();
	}
	cout << endl;

	cout << "Applicants with halfsatisfactory grades: " << endl;
	for (int i = 0; i < NUM_ABITURIENTS; i++) {
		if (abiturients[i].hasHalfsatisfactoryGrades()) {
			abiturients[i].displayInfo();
			cout << endl;
		}
	}
}
