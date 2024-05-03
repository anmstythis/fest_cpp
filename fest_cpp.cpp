#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

bool DigitCheck(string str)
{
    vector<bool> dig;
    for (int i = 0; i < str.length(); i++)
    {
        dig.push_back(isdigit(str[i]));
    }

    if (find(dig.begin(), dig.end(), false) != dig.end())
    {
        return false;
    }

    else
    {
        return true;
    }
}

class Cosplayer//косплееры
{
public:
    Cosplayer(string _surname, string _name, unsigned int _age, string _charname, string _fandom)
    {
        this->lastName = _surname;
        this->firstName = _name;
        this->age = _age;
        this->name = _charname;
        this->fandom = _fandom;

        cout << "\n\tWelcome, " << firstName << " " << lastName << "!" << endl;
        cout << "\t\t" << firstName << " is currently cosplaying " << name << " from " << fandom << "." << endl;
    }

    void ChangeCharacter()
    {
        cout << "\nEnter character's full name: " << endl;
        cin >> name;
        name[0] = toupper(name[0]);

        cout << "Where is the character " << name << " from?" << endl;
        cin >> fandom;

        cout << "\t\t" << firstName << " is currently cosplaying " << name << " from " << fandom << "." << endl;
    }

    void WanderAround()
    {
        cout << "How many miliseconds do you need for it, " << firstName << "?" << endl;
        int sec;
        cin >> sec;

        cout <<"Wandering around...\n" << endl;
        Sleep(sec);

        cout << firstName << " has successfully wandered around." << endl;
    }

    void PeopleInteract()
    {
        string interaction[4] = { " took photo with a person.", " hugged a person.", " talked to a person.", " gave the autograph to a person."};

        srand(static_cast<unsigned int>(time(0))); //посев рандомайзера

        cout << firstName << " is going to interact with " << age << " people.\n\n" << endl;
        for (int i = 0; i < age; i++)
        {
            int rnd = rand(); //создание рандомайзера
            Sleep(2000);
            cout << firstName << interaction[(rnd % 4)] << endl;
        }
    }

private:
    string lastName;
    string firstName;
    unsigned int age;
    string fandom;
    string name;
};

void CosplayerAct()
{
    string surname, cospName, charaName, fandom, ageString;
    unsigned int age = 0;

    cout << "\nEnter cosplayer's last name: " << endl;
    cin >> surname;
    surname[0] = toupper(surname[0]);

    cout << "Enter cosplayer's first name: " << endl;
    cin >> cospName;
    cospName[0] = toupper(cospName[0]);

    do
    {
        cout << "Enter cosplayer's age: " << endl;
        cin >> ageString;

        try
        {
            age = atoi(ageString.c_str());
        }
        catch (...)
        {
            cout << "Enter a number!" << endl;
        }
    } while (!DigitCheck(ageString));

    cout << "\nEnter character's full name: " << endl;
    cin >> charaName;
    charaName[0] = toupper(charaName[0]);

    cout << "Where is the character " << charaName << " from?" << endl;
    cin >> fandom;

    Cosplayer cosplayer{ surname, cospName, age, charaName, fandom };

    char what;
    do
    {
        cout << "\nWHAT TO DO?\n" << endl;
        cout << "1. walk around the building \n2. interact with people \n3. change the character \n4. quit" << endl;
        cin >> what;

        switch (what)
        {
            case '1':
            {
                cosplayer.WanderAround();
                break;
            }
            case '2':
            {
                cosplayer.PeopleInteract();
                break;
            }
            case '3':
            {
                cosplayer.ChangeCharacter();
                break;
            }
            case '4':
            {
                break;
            }
        }
    } while (what != '4');
}

int main()
{
    cout << "\t\tWELCOME TO THE FESTIVAL!\n" << endl;
    cout << "1. cosplayers\n2. artists" << endl;

    int opt;
    cin >> opt;

    switch (opt)
    {
        case 1:
        {
            CosplayerAct();
            break;
        }
    }
}

