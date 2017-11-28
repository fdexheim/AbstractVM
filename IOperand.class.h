/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.class.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 10:56:13 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/08 14:33:33 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_CLASS_HPP
# define IOPERAND_CLASS_HPP

#include <iostream>
#include <string>
#include <cmath>

enum eOperandType
{
	Int8 = 0,
	Int16 = 1,
	Int32 = 2,
	Float = 3,
	Double = 4
};

class IOperand
{
public:
	IOperand() {}
	virtual ~IOperand() {}


	virtual IOperand const *		operator+(IOperand const & rhs) const = 0; // Sum
	virtual IOperand const *		operator-(IOperand const & rhs) const = 0; // Difference
	virtual IOperand const *		operator*(IOperand const & rhs) const = 0; // Product
	virtual IOperand const *		operator/(IOperand const & rhs) const = 0; // Quotient
	virtual IOperand const *		operator%(IOperand const & rhs) const = 0; // Modulo

	virtual std::string const &		toString(void) const = 0; // String representation of the instance

	virtual int						getPrecision(void) const = 0; // Precision of the type of the instance
	virtual eOperandType			getType(void) const = 0;      // Type of the instance

};

#endif
