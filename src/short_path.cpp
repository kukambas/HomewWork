#include <Rcpp.h>
#include <stdio.h>
using namespace Rcpp;
//' @title Find the length of shortest path.
//' @description Calculates the length of shortest path.
//'
//' @param G an 0-1 adjacency matrix which describes graph.
//' @param x a vertex number from which path should be calculated.
//' @param y a vertex number to which path should be calculated.
//' @return d Length of shortest path between two given vertices.
//'
//' @export
// [[Rcpp::export]]
int shortestpath(IntegerMatrix G, int x, int y) {
  int ncol = G.ncol();
  int nrow = G.nrow();
  if(ncol != nrow)
    Rcpp::stop("Matrix should be quadratic");
  
  if(x>ncol || y>ncol || y<0 || x<0)
    Rcpp::stop("You have put wrong indices");
  
  x--;
  y--;
  
  int flg, j=0;
  IntegerVector d(ncol); 
	IntegerVector checked(ncol);

	for (int i = 0; i < ncol; i++) {
		d[i] = ncol*ncol;
		checked[i] = 0; 
	}

	d[x] = 0;
  
	while(j < ncol){
		flg = -1;
		for (int i = 0; i < ncol; i++)
			if ((checked[i] == 0) && ((flg == -1) || (d[i] < d[flg])))
      {
        flg= i;
			}
		checked[flg] = 1;

		for (int i = 0; i < ncol; i++)
			if (G(flg,i)>0)
				if (d[flg] + G(flg,i) < d[i]) 
					d[i] = d[flg] + G(flg,i);
    j++;
	}
  
  return(d[y]);
}
