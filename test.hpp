#ifndef CURRYING_TEST
#define CURRYING_TEST
#include "currying.hpp"
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/auto_unit_test.hpp>
BOOST_AUTO_TEST_CASE( function_currying )
{
    std::function< int( int, int, int ) > f( []( int x, int y, int z ){ return x * y * z; } );
    BOOST_CHECK_EQUAL( currying::curry( f )( 1 )( 2 )( 3 ), 6 );
}
#endif //CURRYING_TEST
