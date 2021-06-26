#include<iostream>
#define MAX 1000
using namespace std;

//��ϵ�˵Ľṹ��
struct Person {
	string name;
	int sex;  //1--��  2--Ů
	int age;
	string phone;
	string address;
};
//ͨѶ¼�Ľṹ��
struct addressBooks {
	struct Person personArr[MAX];
	int current_size;  //ͨѶ¼��ǰ��¼������
};
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.ɾ����ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.�����ϵ��  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
void addPerson(addressBooks * abs)
{
	//�ж�ͨѶ¼�Ƿ���
	if (abs->current_size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		cout << "������������" << endl;
		cin >> abs->personArr[abs->current_size].name;
		cout << "�������Ա�" << endl << "1 -- ��" << endl << "2 -- Ů" << endl;
		int sex = 0;
		
		while (true) {
			cin >> sex;
			// �������1��2�����˳�ѭ��  ���������ʾ��������
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->current_size].sex = sex;
				break;
			}
			else {
				cout << "��������ȷ���Ա�" << endl;
			}
		}
		
		
		cout << "���������䣺" << endl;
		cin >> abs->personArr[abs->current_size].age;
		cout << "������绰��" << endl;
		cin >> abs->personArr[abs->current_size].phone;
		cout << "�������ַ��" << endl;
		cin >> abs->personArr[abs->current_size].address;
		
		//��������
		abs->current_size++;
		cout << "��ӳɹ�" << endl;

		system("pause"); //���������������
		system("cls"); //����
	}
	
}
void showPerson(addressBooks abs)
{   

	//�жϵ�ǰͨѶ¼�Ƿ�Ϊ��
	if (abs.current_size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs.current_size; i++)
		{
			cout << i+1 << " " << abs.personArr[i].name << "\t ";
			cout << (abs.personArr[i].sex == 1 ? "��" : "Ů" )<< "\t";
			cout << abs.personArr[i].age  << "\t";
			cout << abs.personArr[i].phone << "\t";
			cout << abs.personArr[i].address << endl;

		}
	}
	system("pause");
	system("cls");
	
}
// ɾ����ϵ��
int isExist(addressBooks * abs, string name)
{
	for (int i = 0; i < abs->current_size; i++)
	{
		if (abs->personArr[i].name == name)
		{
			return i;
		}	
	}
	return -1;
}
void deletePerson(addressBooks* abs)
{
	string name;
	cout << "����������ɾ������ϵ�˵������� " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		// ɾ��
		for (ret; ret < abs->current_size; ret++)
		{
			abs->personArr[ret] = abs->personArr[ret + 1];
		}
		abs->current_size--; //����ͨѶ¼�е�����
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findPerson(addressBooks* abs) 
{
	string name;
	cout << "����������ҵ���ϵ�������� " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << ret+1<< " " << abs->personArr[ret].name << "\t ";
		cout << (abs->personArr[ret].sex == 1 ? "��" : "Ů") << "\t";
		cout << abs->personArr[ret].age << "\t";
		cout << abs->personArr[ret].phone << "\t";
		cout << abs->personArr[ret].address << endl;
	}
	
	//�������������
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyPerson(addressBooks* abs)
{
	string name;
	cout << "���������޸ĵ���ϵ�������� " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		cout << "������������" << endl;
		cin >> abs->personArr[ret].name;
		cout << "�������Ա�" << endl << "1 -- ��" << endl << "2 -- Ů" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			// �������1��2�����˳�ѭ��  ���������ʾ��������
			if (sex == 1 || sex == 2)
			{
				abs->personArr[ret].sex = sex;
				break;
			}
			else {
				cout << "��������ȷ���Ա�" << endl;
			}
		}

		cout << "���������䣺" << endl;
		cin >> abs->personArr[ret].age;
		cout << "������绰��" << endl;
		cin >> abs->personArr[ret].phone;
		cout << "�������ַ��" << endl;
		cin >> abs->personArr[ret].address;
		cout << "�޸ĳɹ�" << endl;
	}

	//�������������
	system("pause");
	system("cls");
}
void cleanPerson(addressBooks* abs)
{
	
	abs->current_size = 0;
	cout << "ͨѶ¼�����" << endl;

	system("pause");
	system("cls");
}
int main()
{	
	addressBooks abs;
	abs.current_size = 0;
	int select = 0;
	
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs); //�����ַ
			break;
		case 2:
			showPerson(abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������ʾ����" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

