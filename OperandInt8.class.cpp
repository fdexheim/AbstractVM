/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:26:24 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 08:44:47 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.h"
#include "OperandInt8.class.h"

//------------------------------------------------------------------------------
OperandInt8::OperandInt8(std::string str) : IOperand(), _rawString(str), _value(std::stoi(str))
{
	if (_debug_OperandInt8 == true)
		std::cout << "[OperandInt8 assignation constructor called]" << std::endl;
	OperandInt8::_nb_OperandInt8++;
	return;
}

//------------------------------------------------------------------------------
OperandInt8::OperandInt8(OperandInt8 const & src)
{
	if (_debug_OperandInt8 == true)
		std::cout << "[OperandInt8 copy constructor called]" << std::endl;
	OperandInt8::_nb_OperandInt8++;
	*this = src;
}

//------------------------------------------------------------------------------
OperandInt8::~OperandInt8()
{
	if (_debug_OperandInt8 == true)
		std::cout << "[OperandInt8 destructor called]" << std::endl;
	OperandInt8::_nb_OperandInt8--;
	return;
}

//------------------------------------------------------------------------------
OperandInt8 &					OperandInt8::operator=(OperandInt8 const & rhs)
{
	this->_value = rhs._value;
	this->_rawString = rhs._rawString;
	return (*this);
}

//==============================================================================
IOperand const *		OperandInt8::operator+(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) + this->_value > INT8_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) + this->_value < INT8_MIN)
		throw valueUnderflowException();

	return (fac->createOperand(Int8, std::to_string(static_cast<int8_t>(this->_value + std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt8::operator-(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) - this->_value > INT8_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) - this->_value < INT8_MIN)
		throw valueUnderflowException();
	return (fac->createOperand(Int8, std::to_string(static_cast<int8_t>(this->_value - std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt8::operator*(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) * this->_value > INT8_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) * this->_value < INT8_MIN)
		throw valueUnderflowException();
	return (fac->createOperand(Int8, std::to_string(static_cast<int8_t>(this->_value * std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt8::operator/(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	double			ret;
	double			test = std::stod(rhs.toString());

	if (test == 0)
		throw nullDenominatorException();
	ret = floor(this->_value / std::stod(rhs.toString()));
	return (fac->createOperand(Int8, std::to_string(static_cast<int8_t>(ret))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt8::operator%(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	int8_t			a = std::stoi(this->toString());
	int8_t			x = std::stoi(rhs.toString());

	if (x == 0)
		throw nullDenominatorException();
	return (fac->createOperand(Int8, std::to_string(a % x)));
}

//==============================================================================
std::string const &		OperandInt8::toString(void) const { return (this->_rawString); }
int						OperandInt8::getPrecision(void) const { return (Int8); }
eOperandType			OperandInt8::getType(void) const { return (Int8); }
int8_t					OperandInt8::get_value(void) const { return this->_value; }
void					OperandInt8::switchOperandInt8Debug() { OperandInt8::_debug_OperandInt8 = !OperandInt8::_debug_OperandInt8; }
int						OperandInt8::getOperandInt8Number(void) { return (OperandInt8::_nb_OperandInt8); }

//------------------------------------------------------------------------------
int						OperandInt8::_nb_OperandInt8 = 0;
bool					OperandInt8::_debug_OperandInt8 = false;
