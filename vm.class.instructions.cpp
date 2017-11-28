/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.class.instructions.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:45:46 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/20 14:35:19 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.class.h"

//------------------------------------------------------------------------------
void						vm::vmPush(std::string str)
{
	if (str.find("int8(") == 0 && str.size() > 6 && str.find(")") != std::string::npos)
	{
		this->operands.insert(this->operands.begin(), this->facto->createOperand(Int8, str.substr(5, str.find(")") - 5)));
		return ;
	}
	if (str.find("int16(") == 0 && str.size() > 7 && str.find(")") != std::string::npos)
	{
		this->operands.insert(this->operands.begin(), this->facto->createOperand(Int16, str.substr(6, str.find(")") - 6)));
		return ;
	}
	if (str.find("int32(") == 0 && str.size() > 7 && str.find(")") != std::string::npos)
	{
		this->operands.insert(this->operands.begin(), this->facto->createOperand(Int32, str.substr(6, str.find(")") - 6)));
		return ;
	}
	if (str.find("float(") == 0 && str.size() > 7 && str.find(")") != std::string::npos)
	{
		this->operands.insert(this->operands.begin(), this->facto->createOperand(Float, str.substr(6, str.find(")") - 6)));
		return ;
	}
	if (str.find("double(") == 0 && str.size() > 8 && str.find(")") != std::string::npos)
	{
		this->operands.insert(this->operands.begin(), this->facto->createOperand(Double, str.substr(7, str.find(")") - 7)));
		return ;
	}
	throw wrongParameterException();
}

//------------------------------------------------------------------------------
void					vm::vmPop(void)
{
	if (this->operands.size() < 1)
		throw popEmptyStackException();
	this->popFirstOperand();
}

//------------------------------------------------------------------------------
void					vm::vmDump(void)
{
	for (unsigned int i = 0; i < this->operands.size(); i++)
	{
		std::cout << this->operands[i]->toString() << std::endl;
	}
}

//------------------------------------------------------------------------------
void					vm::vmAssert(std::string str)
{
	if (this->operands.size() < 1)
		throw insufficientStackException();

	std::string			sub;
	IOperand const		*ref;
	IOperand const		*cmp = this->getFirstOperand();

	if (this->operands.size() < 1)
		throw insufficientStackException();

	if (str.find("int8(") == 0 && str.size() > 6 && str.find(")") != std::string::npos)
	{
		ref = this->facto->createOperand(Int8, str.substr(5, str.find(")") - 5));
		if (std::stod(ref->toString()) != std::stod(cmp->toString()))
		{
			delete ref;
			throw assertNotTrueException();
		}
		delete ref;
		return;
	}
	else if (str.find("int16(") == 0 && str.size() > 7 && str.find(")") != std::string::npos)
	{
		ref = this->facto->createOperand(Int16, str.substr(6, str.find(")") - 6));
		if (std::stod(ref->toString()) != std::stod(cmp->toString()))
		{
			delete ref;
			throw assertNotTrueException();
		}
		delete ref;
		return;
	}
	else if (str.find("int32(") == 0 && str.size() > 7 && str.find(")") != std::string::npos)
	{
		ref = this->facto->createOperand(Int32, str.substr(6, str.find(")") - 6));
		if (std::stod(ref->toString()) != std::stod(cmp->toString()))
		{
			delete ref;
			throw assertNotTrueException();
		}
		delete ref;
		return;
	}
	else if (str.find("float(") == 0 && str.size() > 7 && str.find(")") != std::string::npos)
	{
		ref = this->facto->createOperand(Float, str.substr(6, str.find(")") - 6));
		if (std::stod(ref->toString()) != std::stod(cmp->toString()))
		{
			delete ref;
			throw assertNotTrueException();
		}
		delete ref;
		return;
	}
	else if (str.find("double(") == 0 && str.size() > 8 && str.find(")") != std::string::npos)
	{
		ref = this->facto->createOperand(Double, str.substr(7, str.find(")") - 7));
		if (std::stod(ref->toString()) != std::stod(cmp->toString()))
		{
			delete ref;
			throw assertNotTrueException();
		}
		delete ref;
		return;
	}
	else
		throw wrongParameterException();
}

//------------------------------------------------------------------------------
void					vm::vmAdd(void)
{
	IOperand const *	ope1;
	IOperand const *	ope2;
	IOperand const *	add = NULL;

	if (this->operands.size() < 2)
		throw insufficientStackException();

	ope1 = this->getFirstOperand();
	this->popFirstOperand();
	ope2 = this->getFirstOperand();
	this->popFirstOperand();

	try
	{
		if (ope1->getPrecision() >= ope2->getPrecision())
		{
			add = *ope1 + *ope2;
			this->operands.insert(this->operands.begin(), add);
		}
		else
		{
			add = *ope2 + *ope1;
			this->operands.insert(this->operands.begin(), add);
		}
	}
	catch (valueOverflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		throw (e);
	}
	catch (valueUnderflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		throw (e);
	}
	delete ope1;
	delete ope2;
}

