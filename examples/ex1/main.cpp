#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <mqf/processes/gbm.h>
#include <mqf/processes/ornstein_uhlenbeck.h>
#include <mqf/utility.h>
#include <mqf/functions.h>
#include <mqf/trading/strategies/cw1.h>
#include <mqf/trading/strategies/moving_average.h>
#include <mqf/trading/strategies/stripes.h>
#include <mqf/trading/backtest.h>
#include <mqf/data/yahoo.h>
#include <mqf/optimization/brute_force.h>

using namespace std;
using namespace mqf;

int main() {

	double drift = 0.1;
	double vol = 0.1;
	auto model = Processes::GBM<>( drift + 0.5*vol*vol, vol );

	string ticker = "aapl";

	auto data = Yahoo::loadWithSplits( (ticker + ".csv").c_str() );

	auto start = std::find_if( data.begin(), data.end(), [](auto&& x){ return x.date.year >= 1900; } );
	auto end   = std::find_if(        start, data.end(), [](auto&& x){ return x.date.year >= 2100; } );

	std::vector<double> timeseries;
	timeseries.reserve( data.size() );
	std::transform( start,
					end,
					std::back_inserter(timeseries),
					[](auto&& x){ return x.close; } );


	/*{
		CW1 strat;
		StochasticTest<CW1,decltype(model)> bt(strat,model);
		bt.repeats = 100000;
		bt.run( "strat-1.csv" );
	}
	{
		MAStrategy strat;
		StochasticTest<MAStrategy,decltype(model)> bt(strat,model);
		bt.repeats = 100000;
		bt.run( "strat-ma.csv" );
	}*/
	/*{
		BruteForce<double,2> bf;
		bf.grid.size.setConstant(50);
		bf.bounds.minBounds[0] = 0.04;
		bf.bounds.minBounds[1] = 100;
		bf.bounds.maxBounds[0] = 0.05;
		bf.bounds.maxBounds[1] = 200;
		auto r = bf.optimize( [&](auto&& x){ 
			CW1 strat(x[0],x[0],x[1]);
			Backtest<CW1> bt(strat);
			auto res = bt.runTest( timeseries.begin(), timeseries.end() );
			return -res.sharpeRatio;
		} );

		r.histogram.writeCSV("h.csv");

		cout << "opt: " << r.optimal << endl;
	}*/
	{
		CW1 strat;
		Backtest<CW1> bt(strat);
		auto res = bt.runTest( ("strat-1-" + ticker + ".csv").c_str(), timeseries.begin(), timeseries.end() );
		res.print();
	}
	/*{
		BruteForce<double,2> bf;
		bf.grid.size.setConstant(10);
		bf.bounds.minBounds[0] = 1;
		bf.bounds.maxBounds[0] = 25;
		bf.bounds.minBounds[1] = 26;
		bf.bounds.maxBounds[1] = 50;
		auto r = bf.optimize( [&](auto&& x){
			MAStrategy strat(x[0],x[1]);
			Backtest<MAStrategy> bt(strat);
			auto res = bt.runTest( timeseries.begin(), timeseries.end() );
			return -res.sharpeRatio;
		} );

		r.histogram.writeCSV("h.csv");

		cout << "opt: " << r.optimal << endl;
	}*/
	{
		MAStrategy strat;
		Backtest<MAStrategy> bt(strat);
		auto res = bt.runTest( ("strat-ma-" + ticker + ".csv").c_str(), timeseries.begin(), timeseries.end() );
		res.print();
	}

	cout << "Press enter to continue . . . "; cin.get();
}
