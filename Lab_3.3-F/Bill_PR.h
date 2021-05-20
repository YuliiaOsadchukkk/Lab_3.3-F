//Bill_PR.h
#pragma once
#pragma pack(1)//
#include <iostream>
#include <sstream>
#include <string>
#include "Time.h"

using namespace std;

class Bill_PR : private Time
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

	Bill_PR();
	Bill_PR(string, string, double, double, double);
	Bill_PR(const Bill_PR&);

	Bill_PR& operator = (const Bill_PR&);
	operator string () const;

	friend ostream& operator << (ostream& out, const Bill_PR& s);
	friend istream& operator >> (istream& in, Bill_PR& s);

	Bill_PR& operator ++ ();
	Bill_PR& operator -- ();
	Bill_PR operator ++ (int);
	Bill_PR operator -- (int);

	double For_Pay(Time T1, Time T2);
};
