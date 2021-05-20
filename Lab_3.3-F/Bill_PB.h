//Bill_PB.h
#pragma once
#pragma pack(1)
#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"

using namespace std;

class Bill_PB : public Time
{
private:
	string surname;
	string cellnumb;
	double taryf;
	double znyzhka;
	double sumforpay;
public:

	string GetSurname() const { return surname; };
	void SetSurname(string v) { this->surname = v; };

	string GetCellnumb() const { return cellnumb; };
	void SetCellnumb(string v) { this->cellnumb = v; }

	double GetTaryf() const { return taryf; };
	void SetTaryf(double);

	double GetZnyzhka() const { return znyzhka; };
	void SetZnyzhka(double);

	double GetSumforpay() const { return sumforpay; };
	void SetSumforpay(double);

	Bill_PB();
	Bill_PB(string, string, double, double, double);
	Bill_PB(const Bill_PB&);

	Bill_PB& operator = (const Bill_PB&);
	operator string () const;

	friend ostream& operator << (ostream& out, const Bill_PB& s);
	friend istream& operator >> (istream& in, Bill_PB& s);

	Bill_PB& operator ++ ();
	Bill_PB& operator -- ();
	Bill_PB operator ++ (int);
	Bill_PB operator -- (int);


	double For_Pay(Time T1, Time T2);
};
