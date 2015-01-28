#include <algorithm>
#include <cmath>
#include <Rcpp.h>
using namespace Rcpp;
//' @title Perm Function
//' @description Calculates all permutations for an integer vector of given length n.
//'
//' @param n a positive integer.
//' @return P matrix with permutations in rows.
//'
//' @export 
// [[Rcpp::export]]
IntegerMatrix perms(double n)
{
  if(n < 0)
    Rcpp::stop("Length of requested integer vector cannot be negative");
    
  if(n - floor(n) != 0)
    Rcpp::stop("Length of requested integer vector cannot fraction");
    
    
  int n_fac = 1;
  IntegerVector v(n);
  //calculating factorial and defining starting vector
  for(int i=0; i < n; i++)
  {
    n_fac = n_fac*(i+1);
    v[i] = i+1;
  }
  IntegerMatrix P(n_fac,n);
  // Filling up resulting matrix
  int j = 0;
  do{
    P(j,_) = v;
    j++;
  }while(std::next_permutation(v.begin(),v.end()));
  
  return(P);
}
