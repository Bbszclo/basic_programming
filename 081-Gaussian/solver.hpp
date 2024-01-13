#ifndef SOLVER_H
#define SOLVER_H

#include "MatrixIO.h"
using namespace std;
using namespace Numeric_lib;
using Numeric_lib::Index;

typedef Numeric_lib::Matrix<double, 2> Matrix2D;
typedef Numeric_lib::Matrix<double, 1> Vector1;

//------------------------------------------------------------------------------

void classical_elimination(Matrix2D& A, Vector1& b);


//------------------------------------------------------------------------------

Vector1 back_substitution(const Matrix2D& A, const Vector1& b);

// An exception of this type is thrown when elimination fails.
struct Elim_failure : std::domain_error {
    Elim_failure(string s) : std::domain_error(s) { }
};


//------------------------------------------------------------------------------

// An exception of this type is thrown when back substitution fails.
struct Back_subst_failure : std::domain_error {
    Back_subst_failure(string s) : std::domain_error(s) { }
};


// YOUR CODE GOES HERE...
void classical_elimination(Matrix2D& A, Vector1& b)
{
    const Index n = A.dim1();

          // traverse from 1st column to the next-to-last
          // filling zeros into all elements under the diagonal:
    for (Index j = 0; j<n-1; ++j) {
        const double pivot = A(j,j);
        if (pivot == 0) throw Elim_failure("Fail to eliminate");
                    // fill zeros into each element under the diagonal of the ith row:
            for (Index i = j+1; i<n; ++i) {
                const double mult = A(i,j) / pivot;
                A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
                b(i) -= mult*b(j);       // make the corresponding change to b
        }
    }
}

Vector1 back_substitution(const Matrix2D& A, Vector1& b)
{
    const Index n = A.dim1();
    Vector1 x(n);

    for (Index i = n-1; i>= 0; --i) {
        double s = b(i) - dot_product(A[i].slice(i+1),x.slice(i+1));

        if (double m = A(i,i))
            x(i) = s/m;
        else
            throw Back_subst_failure("back sub failure");
        }

    return x;
}

void elim_with_partial_pivot(Matrix2D& A, Vector1& b)
{
    const Index n = A.dim1();

    for (Index j = 0; j<n; ++j) {
        Index pivot_row = j;

    // look for a suitable pivot:
        for (Index k = j+1; k<n; ++k)
            if (abs(A(k,j)) > abs(A(pivot_row,j))) pivot_row = k;

        // swap the rows if we found a better pivot:
        if (pivot_row!=j) {
            A.swap_rows(j,pivot_row);
            swap(b(j), b(pivot_row));
        }

                        // elimination:
        for (Index i = j+1; i<n; ++i) {
            const double pivot = A(j,j);
            if (pivot==0) error("can't solve: pivot==0");
            const double mult = A(i,j)/pivot;
            A[i].slice(j) = scale_and_add(A[j].slice(j), -mult, A[i].slice(j));
            b(i) -= mult*b(j);
                    }
    }
}



Vector1 classical_gaussian_elimination(Matrix2D& A, Vector1& b)
{
    elim_with_partial_pivot(A, b);
    return back_substitution(A, b);
}



#endif
