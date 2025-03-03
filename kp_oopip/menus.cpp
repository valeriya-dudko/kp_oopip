#include "header.h"

shared_ptr<component> def_component = make_shared<component>();
shared_ptr<device> def_device = make_shared<device>();
shared_ptr<periphery> def_periphery = make_shared<periphery>();
shared_ptr<user> def_user = make_shared<user>();

//компараторы. нужны только для функций сортировки. менять в зависимости от типа объекта

bool cmpar_c(shared_ptr<component>& p1, shared_ptr<component>& p2)
{
	return p1->get_price() < p2->get_price();
}

bool cmpar_d(shared_ptr<device>& p1, shared_ptr<device>& p2)
{
	return p1->get_price() < p2->get_price();
}

bool cmpar_p(shared_ptr<periphery>& p1, shared_ptr<periphery>& p2)
{
	return p1->get_price() < p2->get_price();
}

//всякие меню

void menu_admin()
{
	int ch;

	while(1)
	{
		cout << "\nЧто вы хотите сделать?\n\n1. Перейти к управлению учетными записями\n2. Добавить товар\n3. Удалить товар\n";
		cout << "4. Редактировать данные о товаре\n5. Просмотреть данные о товаре\n6. Отсортировать товары по цене\n";
		cout << "7. Искать товары по названию\n8. Отфильтровать товары по цене\n0. Выход\n\nВаш выбор: ";

		check_int(8, 0, ch, CHOICE_ERR);

		switch (ch)
		{
		case 1:
		{
			menu_users();
			break;
		}

		case 2:
		{
			int add_ch;
			add a;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, add_ch, CHOICE_ERR);

			switch (add_ch)
			{
			case 1:
			{
				a.add_component();
				break;
			}

			case 2:
			{
				a.add_device();
				break;
			}

			case 3:
			{
				a.add_periphery();
				break;
			}
			}
			break;
		}

		case 3:
		{
			int del_ch;
			del d;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, del_ch, CHOICE_ERR);

			switch (del_ch)
			{
			case 1:
			{
				d.del_component();
				break;
			}

			case 2:
			{
				d.del_device();
				break;
			}

			case 3:
			{
				d.del_periphery();
				break;
			}
			}
			break;
		}

		case 4:
		{
			int edit_ch;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, edit_ch, CHOICE_ERR);

			switch (edit_ch)
			{
			case 1:
			{
				def_component->edit(v_component);
				break;
			}

			case 2:
			{
				def_device->edit(v_device);
				break;
			}

			case 3:
			{
				def_periphery->edit(v_periphery);
				break;
			}
			}
			break;
		}

		case 5:
		{
			int view_ch;
			view v;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, view_ch, CHOICE_ERR);

			switch (view_ch)
			{
			case 1:
			{
				v.view_component();
				break;
			}

			case 2:
			{
				v.view_device();
				break;
			}

			case 3:
			{
				v.view_periphery();
				break;
			}
			}
			break;
		}

		case 6:
		{
			int sort_ch;
			updater u;
			loader l;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, sort_ch, CHOICE_ERR);

			switch (sort_ch)
			{
			case 1:
			{
				l.load_component();
				sort(v_component.begin(), v_component.end(), cmpar_c);
				u.update_component();
				break;
			}

			case 2:
			{
				l.load_device();
				sort(v_device.begin(), v_device.end(), cmpar_d);
				u.update_device();
				break;
			}

			case 3:
			{
				l.load_periphery();
				sort(v_periphery.begin(), v_periphery.end(), cmpar_p);
				u.update_periphery();
				break;
			}
			}
			break;
		}

		case 7:
		{
			int ser_ch;
			serch s;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, ser_ch, CHOICE_ERR);

			switch (ser_ch)
			{
			case 1:
			{
				s.ser_component();
				break;
			}

			case 2:
			{
				s.ser_device();
				break;
			}

			case 3:
			{
				s.ser_periphery();
				break;
			}
			}
			break;
		}

		case 8:
		{
			int filt_ch;
			filter f;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, filt_ch, CHOICE_ERR);

			switch (filt_ch)
			{
			case 1:
			{
				f.filt_component();
				break;
			}

			case 2:
			{
				f.filt_device();
				break;
			}

			case 3:
			{
				f.filt_periphery();
				break;
			}
			}
			break;
		}

		case 0:
			return;
		}
	}
}

