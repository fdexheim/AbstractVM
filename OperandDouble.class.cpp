/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:56:55 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 14:03:32 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.h"
#include "OperandDouble.class.h"

//------------------------------------------------------------------------------
OperandDouble::OperandDouble(std::string str) : IOperand(), _rawString(str), _value(std::stod(str)){
	if (_debug_OperandDouble == true)
		std::cout << "[OperandDouble assignation constructor called]" << std::endl;
	OperandDouble::_nb_OperandDouble++;
	return;
}

//------------------------------------------------------------------------------
OperandDouble::OperandDouble(OperandDouble const & src)
{
	if (_debug_OperandDouble == true)
		std::cout << "[OperandDouble copy constructor called]" << std::endl;
	OperandDouble::_nb_OperandDouble++;
	*this = src;
}

//------------------------------------------------------------------------------
OperandDouble::~OperandDouble()
{
	if (_debug_OperandDouble == true)
		std::cout << "[OperandDouble destructor called]" << std::endl;
	OperandDouble::_nb_OperandDouble--;
	return;
}

//------------------------------------------------------------------------------
OperandDouble &					OperandDouble::operator=(OperandDouble const & rhs)
{
	this->_value = rhs._value;
	this->_rawString = rhs._rawString;
	return (*this);
}

//==============================================================================
IOperand const *		OperandDouble::operator+(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	double				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = std::stod(rhs.toString()) + this->_value;
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();

	return (fac->createOperand(Double, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandDouble::operator-(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	double				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = this->_value - std::stod(rhs.toString());
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();
	return (fac->createOperand(Double, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandDouble::operator*(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	double				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = std::stod(rhs.toString()) * this->_value;
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();

	return (fac->createOperand(Double, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandDouble::operator/(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();
	int					raisedEx;
	double				tmp;

	feclearexcept(FE_ALL_EXCEPT);
	tmp = this->_value / std::stod(rhs.toString());
	raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);

	if (raisedEx & FE_OVERFLOW)
		throw valueOverflowException();
	if (raisedEx & FE_UNDERFLOW)
		throw valueUnderflowException();

	return (fac->createOperand(Double, std::to_string(tmp)));
}

//------------------------------------------------------------------------------
IOperand const *		OperandDouble::operator%(IOperand const & rhs) const // this function should never be called in the first place
{
	double			x = std::stod(rhs.toString());

	throw badValueTypeException();
	if (x == 0)
		throw nullDenominatorException();
	return (NULL);
}

//==============================================================================
std::string const &		OperandDouble::toString(void) const { return (this->_rawString); }
int						OperandDouble::getPrecision(void) const { return (Double); } // why do we need this function when getType offers the same utility ?
eOperandType			OperandDouble::getType(void) const { return (Double); }
double					OperandDouble::get_value(void) const { return this->_value; }
void					OperandDouble::switchOperandDoubleDebug() { OperandDouble::_debug_OperandDouble = !OperandDouble::_debug_OperandDouble; }
int						OperandDouble::getOperandDoubleNumber(void) { return (OperandDouble::_nb_OperandDouble); }

//------------------------------------------------------------------------------
int						OperandDouble::_nb_OperandDouble = 0;
bool					OperandDouble::_debug_OperandDouble = false;
