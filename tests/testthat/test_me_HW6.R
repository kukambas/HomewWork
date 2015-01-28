library(testthat)

## test for mode function
expect_error(mode('a'))
expect_error(mode(numeric(0)))
expect_equivalent(mode(2),2)
expect_equivalent(mode(c(1,1,1,1,1,2,2,2,2,2,3)),1)
expect_equivalent(mode(c(1.2,1.2,3,3,-1,1,7,1.2,3,3)),3)

## test for perm function
expect_error(perms('a'))
expect_error(perms(-1))
expect_error(perms(1.5))

## test for shortestpath function
G <- matrix(c(0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0),6,6)
expect_equivalent(shortestpath(G,1,2),3)
expect_equivalent(shortestpath(G,1,1),0)
expect_error(shortestpath(G,0,2))
expect_error(shortestpath(G,1,0))
expect_error(shortestpath(G,1,7))
expect_error(shortestpath(G,7,2))
G <- matrix(1,3,5)
expect_error(shortestpath(G,1,2))




