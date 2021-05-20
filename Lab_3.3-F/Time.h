//Time.h

#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Time
{
private:
	unsigned int hour, minute, second;
public:
	unsigned int GetHour() const { return hour; };
	unsigned int GetMinute() const { return minute; };
	unsigned int GetSecond() const { return second; };

	void SetHour(unsigned int);
	void SetMinute(unsigned int);
	void SetSecond(unsigned int);

	Time();
	Time(unsigned int, unsigned int, unsigned int);
	Time& operator = (const Time&);
	operator string () const;

	Time& operator ++ ();
	Time& operator -- ();
	Time operator ++ (int);
	Time operator -- (int);

	friend ostream& operator << (ostream& out, const Time& p);
	friend istream& operator >> (istream& in, Time& p);


	//////////////////////////////////////////////////////////////////////
	// ��������� ������� ����
	friend bool operator <(const Time&, const Time&);
	friend bool operator == (const Time&, const Time&);
	friend bool operator > (const Time&, const Time&);
	friend bool operator <=(const Time&, const Time&);
	friend bool operator >= (const Time&, const Time&);
	friend bool operator != (const Time&, const Time&);

	Time& operator - (int);//����������� � ���� ������ ������� ������
	Time& operator + (int);//��������� �� ���� ������ ������� ������

	friend unsigned int Difference(Time T1, Time T2);//seconds
	friend unsigned int DifferenceForT(Time T1, Time T2);//minutes
	unsigned int ToSeconds();// ����������� � �������
	unsigned int ToMinutes();// ����������� � ������� (� ����������� �� ���� �������)
};


