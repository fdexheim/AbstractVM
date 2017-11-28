/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandDouble.class.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:57:28 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 13:01:48 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDDOUBLE_CLASS_H
# define OPERANDDOUBLE_CLASS_H

#include <iostream>
#include <string>
#include <float.h>
#include <cfenv>
#include "IOperand.class.h"
#include "exceptions.h"

class OperandDouble : public virtual IOperand
{
public:
	OperandDouble(std::string str);
	OperandDouble(OperandDouble const & src);
	virtual ~OperandDouble();

	OperandDouble &					operator=(OperandDouble const & rhs);

	virtual IOperand const *		operator+(IOperand const & rhs) const; // Sum
	virtual IOperand const *		operator-(IOperand const & rhs) const; // Difference
	virtual IOperand const *		operator*(IOperand const & rhs) const; // Product
	virtual IOperand const *		operator/(IOperand const & rhs) const; // Quotient
	virtual IOperand const *		operator%(IOperand const & rhs) const; // Modulo

	virtual std::string const &		toString(void) const; // String representation of the instance
	virtual int						getPrecision(void) const; // Precision of the type of the instance
	double							get_value(void) const;
	virtual eOperandType			getType(void) const;

	static int						getOperandDoubleNumber(void);
	static void						switchOperandDoubleDebug(void);

private:
	std::string			_rawString;
	double				_value;
	static int			_nb_OperandDouble;
	static bool			_debug_OperandDouble;
};

#endif
