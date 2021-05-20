//Bill_PB.cpp
#include "Bill_PB.h"

void Bill_PB::SetTaryf(double v)
{
	this->taryf = v;
}

void Bill_PB::SetZnyzhka(double v)
{
	if (v > 100 || v < 0)
	{
		v = 0;
	}
	this->znyzhka = v;
}

void Bill_PB::SetSumforpay(double v)
{
	this->sumforpay = v;
}


Bill_PB::Bill_PB()
	:surname("a"), cellnumb("0"), taryf(0), znyzhka(0), sumforpay(0)
{}


Bill_PB::Bill_PB(string surname, string cellnumb, double taryf, double znyzhka, double sumforpay)
{
	SetSurname(surname);
	SetCellnumb(cellnumb);
	SetTaryf(taryf);
	SetZnyzhka(znyzhka);
	SetSumforpay(sumforpay);
}

Bill_PB::Bill_PB(const Bill_PB& v)
{
	*this = v;
}

Bill_PB& Bill_PB::operator = (const Bill_PB& n)
{
	surname = n.surname;
	cellnumb = n.cellnumb;
	taryf = n.taryf;
	znyzhka = n.znyzhka;
	sumforpay = n.sumforpay;
	return *this;
}

Bill_PB::operator string () const
{
	stringstream sout;
	sout << endl << " Surname: " << surname << endl;
	sout << " Phone number: " << cellnumb << endl;
	sout << " Taryf per minute: " << taryf << "UAH" << endl;
	sout << " Discount: " << znyzhka << "%" << endl;

	return sout.str();
}

ostream& operator <<(ostream& out, const Bill_PB& s)
{
	out << string(s);
	return out;
}

istream& operator >>(istream& in, Bill_PB& s)
{
	string surname;
	cout << " Enter surname: "; in >> surname;
	s.SetSurname(surname);

	string cellnumb;
	cout << " Enter phone number: "; in >> cellnumb;
	s.SetCellnumb(cellnumb);

	double taryf, znyzhka;
	cout << " Enter taryf per minute: "; in >> taryf;
	do {
		cout << " Enter discount, %: "; in >> znyzhka;
	} while (znyzhka > 100 || znyzhka < 0);
	s.SetTaryf(taryf);
	s.SetZnyzhka(znyzhka);

	return in;
}

double Bill_PB::For_Pay(Time T1, Time T2)
{
	sumforpay = DifferenceForT(T1, T2) * taryf - (DifferenceForT(T1, T2) * taryf) * (znyzhka / 100);
	return sumforpay;
}


Bill_PB& Bill_PB::operator ++() {
	Time::operator++();
	return *this;
}

Bill_PB& Bill_PB::operator --() {
	Time::operator--();
	return *this;
}

Bill_PB Bill_PB::operator ++(int) {
	Bill_PB P = *this;
	Time::operator++(1);
	return P;
}

Bill_PB Bill_PB::operator --(int)
{
	Bill_PB P = *this;
	Time::operator--(1);
	return P;
}
