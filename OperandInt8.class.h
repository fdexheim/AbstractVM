/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt8.class.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 13:08:21 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/08 14:21:35 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDINT8_CLASS_H
# define OPERANDINT8_CLASS_H

#include <iostream>
#include <string>
#include "IOperand.class.h"
#include "exceptions.h"

class OperandInt8 : public virtual IOperand
{
public:
	OperandInt8(std::string str);
	OperandInt8(OperandInt8 const & src);
	virtual ~OperandInt8();

	OperandInt8 &					operator=(OperandInt8 const & rhs);

	virtual IOperand const *		operator+(IOperand const & rhs) const; // Sum
	virtual IOperand const *		operator-(IOperand const & rhs) const; // Difference
	virtual IOperand const *		operator*(IOperand const & rhs) const; // Product
	virtual IOperand const *		operator/(IOperand const & rhs) const; // Quotient
	virtual IOperand const *		operator%(IOperand const & rhs) const; // Modulo

	virtual std::string const &		toString(void) const; // String representation of the instance
	virtual int						getPrecision(void) const; // Precision of the type of the instance
	int8_t							get_value(void) const;
	virtual eOperandType			getType(void) const;

	static int						getOperandInt8Number(void);
	static void						switchOperandInt8Debug(void);

private:
	std::string			_rawString;
	double				_value;
	static int			_nb_OperandInt8;
	static bool			_debug_OperandInt8;
};

#endif
