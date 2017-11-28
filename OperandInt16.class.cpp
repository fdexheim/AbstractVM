/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:09:24 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 08:56:41 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.h"
#include "OperandInt16.class.h"

//------------------------------------------------------------------------------
OperandInt16::OperandInt16(std::string str) : IOperand(), _rawString(str), _value(std::stoi(str))
{
	if (_debug_OperandInt16 == true)
		std::cout << "[OperandInt16 assignation constructor called]" << std::endl;
	OperandInt16::_nb_OperandInt16++;
	return;
}

//------------------------------------------------------------------------------
OperandInt16::OperandInt16(OperandInt16 const & src)
{
	if (_debug_OperandInt16 == true)
		std::cout << "[OperandInt16 copy constructor called]" << std::endl;
	OperandInt16::_nb_OperandInt16++;
	*this = src;
}

//------------------------------------------------------------------------------
OperandInt16::~OperandInt16()
{
	if (_debug_OperandInt16 == true)
		std::cout << "[OperandInt16 destructor called]" << std::endl;
	OperandInt16::_nb_OperandInt16--;
	return;
}

//------------------------------------------------------------------------------
OperandInt16 &					OperandInt16::operator=(OperandInt16 const & rhs)
{
	this->_value = rhs._value;
	this->_rawString = rhs._rawString;
	return (*this);
}

//==============================================================================
IOperand const *		OperandInt16::operator+(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) + this->_value > INT16_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) + this->_value < INT16_MIN)
		throw valueUnderflowException();

	return (fac->createOperand(Int16, std::to_string(static_cast<int16_t>(this->_value + std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt16::operator-(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) - this->_value > INT16_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) - this->_value < INT16_MIN)
		throw valueUnderflowException();
	return (fac->createOperand(Int16, std::to_string(static_cast<int16_t>(this->_value - std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt16::operator*(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) * this->_value > INT16_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) * this->_value < INT16_MIN)
		throw valueUnderflowException();
	return (fac->createOperand(Int16, std::to_string(static_cast<int16_t>(this->_value * std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt16::operator/(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	double			ret;
	double			test = std::stod(rhs.toString());

	if (test == 0)
		throw nullDenominatorException();
	ret = floor(this->_value / std::stod(rhs.toString()));
	return (fac->createOperand(Int16, std::to_string(static_cast<int16_t>(ret))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt16::operator%(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	int16_t			a = std::stoi(this->toString());
	int16_t			x = std::stoi(rhs.toString());

	if (x == 0)
		throw nullDenominatorException();
	return (fac->createOperand(Int16, std::to_string(a % x)));
}

//==============================================================================
std::string const &		OperandInt16::toString(void) const { return (this->_rawString); }
int						OperandInt16::getPrecision(void) const { return (Int16); }
eOperandType			OperandInt16::getType(void) const { return (Int16); }
int16_t					OperandInt16::get_value(void) const { return this->_value; }
void					OperandInt16::switchOperandInt16Debug() { OperandInt16::_debug_OperandInt16 = !OperandInt16::_debug_OperandInt16; }
int						OperandInt16::getOperandInt16Number(void) { return (OperandInt16::_nb_OperandInt16); }

//------------------------------------------------------------------------------
int						OperandInt16::_nb_OperandInt16 = 0;
bool					OperandInt16::_debug_OperandInt16 = false;
