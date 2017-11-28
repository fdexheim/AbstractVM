/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.class.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:07:47 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 15:02:42 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OperandFactory.class.h"
#include "OperandInt8.class.h"
#include "OperandInt16.class.h"
#include "OperandInt32.class.h"
#include "OperandFloat.class.h"
#include "OperandDouble.class.h"

//------------------------------------------------------------------------------
OperandFactory::OperandFactory()
{
	if (_debug_OperandFactory == true)
		std::cout << "[OperandFactory default constructor called]" << std::endl;
	OperandFactory::_nb_OperandFactory++;

	factoMap[Int8] = &OperandFactory::createInt8;
	factoMap[Int16] = &OperandFactory::createInt16;
	factoMap[Int32] = &OperandFactory::createInt32;
	factoMap[Float] = &OperandFactory::createFloat;
	factoMap[Double] = &OperandFactory::createDouble;

	this->_inst = this;

	return;
}

//------------------------------------------------------------------------------
OperandFactory::~OperandFactory()
{
	if (_debug_OperandFactory == true)
		std::cout << "[OperandFactory destructor called]" << std::endl;
	OperandFactory::_nb_OperandFactory--;
	return;
}

//==============================================================================
IOperand const *			OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	return (this->*factoMap[type])(value);
}

//------------------------------------------------------------------------------
IOperand const *			OperandFactory::createInt8(std::string const & value) const
{
	double					vaal;
	int 					raisedEx;

	std::feclearexcept(FE_ALL_EXCEPT);
	try
	{
		vaal = std::stod(value);
	}
	catch (std::out_of_range & e)
	{
		raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);
		if (raisedEx & FE_OVERFLOW)
			throw valueOverflowException();
		if (raisedEx & FE_UNDERFLOW)
			throw valueUnderflowException();
	}
	catch (std::invalid_argument & e)
	{
		throw wrongParameterException();
	}
	if (vaal - static_cast<int>(vaal) != 0 && vaal >= INT8_MIN && vaal <= INT8_MAX)
		throw wrongParameterException();
	if (vaal > INT8_MAX)
		throw valueOverflowException();
	if (vaal < INT8_MIN)
		throw valueUnderflowException();

	IOperand*				ptr = new OperandInt8(std::to_string(static_cast<int>(vaal)));
	return ptr;
}

//------------------------------------------------------------------------------
IOperand const *			OperandFactory::createInt16(std::string const & value) const
{
	double					vaal;
	int						raisedEx;

	std::feclearexcept(FE_ALL_EXCEPT);
	try
	{
		vaal = std::stod(value);
	}
	catch (std::out_of_range & e)
	{
		raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);
		if (raisedEx & FE_OVERFLOW)
			throw valueOverflowException();
		if (raisedEx & FE_UNDERFLOW)
			throw valueUnderflowException();
	}
	catch (std::invalid_argument & e)
	{
		throw wrongParameterException();
	}
	if (vaal - static_cast<int>(vaal) != 0 && vaal >= INT16_MIN && vaal <= INT16_MAX)
		throw wrongParameterException();
	if (vaal > INT16_MAX)
		throw valueOverflowException();
	if (vaal < INT16_MIN)
		throw valueUnderflowException();

	IOperand*				ptr = new OperandInt16(std::to_string(static_cast<int>(vaal)));
	return ptr;
}

//------------------------------------------------------------------------------
IOperand const *			OperandFactory::createInt32(std::string const & value) const
{
	double					vaal;
	int 					raisedEx;

	std::feclearexcept(FE_ALL_EXCEPT);
	try
	{
		vaal = std::stod(value);
	}
	catch (std::out_of_range & e)
	{
		raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);
		if (raisedEx & FE_OVERFLOW)
			throw valueOverflowException();
		if (raisedEx & FE_UNDERFLOW)
			throw valueUnderflowException();
	}
	catch (std::invalid_argument & e)
	{
		throw wrongParameterException();
	}
	if (vaal - static_cast<int>(vaal) != 0 && vaal >= INT32_MIN && vaal <= INT32_MAX)
		throw wrongParameterException();
	if (vaal > INT32_MAX)
		throw valueOverflowException();
	if (vaal < INT32_MIN)
		throw valueUnderflowException();

	IOperand*				ptr = new OperandInt32(std::to_string(static_cast<int>(vaal)));
	return ptr;
}

//------------------------------------------------------------------------------
IOperand const *			OperandFactory::createFloat(std::string const & value) const
{
	double					vaal;
	int 					raisedEx;

	std::feclearexcept(FE_ALL_EXCEPT);
	try
	{
		vaal = std::stod(value);
	}
	catch (std::out_of_range & e)
	{
		raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);
		if (raisedEx & FE_OVERFLOW)
			throw valueOverflowException();
		if (raisedEx & FE_UNDERFLOW)
			throw valueUnderflowException();
	}
	catch (std::invalid_argument & e)
	{
		throw wrongParameterException();
	}
	if (vaal > FLT_MAX)
		throw valueOverflowException();
	if ((vaal < -FLT_MAX) || (vaal < FLT_MIN && vaal > 0) || (vaal > -FLT_MIN && vaal < 0))
		throw valueUnderflowException();

	IOperand*				ptr = new OperandFloat(value);
	return ptr;
}

//------------------------------------------------------------------------------
IOperand const *			OperandFactory::createDouble(std::string const & value) const
{
	double					vaal;
	int 					raisedEx;

	std::feclearexcept(FE_ALL_EXCEPT);
	try
	{
		vaal = std::stod(value);
	}
	catch (std::out_of_range & e)
	{
		raisedEx = fetestexcept(FE_OVERFLOW | FE_UNDERFLOW);
		if (raisedEx & FE_OVERFLOW)
			throw valueOverflowException();
		if (raisedEx & FE_UNDERFLOW)
			throw valueUnderflowException();
	}
	catch (std::invalid_argument & e)
	{
		throw wrongParameterException();
	}

	IOperand*				ptr = new OperandDouble(value);
	return ptr;
}

//==============================================================================
OperandFactory*			OperandFactory::_inst = NULL;
int						OperandFactory::_nb_OperandFactory = 0;
bool					OperandFactory::_debug_OperandFactory = false;

//------------------------------------------------------------------------------
void					OperandFactory::switchOperandFactoryDebug() { OperandFactory::_debug_OperandFactory = !OperandFactory::_debug_OperandFactory; }
int						OperandFactory::getOperandFactoryNumber(void) { return (OperandFactory::_nb_OperandFactory); }
OperandFactory *		OperandFactory::getInstance(void) { return _inst; }
