#include <iostream>
#include <cmath>
#include "eigen/Eigen/Dense"

#include "macro.hpp"
#include "timing.hpp"

class MatrixBenchmarks
{
private:
    using Matrix = Eigen::MatrixXd;
    using Vector = Eigen::VectorXd;

public:
    template <size_t order>
    static double leastSquaresPolynomial(size_t size)
    {
        Vector input = Vector::LinSpaced(size, -1, 1);
        Vector response = Vector::Random(size);
        Matrix expansionMatrix{size, order + 1};
        
        
        for(size_t i = 0; i < size; ++i)
        {
            Vector expansion = calcPolynomialExpansion<order>(input[i]);
            expansionMatrix.row(i) = expansion;
        }
        std::cout<<"Matrix generation done. Starting timer..." << std::endl;
        
        timing::Measurement timer;
        timer.start();

        // Using these coefficients in a polynomial series will yield the 
        // polynomial function with minimal least squares deviation from the
        // input/response data.
        // Volatile is used to ensure that the compiler does not skip the
        // benchmark, due to its results never being used.
        NO_WARN_UNUSED(
            volatile auto expansionCoefficients = 
                expansionMatrix.colPivHouseholderQr().solve(response);
        )

        timer.end();
        return timer.elapsedTime();
    }

private:
    template <size_t order>
    static Vector calcPolynomialExpansion(double input)
    {
        Vector expansion{order + 1};
        
        for(size_t i = 0; i < order + 1; ++i)
            expansion[i] = std::pow(input, i);

        return expansion;
    }
};
