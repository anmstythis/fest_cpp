#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

bool DigitCheck(string str) {
	vector<bool> dig;

	for (int i = 0; i < str.length(); i++) {
		dig.push_back(isdigit(str[i]));
	}

	if (find(dig.begin(), dig.end(), false) != dig.end()) {
		cout << "Введите число!" << endl;
		return false;
	}

	else {
		return true;
	}
}

class Merch {
public:
	string name;
	string type;
	double price;
	bool isSold;

	Merch(string _name, string _type, double _price) {
		this->name = _name;
		this->type = _type;
		if (_price > 0) {
			this->price = _price;
		}
		else {
			this->price = 0;
		}
		this->isSold = false;
	}

	void Info() {
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
		merch = new Merch * [size];
	}

	MerchCollection() {}

	void AddMerch(Merch* m) {
		merch[count++] = m;
	}

	void MerchOutput() {
		for (int i = 0; i < count; i++) {
			if (merch[i]->isSold == false) {
				cout << i + 1 << ". ";
				merch[i]->Info();
			}
		}
	}

	string GetName(int index) {
		return merch[index - 1]->name;
	}

	void ChangeStatus(int index) {
		merch[index - 1]->isSold = true;
	}

	double GetPrice(int index) {
		return merch[index - 1]->price;
	}

	int GetCount() {
		return count;
	}
};

class Artist {
private:
	string nickname;
	unsigned int exp;

public:
	Artist(string nick, unsigned int _exp) {
		this->nickname = nick;
		this->exp = _exp;
	}