//------------------------------------------------------------------------------
void					vm::vmSub(void)
{
	IOperand const *	ope1;
	IOperand const *	ope2;
	IOperand const *	casted = NULL;
	IOperand const *	sub = NULL;

	if (this->operands.size() < 2)
		throw insufficientStackException();

	ope2 = this->getFirstOperand();
	this->popFirstOperand();
	ope1 = this->getFirstOperand();
	this->popFirstOperand();

	try
	{
		if (ope1->getPrecision() >= ope2->getPrecision())
		{
			sub = *ope1 - *ope2;
			this->operands.insert(this->operands.begin(), sub);
		}
		else
		{
			casted = this->facto->createOperand(ope2->getType(), ope1->toString());
			sub = *casted - *ope2;
			this->operands.insert(this->operands.begin(), sub);
			delete casted;
		}
	}
	catch (valueOverflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		if (casted != NULL)
			delete casted;
		throw (e);
	}
	catch (valueUnderflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		if (casted != NULL)
			delete casted;
		throw (e);
	}
	delete ope1;
	delete ope2;
}

//------------------------------------------------------------------------------
void					vm::vmMul(void)
{
	IOperand const *	ope1;
	IOperand const *	ope2;
	IOperand const *	mul = NULL;

	if (this->operands.size() < 2)
		throw insufficientStackException();

	ope1 = this->getFirstOperand();
	this->popFirstOperand();
	ope2 = this->getFirstOperand();
	this->popFirstOperand();

	try
	{
		if (ope1->getPrecision() >= ope2->getPrecision())
		{
			mul = *ope1 * *ope2;
			this->operands.insert(this->operands.begin(), mul);
		}
		else
		{
			mul = *ope2 * *ope1;
			this->operands.insert(this->operands.begin(), mul);
		}
	}
	catch (valueOverflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		throw (e);
	}
	catch (valueUnderflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		throw (e);
	}
	delete ope1;
	delete ope2;
}

//------------------------------------------------------------------------------
void					vm::vmDiv(void)
{
	IOperand const *	ope1;
	IOperand const *	ope2;
	IOperand const *	casted = NULL;
	IOperand const *	div = NULL;

	if (this->operands.size() < 2)
		throw insufficientStackException();

	ope2 = this->getFirstOperand();
	this->popFirstOperand();
	ope1 = this->getFirstOperand();
	this->popFirstOperand();

	try
	{
		if (ope1->getPrecision() >= ope2->getPrecision())
		{
			div = *ope1 / *ope2;
			this->operands.insert(this->operands.begin(), div);
		}
		else
		{
			casted = this->facto->createOperand(ope2->getType(), ope1->toString());
			div = *casted / *ope2;
			this->operands.insert(this->operands.begin(), div);
			delete casted;
		}
	}
	catch (valueOverflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		if (casted != NULL)
			delete casted;
		throw (e);
	}
	catch (valueUnderflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		if (casted != NULL)
			delete casted;
		throw (e);
	}
	delete ope1;
	delete ope2;
}

//------------------------------------------------------------------------------
void					vm::vmMod(void)
{
	IOperand const *	ope1;
	IOperand const *	ope2;
	IOperand const *	casted = NULL;

	if (this->operands.size() < 2)
		throw insufficientStackException();

	ope2 = this->getFirstOperand();
	this->popFirstOperand();
	ope1 = this->getFirstOperand();
	this->popFirstOperand();

	try
	{
		if (ope2->getPrecision() >= Float || ope1->getPrecision() >= Float)
		{
			this->operands.insert(this->operands.begin(), ope2);
			this->operands.insert(this->operands.begin(), ope1);
			throw badValueTypeException();
		}
		if (ope1->getPrecision() >= ope2->getPrecision())
		{
			IOperand const *		add = *ope1 % *ope2;
			this->operands.insert(this->operands.begin(), add);
		}
		else
		{
			casted = this->facto->createOperand(ope2->getType(), ope1->toString());
			IOperand const *		add = *casted % *ope2;
			this->operands.insert(this->operands.begin(), add);
			delete casted;
		}
	}
	catch (valueOverflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		if (casted != NULL)
			delete casted;
		throw (e);
	}
	catch (valueUnderflowException & e)
	{
		this->operands.insert(this->operands.begin(), ope2);
		this->operands.insert(this->operands.begin(), ope1);
		if (casted != NULL)
			delete casted;
		throw (e);
	}
	delete ope1;
	delete ope2;
}

//------------------------------------------------------------------------------
void					vm::vmPrint(void)
{
	if (this->operands.size() < 1)
		throw insufficientStackException();

	IOperand const *	cmp = this->getFirstOperand();
	int8_t				value;

	if (cmp->getPrecision() == Int8)
	{
		value = std::stoi(cmp->toString());
		std::cout << value;
	}
	else
		throw assertNotTrueException();
}

//------------------------------------------------------------------------------
void					vm::vmExit(void)
{
	std::cout << std::endl << "Exit command recived. Goodbye :( " << std::endl;
}
