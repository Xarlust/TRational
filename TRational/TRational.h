class TRational
{
private:
	int Numerator;// ���������
	int Denominator;//�����������

public:
	TRational(int numerator, int denominator = 1);					//�����������
	~TRational();													//����������
	void Reduction_fractions();								        //��������� �����
	int Common_denominator(int denominator1, int denominator2);		//���������� ����� �����������
	void Print_Numerator_Denumirator();								//����� ����� � ������������� (���������)/(�����������)
	void Print_String();											//����� ����� � ������

	TRational* operator+( int b)				//��������� ������������ ����� �� ������
	{
		return new TRational(this->Numerator + this->Denominator * b, this->Denominator);
	}

	TRational* operator-( int b)					//�������� ������������ ����� �� ������
	{
		return new TRational(this->Numerator - this->Denominator * b, this->Denominator);
	}

	TRational* operator*( int b)					//�������� ������������ ����� �� ������
	{
		return new TRational(this->Numerator * b, this->Denominator);
	}

	TRational* operator/( int b)					//����� ������������ ����� �� ������
	{
		return new TRational(this->Numerator , this->Denominator * b);
	}

	TRational* operator+( TRational b)			//���������� ������������ ����� � ������������ ������
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

	TRational* operator-( TRational b)			//�������� ������������ ����� � ������������ ������
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

	TRational* operator*( TRational b)			//�������� ������������ ����� �� ������������ �����
	{
		if (this->Denominator == 0 || b.Denominator == 0)
			return new TRational(1, 0);

		return new TRational(this->Numerator * b.Numerator, this->Denominator * b.Denominator);
	}

	TRational* operator/( TRational b)			//�����  ������������ ����� �� ������������ �����
	{
		if (this->Denominator == 0 || b.Denominator == 0)
			return new TRational(1, 0);

		return new TRational(this->Numerator*b.Denominator, this->Denominator*b.Numerator);
	}

	
};