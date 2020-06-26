/**
 * @file AddOverflowException.h
 *
 * @brief Declaration of exception to manage overflows in add operation.
 *
 * @author   Jose Pisa
 * @date     Jun 04, 2020
 * @revision 1
 */

#ifndef CHALLENGE_ADDOVERFLOWEXCEPTION_H
#define CHALLENGE_ADDOVERFLOWEXCEPTION_H

/* INCLUDES ******************************************************************/
#include <string>

/* CONSTANTS ****************************************************************/
const std::string ADD_OVERFLOW_WHAT = "Overflow in addition of numbers";

/* CLASS DECLARATION *********************************************************/
struct AddOverflowException : public std::exception {
  const char * what () const throw () {
    return ADD_OVERFLOW_WHAT.c_str();
  }
};


#endif //CHALLENGE_ADDOVERFLOWEXCEPTION_H
