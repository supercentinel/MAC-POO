#define BOOST_TEST_MODULE MyTestSuite
#include <iostream>
#include <boost/test/included/unit_test.hpp>

#include "fraccion.hpp"

using namespace std;

BOOST_AUTO_TEST_CASE( test_constructor_defecto )
{
    Fraccion f;
    BOOST_CHECK_EQUAL( f.getA(), 0 );
    BOOST_CHECK_EQUAL( f.getB(), 1 );
}

BOOST_AUTO_TEST_CASE( test_constructor_parametros )
{
    Fraccion f( 1, 2 );
    BOOST_CHECK_EQUAL( f.getA(), 1 );
    BOOST_CHECK_EQUAL( f.getB(), 2 );
}

BOOST_AUTO_TEST_CASE( test_constructor_copia )
{
    Fraccion f( 1, 2 );
    Fraccion g( f );
    BOOST_CHECK_EQUAL(f == g, true);
}
