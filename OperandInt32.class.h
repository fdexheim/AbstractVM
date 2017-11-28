/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt32.class.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:10:00 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/10 09:10:06 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDINT32_CLASS_H
# define OPERANDINT32_CLASS_H

#include <iostream>
#include <string>
#include "IOperand.class.h"
#include "exceptions.h"

class OperandInt32 : public virtual IOperand
{
public:
	OperandInt32(std::string str);
	OperandInt32(OperandInt32 const & src);
	virtual ~OperandInt32();

	OperandInt32 &					operator=(OperandInt32 const & rhs);

	virtual IOperand const *		operator+(IOperand const & rhs) const; // Sum
	virtual IOperand const *		operator-(IOperand const & rhs) const; // Difference
	virtual IOperand const *		operator*(IOperand const & rhs) const; // Product
	virtual IOperand const *		operator/(IOperand const & rhs) const; // Quotient
	virtual IOperand const *		operator%(IOperand const & rhs) const; // Modulo

	virtual std::string const &		toString(void) const; // String representation of the instance
	virtual int						getPrecision(void) const; // Precision of the type of the instance
	int32_t							get_value(void) const;
	virtual eOperandType			getType(void) const;

	static int						getOperandInt32Number(void);
	static void						switchOperandInt32Debug(void);

private:
	std::string			_rawString;
	double				_value;
	static int			_nb_OperandInt32;
	static bool			_debug_OperandInt32;
};

#endif
