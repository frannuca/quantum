#include "QDate.h"

#include <boost/date_time/gregorian/gregorian_types.hpp> 
#include <ctime>
#include <boost/date_time/posix_time/posix_time_io.hpp>
#include "boost/date_time/local_time/local_time.hpp"

namespace pt = boost::posix_time;
namespace g = boost::gregorian;

quantum::time::QDate::QDate(int day, int month, int year) {
	_d = new boost::gregorian::date(year, month, day);
	auto a = _d->day();
	auto b = _d->year();
	auto c = _d->month();
}

quantum::time::QDate::QDate(const QDate& that) {
	_d = new boost::gregorian::date(*that._d);
}

quantum::time::QDate::QDate(QDate&& that) {
	if (this != &that)
	{
		_d = that._d;		
		that._d = nullptr;
	}	
}

quantum::time::QDate::QDate(const long &btime) {
	_d = new boost::gregorian::date(boost::posix_time::from_time_t(btime).date());
}

quantum::time::QDate::~QDate() {
	delete _d;
}

quantum::time::QDate& quantum::time::QDate::operator=(const quantum::time::QDate& other) {
	if (this != &other) {
		delete _d;
		_d = new boost::gregorian::date(*other._d);
	}
	return *this;
}

quantum::time::QDate& quantum::time::QDate::operator=(quantum::time::QDate&& other) {
	if (this != &other) {
		delete _d;		
		_d = std::exchange(other._d, nullptr);
	}
	return *this;
}

quantum::time::QDate quantum::time::QDate::operator+(int ndays) {
	auto date = *_d + boost::gregorian::days(ndays);
	QDate d(date.day(), date.month(), date.year());
	return d;
}

time_t quantum::time::QDate::toEpoch() {
	using namespace boost::posix_time;
	static ptime epoch(boost::gregorian::date(1970, 1, 1));
	time_duration::sec_type secs = (ptime(*_d, seconds(0)) - epoch).total_seconds();
	return time_t(secs);
}

const std::locale fmt(std::locale::classic(),
	new boost::gregorian::date_facet("%m/%d/%Y"));

std::string dateAsMMDDYYYY(const boost::gregorian::date& date)
{
	std::ostringstream os;
	os.imbue(fmt);
	os << date;
	return os.str();
}
std::ostream&  quantum::time::operator<<(std::ostream& os, const quantum::time::QDate& dt) {
	os.imbue(fmt);
	os << *(dt._d);
	return os;
}