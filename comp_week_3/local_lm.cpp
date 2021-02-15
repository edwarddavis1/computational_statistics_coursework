vec local_lm_I(vec& y, rowvec x0, rowvec X0, mat& x, mat& X, mat& H)
{
  mat Hstar = chol(H, "lower"); 
  vec w = dmvnInt(x, x0, Hstar);
  vec beta = lm_cpp_I(y % sqrt(w), X.each_col() % sqrt(w));
  return X0 * beta;
}

// [[Rcpp::export(name="local_lm_fit")]]
vec local_lm_fit_I(vec& y, mat x0, mat X0, mat& x, mat& X, mat& H)
{
  int n0 = x0.n_rows;
  vec out(n0);
  for(int ii=0; ii < n0; ii++)
  {
    rowvec x00 = x0.row(ii);
    rowvec X00 = X0.row(ii);
    out(ii) = as_scalar(local_lm_I(y, x00, X00, x, X, H));
    if(ii % 50 == 0) {R_CheckUserInterrupt();}
  }
  return out;
}