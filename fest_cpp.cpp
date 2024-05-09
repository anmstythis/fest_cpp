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
        cout << "Введите число" << endl;
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
        cout << "Название: " << name << "\nВид: " << type << "\nЦена (руб.): " << price << "\n" << endl;
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

    MerchCollection() {}

    void AddMerch(Merch* m) {
        merch[count++] = m; //добавление человека в массив
    }

    void MerchOutput() {
        for (int i = 0; i < count; i++)
        {
            if (merch[i]->isSold == false)
            {
                cout << i + 1 << ". ";
                merch[i]->Info();
            }
        }
    }
    string GetName(int index)
    {
        return merch[index - 1]->name;
    }

    void ChangeStatus(int index)
    {
        merch[index - 1]->isSold = true;
    }

    double GetPrice(int index)
    {
        return merch[index - 1]->price;
    }

    int GetCount() {
      /*  for (int i = 0; i < count; i++)
        {
            if (merch[i]->isSold == false)
            {
                count = i;
            }
        }*/
        return count;
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
        if (merch.GetCount() <= 0)
        {
            cout << "\nПока нечего продать" << endl;
            return;
        }

        if (artist.exp >= 5)
        {
            string product;
            int index;

            do
            {
                cout << "\t\tЭто твой мерч, " << artist.nickname << ". Что продавать?\n" << endl;
                merch.MerchOutput();

                cin >> product;

                index = atoi(product.c_str());

            } while (!DigitCheck(product));

            merch.ChangeStatus(index);
            string soldMerch = merch.GetName(index);

            cout << soldMerch << " успешно продано." << endl;
        }
    }
    void DrawRealTime()
    {
        string strDraw;
        int draw;

        do
        {
            cout << "\t\tЧто писать в риальном времени? Выберите:." << endl;
            cout << "1. Набросок (100 руб.) \n2. Портрет (500 руб.) \n3. Карикатура (1000 руб.) \n4. Колоссальный портрет (3000 руб.)" << endl;
            cin >> strDraw;

            draw = atoi(strDraw.c_str());

        } while (!DigitCheck(strDraw));

        if (draw == 100 || draw == 1)
        {
            cout << "Набросок в процессе написания..." << endl;
            Sleep(1000);
            cout << "\nНабросок успешно написан." << endl;
        }

        else if (draw == 500 || draw == 2)
        {
            cout << "Портрет в процессе написания..." << endl;
            Sleep(5000);
            cout << "\nПортрет успешно написан." << endl;
        }

        else if (draw == 1000 || draw == 3)
        {
            cout << "Карикатура в процессе написания..." << endl;
            Sleep(10000);
            cout << "\nКарикатура успешно написана." << endl;
        }

        else if (draw == 3000 || draw == 4)
        {
            cout << "Колоссальный портрет в процессе написания..." << endl;
            Sleep(30000);
            cout << "\nКолоссальный портрет успешно написан." << endl;
        }
    }

    MerchCollection AddMerch(MerchCollection collection, int numMerch)
    {
        string merchName, merchType, strPrice;
        double merchPrice;

        for (int i = 0; i < numMerch; i++)
        {
            cout << "Введите название мерча: " << endl;
            cin >> merchName;
            merchName[0] = toupper(merchName[0]);

            cout << "Введите вид мерча: " << endl;
            cin >> merchType;

            do
            {
                cout << "Введите стоимость (руб.): " << endl;
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

        cout << "\n\tДобро пожаловать, " << firstName << " " << lastName << "!" << endl;
        cout << "\t\t" << firstName << " косплеит " << name << " из " << fandom << "." << endl;
    }

    void ChangeCharacter()
    {
        cout << "\nВведите имя персонажа: " << endl;
        cin >> name;
        name[0] = toupper(name[0]);

        cout << "Откуда ваш персонаж:" << name << " ?" << endl;
        cin >> fandom;

        cout << "\t\t" << firstName << " косплеит " << name << " из " << fandom << "." << endl;
    }

    void WanderAround()
    {
        string strSec;
        int sec;

        do
        {
            cout << "Сколько милисекунд тебе нужно на это, " << firstName << "?" << endl;
            cin >> strSec;

            sec = atoi(strSec.c_str());

        } while (!DigitCheck(strSec));

        cout << "Прогуливаешься вокруг...\n" << endl;
        Sleep(sec);

        cout << firstName << " в конечном итоге вернулся на место, где начал прогулку." << endl;
    }

    void PeopleInteract()
    {
        string interaction[4] = { " сделал(-а) фото со случайным человеком.", " обнял(-а) случаного человека.", " поговорил(-а) со случайным человеком.", " дал(-а) автогроаф фанату." };

        srand(static_cast<unsigned int>(time(0))); //посев рандомайзера

        cout << firstName << " развлекается с " << age << " людьми.\n\n" << endl;
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

class Practicant //посетители
{
private:
    string name;
    double balance;

public:
    Practicant(string name, double balance) {
        this->name = name;
        this->balance = balance;
    }

    double getBalance() const {
        return balance;
    }

    void BuyMerch(MerchCollection collection) {
        string product;
        int index;

        if (collection.GetCount() <= 0)
        {
            cout << "\nПока нечего продать" << endl;
            return;
        }
        do {
            cout << "\t\tAvailable merchandize. What to buy?" << endl;
            collection.MerchOutput();
            cin >> product;

            index = atoi(product.c_str());
            
        } while (!DigitCheck(product));

        if (balance >= collection.GetPrice(index))
        {
            balance -= collection.GetPrice(index);
            collection.ChangeStatus(index);
            cout << name << " купил " << collection.GetName(index) << ". Остаток на карте: " << balance << endl;
            // Вывод чека
            cout << "\n--- Чек ---" << endl;
            cout << "Мерч: " << collection.GetName(index) << endl;
            cout << "Сумма покупки: " << collection.GetPrice(index) << endl;
            cout << "Остаток на карте: " << balance << endl;
        }
        else {
            cout << "Not enough budget to buy " << collection.GetName(index) << endl;
        }
    }
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

MerchCollection ArtistAct()
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

    return collection;
}

void ParticipantAct(MerchCollection collection)
{
    string name;
    double balance;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your budget (руб.): ";
    cin >> balance;

    while (balance <= 0) {
        cout << "Invalid input! Please enter a positive number for your budget (руб.): ";
        cin >> balance;
    }

    while (true) {
        cout << "\n\t\tWELCOME TO THE FESTIVAL, " << name << "!\n";
        cout << "1. Buy merchandise\n";
        cout << "2. Exit\n";

        int opt;
        cin >> opt;

        Practicant practicant(name, balance);

        switch (opt) {
            case 1: {
                practicant.BuyMerch(collection);
                balance = practicant.getBalance();
                break;
            }
            case 2: {
                return;
            }
            default: {
                cout << "Invalid option. Please try again.\n";
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    MerchCollection merches;

    while (true)
    {
        cout << "\t\tДобро пожаловать на фестиваль!\n" << endl;
        cout << "1. Косплеер\n2. Художник\n3. Фанат\n4. Уйти\n" << endl;
        cout << "Кто ты?...\n" << endl;

        int opt;
        cin >> opt;

        switch (opt)
        {
        case 1:
            CosplayerAct();
            break;
        case 2:
            merches = ArtistAct();
            break;
        case 3:
            ParticipantAct(merches);
            break;
        case 4:
            cout << "\nЖаль..." << endl;
            return 0;
        }
    }
}