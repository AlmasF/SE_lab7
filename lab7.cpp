#include <bits/stdc++.h>
using namespace std;

/*
"	����������� �����; (��� ��� - 720 000, �� ��� - 3 000 000)
"	�������; (��� ��� - > 18 ���)
"	���; (63 - �������, 58 - �������)
"	���� ������; (��� ���� - > 2)
"	����������� ������ (���.���� ��� ��.����);
"	���������� ������������ ��������;
"	����� ������ ������� (��� ��� ������);
"	������� ���������� ��������� (��� �������, ������ ��� ���������).
"	������������� �����.

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
	//1_ ����������� �� ������������ ������: ��� ���. ��� 720 000 ����� � ��� ��� ��. ��� 3 000 000 ����� � ���.
	if((!entity && income < 720000) || (entity && income < 3000000)) {
		printf("Const1");
		return 0;
	}
	//2_ ����������� ������� ��� ���. ��� 18 ���
	if(!entity && age < 18){
		printf("Const2");
		return 0;
	}
	//3_ �����, ��������� ����������� ��������, ������ �� ��������. ���������� ��������� ������� 63 ���� ��� ������, 58 ��� ��� ������.
	if((age >= 63) || (!gender && age >= 58)){
		printf("Const3");
		return 0;
	}
	//4_ ����������� ���� ������ ��� ���: 2 ����
	if(!entity && expr < 2){
		printf("Const4");
		return 0;
	}
	//5_ ������������ ����� �������: 3 000 000 ����� ��� ���. ��� ��� 30 000 000 ����� ��� ��. ���.
	//6_ � ������ ������� ���������� ���������, ������������ ����� ������� ������������� �� ��������� ��������� ���������� ���������.
	if((!entity && summ > (3000000 + pledge)) || (entity && summ > (30000000 + pledge))){
		printf("Const5");
		return 0;
	}
	//7_ ����������� ���� ������ �������� �� ����� (��. ����): 5 ���.
	if(entity && expr < 5){
		printf("Const7");
		return 0;
	}
	//8_ � ������ ���� � ������� ���� ������������ ������, ������ �����������.
	if(debts){
		printf("Const8");
		return 0;
	}
	//9_ ��������� ������ �������� ������������� ���. �����.
	if(!entity && !type){
		printf("Const9");
		return 0;
	}

	return 1;
}
