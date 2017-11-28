/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.class.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:53:57 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/08 15:04:59 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERANDFACTORY_CLASS_HPP
# define OPERANDFACTORY_CLASS_HPP

#include <iostream>
#include <string>
#include "IOperand.class.h"

class OperandFactory
{
public:
	OperandFactory();
	~OperandFactory();

	IOperand const *		createOperand(eOperandType type, std::string const & value) const;

	typedef const IOperand * (OperandFactory::*facto)(std::string const &) const;
	facto					factoMap[5];

	static OperandFactory *		getInstance(void);
	static int					getOperandFactoryNumber(void);
	static void					switchOperandFactoryDebug(void);

private:
	IOperand const *		createInt8(std::string const & value) const;
	IOperand const *		createInt16(std::string const & value) const;
	IOperand const *		createInt32(std::string const & value) const;
	IOperand const *		createFloat(std::string const & value) const;
	IOperand const *		createDouble(std::string const & value) const;

	OperandFactory(OperandFactory const & src);
	OperandFactory &		operator=(OperandFactory const & rhs);

	static OperandFactory*	_inst;
	static int				_nb_OperandFactory;
	static bool				_debug_OperandFactory;
};

#endif
