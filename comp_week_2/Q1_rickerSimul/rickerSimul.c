#include <R.h>
#include <Rinternals.h>
#include <math.h>

SEXP rickerSimul(SEXP n_, SEXP nburn_, SEXP r_, SEXP y0) {

    SEXP ys;
    double yx;
    int n, r, nburn;
    double *xys;
    
    n = INTEGER(n_)[0];
    ys = PROTECT(allocVector(REALSXP, n));
    yx = REAL(y0)[0];
    r = INTEGER(r_)[0];
    nburn = INTEGER(nburn_)[0];

    xys = REAL(ys);


    // Burn in phase
    if (nburn > 0) {
        for (int i=1; i < nburn; i++) {
            yx = r * yx * exp(-yx);
        }
    }

    // Simulating and storing
    for (int i=1; i < n; i++) {
        yx = r * yx * exp(-yx);
        xys[i] = yx;
    }

    UNPROTECT(1);

    return ys;
}