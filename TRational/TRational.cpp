#include <iostream>
#include "TRational.h"

using namespace std;

void TRational::Reduction_fractions()
{
	this->Numerator = this->Numerator > 0 ? this->Numerator : -this->Numerator;
	this->Denominator = this->Denominator > 0 ? this->Denominator : -this->Denominator;
	int MaxValue = Numerator > Denominator ? Numerator : Denominator;

	for (int i = MaxValue; i >= 2; MaxValue--)
	{
		if (Numerator % MaxValue == 0 && Denominator % MaxValue == 0)
		{
			this->Numerator /= MaxValue;
			this->Denominator /= MaxValue;
			break;
		}
	}
}

int TRational::Common_denominator(int denominator1, int denominator2) {
	if (denominator1 < denominator2)
	{
		int denominator = denominator1;
		denominator1 = denominator2;
		denominator2 = denominator;
	}

	if (denominator1 % denominator2 == 0)
		return denominator1;

	int common_denominator = 0;
	for (int i = 2; ; i++)
	{
		common_denominator = denominator1 * i;
		if (common_denominator % denominator2 == 0)
		{
			break;
		}
	}
	return common_denominator;
}


TRational::~TRational()
{

}

TRational::TRational(int numerator, int denominator )
{
	if (numerator == 0)
	{
		this->Numerator = 0;
		this->Denominator = 1;
	}
	else if (numerator == denominator)
	{
		this->Numerator = 1;
		this->Denominator = 1;
	}
	else if (numerator > 0 && denominator > 0 || numerator < 0 && denominator < 0)
	{
		this->Numerator = numerator;
		this->Denominator = denominator;
		Reduction_fractions();
	}
	else if (numerator < 0 || denominator < 0)
	{
		this->Numerator = numerator;
		this->Denominator = denominator;
		Reduction_fractions();
		this->Numerator *= -1;
	}
}

void TRational::Print_Numerator_Denumirator()
{
	cout << "Print Numerator and Denumirator:" << this->Numerator << "/"<< this->Denominator << endl;
}

void TRational::Print_String()
{
	cout << "Print string:" << (double)this->Numerator/(double)this->Denominator << endl;
}


