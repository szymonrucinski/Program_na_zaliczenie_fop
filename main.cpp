
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
static bool ready_file = true;
//Our class
class Person
{
    //atrybuty
public:
    string Name;
    string Class;
    string Level;

    Person();
    Person(string copy_Name, string copy_Class, string copy_Level);
    //destruktor
    ~Person();
    void PrintOut();

};

//Default constructor
Person::Person()
{
    this->Name = "Szymon";
    this->Class = "Rucinski";
    this->Level = "19";

}

//constructor
Person::Person(string copy_Name, string copy_Class, string copy_Level)
{
    this->Name = copy_Name;
    this->Class = copy_Class;
    this->Level = copy_Level;

}

//destruktor
Person::~Person() {};

//Text
void Person::PrintOut()
{
    cout << "[name]:";
    cout << " ";
    cout << right << this->Name;
    cout << " ";
    cout << "[Class]:";
    cout << " ";
    cout << right << this->Class;
    cout << " ";
    cout << "[Level]:";
    cout << " ";
    cout << right << this->Level << endl;
}

void VectorContent();
void load_file();
void NewPerson();
void EditPerson();
void removeObject();
int getOrderNumber();
void ExportData();
vector <Person> wektorek;
bool getData(string &copy_Name, string & copy_Class, string & copy_Level, bool addingMode);



int main()
{

    while (true)
    {

        cout << "--------> THE GLOURIOUS BOOK OF HEROES from RPG World hweroes of American nationality only) <-------- " << endl;
        cout << endl;

        cout << "  Put your finger on the PAGE:       " << endl;
        cout << endl;

        if (ready_file == true) { cout << "[1] to read file's content" << endl; }
        else { cout << ""; }
        cout << "[2] to add a new Hero to the book" << endl;
        cout << "[3] to edit book's content" << endl;
        cout << "[4] to kill a hero" << endl;
        cout << "[5] to reprint modified book of heroes" << endl;
        cout << "[q] to quit program" << endl;

        char decision;
        cin >> decision;

        //selecting right subprogram
        switch (decision)
        {
            case '1':			 if (ready_file == true) { load_file(); } break;
            case '2':			 NewPerson(); break;
            case '3':			 EditPerson(); break;
            case '4':			 removeObject(); break;
            case '5':			 ExportData(); break;
            case 'q': case 'Q': 	 return 0;

            default:
                system("cls"); cout << "****You have the pressed wrong button, TRY AGAIN!****" << endl;
                break;
        }

        system("cls");
    }


    system("pause");

return 0;
}


void load_file() {
    int  iterator = 0;
    string Name;
    string Class;
    string Level;
    string line;
    cout << "Type in file name:" << endl;
    cout << "(Do not forget about [.txt] extension[My file's default name is [wizytowka.txt]" << endl;
    string fileName;
    cin >> fileName;
    ifstream file;
    file.open(fileName.c_str());
    if (file.good() == true)
    {

        while (getline(file,line))
        {
            iterator++;
            if (line.find(' ') != line.rfind(' '))
            {


                Name=line.substr(0,line.find(' '));
                Level = line.substr(line.rfind(' ')+1,line.length()-1);
                Class = line.substr(line.find(' ')+1,line.length()-Name.length()-4);

                int level_check = atoi(Level.c_str());
                if (level_check>0 && level_check<101  && (Name.find('1')) && (Name.find('2')) && (Name.find('3')) && (Name.find('4')) && (Name.find('5')) && (Name.find('6')) && (Name.find('7')) && (Name.find('8')) && (Name.find('9')) && (Class.find('1')) && (Class.find('2')) && (Class.find('3')) && (Class.find('4')) && (Class.find('5')) && (Class.find('6')) && (Name.find('7')) && (Class.find('8')) && (Class.find('9')))
                {
                    wektorek.push_back(Person(Name, Class, Level));

                }
                else
                {
                    cout << "There is a mistake in a line no " << iterator << endl;
                }


            }
            else
            {
                cout << "There is a mistake in a line no " << iterator << endl;
            }
        }


        system("pause");

        cout << "Reading from file ";
        for (int x = 0; x<8; x++)
        {
            cout << ". ";
        }

        system("cls");


        file.close();
        system("cls");

        VectorContent();

        system("pause");
        system("cls");
    }
    else
    {
        cout << "No such a file on a HDD!" << endl;
    }

}


void VectorContent()
{
    if (wektorek.size() > 0)
    {
        ready_file = false;
        cout << "Mission Completed with success!\n" << endl;
        cout << endl;
        cout << "Here is the content of Your file\n" << endl;
        cout << endl;
        cout << "     TABLE OF CONTENT        " << endl;
        cout << "/////////////////////////////" << endl;
        for (int k = 0; k < wektorek.size(); k++)
        {
            cout << k + 1 << "\t";
            wektorek[k].PrintOut();
        }
    }
    else { system("cls"); cout << "EMPTY FILE" << endl; }
}


