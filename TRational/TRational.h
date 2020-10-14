class TRational
{
private:
	int Numerator;// Числитель
	int Denominator;//Знаменатель

public:
	TRational(int numerator, int denominator = 1);					//Конструктор
	~TRational();													//Деструктор
	void Reduction_fractions();								        //Сокращаем дробь
	int Common_denominator(int denominator1, int denominator2);		//Определяем общий знаменатель
	void Print_Numerator_Denumirator();								//Вывод дроби в представлении (числитель)/(знаменатель)
	void Print_String();											//Вывод дроби в строку

	TRational* operator+( int b)				//Суммируем рациональную дробь со сколяр
	{
		return new TRational(this->Numerator + this->Denominator * b, this->Denominator);
	}

	TRational* operator-( int b)					//Вычитаем рациональную дробь со сколяр
	{
		return new TRational(this->Numerator - this->Denominator * b, this->Denominator);
	}

	TRational* operator*( int b)					//Умножаем рациональную дробь на сколяр
	{
		return new TRational(this->Numerator * b, this->Denominator);
	}

	TRational* operator/( int b)					//Делим рациональную дробь на сколяр
	{
		return new TRational(this->Numerator , this->Denominator * b);
	}

	TRational* operator+( TRational b)			//Складываем рациональную дробь с рациональной дробью
	{
		if (this->Denominator == 0 || b.Denominator == 0)
			return new TRational(1, 0);

		TRational* result1 = new TRational(1);
		TRational* result2 = new TRational(1);
		int common_denominator = this->Common_denominator(this->Denominator, b.Denominator );
		result1->Numerator = common_denominator / this->Denominator * this->Numerator;
		result2->Numerator = common_denominator / b.Denominator * b.Numerator;
		return new TRational(result1->Numerator + result2->Numerator, common_denominator);
	}

	TRational* operator-( TRational b)			//Вычитаем рациональную дробь с рациональной дробью
	{
		if (this->Denominator == 0 || b.Denominator == 0)
			return new TRational(1, 0);

		TRational* result1 = new TRational(1);
		TRational* result2 = new TRational(1);
		int common_denominator = this->Common_denominator(this->Denominator, b.Denominator);
		result1->Numerator = common_denominator / this->Denominator * this->Numerator;
		result2->Numerator = common_denominator / b.Denominator * b.Numerator;
		return new TRational(result1->Numerator - result2->Numerator, common_denominator);
	}

	TRational* operator*( TRational b)			//Умножаем рациональную дробь на рациональную дробь
	{
		if (this->Denominator == 0 || b.Denominator == 0)
			return new TRational(1, 0);

		return new TRational(this->Numerator * b.Numerator, this->Denominator * b.Denominator);
	}

	TRational* operator/( TRational b)			//Делим  рациональную дробь на рациональную дробь
	{
		if (this->Denominator == 0 || b.Denominator == 0)
			return new TRational(1, 0);

		return new TRational(this->Numerator*b.Denominator, this->Denominator*b.Numerator);
	}

	
};