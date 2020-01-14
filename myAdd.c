/*
 * implement of myAdd() using fullAdderSum() and fullAdderCarry()
 *
 * project: hw4
 * name: Daniel Duff
 * date: 07/01/19
 * file: myAdd.c
 * pseudo code:
 * notes:
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "adder.h"

/*
 * use fullAdderSum() and fullAdderCarry() to add two numbers bit by bit
 * p and q are nonnegative
 * assume their sum does not cause overflow of a 32-bit unsigned int
 */
unsigned int myAdd(unsigned int p, unsigned int q)
{
  unsigned int mySum;
  mySum = 0;
  int Cin = 0;
  int parray[31], qarray[31], sumarray[31];
  for (int i = 0; i <= 31; i++) {
    parray[i] = p % 2;
    qarray[i] = q % 2;
    p /= 2;
    q /= 2;
    
    sumarray[i] = fullAdderSum(parray[i], qarray[i], Cin);
    Cin = fullAdderCarry(parray[i], qarray[i], Cin);
    mySum = mySum + (pow(2, i) * sumarray[i]);
  }
  /*
   * loop 32 times
   * add a pair of bits from p and q, and the previous carry bit
   * record the sum bit in the corresponding bit in mySum
   * the first carry bit is zero
   * the last carry bit is discarded, assuming no overflow
   */
  return mySum;
}
