#ifndef INCLUDED_MQF_DISTRIBUTIONS_LOG_CAUCHY
#define INCLUDED_MQF_DISTRIBUTIONS_LOG_CAUCHY
#include <limits>
#include "cauchy.h"
#include "../functions.h"

namespace mqf {
namespace Distributions {

	struct LogCauchy : Density<> {
		double mu, sigma;
				
		explicit LogCauchy( double mu = 0.0, double sigma = 1.0 ) : mu(mu), sigma(sigma) {}

		double median() const {
			return std::exp( mu );
		}

		double variance() const {
			return std::numeric_limits<double>::infinity();
		}

		double operator()( double x ) const {
			double y = ( std::log(x) - mu ) / sigma;
			return 1.0 / ( x * sigma * Pi * ( 1 + y*y ) );
		}

		double derivative( double x ) const {
			double y = ( std::log(x) - mu ) / sigma;
			double z = sigma * (1.0 + y * y);
			return -(z + 2.0*y) / ( Pi * square(x * z) );
		}

		double cumulative( double x ) const {
			double y = ( std::log(x) - mu ) / sigma;
			return 0.5 + std::atan( y ) / Pi ;
		}

	};

	struct StdLogCauchy : Density<> {

		double median() const {
			return 1.0;
		}

		double variance() const {
			return std::numeric_limits<double>::infinity();
		}

		double operator()( double x ) const {
			double y = std::log(x);
			return 1.0 / ( x * Pi * ( 1 + y*y ) );
		}

		double derivative( double x ) const {
			double y = std::log(x);
			double z = 1.0 + y * y;
			return -(z + 2.0*y) / ( Pi * square(x * z) );
		}

		double cumulative( double x ) const {
			double y = std::log(x);
			return 0.5 + std::atan( y ) / Pi ;
		}

		operator LogCauchy() const {
			return LogCauchy( 0, 1 );
		}

	};

	RV<LogCauchy> exp( const RV<Cauchy>& x ) {
		return MakeRV( LogCauchy( x.dist.mu, x.dist.sigma ) );
	}

	RV<Cauchy> log( const RV<LogCauchy>& x ) {
		return MakeRV( Cauchy( x.dist.mu, x.dist.sigma ) );
	}

}
}

#endif
