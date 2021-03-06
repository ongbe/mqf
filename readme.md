# MQF

Mathematics for quantitative finance.

* For educational purposes only
* Work in progress
* ~7200 lines of code


## Features

### Data Acquisition

* Parsing historical data from Yahoo Finance

### Chrono

* Gregorian calendar
* Day count conventions
* Time of day in nanoseconds
* Formatted time of day (hh:mm:ss.ms'us'ns)


### Probability and Stochastic Processes

#### Probability Distributions

* Bernoulli
* Beta
* Binomial
* Bivariate Normal
* Cauchy
* Chi
* Chi-squared
* Continuous Uniform
* Dirac Delta
* Discrete Uniform
* Exponential
* F
* Folded Normal
* Gamma
* Geometric
* Gumbel
* Half-Logistic
* Half-Normal
* Inverse Chi-squared
* Inverse Gamma
* Laplace
* Levy
* Log-Cauchy
* Log-Logistic
* Log-Normal
* Logistic
* Maxwell--Boltzmann
* Multinomial
* Negative Binomial
* Normal
* Poisson
* Rayleigh
* Student's T
* Student's T with Location-Scale
* Triangular
* Wald
* Weibull

#### Copulas

* Ali--Mikhail--Haq
* Clayton
* Comonotonicity
* Countermonotonicity
* Farlie--Gumbel--Morgenstern
* Frank
* Galambos
* Gumbel
* Husler--Reiss
* Independent
* Joe
* Marshall--Olkin
* Plackett

#### Stochastic Processes

* Wiener / Brownian Motion
* Brownian Bridge
* Geometric Brownian Motion
* Ornstein--Uhlenbeck / Vasicek
* Square-Root / CIR
* Exponential Vasicek
* Binomial Tree
* Trinomial Tree
* Gamma
* Poisson

#### Numerical Methods for SDEs

* Euler--Maruyama
* Milstein
* Stochastic RK1


### Statistics

#### Descriptive Statistics

* Sample Mean
* Sample Variance
* Sample Covariance
* Sample Correlation
* Sample Skewness
* Sample Excess Kurtosis
* Min
* Max
* Range
* Geometric Mean
* Harmonic Mean
* Histogram Generation
* Empirical Distribution
* Kernel Density Estimation

#### Kernels

* Cosine
* Epanechnikov
* Gaussian
* Logistic
* Quartic
* Silverman
* Triangular
* Tricube
* Triweight
* Uniform

#### Regression

* Ordinary Least Squares
* Generalized Least Squares
* Polynomial Regression
* Kernel Regression

#### Maximum Likelihood Estimation (MLE)

* Bernoulli
* Exponential
* Geometric
* Maxwell--Boltzmann
* Normal
* Poisson
* Rayleigh
* Wald

#### Method of Moments Estimation

* Chi
* Chi-squared
* Exponential
* Gamma
* Geometric
* Gumbel
* Laplace
* Logistic
* Maxwell--Boltzmann
* Normal
* Poisson
* Rayleigh
* Student's T
* Student's T with Location-Scale
* Wald


### Nonlinear Optimization

* Brute Force Grid
* Differential Evolution
* Sequential Minimal Optimization

#### For Smooth Cost Functions on Riemannian Manifolds

* Line Search
* Gradient Descent
* Conjugate Gradient
 * Fletcher--Reeves
 * Polak--Ribiere
 * Hestenes--Stiefel
 * Conjugate Descent
 * Dai--Yuan
 

### Time Series Analysis

* Exponential Moving Average
* Double Exponential Moving Average
* Simple Moving Average
* Weighted Moving Average
* Autoregression
* Shift Operator
* Finite Difference Operators


### Portfolios

* Efficient Frontier
 * Unconstrained
 * Fully-Invested
* Capital Asset Pricing Model (CAPM)
* Black--Litterman


### Trading

* Portfolios
* Backtest
* Stochastic Test

#### Test Results

* Return
* Log Return
* Volatility
* Sharpe Ratio
* Drawdown
* Max Drawdown

#### Indicators

* Moving Average Convergence/Divergence (MACD)
* Relative Strength (RS)
* Relative Strength Index (RSI)

#### Utility Functions

* Exponential
* Logarithmic
* IsoElastic
* Absolute Risk Aversion
* Relative Risk Aversion


### Finance

#### Interest Rates

* Accumulation factor
* Discount factor
* Conversion between continuous and non-continuous conversion periods.

#### Pricing

* Black--Scholes pricing for European options
* Zero Coupon Bond
* Fixed Coupon Bond
* Floating Rate Note
* Flat Yield Curve
* Nelson--Siegel Curve
* Svensson Curve


### Other

* Fibonacci Numbers
* Fibonacci Ratios

#### Polynomials

* Chebyshev
* Hermite
* Legendre

#### Functions

* Factorial
* Binomial Coefficient
* Beta
* Digamma
* Trigamma

#### Numerical Methods for PDEs

* Rectangular grid in n-dimensions
* Finite differences for partial derivatives, laplacian
* Multi-Index


## Dependencies

* Eigen for linear algebra

