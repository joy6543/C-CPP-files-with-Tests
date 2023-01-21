#ifndef SOLUTIONS_H
#define SOLUTIONS_H

/*! @file */

/*! \breif Complex object and method definitions
 *
 *  A Complex object is a struct with a numerator, denoted num, and
 *  a denominator, denoted den. Varions Methods that take Complexs and return 
 *  Complexs do arithmetical operations on them.
 */

/*
typedef struct {
    double real;
    double im;
} int;
*/
/*! Add two Complex numbers
 *  \param a The first summand
 *  \param b The second summand
 */
int running_total (a);

/*! Subtract two Complex numbers
 *  \param a The negate term 
 */
int reverse (x,a);

/*! Multiply two Complex numbers
 *  \param a The first term
 *  \param b The second term
 */
int reverse_in_place (x,a);

/*! Multiply two Complexs together (does not reduce)
 *  \param a The magnitude value
 */
int num_occurences (a,len,num);

#endif