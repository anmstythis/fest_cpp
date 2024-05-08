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
        cout << "Enter a number!" << endl;
        return false;
    }

    else
    {
        return true;
    }
}

class Merch
{
public:
    string name;
    string type;
    double price;
    bool isSold;

    Merch(string _name, string _type, double _price)
    {
        this->name = _name;
        this->type = _type;
        if (_price > 0)
        {
            this->price = _price;
        }
        else
        {
            this->price = 0;
        }
        this->isSold = false;
    }
    void Info()
    {
        cout << "Merchandize name: " << name << "\nMerchandize type: " << type << "\nPrice: " << price <<"\n" << endl;
    }
};

class MerchCollection {
private:
    int count;
    Merch** merch;

public:
    MerchCollection(int size) {
        count = 0;
        merch = new Merch * [size]; //создание массива
    }

    MerchCollection(){}

    void AddMerch(Merch* m) {
        merch[count++] = m; //добавление человека в массив
    }

    void MerchOutput() {
        for (int i = 0; i < count; i++)
        {
            if (merch[i]->isSold == false)
            {
                cout << i+1 << ". ";
                merch[i]->Info();
            }
        }
    }
    string GetName(int index)
    {
        string Name = merch[index-1]->name;
        return Name;
    }

    void ChangeStatus(int index)
    {
        merch[index-1]->isSold = true;
    }
};


class Artist //художники
{
private:
    string nickname;
    unsigned int exp;

public:
    Artist(string nick, unsigned int _exp)
    {
        this->nickname = nick;
        this->exp = _exp;
    }

    friend void SellMerch(Artist& artist, MerchCollection merch) //мерч можно будет продавать только имея по крайней мере 5-летний опыт в рисовании
    {
        if (artist.exp >= 5)
        {
            string product;
            int index;

            do
            {
                cout << "\t\tThis is " << artist.nickname << "'s merchandize. What to sell?\n" << endl;
                merch.MerchOutput();

                cin >> product;

                index = atoi(product.c_str());

            } while (!DigitCheck(product));

            merch.ChangeStatus(index);
            string soldMerch = merch.GetName(index);

            cout << soldMerch << " is sold successfully." << endl;
        }
    }
    void DrawRealTime()
    {
        string strDraw;
        int draw;

        do
        {
            cout << "\t\tWhat to draw in real time? Enter price." << endl;
            cout << "1. sketch(100) \n2. portrait(500) \n3. half(1000) \n4. full(3000)" << endl;
            cin >> strDraw;

            draw = atoi(strDraw.c_str());

        } while (!DigitCheck(strDraw));

        if (draw == 100 || draw == 1)
        {
            cout << "Starting drawing sketch..." << endl;
            Sleep(1000);
            cout << "\nSketch is drawn successfully." << endl;
        }

        else if (draw == 500 || draw == 2)
        {
            cout << "Starting drawing portrait..." << endl;
            Sleep(5000);
            cout << "\nPortrait is drawn successfully." << endl;
        }

        else if (draw == 1000 || draw == 3)
        {
            cout << "Starting drawing half..." << endl;
            Sleep(10000);
            cout << "\nHalf is drawn successfully." << endl;
        }

        else if (draw == 3000 || draw == 4)
        {
            cout << "Starting drawing full..." << endl;
            Sleep(30000);
            cout << "\nFull is drawn successfully." << endl;
        }
    }

    MerchCollection AddMerch(MerchCollection collection, int numMerch)
    {
        string merchName, merchType, strPrice;
        double merchPrice;

        for (int i = 0; i < numMerch; i++)
        {
            cout << "Enter merchandize name: " << endl;
            cin >> merchName;
            merchName[0] = toupper(merchName[0]);

            cout << "Enter merchandize type: " << endl;
            cin >> merchType;

            do
            {
                cout << "Enter merchandize price: " << endl;
                cin >> strPrice;

                merchPrice = atoi(strPrice.c_str());

            } while (!DigitCheck(strPrice));

            Merch* new_merch = new Merch(merchName, merchType, merchPrice);

            collection.AddMerch(new_merch);
        }
        return collection;
    }
};


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
        string strSec;
        int sec;

        do
        {
            cout << "How many miliseconds do you need for it, " << firstName << "?" << endl;
            cin >> strSec;

            sec = atoi(strSec.c_str());

        } while (!DigitCheck(strSec));

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

class Participant //посетители
{

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

        age = atoi(ageString.c_str());
      
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

void ArtistAct()
{
    string artName, exp;
    unsigned int artExp;
    MerchCollection collection;

    cout << "Enter your nickname: " << endl;
    cin >> artName;

    do
    {
        cout << "How many years have you been drawing? " << endl;
        cin >> exp;

        artExp = atoi(exp.c_str());
     
    } while (!DigitCheck(exp));

    Artist artist{ artName, artExp };

    char what;
    do
    {
        cout << "\nWHAT TO DO?\n" << endl;
        cout << "1. add merchandize \n2. sell merchandize \n3. sell sketch \n4. quit" << endl;
        cin >> what;

        switch (what)
        {
            case '1':
            {
                string strNum;
                int numMerch;

                do
                {
                    cout << "Enter a number of merch: " << endl;
                    cin >> strNum;
                   
                    numMerch = atoi(strNum.c_str());
                    
                } while (!DigitCheck(strNum));
                
                MerchCollection coll(numMerch);

                collection = artist.AddMerch(coll, numMerch);
                break;
            }
            case '2':
            {
                SellMerch(artist, collection);
                break;
            }
            case '3':
            {
                artist.DrawRealTime();
                break;
            }
            case '4':
            {
                break;
            }
        }
    } while (what != '4');
    
    
}

void ParticipantAct() // функция для посетителя
{
    vector<Merch> merch; //официальный мерч от феста. можно будет что-нибудь добавить туда

    Merch first{ "Pikachu sparkling keychain", "keychain", 510 };
    merch.push_back(first);

    Merch second{ "Mewtwo purple badge", "badge", 200 };
    merch.push_back(second);

    Merch third{ "Cat ears with decorations", "headband", 3500 };
    merch.push_back(third);

    for (Merch item : merch)
    {
        if (item.isSold == false)
        {
            cout << "\nMerchandize name: " << item.name << "\nMerchandize type: " << item.type << "\nPrice: " << item.price << endl;
        }
    }
}

int main()
{
    cout << "\t\tWELCOME TO THE FESTIVAL!\n" << endl;
    cout << "1. cosplayers\n2. artists\n3. ordinary participant" << endl;

    int opt;
    cin >> opt;

    switch (opt)
    {
        case 1:
        {
            CosplayerAct();
            break;
        }
        case 2:
        {
            ArtistAct();
            break;
        }
        case 3:
        {
            ParticipantAct();
            break;
        }
    }
}

