#ifndef CURRYING_EXAMPLE
#define CURRYING_EXAMPLE
#include "currying.hpp"
namespace currying
{
	int example( )
	{
		std::function< int( int, int, int ) > f( []( int x, int y, int z ){ return x * y * z; } );
		std::cout << curry( f )( 1 )( 2 )( 3 ) << std::endl;
		return 0;
	}
}
#endif //CURRYING_EXAMPLE
