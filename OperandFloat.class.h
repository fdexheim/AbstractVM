/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFloat.class.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 08:50:44 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 13:01:57 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFLOAT_CLASS_H
# define OPERANDFLOAT_CLASS_H

#include <iostream>
#include <string>
#include <float.h>
#include <cfenv>
#include "IOperand.class.h"
#include "exceptions.h"

class OperandFloat : public virtual IOperand
{
public:
	OperandFloat(std::string str);
	OperandFloat(OperandFloat const & src);
	virtual ~OperandFloat();

	OperandFloat &					operator=(OperandFloat const & rhs);

	virtual IOperand const *		operator+(IOperand const & rhs) const; // Sum
	virtual IOperand const *		operator-(IOperand const & rhs) const; // Difference
	virtual IOperand const *		operator*(IOperand const & rhs) const; // Product
	virtual IOperand const *		operator/(IOperand const & rhs) const; // Quotient
	virtual IOperand const *		operator%(IOperand const & rhs) const; // Modulo

	virtual std::string const &		toString(void) const; // String representation of the instance
	virtual int						getPrecision(void) const; // Precision of the type of the instance
	float							get_value(void) const;
	virtual eOperandType			getType(void) const;

	static int						getOperandFloatNumber(void);
	static void						switchOperandFloatDebug(void);

private:
	std::string			_rawString;
	double				_value;
	static int			_nb_OperandFloat;
	static bool			_debug_OperandFloat;
};

#endif
