#ifndef CURRYING_CURRYING
#define CURRYING_CURRYING
#include <functional>
namespace currying
{
	template< typename RET, typename ... R > struct currying_return;
	template< typename RET, typename T > struct currying_return< RET( T ) > { typedef std::function< RET( T ) > type; };
	template< typename RET, typename T, typename ... R >
	struct currying_return< RET( T, R ... ) >
	{ typedef std::function< typename currying_return< RET( R ... ) >::type( T ) > type; };
	template< typename RET, typename R > std::function< RET( R ) >curry( const std::function< RET( R ) > & f ) { return f; }
	template< typename RET, typename T, typename ... R >
	typename currying_return< RET( T, R ... ) >::type curry( const std::function< RET( T, R ... ) > & f )
	{
		return std::function< decltype( curry( std::function< RET( R ... x ) >( ) ) )( T ) >
				( [=]( T t )
		{
			return curry( std::function< RET( R ... x ) >
										( [=]( R ... x ){ return f( t, x ... ); } ) );
		} );
	}
}
#endif //CURRYING_CURRYING