	friend void SellMerch(Artist& artist, MerchCollection merch) {
		if (merch.GetCount() <= 0) {
			cout << "\nПока нечего продать" << endl;
			return;
		}

		if (artist.exp >= 5) {
			string product;
			int index;

			do {
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

	void DrawRealTime() {
		string strDraw;
		int draw;

		do {
			cout << "\t\tЧто писать в режиме реального времени? Выберите:\n" << endl;
			cout << "1. Набросок (100 руб.) \n2. Портрет (500 руб.) \n3. Карикатура (1000 руб.) \n4. Колоссальный портрет (3000 руб.)\n" << endl;
			cin >> strDraw;
			cout << endl;

			draw = atoi(strDraw.c_str());

		} while (!DigitCheck(strDraw));

		if (draw == 100 || draw == 1) {
			cout << "Набросок в процессе написания..." << endl;
			Sleep(1000);
			cout << "\nНабросок успешно написан." << endl;
		}

		else if (draw == 500 || draw == 2) {
			cout << "Портрет в процессе написания..." << endl;
			Sleep(5000);
			cout << "\nПортрет успешно написан." << endl;
		}

		else if (draw == 1000 || draw == 3) {
			cout << "Карикатура в процессе написания..." << endl;
			Sleep(10000);
			cout << "\nКарикатура успешно написана." << endl;
		}

		else if (draw == 3000 || draw == 4) {
			cout << "Колоссальный портрет в процессе написания..." << endl;
			Sleep(30000);
			cout << "\nКолоссальный портрет успешно написан." << endl;
		}
	}

	MerchCollection AddMerch(MerchCollection collection, int numMerch) {
		string merchName, merchType, strPrice;
		double merchPrice;

		for (int i = 0; i < numMerch; i++) {
			cout << "Введите название мерча: " << endl;
			cin >> merchName;
			merchName[0] = toupper(merchName[0]);

			cout << "Введите вид мерча: " << endl;
			cin >> merchType;

			do {
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

class Cosplayer {
private:
	string lastName;
	string firstName;
	unsigned int age;
	string fandom;
	string name;

public:
	Cosplayer(string _surname, string _name, unsigned int _age, string _charname, string _fandom) {
		this->lastName = _surname;
		this->firstName = _name;
		this->age = _age;
		this->name = _charname;
		this->fandom = _fandom;

		cout << "\n\tДобро пожаловать, " << firstName << " " << lastName << "!" << endl;
		cout << "\t\t" << firstName << " косплеит " << name << " из " << fandom << "." << endl;
	}

	string getFirstName() const {
		return firstName;
	}

	string getCharName() const {
		return name;
	}

	void ChangeCharacter() {
		cout << "Введите имя персонажа: " << endl;
		cin >> name;
		name[0] = toupper(name[0]);

		cout << "Откуда ваш персонаж: " << name << " ?" << endl;
		cin >> fandom;

		cout << "\t\t" << firstName << " косплеит " << name << " из " << fandom << "." << endl;
	}

	void WanderAround() {
		string strSec;
		int sec;

		do {
			cout << "Сколько милисекунд тебе нужно на это, " << firstName << "?" << endl;
			cin >> strSec;

			sec = atoi(strSec.c_str());

		} while (!DigitCheck(strSec));

		cout << "\nПрогуливаешься вокруг...\n" << endl;
		Sleep(sec);

		cout << firstName << " в конечном итоге вернулся на место, где начал прогулку." << endl;
	}

	void PeopleInteract() {
		string interaction[4] = { " сделал(-а) фото со случайным человеком.", " обнял(-а) случаного человека.", " поговорил(-а) со случайным человеком.", " дал(-а) автогроаф фанату." };

		srand(static_cast<unsigned int>(time(0)));

		cout << firstName << " развлекается с " << age << " людьми.\n\n" << endl;
		for (int i = 0; i < age; i++) {
			int rnd = rand();
			Sleep(2000);
			cout << firstName << interaction[(rnd % 4)] << endl;
		}
	}
};

class Practicant {
private:
	string name;
	double balance;
	MerchCollection& collection;

public:
	Practicant(string name, double balance, MerchCollection& collection)
		: collection(collection) {
		this->name = name;
		this->balance = balance;
	}

	double getBalance() const {
		return balance;
	}

	void BuyMerch() {
		string product;
		int index;

		if (collection.GetCount() <= 0) {
			cout << "Пока нечего продавать..." << endl;
			return;
		}

		do {
			cout << "\t\tДоступный мерч. Что купить?" << endl;
			collection.MerchOutput();
			cin >> product;

			index = atoi(product.c_str());

		} while (!DigitCheck(product));

		if (balance >= collection.GetPrice(index)) {
			balance -= collection.GetPrice(index);
			collection.ChangeStatus(index);
			cout << name << " купил " << collection.GetName(index) << ". Остаток на карте: " << balance << endl;
			cout << "\n--- Чек ---" << endl;
			cout << "Мерч: " << collection.GetName(index) << endl;
			cout << "Сумма покупки: " << collection.GetPrice(index) << endl;
			cout << "Остаток на карте: " << balance << endl;
		}

		else {
			cout << "Недостаточно средств для покупки " << collection.GetName(index) << endl;
		}
	}

	void InteractWithCosplayers(const vector<Cosplayer>& cosplayers) {
		if (cosplayers.empty()) {
			cout << "Пока что никого нет..." << endl;
			return;
		}

		cout << "Доступные косплееры:\n";
		for (size_t i = 0; i < cosplayers.size(); i++) {
			cout << i + 1 << ". " << cosplayers[i].getFirstName() << " косплеит " << cosplayers[i].getCharName() << endl;
		}

		string choice;
		int index;

		do {
			cout << "С кем вы хотите взаимодействовать? Введите номер: ";
			cin >> choice;
			index = atoi(choice.c_str());
		} while (!DigitCheck(choice) || index < 1 || index > cosplayers.size());

		cout << "\nВы выбрали " << cosplayers[index - 1].getFirstName() << " косплеит " << cosplayers[index - 1].getCharName() << ".\n";

		char action;
		while (true) {
			cout << "\nЧто вы хотите сделать?\n";
			cout << "1. Фотосессия\n2. Общение\n3. Участие в конкурсе\n4. Выйти\n" << endl;
			cin >> action;
			cout << endl;

			switch (action) {
			case '1':
				Photoshoot(cosplayers[index - 1]);
				break;
			case '2':
				Chat(cosplayers[index - 1]);
				break;
			case '3':
				ParticipateInContest(cosplayers[index - 1]);
				break;
			case '4':
				return;
			default:
				cout << "Неверный вариант. Пожалуйста, попробуйте снова.\n";
			}
		}
	}

	void Photoshoot(const Cosplayer& cosplayer) {
		cout << "Вы устроили фотосессию с " << cosplayer.getFirstName() << ". Улыбайтесь!\n" << endl;

		string poseChoice;
		int poseIndex;

		cout << "Выберите позу для фотосессии:\n" << endl;
		cout << "1. Классическая поза\n2. Экшн поза\n3. Забавная поза\n4. Групповая поза\n" << endl;

		do {
			cin >> poseChoice;
			cout << endl;
			poseIndex = atoi(poseChoice.c_str());
		} while (!DigitCheck(poseChoice) || poseIndex < 1 || poseIndex > 4);

		switch (poseIndex) {
		case 1:
			cout << cosplayer.getFirstName() << " принял классическую позу.\n" << endl;
			break;
		case 2:
			cout << cosplayer.getFirstName() << " принял экшн позу.\n" << endl;
			break;
		case 3:
			cout << cosplayer.getFirstName() << " принял забавную позу.\n" << endl;
			break;
		case 4:
			cout << cosplayer.getFirstName() << " позирует вместе с вами и другими участниками.\n" << endl;
			break;
		}

		cout << "Фотосессия завершена! У вас получились отличные фотографии с " << cosplayer.getFirstName() << ".\n";
	}

	void Chat(const Cosplayer& cosplayer) {
		cout << "Вы начали общаться с " << cosplayer.getFirstName() << ".\n" << endl;

		string chatChoice;
		int chatIndex;

		cout << "Выберите тему для обсуждения:\n" << endl;
		cout << "1. Косплей и костюмы\n2. Любимые аниме и игры\n3. Личное и хобби\n4. Советы для начинающих косплееров\n" << endl;

		do {
			cin >> chatChoice;
			cout << endl;
			chatIndex = atoi(chatChoice.c_str());
		} while (!DigitCheck(chatChoice) || chatIndex < 1 || chatIndex > 4);

		switch (chatIndex) {
		case 1:
			cout << cosplayer.getFirstName() << " рассказывает вам о своем костюме и процессе его создания.\n" << endl;
			break;
		case 2:
			cout << cosplayer.getFirstName() << " делится своими любимыми аниме и играми.\n" << endl;
			break;
		case 3:
			cout << cosplayer.getFirstName() << " рассказывает о своих хобби и интересах.\n" << endl;
			break;
		case 4:
			cout << cosplayer.getFirstName() << " дает советы по созданию косплея и участию в фестивалях.\n" << endl;
			break;
		}

		cout << "Ваше общение с " << cosplayer.getFirstName() << " прошло отлично!\n";
	}

	void ParticipateInContest(const Cosplayer& cosplayer) {
		cout << cosplayer.getFirstName() << " участвует в конкурсе!\n" << endl;

		string contestChoice;
		int contestIndex;

		cout << "Выберите тип конкурса:\n" << endl;
		cout << "1. Конкурс костюмов\n2. Конкурс сценок\n3. Конкурс фотографий\n4. Танцевальный конкурс\n" << endl;

		do {
			cin >> contestChoice;
			cout << endl;
			contestIndex = atoi(contestChoice.c_str());
		} while (!DigitCheck(contestChoice) || contestIndex < 1 || contestIndex > 4);

		switch (contestIndex) {
		case 1:
			cout << cosplayer.getFirstName() << " участвует в конкурсе костюмов. Желаем удачи!\n" << endl;
			break;
		case 2:
			cout << cosplayer.getFirstName() << " готовит сценку для участия в конкурсе. Это будет зрелищно!\n" << endl;
			break;
		case 3:
			cout << cosplayer.getFirstName() << " отправил свою лучшую фотографию на конкурс.\n" << endl;
			break;
		case 4:
			cout << cosplayer.getFirstName() << " участвует в танцевальном конкурсе. Пусть музыка заиграет!\n" << endl;
			break;
		}

		cout << "Участие в конкурсе завершено. " << cosplayer.getFirstName() << " получил много позитивных эмоций!\n";
	}
};


void CosplayerAct(vector<Cosplayer>& cosplayers) {
	string surname, cospName, charaName, fandom, ageString;
	unsigned int age = 0;

	cout << "Введите фамилию косплеера: " << endl;
	cin >> surname;
	surname[0] = toupper(surname[0]);

	cout << "Введите имя косплеера: " << endl;
	cin >> cospName;
	cospName[0] = toupper(cospName[0]);

	do {
		cout << "Введите возраст косплеера: " << endl;
		cin >> ageString;

		age = atoi(ageString.c_str());

	} while (!DigitCheck(ageString));

	cout << "\nВведите полное имя персонажа для косплея: " << endl;
	cin >> charaName;
	charaName[0] = toupper(charaName[0]);

	cout << "Из какого произведения " << charaName << "?" << endl;
	cin >> fandom;

	cosplayers.emplace_back(surname, cospName, age, charaName, fandom);

	Cosplayer& cosplayer = cosplayers.back();

	char what;
	do {
		cout << "\nЧем заняться?" << endl;
		cout << "\n1. Прогуляться по зданию\n2. Взаимодействовать с людьми\n3. Изменить персонажа\n4. Выйти\n" << endl;
		cin >> what;
		cout << endl;

		switch (what) {
		case '1':
			cosplayer.WanderAround();
			break;
		case '2':
			cosplayer.PeopleInteract();
			break;
		case '3':
			cosplayer.ChangeCharacter();
			break;
		case '4':
			break;
		}
	} while (what != '4');
}

MerchCollection ArtistAct() {
	string artName, exp;
	unsigned int artExp;
	MerchCollection collection;

	cout << "Введите ваш никнейм: " << endl;
	cin >> artName;

	do {
		cout << "Сколько лет вы рисуете? " << endl;
		cin >> exp;

		artExp = atoi(exp.c_str());

	} while (!DigitCheck(exp));

	Artist artist{ artName, artExp };

	char what;
	do {
		cout << "\nЧем заняться?\n" << endl;
		cout << "1. Добавить товары \n2. Продать товары \n3. Продать эскиз \n4. Выйти\n" << endl;
		cin >> what;
		cout << endl;

		switch (what) {
		case '1': {
			string strNum;
			int numMerch;

			do {
				cout << "Введите количество товаров: " << endl;
				cin >> strNum;

				numMerch = atoi(strNum.c_str());

			} while (!DigitCheck(strNum));

			MerchCollection coll(numMerch);

			collection = artist.AddMerch(coll, numMerch);
			break;
		}
		case '2':
			SellMerch(artist, collection);
			break;
		case '3':
			artist.DrawRealTime();
			break;
		case '4':
			break;
		}
	} while (what != '4');

	return collection;
}

void PracticantAct(MerchCollection collection, vector<Cosplayer>& cosplayers) {
	string name;
	double balance;

	cout << "Введите ваше имя: ";
	cin >> name;

	cout << "Введите ваш баланс (руб.): ";
	cin >> balance;

	while (balance <= 0) {
		cout << "Недопустимый ввод! Пожалуйста, введите положительное число для вашего баланса (руб.): ";
		cin >> balance;
	}

	Practicant practicant(name, balance, collection);

	while (true) {
		cout << "\n\t\tЧем желаете заняться, " << name << "?\n" << endl;
		cout << "1. Купить мерч\n2. Взаимодействовать с косплеерами\n3. Проверить кошелёк\n4. Выйти\n" << endl;

		int opt;
		cin >> opt;
		cout << endl;

		switch (opt) {
		case 1:
			practicant.BuyMerch();
			balance = practicant.getBalance();
			break;
		case 2:
			practicant.InteractWithCosplayers(cosplayers);
			break;
		case 3:
			cout << practicant.getBalance() << " руб." << endl;
			break;
		case 4:
			return;
		default:
			cout << "Неверный вариант. Пожалуйста, попробуйте снова.\n";
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MerchCollection collection;
	vector<Cosplayer> cosplayers;

	while (true) {
		cout << "\t\tДобро пожаловать на фестиваль!\n" << endl;
		cout << "1. Косплеер\n2. Художник\n3. Фанат\n4. Уйти\n" << endl;
		cout << "Кто ты?...\n" << endl;

		int opt;
		cin >> opt;
		cout << endl;

		switch (opt) {
		case 1:
			CosplayerAct(cosplayers);
			break;
		case 2:
			collection = ArtistAct();
			break;
		case 3:
			PracticantAct(collection, cosplayers);
			break;
		case 4:
			cout << "\nЖаль..." << endl;
			return 0;
		}
	}
}
