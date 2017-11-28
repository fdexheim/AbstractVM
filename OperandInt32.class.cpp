/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt32.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:10:17 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/10 09:10:20 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.h"
#include "OperandInt32.class.h"

//------------------------------------------------------------------------------
OperandInt32::OperandInt32(std::string str) : IOperand(), _rawString(str), _value(std::stoi(str))
{
	if (_debug_OperandInt32 == true)
		std::cout << "[OperandInt32 assignation constructor called]" << std::endl;
	OperandInt32::_nb_OperandInt32++;
	return;
}

//------------------------------------------------------------------------------
OperandInt32::OperandInt32(OperandInt32 const & src)
{
	if (_debug_OperandInt32 == true)
		std::cout << "[OperandInt32 copy constructor called]" << std::endl;
	OperandInt32::_nb_OperandInt32++;
	*this = src;
}

//------------------------------------------------------------------------------
OperandInt32::~OperandInt32()
{
	if (_debug_OperandInt32 == true)
		std::cout << "[OperandInt32 destructor called]" << std::endl;
	OperandInt32::_nb_OperandInt32--;
	return;
}

//------------------------------------------------------------------------------
OperandInt32 &					OperandInt32::operator=(OperandInt32 const & rhs)
{
	this->_value = rhs._value;
	this->_rawString = rhs._rawString;
	return (*this);
}

//==============================================================================
IOperand const *		OperandInt32::operator+(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) + this->_value > INT32_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) + this->_value < INT32_MIN)
		throw valueUnderflowException();

	return (fac->createOperand(Int32, std::to_string(static_cast<int32_t>(this->_value + std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt32::operator-(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) - this->_value > INT32_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) - this->_value < INT32_MIN)
		throw valueUnderflowException();
	return (fac->createOperand(Int32, std::to_string(static_cast<int32_t>(this->_value - std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt32::operator*(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	if (std::stod(rhs.toString()) * this->_value > INT32_MAX)
		throw valueOverflowException();
	if (std::stod(rhs.toString()) * this->_value < INT32_MIN)
		throw valueUnderflowException();
	return (fac->createOperand(Int32, std::to_string(static_cast<int32_t>(this->_value * std::stod(rhs.toString())))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt32::operator/(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	double			ret;
	double			test = std::stod(rhs.toString());

	if (test == 0)
		throw nullDenominatorException();
	ret = floor(this->_value / std::stod(rhs.toString()));
	return (fac->createOperand(Int32, std::to_string(static_cast<int32_t>(ret))));
}

//------------------------------------------------------------------------------
IOperand const *		OperandInt32::operator%(IOperand const & rhs) const
{
	OperandFactory*		fac = OperandFactory::getInstance();

	int32_t			a = std::stoi(this->toString());
	int32_t			x = std::stoi(rhs.toString());

	if (x == 0)
		throw nullDenominatorException();
	return (fac->createOperand(Int32, std::to_string(a % x)));
}

//==============================================================================
std::string const &		OperandInt32::toString(void) const { return (this->_rawString); }
int						OperandInt32::getPrecision(void) const { return (Int32); }
eOperandType			OperandInt32::getType(void) const { return (Int32); }
int32_t					OperandInt32::get_value(void) const { return this->_value; }
void					OperandInt32::switchOperandInt32Debug() { OperandInt32::_debug_OperandInt32 = !OperandInt32::_debug_OperandInt32; }
int						OperandInt32::getOperandInt32Number(void) { return (OperandInt32::_nb_OperandInt32); }

//------------------------------------------------------------------------------
int						OperandInt32::_nb_OperandInt32 = 0;
bool					OperandInt32::_debug_OperandInt32 = false;
