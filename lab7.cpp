#include <bits/stdc++.h>
using namespace std;

/*
"	Ежемесячный доход; (физ лиц - 720 000, Юр лиц - 3 000 000)
"	Возраст; (физ лиц - > 18 лет)
"	Пол; (63 - мужчины, 58 - женщины)
"	Стаж работы; (физ лица - > 2)
"	Юридический статус (физ.лицо или юр.лицо);
"	Количество просроченных кредитов;
"	Форма выдачи кредита (нал или безнал);
"	Наличие залогового имущества (при наличии, вводит его стоимость).
"	Запрашиваемая сумма.
*/


int income, age, expr, debts, summ, pledge;
bool entity, gender, type;	

bool check();

int main(){

	printf("Hello! Wanna get a credit? Fill the form");
	
	printf("\nIncome per month: ");
	cin >> income;
	printf("Age: ");
	cin >> age;
	printf("Gender(male 1, female 0): ");
	cin >> gender;
	printf("Years of experience: ");
	cin >> expr;
	printf("Quantity of debts: ");
	cin >> debts;
	printf("Type of credit query(cash 1, non-cash 0): ");
	cin >> type;
	printf("Law entity(Legal 1, physical 0): ");
	cin >> entity;
	printf("Pledge (if no enter 0): ");
	cin >> pledge;
	printf("Summ query: ");
	cin >> summ;
	
	if(check()) printf("\nCredit is allowed! Congrats!");
	else printf("\nCredit is not allowed! :( ");
	
	return 0;
}



bool check(){
	//1_ Ограничение по минимальному доходу: для физ. лиц 720 000 тенге в год для юр. лиц 3 000 000 тенге в год.
	if((!entity && income < 720000) || (entity && income < 3000000)) {
		printf("Const1");
		return 0;
	}
	//2_ Минимальный возраст для физ. лиц 18 лет
	if(!entity && age < 18){
		printf("Const2");
		return 0;
	}
	//3_ Лицам, достигшим пенсионного возраста, кредит не выдается. Пенсионным возрастом считать 63 года для мужчин, 58 лет для женщин.
	if((age >= 63) || (!gender && age >= 58)){
		printf("Const3");
		return 0;
	}
	//4_ Минимальный стаж работы для физ: 2 года
	if(!entity && expr < 2){
		printf("Const4");
		return 0;
	}
	//5_ Максимальная сумма кредита: 3 000 000 тенге для физ. лиц или 30 000 000 тенге для юр. лиц.
	//6_ В случае наличия залогового имущества, максимальная сумма кредита увеличивается на указанную стоимость залогового имущества.
	if((!entity && summ > (3000000 + pledge)) || (entity && summ > (30000000 + pledge))){
		printf("Const5");
		return 0;
	}
	//7_ Минимальный стаж работы компании на рынке (юр. лицо): 5 лет.
	if(entity && expr < 5){
		printf("Const7");
		return 0;
	}
	//8_ В случае если в истории есть просроченный кредит, заявка отклоняется.
	if(debts){
		printf("Const8");
		return 0;
	}
	//9_ Наличными кредит выдается исключительно физ. лицам.
	if(!entity && !type){
		printf("Const9");
		return 0;
	}

	return 1;
}
