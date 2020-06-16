//������������� �� ��� ���������� �� �������� �� ��� �� ���������, �������� �� �������� �������� (Zeller & RataDie)
#include <iostream>
#include <stdio.h>

using namespace std;

//��������� �� ��������� � main()
int findDayOfWeekZeller(int day, int month, int year);
int findRataDieNumber(int year, int month, int day);

int main()
{
    //��������� ��������� � �������� ����� � z ������� ��������� ��������, ����� � z{0;7}
    int z = findDayOfWeekZeller(15, 6, 2020);
    //������ ��������� �������� �� ���������, ����� �� ��������� ��� �� �������� 7 �������� � � ������� �� switch-case � �� ����� ������ ��� �� ����, ���������� ��� �� �������
    switch(z){
    case 0:
        cout<<"Saturday";
        break;
    case 1:
        cout<<"Sunday";
        break;
    case 2:
        cout<<"Monday";
        break;
    case 3:
        cout<<"Tuesday";
        break;
    case 4:
        cout<<"Wednesday";
        break;
    case 5:
        cout<<"Thursday";
        break;
    case 6:
        cout<<"Friday";
        break;
    }

    //��� �������� ���������� �������, ����� �� ����� �� ���������
    cout<<"\nRata Die Number: "<<findRataDieNumber(2020, 6, 15);

    return 0;
}

//���� ������� ������ ���� � ����� ���������� ��� �� ��������� � ������� �� ���������� �� �����
int findDayOfWeekZeller(int day, int month, int year){

    int d = day;
    int m = 0;
    int k = year % 100;
    int l = year / 100;
    int w = 0;


    if(month == 1){

        month = 13;
        year = year - 1;

    }if(month == 2){

        month = 14;
        year = year - 1;
    }

    m = month;

    w = d + 13*(m+1)/5 + k + k/4 + l/4 + 5*l; //��������� �� ���������� �� �����, ����� � ������� � ������ � ��������
    w = w % 7; //��������� ���� �� ���������
    return w; //����� ����� �� 0 �� 6 ��������� ��� �� ���������
}


//���� ������� ��������� ���������� �� IBM Rata Die, ����� ������� ����� �� 01.01.01, ������ � � �������� ���������
int findRataDieNumber(int year, int month, int day){
	//���������� ����� � ����� ���� ��������� � ����������� ������
	static char daytab[2][13] =
	{
		{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};
	int daystotal = day;
	for (int yearI = 1 ; yearI <= year ; yearI++)
	{
		int max_month = ( yearI < year ? 12 : month-1 );
		int leap = (yearI%4 == 0);
		if (yearI%100 == 0 && yearI%400 != 0) //����������� ���� � ��������� ������
			leap = 0;
		for (int monthI = 1 ; monthI <= max_month ; monthI++)
		{
			daystotal += daytab[leap][monthI];//����������� �� ����� ����� � ������ ���� ���� � ��������� ��� �����������
		}
	}
	return daystotal; //������� ����� ���� �������� ���
}
