/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:06:29 by fdexheim          #+#    #+#             */
/*   Updated: 2017/10/30 16:34:26 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exceptions.h"

//------------------------------------------------------------------------------
syntaxErrorException::syntaxErrorException() { }
syntaxErrorException::syntaxErrorException(syntaxErrorException const & src) : std::exception(src) { }
syntaxErrorException::~syntaxErrorException() throw() { }
const char * syntaxErrorException::what() const throw() { return ("Exception : Syntax error"); }


//------------------------------------------------------------------------------
unknownInstructionException::unknownInstructionException() { }
unknownInstructionException::unknownInstructionException(unknownInstructionException const & src) : std::exception(src) { }
unknownInstructionException::~unknownInstructionException() throw() { }
const char * unknownInstructionException::what() const throw() { return ("Exception : Unknown instruction"); }


//------------------------------------------------------------------------------
valueOverflowException::valueOverflowException() { }
valueOverflowException::valueOverflowException(valueOverflowException const & src) : std::exception(src) { }
valueOverflowException::~valueOverflowException() throw() { }
const char * valueOverflowException::what() const throw() { return ("Exception : Value overflow"); }


//------------------------------------------------------------------------------
valueUnderflowException::valueUnderflowException() { }
valueUnderflowException::valueUnderflowException(valueUnderflowException const & src) : std::exception(src) { }
valueUnderflowException::~valueUnderflowException() throw() { }
const char * valueUnderflowException::what() const throw() { return ("Exception : Value underflow"); }


//------------------------------------------------------------------------------
popEmptyStackException::popEmptyStackException() { }
popEmptyStackException::popEmptyStackException(popEmptyStackException const & src) : std::exception(src) { }
popEmptyStackException::~popEmptyStackException() throw() { }
const char * popEmptyStackException::what() const throw() { return ("Exception : Attempt to pop on an empty stack"); }


//------------------------------------------------------------------------------
nullDenominatorException::nullDenominatorException() { }
nullDenominatorException::nullDenominatorException(nullDenominatorException const & src) : std::exception(src) { }
nullDenominatorException::~nullDenominatorException() throw() { }
const char * nullDenominatorException::what() const throw() { return ("Exception : Division or modulo with denominator = 0. You monster."); }


//------------------------------------------------------------------------------
noExitException::noExitException() { }
noExitException::noExitException(noExitException const & src) : std::exception(src) { }
noExitException::~noExitException() throw() { }
const char * noExitException::what() const throw() { return ("Exception : Missing exit command for [right] proper exit"); }


//------------------------------------------------------------------------------
assertNotTrueException::assertNotTrueException() { }
assertNotTrueException::assertNotTrueException(assertNotTrueException const & src) : std::exception(src) { }
assertNotTrueException::~assertNotTrueException() throw() { }
const char * assertNotTrueException::what() const throw() { return ("Exception : Assert is not true"); }


//------------------------------------------------------------------------------
insufficientStackException::insufficientStackException() { }
insufficientStackException::insufficientStackException(insufficientStackException const & src) : std::exception(src) { }
insufficientStackException::~insufficientStackException() throw() { }
const char * insufficientStackException::what() const throw() { return ("Exception : Attempt to execute an instruction with insufficient number of operands on the stack"); }

//------------------------------------------------------------------------------
wrongParameterException::wrongParameterException() { }
wrongParameterException::wrongParameterException(wrongParameterException const & src) : std::exception(src) { }
wrongParameterException::~wrongParameterException() throw() { }
const char * wrongParameterException::what() const throw() { return ("Exception : syntax error : associated parameter is invalid"); }

//------------------------------------------------------------------------------
missingPushParameterException::missingPushParameterException() { }
missingPushParameterException::missingPushParameterException(missingPushParameterException const & src) : std::exception(src) { }
missingPushParameterException::~missingPushParameterException() throw() { }
const char * missingPushParameterException::what() const throw() { return ("Exception : missing value for push"); }

//------------------------------------------------------------------------------
badValueTypeException::badValueTypeException() { }
badValueTypeException::badValueTypeException(badValueTypeException const & src) : std::exception(src) { }
badValueTypeException::~badValueTypeException() throw() { }
const char * badValueTypeException::what() const throw() { return ("Exception : wrong value type"); }

//------------------------------------------------------------------------------
floatPrecisionException::floatPrecisionException() { }
floatPrecisionException::floatPrecisionException(floatPrecisionException const & src) : std::exception(src) { }
floatPrecisionException::~floatPrecisionException() throw() { }
const char * floatPrecisionException::what() const throw() { return ("Exception : floating point value is 'valid' but results in a loss of precision in specified data type"); }