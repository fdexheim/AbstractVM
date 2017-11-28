/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.class.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 09:26:43 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/08 14:47:55 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_CLASS_H
# define VM_CLASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include <sstream>
#include "IOperand.class.h"
#include "exceptions.h"
#include "OperandFactory.class.h"

class vm
{
public:
	vm();
	~vm();

	void					clean(void);
	int						setup(std::vector<std::string> & args);
	void					saveInLog(std::string error);
	std::string				epurLine(std::string & line);
	int						parseLine(std::string line);
	std::string				get_whole_line(void);
	int						parseExec(std::vector<std::string> & args);
	void					exec(void);
	void					putLinesInVector(void);
	IOperand const *		getFirstOperand(void);
	void					popFirstOperand(void);

	void					vmPush(std::string str);
	void					vmPop(void);
	void					vmDump(void);
	void					vmAssert(std::string str);
	void					vmAdd(void);
	void					vmSub(void);
	void					vmMul(void);
	void					vmDiv(void);
	void					vmMod(void);
	void					vmPrint(void);
	void					vmExit(void);

	static int				getvmNumber(void);
	static void				switchvmDebug(void);

	OperandFactory *					facto;
	std::vector<const IOperand *>		operands;
	std::vector<std::string>			lines;
	bool								flagLogFile;
	bool								flagFileExec;
	std::ofstream						logTarget;
	std::ifstream						fileExecTarget;

private:
	vm(vm const & src);
	vm &		operator=(vm const & rhs);

	static int			_nb_vm;
	static bool			_debug_vm;
};

#endif
