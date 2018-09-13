#ifndef QDATE_H
#define QDATE_H

#include "libdef.h"
#include <time.h>
#include <iostream>

namespace boost { namespace gregorian{ class date; } }

namespace quantum {	namespace time {
	
class EXPORT_SYMBOL QDate {
protected:
	boost::gregorian::date *_d;
public:
	QDate() = delete;
	QDate(int day, int month, int year);	

	QDate(const QDate& date);
	QDate(QDate&& date);
	explicit QDate(const long& unixtime);
	QDate& operator=(const QDate& other);
	QDate& operator=(QDate&& other);
	~QDate();
	QDate operator+(int days);
	time_t toEpoch();

	friend EXPORT_SYMBOL std::ostream&  operator<<(std::ostream& os, const QDate& dt);
};
}}
#endif