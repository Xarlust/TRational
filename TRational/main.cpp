#include <iostream>
#include "TRational.h"

using namespace std;


int main()
{
	cout << "Creating a fraction with a numerator=2 and denominator=4" << endl;
	TRational* rational1 = new TRational(2, 4);	//Создание  дроби, зполнение дроби и автоматическое сокращение дроби
	rational1->Print_Numerator_Denumirator();	//Вывод дроби в представлении (числитель)/(знаменатель)
	rational1->Print_String();					//Вывод дроби в строку

	cout << "Creating a fraction with a numerator=8 and denominator=2" << endl;
	TRational* rational2 = new TRational(8,2 );
	rational2->Print_Numerator_Denumirator();	
	rational2->Print_String();
	cout << "-------------------------" << endl;

	TRational* Sum = rational1->operator+(*rational2);
	cout << "Sum rational1(2/4) + rationa2(8/2) " << endl ;
	Sum->Print_Numerator_Denumirator();
	Sum->Print_String();
	TRational* Minus = rational1->operator-(*rational2);
	cout << "Munus rational1(2/4) - rationa2(8/2) "<< endl ;
	Minus->Print_Numerator_Denumirator();
	Minus->Print_String();
	TRational* Multi = rational1->operator*( *rational2);
	cout << "Multi rational1(2/4) * rationa2(8/2) " << endl;
	Multi->Print_Numerator_Denumirator();
	Multi->Print_String();
	TRational* Div = rational1->operator/( *rational2);
	cout << "Div rational1(2/4) / rationa2(8/2) " << endl;
	Div->Print_Numerator_Denumirator();
	Div->Print_String();
	cout << "-------------------------" << endl;

	Sum = rational1->operator+(6);
	cout << "Sum rational1(2/4) + 4 " << endl;
	Sum->Print_Numerator_Denumirator();
	Sum->Print_String();
	Minus = rational1->operator-(1);
	cout << "Munus rational1(2/4) - 1 " << endl;
	Minus->Print_Numerator_Denumirator();
	Minus->Print_String();
	Multi = rational1->operator*(8);
	cout << "Multi rational1(2/4) * 8 " << endl;
	Multi->Print_Numerator_Denumirator();
	Multi->Print_String();
	Div = rational1->operator/(16);
	cout << "Div rational1(2/4) / 16 " << endl;
	Div->Print_Numerator_Denumirator();
	Div->Print_String();
	cout << "-------------------------" << endl;

	cout << "Creating a fraction with a numerator=2 and denominator=4" << endl;
	TRational* rational3 = new TRational(2, 4);
	rational3->Print_Numerator_Denumirator();
	rational3->Print_String();
	cout << "Creating a fraction with a numerator=6 and denominator=9" << endl;
	TRational* rational4 = new TRational(6, 9);
	rational4->Print_Numerator_Denumirator();
	rational4->Print_String();
	cout << "Creating a fraction with a numerator=16 and denominator=16" << endl;
	TRational* rational5 = new TRational(16, 16);
	rational5->Print_Numerator_Denumirator();
	rational5->Print_String();

	system("pause");
	return 0;
}