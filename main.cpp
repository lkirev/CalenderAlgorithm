//Имплементация на два алгоритъма за намиране на ден от седмицата, работещи на различни принципи (Zeller & RataDie)
#include <iostream>
#include <stdio.h>

using namespace std;

//Прототипи на функциите в main()
int findDayOfWeekZeller(int day, int month, int year);
int findRataDieNumber(int year, int month, int day);

int main()
{
    //извикваме функцията с подадени данни и z усвоява върнатата стойност, която е z{0;7}
    int z = findDayOfWeekZeller(15, 6, 2020);
    //според върнатата стойност от функцията, можем да определим коя от всичките 7 варианта е с помощта на switch-case и за всеки цифрен вид на деня, принтираме низ от символи
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

    //тук директно принтираме числото, което се връща от функцията
    cout<<"\nRata Die Number: "<<findRataDieNumber(2020, 6, 15);

    return 0;
}

//тази функция приема дата и връща съответния ден от седмицата с помощта на Алгоритъма на Зелер
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

    w = d + 13*(m+1)/5 + k + k/4 + l/4 + 5*l; //формулата на Алгоритъма на Зелер, която е описана в детайл в реферата
    w = w % 7; //модулната част от формулата
    return w; //връща число от 0 до 6 съответно ден от седмицата
}


//тази функция изпълнява алгоритъма на IBM Rata Die, който измерва дните от 01.01.01, описан е в реферата последния
int findRataDieNumber(int year, int month, int day){
	//дефинираме масив с дните през високосна и невисокосна година
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
		if (yearI%100 == 0 && yearI%400 != 0) //проверяваме дали е високосна година
			leap = 0;
		for (int monthI = 1 ; monthI <= max_month ; monthI++)
		{
			daystotal += daytab[leap][monthI];//присвояваме за всеки месец и спрямо това дали е високосна или невисокосна
		}
	}
	return daystotal; //връщаме общия брой изминали дни
}
