#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE quantumTest

//#include <boost/test/unit_test.hpp>
#include <boost/test/included/unit_test.hpp> // this work

#include <iostream>
#include <optional>
#include "QDate.h"



BOOST_AUTO_TEST_CASE(QDATE)
{
	using namespace quantum::time;
	QDate a(01, 01, 2020);
	QDate b(01, 01, 2020);
	QDate c = a + 20;
	auto d = c.toEpoch();

	std::cout << "a=" << a << std::endl;
	std::cout << "a+20=" << c << std::endl;
	std::cout << "epoch=" << d << std::endl;
	
}
