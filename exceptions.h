/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:32:42 by fdexheim          #+#    #+#             */
/*   Updated: 2017/10/30 14:52:55 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_H
# define EXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
class syntaxErrorException : public virtual std::exception
{
public:
	syntaxErrorException();
	syntaxErrorException(syntaxErrorException const & src);
	virtual ~syntaxErrorException() throw();
	virtual const char * what() const throw();
private:
	syntaxErrorException & operator=(syntaxErrorException const & rhs);
};


//------------------------------------------------------------------------------
class unknownInstructionException : public virtual std::exception
{
public:
	unknownInstructionException();
	unknownInstructionException(unknownInstructionException const & src);
	virtual ~unknownInstructionException() throw();
	virtual const char * what() const throw();
private:
	unknownInstructionException & operator=(unknownInstructionException const & rhs);
};


//------------------------------------------------------------------------------
class valueOverflowException : public virtual std::exception
{
public:
	valueOverflowException();
	valueOverflowException(valueOverflowException const & src);
	virtual ~valueOverflowException() throw();
	virtual const char * what() const throw();
private:
	valueOverflowException & operator=(valueOverflowException const & rhs);
};


//------------------------------------------------------------------------------
class valueUnderflowException : public virtual std::exception
{
public:
	valueUnderflowException();
	valueUnderflowException(valueUnderflowException const & src);
	virtual ~valueUnderflowException() throw();
	virtual const char * what() const throw();
private:
	valueUnderflowException & operator=(valueUnderflowException const & rhs);
};


//------------------------------------------------------------------------------
class popEmptyStackException : public virtual std::exception
{
public:
	popEmptyStackException();
	popEmptyStackException(popEmptyStackException const & src);
	virtual ~popEmptyStackException() throw();
	virtual const char * what() const throw();
private:
	popEmptyStackException & operator=(popEmptyStackException const & rhs);
};


//------------------------------------------------------------------------------
class nullDenominatorException : public virtual std::exception
{
public:
	nullDenominatorException();
	nullDenominatorException(nullDenominatorException const & src);
	virtual ~nullDenominatorException() throw();
	virtual const char * what() const throw();
private:
	nullDenominatorException & operator=(nullDenominatorException const & rhs);
};


//------------------------------------------------------------------------------
class noExitException : public virtual std::exception
{
public:
	noExitException();
	noExitException(noExitException const & src);
	virtual ~noExitException() throw();
	virtual const char * what() const throw();
private:
	noExitException & operator=(noExitException const & rhs);
};


//------------------------------------------------------------------------------
class assertNotTrueException : public virtual std::exception
{
public:
	assertNotTrueException();
	assertNotTrueException(assertNotTrueException const & src);
	virtual ~assertNotTrueException() throw();
	virtual const char * what() const throw();
private:
	assertNotTrueException & operator=(assertNotTrueException const & rhs);
};


//------------------------------------------------------------------------------
class insufficientStackException : public virtual std::exception
{
public:
	insufficientStackException();
	insufficientStackException(insufficientStackException const & src);
	virtual ~insufficientStackException() throw();
	virtual const char * what() const throw();
private:
	insufficientStackException & operator=(insufficientStackException const & rhs);
};

//------------------------------------------------------------------------------
class wrongParameterException : public virtual std::exception
{
public:
	wrongParameterException();
	wrongParameterException(wrongParameterException const & src);
	virtual ~wrongParameterException() throw();
	virtual const char * what() const throw();
private:
	wrongParameterException & operator=(wrongParameterException const & rhs);
};

//------------------------------------------------------------------------------
class missingPushParameterException : public virtual std::exception
{
public:
	missingPushParameterException();
	missingPushParameterException(missingPushParameterException const & src);
	virtual ~missingPushParameterException() throw();
	virtual const char * what() const throw();
private:
	missingPushParameterException & operator=(missingPushParameterException const & rhs);
};

//------------------------------------------------------------------------------
class badValueTypeException : public virtual std::exception
{
public:
	badValueTypeException();
	badValueTypeException(badValueTypeException const & src);
	virtual ~badValueTypeException() throw();
	virtual const char * what() const throw();
private:
	badValueTypeException & operator=(badValueTypeException const & rhs);
};

//------------------------------------------------------------------------------
class floatPrecisionException : public virtual std::exception
{
public:
	floatPrecisionException();
	floatPrecisionException(floatPrecisionException const & src);
	virtual ~floatPrecisionException() throw();
	virtual const char * what() const throw();
private:
	floatPrecisionException & operator=(floatPrecisionException const & rhs);
};

#endif
