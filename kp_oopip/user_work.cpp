#include "header.h"

user::user()
{
	login = " ";
	password = 0;
	level = 0;
}
user::user(string login, size_t password, int level)
{
	set_login(login);
	set_password(password);
	set_level(level);
}

void user::set_password(size_t password)
{
	this->password = password;
}
void user::set_login(string login)
{
	this->login = login;
}
void user::set_level(int level)
{
	this->level = level;
}
void user::edit(vector<shared_ptr<user>>& v_user)
{
	trans_user<user> tr(*this);
	int count = 0, elem, ch;
	view v;
	updater u;
	tr.begin();

	v.view_user();

	cout << "����� ������������: ";
	check_int(v_user.size(), 1, elem, CHOICE_ERR);
	elem = elem - 1;

	while (1)
	{
		cout << "��� �� ������ ��������?\n1. �����\n2. ������\n3. ������� �������\n0. �����\n\n��� �����: ";
		check_int(3, 0, ch, CHOICE_ERR);
		switch (ch)
		{
		case 1:
		{
			string new_login;
			cout << "����� �����: ";
			write_str(new_login);
			v_user[elem]->set_login(new_login);
			break;
		}
		
		case 2:
		{
			char p;
			string pass;
			hash<string> passhasher;
			size_t new_password;

			cout << "����� ������: ";
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

			new_password = passhasher(pass);
			v_user[elem]->set_password(new_password);
            break;
		}
		
		case 3:
		{
			int new_level;
			cout << "������� �������:\n1. ������������\n2. �������������\n\n��� �����: ";
			check_int(2, 1, new_level, CHOICE_ERR);
			v_user[elem]->set_level(new_level);
			break;
		}

		case 0:
		{
			cout << "��������� ���������?\n1.��\n 2.���\n";
			check_int(2, 1, ch, CHOICE_ERR);
			if (ch == 1)
			{
				tr.commit();
				u.update_user();
			}
			else
			{
				tr.backup();
				v_user[elem]->set_login(tr->get_login());
				v_user[elem]->set_password(tr->get_password());
				v_user[elem]->set_level(tr->get_level());
			}

			return;
		}
		
		}
	}
}
void user::get_info(int count)
{
	cout.setf(ios::left);
	cout << "| " << setw(4) << count + 1 << " | " << setw(20) << get_login() << " | " << setw(20) << get_level() << " | " << endl;
	cout.unsetf(ios::left);
}

void add::add_user()
{
	serch s;
	char p;
	string pass;
	hash<string> passhasher;

	cout << "�����: ";
	write_str(login);

	while (s.ser_user(login) != -1)
	{
		cout << "������������ � ����� ������� ��� ����������. ��������� �������: ";
		write_str(login);
	}

	cout << "������: ";
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

	while (pass.length() < 5)
	{
		cout << "\n������ ������� ��������. ��������� �������.\n";
		pass = "";
		cout << "������: ";
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
	}

	password = passhasher(pass);
	cout << "������� �������:\n1. ������������\n2. �������������\n\n��� �����: ";
	check_int(2, 1, level, CHOICE_ERR);

	shared_ptr<user> u = make_shared<user>(login, password, level);
	v_user.push_back(u);

	updater upd;
	upd.update_user();
}
void view::view_user()
{
	loader load;
	load.load_user();

	int i = 0;

	cout << "======================================================\n";
	cout.setf(ios::left);
	cout << "| " << setw(4) << "�" << " | " << setw(20) << "�����" << " | " << setw(20) << "������� �������" << " | " << endl;
	cout.unsetf(ios::left);
	cout << "======================================================\n";
	for (const auto& u : v_user)
	{
		u->get_info(i);
		i++;
		cout << "------------------------------------------------------\n";
	}
}
void del::del_user()
{
	int elem;
	view v;
	updater u;
	v.view_user();

	cout << "����� ������������� ��� ��������: ";
	check_int(v_user.size(), 1, elem, CHOICE_ERR);

	elem = elem - 1;

	v_user.erase(v_user.begin() + elem);

	u.update_user();
}
int serch::ser_user(string login)
{
	loader load;
	load.load_user();

	int i = 0;

	for (const auto& u : v_user)
	{
		if (u->get_login() == login)
		{
			return i;
		}
		i++;
	}

	return -1;
}


vector<shared_ptr<user>> v_user;

