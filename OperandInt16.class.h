/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandInt16.class.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:09:41 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/10 09:09:44 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDINT16_CLASS_H
# define OPERANDINT16_CLASS_H

#include <iostream>
#include <string>
#include "IOperand.class.h"
#include "exceptions.h"

class OperandInt16 : public virtual IOperand
{
public:
	OperandInt16(std::string str);
	OperandInt16(OperandInt16 const & src);
	virtual ~OperandInt16();

	OperandInt16 &					operator=(OperandInt16 const & rhs);

	virtual IOperand const *		operator+(IOperand const & rhs) const; // Sum
	virtual IOperand const *		operator-(IOperand const & rhs) const; // Difference
	virtual IOperand const *		operator*(IOperand const & rhs) const; // Product
	virtual IOperand const *		operator/(IOperand const & rhs) const; // Quotient
	virtual IOperand const *		operator%(IOperand const & rhs) const; // Modulo

	virtual std::string const &		toString(void) const; // String representation of the instance
	virtual int						getPrecision(void) const; // Precision of the type of the instance
	int16_t							get_value(void) const;
	virtual eOperandType			getType(void) const;

	static int						getOperandInt16Number(void);
	static void						switchOperandInt16Debug(void);

private:
	std::string			_rawString;
	double				_value;
	static int			_nb_OperandInt16;
	static bool			_debug_OperandInt16;
};

#endif
