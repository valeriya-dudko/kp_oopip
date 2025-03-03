#include "header.h"

//все для записи в файл

void loader::load_component()
{
	string price_buf, amount_buf;
	ifstream ifstr;
	ifstr.open("components.txt", ios::binary);

	ifstr.seekg(0, ios::end);
	if (ifstr.tellg() == 0)
	{
		ifstr.close();
		return;
	}

	ifstr.seekg(0, ios::beg);

	v_component.clear();

	while (1)
	{
		getline(ifstr, name);

		getline(ifstr, price_buf);
		price = stod(price_buf);

		getline(ifstr, brand);

		getline(ifstr, amount_buf);
		amount = stoi(amount_buf);

		getline(ifstr, series);

		if (ifstr.eof())
			break;

		shared_ptr<component> component_buf = make_shared<component>(name, price, brand, amount, series);
		v_component.push_back(component_buf);
	}

	ifstr.close();
}
void loader::load_device()
{
	string price_buf, type_buf, amount_buf;
	ifstream ifstr;
	ifstr.open("devices.txt", ios::binary);

	ifstr.seekg(0, ios::end);
	if (ifstr.tellg() == 0)
	{
		ifstr.close();
		return;
	}

	ifstr.seekg(0, ios::beg);

	v_device.clear();

	while (1)
	{
		getline(ifstr, name);

		getline(ifstr, price_buf);
		price = stod(price_buf);

		getline(ifstr, brand);

		getline(ifstr, amount_buf);
		amount = stoi(amount_buf);

		getline(ifstr, type_buf);
		type = stoi(type_buf);

		if (ifstr.eof())
			break;

		shared_ptr<device> device_buf = make_shared<device>(name, price, brand, amount, type);
		v_device.push_back(device_buf);
	}

	ifstr.close();
}
void loader::load_periphery()
{
	string price_buf, purpose_buf, amount_buf;
	ifstream ifstr;
	ifstr.open("peripherys.txt", ios::binary);

	ifstr.seekg(0, ios::end);
	if (ifstr.tellg() == 0)
	{
		ifstr.close();
		return;
	}

	ifstr.seekg(0, ios::beg);

	v_periphery.clear();

	while (1)
	{
		getline(ifstr, name);

		getline(ifstr, price_buf);
		price = stod(price_buf);

		getline(ifstr, brand);

		getline(ifstr, amount_buf);
		amount = stoi(amount_buf);

		getline(ifstr, purpose_buf);
		purpose = stoi(purpose_buf);

		if (ifstr.eof())
			break;

		shared_ptr<periphery> periphery_buf = make_shared<periphery>(name, price, brand, amount, purpose);
		v_periphery.push_back(periphery_buf);
	}

	ifstr.close();
}
void loader::load_user()
{
	ifstream ifstr;
	string pass_buf, level_buf;
	ifstr.open("users.txt", ios::binary);

	ifstr.seekg(0, ios::end);
	if (ifstr.tellg() == 0)
	{
		ifstr.close();
		return;
	}

	ifstr.seekg(0, ios::beg);

	v_user.clear();

	while (1)
	{
		getline(ifstr, login);

		getline(ifstr, pass_buf);
		stringstream sstream(pass_buf);
		sstream >> password;

		getline(ifstr, level_buf);
		level = stoi(level_buf);

		if (ifstr.eof())
			break;

		shared_ptr<user> user_buf = make_shared<user>(login, password, level);
		v_user.push_back(user_buf);
	}

	ifstr.close();
}

void updater::update_component()
{
	ofstream ofstr;
	ofstr.open("components.txt", ios_base::binary | ios_base::trunc);

	for (int i = 0; i < v_component.size(); i++)
	{
		ofstr << v_component[i]->get_name() << '\n' << to_string(v_component[i]->get_price()) << '\n';
		ofstr << v_component[i]->get_brand() << '\n' << to_string(v_component[i]->get_amount()) << '\n' << v_component[i]->get_series() << '\n';
	}
	ofstr.close();
}
void updater::update_device()
{
	ofstream ofstr;
	ofstr.open("devices.txt", ios_base::binary | ios_base::trunc);

	for (int i = 0; i < v_device.size(); i++)
	{
		ofstr << v_device[i]->get_name() << '\n' << to_string(v_device[i]->get_price()) << '\n';
		ofstr << v_device[i]->get_brand() << '\n' << to_string(v_device[i]->get_amount()) << '\n' << to_string(v_device[i]->get_type()) << '\n';
	}
	ofstr.close();
}
void updater::update_periphery()
{
	ofstream ofstr;
	ofstr.open("peripherys.txt", ios_base::binary | ios_base::trunc);

	for (int i = 0; i < v_periphery.size(); i++)
	{
		ofstr << v_periphery[i]->get_name() << '\n' << to_string(v_periphery[i]->get_price()) << '\n';
		ofstr << v_periphery[i]->get_brand() << '\n' << to_string(v_periphery[i]->get_amount()) << '\n' << to_string(v_periphery[i]->get_purpose()) << '\n';
	}
	ofstr.close();
}
void updater::update_user()
{
	ofstream ofstr;
	ofstr.open("users.txt", ios_base::binary | ios_base::trunc);

	for (int i = 0; i < v_user.size(); i++)
	{
		ofstr << v_user[i]->get_login() << '\n' << to_string(v_user[i]->get_password()) << '\n' << to_string(v_user[i]->get_level()) << '\n';
	}
	ofstr.close();
}