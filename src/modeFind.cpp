#include <Rcpp.h>
using namespace Rcpp;

//' @title Mode Function
//' @description Finds mode of given numeric vector.
//'
//' @param z - a numeric vector.
//' @return Mode - the most frequent number.
//'
//' @export 
// [[Rcpp::export]]
double mode(NumericVector z)
{
  if(z.size() < 1){
    Rcpp::stop("Numeric vector does not have any elements");
  }else if(z.size() == 1){
   double mode = z[0];
    return(mode);
  }
  
  NumericVector x = clone(z);
  std::sort(x.begin(), x.end());
  int cnt = 2;
  int cnt_max = 0;
  double mode = x[1];
  
  for(int i=2; i < x.size(); i++){
    if((x[i] == x[i-1]) & (i < (x.size()-1))){
      cnt++;        
    }else{
      if(cnt_max < cnt){
        mode = x[i-1];
        cnt_max = cnt;
      }
      if(cnt_max > (x.size()-i))
        break; 
      
      cnt = 1;
    }
  }
  return mode;
}





