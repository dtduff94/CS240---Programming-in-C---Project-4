/*
 * driver for testing the full adder and myAdd()
 *
 * project: hw4
 * name: Daniel Duff
 * date: 07/01/19
 * file: main.c
 * pseudo code: Produces a half adder table and full adder table based on the methods in adder.c.  The last set of for loops should yield most combinations of p and q where their sums are less than 256. I think the (p = 0; p < 256; p++) loop stops iterating at 127 because if it equals 128, then the second loop has nothing to iterate through based on the q = p, and q < 256 - p criteria.  If the myAdd function correctly adds p and q then the combination is printed, otherwise a myAdd() fails messege will be outputted and the program will be exited. 
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include "adder.h"

/*
 * This is the driver for testing your implementation
 * Do not modify the code below
 */
int main(void)
{
  enum bits P, Q, Cin;
  unsigned int p, q;

  for (P = ZERO; P <= ONE; P++)
    for (Q = ZERO; Q <= ONE; Q++)
      printf("P %1u Q %1u C %1u S %1u\n",
	     P, Q, halfAdderCarry(P, Q), halfAdderSum(P, Q));

  for (P = ZERO; P <= ONE; P++)
    for (Q = ZERO; Q <= ONE; Q++)
      for (Cin = ZERO; Cin <= ONE; Cin++)
	printf("P %1u Q %1u Cin %1u Cout %1u S %1u\n",
	       P, Q, Cin, fullAdderCarry(P, Q, Cin), fullAdderSum(P, Q, Cin));

  for (p = 0; p < 256; p++)
    for (q = p; q < 256 - p; q++) {
      printf("p %u q %u\n", p, q);
      if (p + q != myAdd(p, q)) {
	fprintf(stderr, "myAdd() fails when adding %u and %u\n", p, q);
	exit(1);
      }
    }

  return 0;
}
