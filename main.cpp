#include<iostream>
#define MAX 1000
using namespace std;

//联系人的结构体
struct Person {
	string name;
	int sex;  //1--男  2--女
	int age;
	string phone;
	string address;
};
//通讯录的结构体
struct addressBooks {
	struct Person personArr[MAX];
	int current_size;  //通讯录当前记录的人数
};
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
void addPerson(addressBooks * abs)
{
	//判断通讯录是否满
	if (abs->current_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> abs->personArr[abs->current_size].name;
		cout << "请输入性别：" << endl << "1 -- 男" << endl << "2 -- 女" << endl;
		int sex = 0;
		
		while (true) {
			cin >> sex;
			// 输入的是1或2可以退出循环  输入错误提示重新输入
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->current_size].sex = sex;
				break;
			}
			else {
				cout << "请输入正确的性别" << endl;
			}
		}
		
		
		cout << "请输入年龄：" << endl;
		cin >> abs->personArr[abs->current_size].age;
		cout << "请输入电话：" << endl;
		cin >> abs->personArr[abs->current_size].phone;
		cout << "请输入地址：" << endl;
		cin >> abs->personArr[abs->current_size].address;
		
		//更新人数
		abs->current_size++;
		cout << "添加成功" << endl;

		system("pause"); //请输入任意键继续
		system("cls"); //清屏
	}
	
}
void showPerson(addressBooks abs)
{   

	//判断当前通讯录是否为空
	if (abs.current_size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs.current_size; i++)
		{
			cout << i+1 << " " << abs.personArr[i].name << "\t ";
			cout << (abs.personArr[i].sex == 1 ? "男" : "女" )<< "\t";
			cout << abs.personArr[i].age  << "\t";
			cout << abs.personArr[i].phone << "\t";
			cout << abs.personArr[i].address << endl;

		}
	}
	system("pause");
	system("cls");
	
}
// 删除联系人
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
	cout << "请输入你想删除的联系人的姓名： " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		// 删除
		for (ret; ret < abs->current_size; ret++)
		{
			abs->personArr[ret] = abs->personArr[ret + 1];
		}
		abs->current_size--; //更新通讯录中的人数
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findPerson(addressBooks* abs) 
{
	string name;
	cout << "输入你想查找的联系人姓名： " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << ret+1<< " " << abs->personArr[ret].name << "\t ";
		cout << (abs->personArr[ret].sex == 1 ? "男" : "女") << "\t";
		cout << abs->personArr[ret].age << "\t";
		cout << abs->personArr[ret].phone << "\t";
		cout << abs->personArr[ret].address << endl;
	}
	
	//按任意键后清屏
	system("pause");
	system("cls");
}

//修改联系人
void modifyPerson(addressBooks* abs)
{
	string name;
	cout << "输入你想修改的联系人姓名： " << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		cin >> abs->personArr[ret].name;
		cout << "请输入性别：" << endl << "1 -- 男" << endl << "2 -- 女" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			// 输入的是1或2可以退出循环  输入错误提示重新输入
			if (sex == 1 || sex == 2)
			{
				abs->personArr[ret].sex = sex;
				break;
			}
			else {
				cout << "请输入正确的性别" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		cin >> abs->personArr[ret].age;
		cout << "请输入电话：" << endl;
		cin >> abs->personArr[ret].phone;
		cout << "请输入地址：" << endl;
		cin >> abs->personArr[ret].address;
		cout << "修改成功" << endl;
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}
void cleanPerson(addressBooks* abs)
{
	
	abs->current_size = 0;
	cout << "通讯录已清空" << endl;

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
			addPerson(&abs); //传入地址
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入所示按键" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}