void menu_user()
{
	int ch;

	while(1)
	{
		cout << "\nЧто вы хотите сделать?\n\n1. Просмотреть данные о товаре\n2. Отсортировать товары по цене\n3. Искать товары по названию\n";
		cout << "4. Отфильтровать товары по цене\n5. Собрать заказ\n6. Просмотреть заказ\n0. Выход\n\nВаш выбор: ";

		check_int(6, 0, ch, CHOICE_ERR);

		switch (ch)
		{
		case 1:
		{
			int view_ch;
			view v;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, view_ch, CHOICE_ERR);

			switch (view_ch)
			{
			case 1:
			{
				v.view_component();
				break;
			}

			case 2:
			{
				v.view_device();
				break;
			}

			case 3:
			{
				v.view_periphery();
				break;
			}
			}
			break;
		}

		case 2:
		{
			int sort_ch;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, sort_ch, CHOICE_ERR);

			switch (sort_ch)
			{
			case 1:
			{
				sort(v_component.begin(), v_component.end());
				break;
			}

			case 2:
			{
				sort(v_device.begin(), v_device.end());
				break;
			}

			case 3:
			{
				sort(v_periphery.begin(), v_periphery.end());
				break;
			}
			}
			break;
		}

		case 3:
		{
			int ser_ch;
			serch s;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, ser_ch, CHOICE_ERR);

			switch (ser_ch)
			{
			case 1:
			{
				s.ser_component();
				break;
			}

			case 2:
			{
				s.ser_device();
				break;
			}

			case 3:
			{
				s.ser_periphery();
				break;
			}
			}
			break;
		}

		case 4:
		{
			int filt_ch;
			filter f;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, filt_ch, CHOICE_ERR);

			switch (filt_ch)
			{
			case 1:
			{
				f.filt_component();
				break;
			}

			case 2:
			{
				f.filt_device();
				break;
			}

			case 3:
			{
				f.filt_periphery();
				break;
			}

			}
			break;
		}

		case 5:
		{
			int or_ch;
			order o;
			cout << "1. Компонент\n2. Устройство\n3. Периферийное устройство\n\nВаш выбор: ";
			check_int(3, 1, or_ch, CHOICE_ERR);

			switch (or_ch)
			{
			case 1:
			{
				o.or_component();
				break;
			}

			case 2:
			{
				o.or_device();
				break;
			}

			case 3:
			{
				o.or_periphery();
				break;
			}
			}
			break;
		}

		case 6:
		{
			order o;
			o.view_or();
			break;
		}

		case 0:
			return;
		}
	}
}

void menu_users()
{
	int ch;

	while(1)
	{
		cout << "Что вы хотите сделать?\n1. Зарегистрировать нового пользователя\n2. Просмотреть список пользователей\n";
		cout << "3. Удалить пользователя\n4. Редактировать данные о пользователях\n0. Выход\n\nВаш выбор: ";
		check_int(4, 0, ch, CHOICE_ERR);

		switch (ch)
		{
		case 1:
		{
			add a;
			a.add_user();
			break;
		}

		case 2:
		{
			view v;
			v.view_user();
			break;
		}

		case 3:
		{
			del d;
			d.del_user();
			break;
		}

		case 4:
		{
			def_user->edit(v_user);
			break;
		}

		case 0:
			return;
		}
	}
}

void log_in() //вход
{
	string login, pass;
	size_t password;
	char p;
	hash<string> passhasher;
	serch s;

	cout << "Логин: ";
	write_str(login);
	
	while (s.ser_user(login) == -1)
	{
		cout << "Такого пользователя не существует. Повторите попытку.\n";
		cout << "Логин: ";
		write_str(login);
	}

	cout << "Пароль: ";
	while (true)
	{
		p = _getch();
		if (p == 13) break;
		if (p == '\b') {
			if (!pass.empty()) {
				pass.erase(pass.size() - 1);
				cout << "\b \b";
			}
		}
		if (iswalnum((unsigned char)p))
		{
			cout << '*';
			pass += p;
		}
	}

	password = passhasher(pass);

	while (v_user[s.ser_user(login)]->get_password() != password)
	{
		cout << "\nНеверный пароль. Повторите попытку.\n";
		pass = "";

		cout << "Пароль: ";
		while (true)
		{
			p = _getch();
			if (p == 13) break;
			if (p == '\b') {
				if (!pass.empty()) {
					pass.erase(pass.size() - 1);
					cout << "\b \b";
				}
			}
			if (iswalnum((unsigned char)p))
			{
				cout << '*';
				pass += p;
			}
		}

		password = passhasher(pass);
	}

	user log_user(login, password, 1);
	user log_admin(login, password, 2);

	if (v_user[s.ser_user(login)]->get_level() == 1)
		menu_user();
	else if (v_user[s.ser_user(login)]->get_level() == 2)
		menu_admin();
} 