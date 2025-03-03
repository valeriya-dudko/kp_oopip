#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctype.h>

//в хедере нужно указывать прототипы всех функций и классов !!!только прототипы, то есть типа логин(войд); и все. без реализации!!!

using namespace std;

namespace inputing
{
	const string CHOICE_ERR = "Такого варианта нет. Повторите попытку: ";
	const string UNKNOWN_ERR = "Произошла ошибка. Повторите попытку: ";
	const string VALUE_ERR = "Недопустимое значение. Повторите попытку: ";
	const string AMOUNT_ERR = "Товара нет в наличии.";

	void check_int(int max, int min, int& val, string message);
	void check_double(double max, double min, double& val, string message);
	void write_str(string& str);
}

using namespace inputing; //это не обязательно, просто в требованиях было сделать свой неймспейс

//это все можно делать в функциях, а не классах. векторы можешь менять на любую другую структуру, принцип везде похожий

class user
{
protected:
	string login;
	size_t password;
	int level;

public:
	user();
	user(string login, size_t password, int level);

	void set_password(size_t password);
	void set_login(string login);
	void set_level(int level);

	size_t get_password()
	{	return password;}
	string get_login()
	{	return login;}
	int get_level()
	{	return level;}

	void get_info(int count);

	void edit(vector<shared_ptr<user>>& v_user);
};

class product
{
protected:
	string name;
	double price;
	string brand;
	int amount;

public:
	product();
	product(string name, double price, string brand, int amount);

	void set_name(string name);
	void set_price(double price);
	void set_brand(string brand);
	void set_amount(int amount);

	string get_name()
	{	return name;}
	double get_price()
	{	return price;}
	string get_brand()
	{	return brand;}
	int get_amount()
	{	return amount;}

	void get_info(int count);

	friend bool operator< (const product& p1, const product& p2)
	{
		return p1.price < p2.price;
	}
	friend bool operator> (const product& p1, const product& p2)
	{
		return p1.price > p2.price;
	}
	
};

class component : public product
{
protected:
	string series;

public:
	component();
	component(string name, double price, string brand, int amount, string series);

	void set_series(string series);

	string get_series()
	{return series;}

	void get_info(int count);

	void edit(vector<shared_ptr<component>>& v_component);

	friend ostream& operator<<(ostream& out, const component& p);
};

//эти сто проц в функции. будет проще

class device : public product
{
protected:
	int type;

public:
	device();
	device(string name, double price, string brand, int amount, int type);

	void set_type(int type);

	int get_type()
	{	return type;}

	void get_info(int count);

	void edit(vector<shared_ptr<device>>& v_device);
};

class periphery : public product
{
protected:
	int purpose;

public:
	periphery();
	periphery(string name, double price, string brand, int amount, int purpose);

	void set_purpose(int purpose);

	int get_purpose()
	{	return purpose;}

	void get_info(int count);

	void edit(vector<shared_ptr<periphery>>& v_periphery);
};

class loader
{
protected:
	string name, brand, series, login;
	double price;
	int type, purpose, level, amount;
	size_t password;
public:
	void load_component();
	void load_device();
	void load_periphery();
	void load_user();
};

class updater
{
public:
	void update_component();
	void update_device();
	void update_periphery();
	void update_user();
};

class add
{
protected:
	string name, brand, series, login;
	double price;
	int type, purpose, amount, level;
	size_t password;

public:
	void add_component();
	void add_device();
	void add_periphery();
	void add_user();
};

class view
{
public:
	void view_component();
	void view_device();
	void view_periphery();
	void view_user();
};

class del
{
public:
	void del_component();
	void del_device();
	void del_periphery();
	void del_user();
};

//поиск по названию
class serch
{
protected:
	string name, login;

public:
	void ser_component();
	void ser_device();
	void ser_periphery();
	int ser_user(string login);
};

//фильтр по цене
class filter
{
protected:
	double p1, p2;

public:
	void filt_component();
	void filt_device();
	void filt_periphery();
};

class order
{
protected:
	int amount;

public:
	void view_or();
	void or_component();
	void or_device();
	void or_periphery();
};

//экстерны чтоб работали в других файлах

extern vector<shared_ptr<component>> v_component;
extern vector<shared_ptr<device>> v_device;
extern vector<shared_ptr<periphery>> v_periphery;

extern vector<shared_ptr<component>> ov_component;
extern vector<shared_ptr<device>> ov_device;
extern vector<shared_ptr<periphery>> ov_periphery;

extern vector<shared_ptr<user>> v_user;

//фу трансы (можно без них. это для того, чтоб откатывать изменения)

template <typename product>
class trans_product
{
	shared_ptr<product> previous_state, current_state;
public:
	trans_product(product obj) :current_state(make_shared<product>(obj)), previous_state(nullptr)
	{}
	trans_product() :current_state(nullptr), previous_state(nullptr)
	{}
	~trans_product()
	{
		previous_state = nullptr;
	}
	shared_ptr<product> operator->() {
		return current_state;
	}

	void begin()
	{
		previous_state = current_state;
		current_state = make_shared<product>(product(*previous_state));
	}
	void commit()
	{
		previous_state = nullptr;
	}

	void backup()
	{
		current_state = previous_state;
	}
};

template <typename user>
class trans_user
{
	shared_ptr<user> previous_state, current_state;
public:
	trans_user(user obj) :current_state(make_shared<user>(obj)), previous_state(nullptr)
	{}
	trans_user() :current_state(nullptr), previous_state(nullptr)
	{}
	~trans_user()
	{
		previous_state = nullptr;
	}
	shared_ptr<user> operator->() {
		return current_state;
	}

	void begin()
	{
		previous_state = current_state;
		current_state = make_shared<user>(user(*previous_state));
	}
	void commit()
	{
		previous_state = nullptr;
	}

	void backup()
	{
		current_state = previous_state;
	}
};

void menu_admin();
void menu_users();
void menu_user();
void log_in();


