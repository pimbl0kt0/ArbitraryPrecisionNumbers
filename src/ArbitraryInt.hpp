#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <sstream>
#include <iterator>

class AInt
{
public:
	AInt() {}
	AInt(const AInt& n) : data(n.data), negative(n.negative) {}
	AInt(const char* n) : data((n[0] == '0' && strlen(n) != 1) ? std::string(n + 1, n + std::strlen(n)) : n), negative((n[0] == '0' && strlen(n) != 1) ? true : false) {}
	AInt(const std::string &n) : data((n[0] == '0' && n.length() != 1) ? n.substr(1,-1) : n), negative((n[0] == '0' && n.length() != 1) ? true : false) {}
	AInt(int n) : data(std::to_string(n).substr((n < 0) ? 1 : 0, -1)), negative((n < 0) ? true : false) {}
	AInt(long long int n) : data(std::to_string(n).substr((n < 0) ? 1 : 0, -1)), negative((n < 0) ? true : false) {}

	AInt& operator=(const AInt& n);

	AInt operator+(AInt addend);
	AInt operator-(AInt subtrahend);
	AInt operator*(AInt factor);
	AInt operator/(AInt divisor);
	AInt operator%(AInt divisor);

	AInt pow(AInt exp);
	static AInt pow(AInt base, AInt exp);
	
	void operator+=(const AInt& addend);
	void operator-=(const AInt& subtrahend);
	void operator*=(const AInt& factor);
	void operator/=(const AInt& divisor);
	void operator%=(const AInt& divisor);

	AInt operator++();
	AInt operator--();

	AInt operator++(int);
	AInt operator--(int);

	AInt operator-();

	bool operator>(const AInt& comp);
	bool operator<(const AInt& comp);
	bool operator>=(const AInt& comp);
	bool operator<=(const AInt& comp);
	bool operator==(const AInt& comp);
	bool operator!=(const AInt& comp);

	friend inline std::ostream& operator<<(std::ostream& os, const AInt& num);

	friend inline AInt operator""_ai(const char* lit);
	//friend inline AInt operator""_ani(const char* lit);

	std::string getString() const { return data; }
	int length() const { return (int) data.length(); }
	
private:
	std::string data;
	bool negative = false;
};

inline std::ostream& operator<<(std::ostream& os, const AInt& num) {
	os << ((num.negative) ? "-" : "") << num.data;
	return os;
}

inline AInt operator""_ai(const char* lit) {
	return AInt(lit);
}