void NewPerson()
{
    string Name, Class, Level;

    if (getData(Name, Class, Level, true) == true)
    {
        wektorek.push_back(Person(Name, Class, Level));
        system("cls");
        VectorContent();
    }
    else cout << "No Hero was added\n\n";
}


void EditPerson()
{
    VectorContent();
    if (wektorek.size() > 0)
    {
        int orderNumber = getOrderNumber() - 1;
        if (orderNumber >= 0 && orderNumber < wektorek.size())
        {
            string Name, Class, Level;

            if (getData(Name, Class, Level, false) == true)
            {
                if (Name != "")     wektorek[orderNumber].Name = Name;					//checking vector is not empty
                if (Class != "")   wektorek[orderNumber].Class = Class;
                if (Level != "")       wektorek[orderNumber].Level = Level;
                system("cls");
                VectorContent();
            }
            else cout << "The data is incorrect\n\n";
        }
        else cout << "No such number in the range\n\n";
    }
}


void removeObject()
{
    VectorContent();
    if (wektorek.size() > 0)
    {
        int orderNumber = getOrderNumber() - 1;
        if (orderNumber >= 0 && orderNumber < wektorek.size())
        {
            wektorek.erase(wektorek.begin() + orderNumber);
            system("cls");
            VectorContent();
        }
        else cout << "No such number in the range\n\n";
    }
}


void ExportData()
{
    string path;
    fstream plik;
    cout << "Give the name of the file with a .txt extension" << endl;
    cin >> path;
    plik.open(path.c_str(), std::ios::out);
    if (!plik.good()) cout << "Program is unable to open this such a file!\n\n";
    else
    {
        for (int i = 0; i < wektorek.size(); i++)
        {
            plik << wektorek[i].Name << " " << wektorek[i].Class << " " << wektorek[i].Level<<endl;
        }
        plik.close();
        cout << "Data has been saved successfully\n\n";
    }
}


//biblia wyjatkow
bool getData(string &copy_Name, string & copy_Class, string & copy_Level, bool addingMode)
{
    char input = 0;
    bool somethingWrong = false;			//default conditions
    int wrongIndex = 0;
    cin.ignore();
    //----------------------------------------------------------------------------------------------------------------------------
    cout << "print in in the name: ";
    while (true)
    {
        input = cin.get();   //gets character
        if (input != '\n') copy_Name += input;

        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') || input == ' ' || input == '\n') {} //checking if character is a letter
        else somethingWrong = true;

        if (input == '\n')
        {
            if (somethingWrong || (addingMode && copy_Name == ""))
            {
                copy_Name = "";
                wrongIndex++;
                if (wrongIndex >= 2) { system("cls"); cout << "Wrong input was typed in exactly two times!!!\n"; break; }
                cout << "Given data is incorrect, please try again using only letters: ";
                somethingWrong = false;
            }
            else break;
        }
    }
    if (wrongIndex >= 2) return false;
    wrongIndex = 0;
    somethingWrong = false;
    //-------------------------------------------------------------------------------------------------------------------------------------
    cout << "print in the Class of your hero : ";
    while (true)
    {
        input = cin.get();
        if (input != '\n') copy_Class += input;

        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') || input == ' ' || input == '\n') {}
        else somethingWrong = true;

        if (input == '\n')
        {
            if (somethingWrong || (addingMode && copy_Class == ""))
            {
                copy_Class = "";
                wrongIndex++;
                if (wrongIndex >= 2) { cout << "Wrong input was typed in twice\n"; break; }
                cout << "Please try again using just letters: ";
                somethingWrong = false;
            }
            else break;
        }
    }
    if (wrongIndex >= 2) return false;
    wrongIndex = 0;
    somethingWrong = false;
    //----------------------------------------------------------------------------------------------------------------------------------------------
    cout << "Type in the Level: ";
    while (true)
    {
        input = cin.get();
        if (input != '\n') copy_Level += input;

        if ((input >= '0' && input <= '9') || input == '\n') {}
        else somethingWrong = true;

        if (input == '\n')
        {
            if (somethingWrong || (copy_Level != "" && atoi(copy_Level.c_str()) < 1 || atoi(copy_Level.c_str()) > 101) || (addingMode && copy_Level == ""))

            {
                copy_Level = "";
                wrongIndex++;
                if (wrongIndex >= 2) { cout << "Wrong input was typed in twice\n"; break; }
                cout << "Given data is incorrect, please try again using only integers: ";
                somethingWrong = false;
            }
            else break;
        }
    }
    if (wrongIndex >= 2) return false;

    return true;
}

int getOrderNumber() //conerting user input into an int --> for the vector
{
    cout << "Type in the hero's number: ";
    string number;
    cin >> number;
    int converted = atoi(number.c_str());
    if (converted <= 0 || converted > wektorek.size())
    {
        cout << "There is no such a number";
        cin >> number;
        converted = atoi(number.c_str());
    }

    return converted;
}