/*
 * implement fullAdderSum() fullAdderCarry()
 *
 * project: hw4
 * name: Daniel Duff
 * date: 07/01/19
 * file: adder.c
 * pseudo code:
 * notes:
 */

#include "adder.h"

/*
 * add two bits P and Q
 * return the sum bit
 */
enum bits halfAdderSum(enum bits P, enum bits Q)
{
  return P ^ Q;
}

/*
 * add two bits P and Q
 * return the carry bit
 */
enum bits halfAdderCarry(enum bits P, enum bits Q)
{
  return P & Q;
}

/*
 * add three bits P, Q, and Cin
 * return the sum bit
 */
enum bits fullAdderSum(enum bits P, enum bits Q, enum bits Cin)
{
  return P ^ Q ^ Cin;
}

/*
 * add three bits P, Q, and Cin
 * return the carry bit
 */
enum bits fullAdderCarry(enum bits P, enum bits Q, enum bits Cin)
{
  return ((P & Q) | (Q & Cin) | (P & Cin));
}
