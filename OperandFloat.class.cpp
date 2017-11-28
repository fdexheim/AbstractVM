/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:10:17 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 14:20:44 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.h"
#include "OperandFloat.class.h"

//------------------------------------------------------------------------------
OperandFloat::OperandFloat(std::string str) : IOperand(), _rawString(str), _value(std::stof(str))
{
	if (_debug_OperandFloat == true)
		std::cout << "[OperandFloat assignation constructor called]" << std::endl;
	OperandFloat::_nb_OperandFloat++;
	return;
}

//------------------------------------------------------------------------------
OperandFloat::OperandFloat(OperandFloat const & src)
{
	if (_debug_OperandFloat == true)
		std::cout << "[OperandFloat copy constructor called]" << std::endl;
	OperandFloat::_nb_OperandFloat++;
	*this = src;
}

//------------------------------------------------------------------------------
OperandFloat::~OperandFloat()
{
	if (_debug_OperandFloat == true)
		std::cout << "[OperandFloat destructor called]" << std::endl;
	OperandFloat::_nb_OperandFloat--;
	return;
}

//------------------------------------------------------------------------------
OperandFloat &					OperandFloat::operator=(OperandFloat const & rhs)
{
	this->_value = rhs._value;
	this->_rawString = rhs._rawString;
	return (*this);
}

//==============================================================================
IOperand const *		OperandFloat::operator+(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	float				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = std::stof(rhs.toString()) + this->_value;
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();

	return (fac->createOperand(Float, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandFloat::operator-(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	float				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = this->_value - std::stof(rhs.toString());
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();
	return (fac->createOperand(Float, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandFloat::operator*(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	float				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = std::stof(rhs.toString()) * this->_value;
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();

	return (fac->createOperand(Float, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandFloat::operator/(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	float				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = this->_value / std::stof(rhs.toString());
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();

	return (fac->createOperand(Float, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandFloat::operator%(IOperand const & rhs) const
{
	float			x = std::stof(rhs.toString());

	throw badValueTypeException();
	if (x == 0)
		throw nullDenominatorException();
	return (NULL);
}

//==============================================================================
std::string const &		OperandFloat::toString(void) const { return (this->_rawString); }
int						OperandFloat::getPrecision(void) const { return (Float); }
eOperandType			OperandFloat::getType(void) const { return (Float); }
float					OperandFloat::get_value(void) const { return this->_value; }
void					OperandFloat::switchOperandFloatDebug() { OperandFloat::_debug_OperandFloat = !OperandFloat::_debug_OperandFloat; }
int						OperandFloat::getOperandFloatNumber(void) { return (OperandFloat::_nb_OperandFloat); }

//------------------------------------------------------------------------------
int						OperandFloat::_nb_OperandFloat = 0;
bool					OperandFloat::_debug_OperandFloat = false;
