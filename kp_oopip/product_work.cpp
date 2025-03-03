#include "header.h"

product::product()
{
	name = " ";
	price = 0;
	brand = " ";
	amount = 0;
}
product::product(string name, double price, string brand, int amount)
{
	set_name(name);
	set_price(price);
	set_brand(brand);
	set_amount(amount);
}
void product::set_name(string name)
{
	this->name = name;
}
void product::set_price(double price)
{
	this->price = price;
}
void product::set_brand(string brand)
{
	this->brand = brand;
}
void product::set_amount(int amount)
{
	this->amount = amount;
}

component::component()
{
	series = " ";
}
component::component(string name, double price, string brand, int amount, string series) : product(name, price, brand, amount)
{
	set_series(series);
};
void component::set_series(string series)
{
	this->series = series;
}
void component::get_info(int count)
{
	cout.setf(ios::left);
	cout << "| " << setw(4) << count + 1 << " | " << setw(20) << get_name() << " | " << setw(10) << get_price() << " | ";
	cout << setw(15) << get_brand() << " | " << setw(15) << get_series() << " | " << setw(7) << get_amount() << " |" << endl;
	cout.unsetf(ios::left);
}
void component::edit(vector<shared_ptr<component>>& v_component)
{
	trans_product<component> tr(*this);
	int count = 0, elem, ch;
	view v;
	updater u;
	tr.begin();

	v.view_component();

	cout << "Номер компонента: ";
	check_int(v_component.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	while (1)
	{
		cout << "Что вы хотите изменить?\n1. Название\n2. Цена\n3. Производитель\n4. Серия\n5. Кол-во\n0. Выход\n\nВаш выбор: ";
		check_int(5, 0, ch, CHOICE_ERR);
		switch (ch)
		{
		case 1:
		{
			string new_name;
			cout << "Новое название: ";
			write_str(new_name);
			v_component[elem]->set_name(new_name);
		}
		break;
		case 2:
		{
			double new_price;
			cout << "Новая цена: ";
			check_double(9999, 1, new_price, VALUE_ERR);
			v_component[elem]->set_price(new_price);

		}
		break;
		case 3:
		{
			string new_brand;
			cout << "Новый производитель: ";
			write_str(new_brand);
			v_component[elem]->set_brand(new_brand);
		}
		break;
		case 4:
		{
			string new_series;
			cout << "Новая серия: ";
			write_str(new_series);
			v_component[elem]->set_series(new_series);
		}
		break;
		case 5:
		{
			int new_amount;
			cout << "Новое кол-во: ";
			check_int(9999, 0, new_amount, VALUE_ERR);
			v_component[elem]->set_amount(new_amount);
		}
		break;
		case 0:
		{
			cout << "Сохранить изменения?\n1. Да\n2. Нет\n";
			check_int(2, 1, ch, CHOICE_ERR);
			if (ch == 1)
			{
				tr.commit();
				u.update_component();
			}
			else
			{
				tr.backup();
				v_component[elem]->set_name(tr->get_name());
				v_component[elem]->set_price(tr->get_price());
				v_component[elem]->set_brand(tr->get_brand());
				v_component[elem]->set_series(tr->get_series());
				v_component[elem]->set_amount(tr->get_amount());
			}
		}
		return;
		}
	}
}

device::device()
{
	type = 1;
}
device::device(string name, double price, string brand, int amount, int type) : product(name, price, brand, amount)
{
	set_type(type);
}
void device::set_type(int type)
{
	this->type = type;
}
void device::get_info(int count)
{
	cout.setf(ios::left);
	cout << "| " << setw(4) << count + 1 << " | " << setw(20) << get_name() << " | " << setw(10) << get_price() << " | ";
	cout << setw(15) << get_brand() << " | " << setw(15);
	if (get_type() == 1)
		cout << "Ноутбук";
	else if (get_type() == 2)
		cout << "Моноблок";
	else
		cout << "Компьютер";
	cout << " | " << setw(7) << get_amount() << " |" << endl;
	cout.unsetf(ios::left);
}
void device::edit(vector<shared_ptr<device>>& v_device)
{
	trans_product<device> tr(*this);
	int count = 0, elem, ch;
	view v;
	updater u;
	tr.begin();

	v.view_device();

	cout << "Номер устройства: ";
	check_int(v_device.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	while (1)
	{
		cout << "Что вы хотите изменить?\n1. Название\n2. Цена\n3. Производитель\n4. Тип\n5. Кол-во\n0. Выход\n\nВаш выбор: ";
		check_int(5, 0, ch, CHOICE_ERR);
		switch (ch)
		{
		case 1:
		{
			string new_name;
			cout << "Новое название: ";
			write_str(new_name);
			v_device[elem]->set_name(new_name);
		}
		break;
		case 2:
		{
			double new_price;
			cout << "Новая цена: ";
			check_double(9999, 1, new_price, VALUE_ERR);
			v_device[elem]->set_price(new_price);

		}
		break;
		case 3:
		{
			string new_brand;
			cout << "Новый производитель: ";
			write_str(new_brand);
			v_device[elem]->set_brand(new_brand);
		}
		break;
		case 4:
		{
			int new_type;
			cout << "1. Ноутбук\n2. Моноблок\n3. Компьютер\n\nВаш выбор: ";
			check_int(3, 1, new_type, CHOICE_ERR);
			v_device[elem]->set_type(new_type);
		}
		break;
		case 5:
		{
			int new_amount;
			cout << "Новое кол-во: ";
			check_int(9999, 0, new_amount, VALUE_ERR);
			v_device[elem]->set_amount(new_amount);
		}
		break;
		case 0:
		{
			cout << "Сохранить изменения?\n1. Да\n2. Нет\n";
			check_int(2, 1, ch, CHOICE_ERR);
			if (ch == 1)
			{
				tr.commit();
				u.update_device();
			}
			else
			{
				tr.backup();
				v_device[elem]->set_name(tr->get_name());
				v_device[elem]->set_price(tr->get_price());
				v_device[elem]->set_brand(tr->get_brand());
				v_device[elem]->set_type(tr->get_type());
				v_device[elem]->set_amount(tr->get_amount());
			}
		}
		return;
		}
	}
}

periphery::periphery()
{
	purpose = 1;
}
periphery::periphery(string name, double price, string brand, int amount, int purpose) : product(name, price, brand, amount)
{
	set_purpose(purpose);
}
void periphery::set_purpose(int purpose)
{
	this->purpose = purpose;
}
void periphery::get_info(int count)
{
	cout.setf(ios::left);
	cout << "| " << setw(4) << count + 1 << " | " << setw(20) << get_name() << " | " << setw(10) << get_price() << " | ";
	cout << setw(15) << get_brand() << " | " << setw(15);
	if (get_purpose() == 1)
		cout << "Ввод";
	else if (get_purpose() == 2)
		cout << "Вывод";
	else if (get_purpose() == 3)
		cout << "Хранение";
	else
		cout << "Обмен";
	cout << " | " << setw(7) << get_amount() << " |" << endl;
	cout.unsetf(ios::left);
}
void periphery::edit(vector<shared_ptr<periphery>>& v_periphery)
{
	trans_product<periphery> tr(*this);
	int count = 0, elem, ch;
	view v;
	updater u;
	tr.begin();

	v.view_periphery();

	cout << "Номер устройства: ";
	check_int(v_periphery.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	while (1)
	{
		cout << "Что вы хотите изменить?\n1. Название\n2. Цена\n3. Производитель\n4. Тип\n5. Кол-во\n0. Выход\n\nВаш выбор: ";
		check_int(5, 0, ch, CHOICE_ERR);
		switch (ch)
		{
		case 1:
		{
			string new_name;
			cout << "Новое название: ";
			write_str(new_name);
			v_periphery[elem]->set_name(new_name);
		}
		break;
		case 2:
		{
			double new_price;
			cout << "Новая цена: ";
			check_double(9999, 1, new_price, VALUE_ERR);
			v_periphery[elem]->set_price(new_price);

		}
		break;
		case 3:
		{
			string new_brand;
			cout << "Новый производитель: ";
			write_str(new_brand);
			v_periphery[elem]->set_brand(new_brand);
		}
		break;
		case 4:
		{
			int new_purpose;
			cout << "1. Ввод\n2. Вывод\n3. Хранение данных\n4. Обмен данных\n\nВаш выбор: ";
			check_int(4, 1, new_purpose, CHOICE_ERR);
			v_periphery[elem]->set_purpose(new_purpose);
		}
		break;
		case 5:
		{
			int new_amount;
			cout << "Новое кол-во: ";
			check_int(9999, 0, new_amount, VALUE_ERR);
			v_periphery[elem]->set_amount(new_amount);
		}
		break;
		case 0:
		{
			cout << "Сохранить изменения?\n1. Да\n2. Нет\n";
			check_int(2, 1, ch, CHOICE_ERR);
			if (ch == 1)
			{
				tr.commit();
				u.update_periphery();
			}
			else
			{
				tr.backup();
				v_periphery[elem]->set_name(tr->get_name());
				v_periphery[elem]->set_price(tr->get_price());
				v_periphery[elem]->set_brand(tr->get_brand());
				v_periphery[elem]->set_purpose(tr->get_purpose());
				v_periphery[elem]->set_amount(tr->get_amount());
			}
		}
		return;
		}
	}
}

vector<shared_ptr<component>> v_component;
vector<shared_ptr<device>> v_device;
vector<shared_ptr<periphery>> v_periphery;

vector<shared_ptr<component>> ov_component;
vector<shared_ptr<device>> ov_device;
vector<shared_ptr<periphery>> ov_periphery;

void add::add_component()
	{
		cout << "Название: ";
		write_str(name);

		cout << "Цена: ";
		check_double(9999, 1, price, VALUE_ERR);

		cout << "Производитель: ";
		write_str(brand);

		cout << "Серия: ";
		write_str(series);

		cout << "Кол-во в наличии: ";
		check_int(9999, 1, amount, VALUE_ERR);

		shared_ptr<component> c = make_shared<component>(name, price, brand, amount, series);
		v_component.push_back(c);

		updater upd;
		upd.update_component();
	}
void add::add_device()
	{
		cout << "Название: ";
		write_str(name);

		cout << "Цена: ";
		check_double(9999, 1, price, VALUE_ERR);

		cout << "Производитель: ";
		write_str(brand);

		cout << "1. Ноутбук\n2. Моноблок\n3. Компьютер\n\nВаш выбор: ";
		check_int(3, 1, type, CHOICE_ERR);

		cout << "Кол-во в наличии: ";
		check_int(9999, 1, amount, VALUE_ERR);

		shared_ptr<device> d = make_shared<device>(name, price, brand, amount, type);
		v_device.push_back(d);

		updater upd;
		upd.update_device();
	}
void add::add_periphery()
	{
		cout << "Название: ";
		write_str(name);

		cout << "Цена: ";
		check_double(9999, 1, price, VALUE_ERR);

		cout << "Производитель: ";
		write_str(brand);

		cout << "1. Ввод\n2. Вывод\n3. Хранение данных\n4. Обмен данных\n\nВаш выбор: ";
		check_int(4, 1, purpose, CHOICE_ERR);

		cout << "Кол-во в наличии: ";
		check_int(9999, 1, amount, VALUE_ERR);

		shared_ptr<periphery> p = make_shared<periphery>(name, price, brand, amount, purpose);
		v_periphery.push_back(p);

		updater upd;
		upd.update_periphery();
	}

ostream& operator<<(ostream& out, const component& p) //перегрузка операторы вывода. это для табличного вывода
{
	out << " | " << setw(20) << p.name << " | " << setw(10) << p.price << " | " << setw(15) << p.brand << " | " << setw(15) << p.series << " | " << setw(7) << p.amount << " |";


	return out;
}

void view::view_component()
{
	loader load;
	load.load_component();

	int i = 0;

	cout << "==========================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(10) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Серия" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==========================================================================================\n";
	for (const auto& c : v_component)
	{	
		cout.setf(ios::left);
		cout << "| " << setw(4) << i + 1;
		cout << *c << endl;
		cout.unsetf(ios::left);
		i++;
		cout << "------------------------------------------------------------------------------------------\n";
	}
}
void view::view_device()
{
	loader load;
	load.load_device();

	int i = 0;

	cout << "==========================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(10) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Тип" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==========================================================================================\n";
	for (const auto& d : v_device)
	{
		d->get_info(i);
		i++;
		cout << "------------------------------------------------------------------------------------------\n";
	}
}
void view::view_periphery()
{
	loader load;
	load.load_periphery();

	int i = 0;

	cout << "==========================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(10) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Назначение" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==========================================================================================\n";
	for (const auto& p : v_periphery)
	{
		p->get_info(i);
		i++;
		cout << "------------------------------------------------------------------------------------------\n";
	}
}

void del::del_component()
{
	int elem;
	view v;
	updater u;
	v.view_component();

	cout << "Номер компонента для удаления: ";
	check_int(v_component.size(), 1, elem, CHOICE_ERR);

	elem = elem - 1;

	v_component.erase(v_component.begin() + elem);

	u.update_component();
}
void del::del_device()
{
	int elem;
	view v;
	updater u;
	v.view_device();

	cout << "Номер устройства для удаления: ";
	check_int(v_device.size(), 1, elem, CHOICE_ERR);

	elem = elem - 1;

	v_device.erase(v_device.begin() + elem);

	u.update_device();
}
void del::del_periphery()
{
	int elem;
	view v;
	updater u;
	v.view_periphery();

	cout << "Номер устройства для удаления: ";
	check_int(v_periphery.size(), 1, elem, CHOICE_ERR);

	elem = elem - 1;

	v_periphery.erase(v_periphery.begin() + elem);

	u.update_periphery();
}

void serch::ser_component()
{
	loader load;
	load.load_component();

	int i = 0;

	cout << "Введите название компонента: ";
	write_str(name);

	cout << "==================================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(8) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Серия" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==================================================================================================\n";
	for (const auto& c : v_component)
	{
		if (c->get_name().find(name) != -1)
		{
			c->get_info(i);
			i++;
			cout << "--------------------------------------------------------------------------------------------------\n";
		}
		
	}
}
void serch::ser_device()
{
	loader load;
	load.load_device();

	int i = 0;

	cout << "Введите название устройства: ";
	write_str(name);

	cout << "==================================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(8) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Тип" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==================================================================================================\n";
	for (const auto& d : v_device)
	{
		if (d->get_name().find(name) != -1)
		{
			d->get_info(i);
			i++;
			cout << "--------------------------------------------------------------------------------------------------\n";
		}
	}
}
void serch::ser_periphery()
{
	loader load;
	load.load_periphery();

	int i = 0;

	cout << "Введите название устройства: ";
	write_str(name);

	cout << "==================================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(8) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Назначение" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==================================================================================================\n";
	for (const auto& p : v_periphery)
	{
		if (p->get_name().find(name) != -1)
		{
			p->get_info(i);
			i++;
			cout << "--------------------------------------------------------------------------------------------------\n";
		}
	}
}

void filter::filt_component()
{
	loader load;
	load.load_component();

	int i = 0;

	cout << "Минимальная цена: ";
	check_double(9999, 1, p1, VALUE_ERR);
	cout << "Максимальная цена: ";
	check_double(9999, 1, p2, VALUE_ERR);

	if (p1 > p2)
		swap(p1, p2);

	cout << "==================================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(8) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Серия" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==================================================================================================\n";
	for (const auto& c : v_component)
	{
		if (c->get_price() >= p1 && c->get_price() <= p2)
		{
			c->get_info(i);
			i++;
			cout << "--------------------------------------------------------------------------------------------------\n";
		}
	}
}
void filter::filt_device()
{
	loader load;
	load.load_device();

	int i = 0;

	cout << "Минимальная цена: ";
	check_double(9999, 1, p1, VALUE_ERR);
	cout << "Максимальная цена: ";
	check_double(9999, 1, p2, VALUE_ERR);

	if (p1 > p2)
		swap(p1, p2);

	cout << "==================================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(8) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Тип" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==================================================================================================\n";
	for (const auto& d : v_device)
	{
		if (d->get_price() >= p1 && d->get_price() <= p2)
		{
			d->get_info(i);
			i++;
			cout << "--------------------------------------------------------------------------------------------------\n";
		}
	}
}
void filter::filt_periphery()
{
	loader load;
	load.load_periphery();

	int i = 0;

	cout << "Минимальная цена: ";
	check_double(9999, 1, p1, VALUE_ERR);
	cout << "Максимальная цена: ";
	check_double(9999, 1, p2, VALUE_ERR);

	if (p1 > p2)
		swap(p1, p2);

	cout << "==================================================================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(8) << "Цена, BYN" << " | ";
	cout << setw(15) << "Производитель" << " | " << setw(15) << "Назначение" << " | " << setw(7) << "Кол-во" << " |" << endl;
	cout.unsetf(ios::left);
	cout << "==================================================================================================\n";
	for (const auto& p : v_periphery)
	{
		if (p->get_price() >= p1 && p->get_price() <= p2)
		{
			p->get_info(i);
			i++;
			cout << "--------------------------------------------------------------------------------------------------\n";
		}
	}
}

void order::view_or()
{
	int i = 0;

	if (!ov_component.empty())
	{
		cout << "================================================================================\n";
		cout.setf(ios::left);
		cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(10) << "Цена, BYN" << " | ";
		cout << setw(15) << "Производитель" << " | " << setw(15) << "Серия" << " |" << endl;
		cout.unsetf(ios::left);
		cout << "================================================================================\n";
		for (const auto& c : ov_component)
		{
			cout.setf(ios::left);
			cout << "| " << setw(4) << i + 1 << " | " << setw(20) << c->get_name() << " | " << setw(10) << c->get_price() << " | ";
			cout << setw(15) << c->get_brand() << " | " << setw(15) << c->get_series() << " |" << endl;
			cout.unsetf(ios::left);
			i++;
			cout << "--------------------------------------------------------------------------------\n";
		}
	}

	if (!ov_device.empty())
	{
		cout << "================================================================================\n";
		cout.setf(ios::left);
		cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(10) << "Цена, BYN" << " | ";
		cout << setw(15) << "Производитель" << " | " << setw(15) << "Тип" << " |" << endl;
		cout.unsetf(ios::left);
		cout << "================================================================================\n";
		for (const auto& d : ov_device)
		{
			cout.setf(ios::left);
			cout << "| " << setw(4) << i + 1 << " | " << setw(20) << d->get_name() << " | " << setw(10) << d->get_price() << " | ";
			cout << setw(15) << d->get_brand() << " | " << setw(15) << d->get_type() << " |" << endl;
			cout.unsetf(ios::left);
			i++;
			cout << "--------------------------------------------------------------------------------\n";
		}
	}

	if (!ov_periphery.empty())
	{
		cout << "================================================================================\n";
		cout.setf(ios::left);
		cout << "| " << setw(4) << "№" << " | " << setw(20) << "Название" << " | " << setw(10) << "Цена, BYN" << " | ";
		cout << setw(15) << "Производитель" << " | " << setw(15) << "Назначение" << " |" << endl;
		cout.unsetf(ios::left);
		cout << "================================================================================\n";
		for (const auto& p : ov_periphery)
		{
			cout.setf(ios::left);
			cout << "| " << setw(4) << i + 1 << " | " << setw(20) << p->get_name() << " | " << setw(10) << p->get_price() << " | ";
			cout << setw(15) << p->get_brand() << " | " << setw(15) << p->get_purpose() << " |" << endl;
			cout.unsetf(ios::left);
			i++;
			cout << "--------------------------------------------------------------------------------\n";
		}
	}
}
void order::or_component()
{
	int elem;
	view v;
	updater upd;

	v.view_component();

	cout << "Номер компонента: ";
	check_int(v_component.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	if (v_component[elem]->get_amount() == 0)
		cout << AMOUNT_ERR << endl;
	else
	{
		amount = v_component[elem]->get_amount();
		ov_component.push_back(v_component[elem]);
		v_component[elem]->set_amount(amount - 1);
		upd.update_component();
	}
}
void order::or_device()
{
	int elem;
	view v;
	updater upd;

	v.view_device();

	cout << "Номер устройства: ";
	check_int(v_device.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	if (v_device[elem]->get_amount() == 0)
		cout << AMOUNT_ERR << endl;
	else
	{
		amount = v_device[elem]->get_amount();
		ov_device.push_back(v_device[elem]);
		v_device[elem]->set_amount(amount - 1);
		upd.update_device();
	}
}
void order::or_periphery()
{
	int elem;
	view v;
	updater upd;

	v.view_periphery();

	cout << "Номер устройства: ";
	check_int(v_periphery.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	if (v_periphery[elem]->get_amount() == 0)
		cout << AMOUNT_ERR << endl;
	else
	{
		amount = v_periphery[elem]->get_amount();
		v_periphery[elem]->set_amount(amount - 1);
		ov_periphery.push_back(v_periphery[elem]);
		upd.update_periphery();
	}
}
