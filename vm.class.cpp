/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 09:27:32 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 12:14:33 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.class.h"

//------------------------------------------------------------------------------
vm::vm()
{
	if (_debug_vm == true)
		std::cout << "[vm default constructor called]" << std::endl;
	vm::_nb_vm++;
	return;
}

//------------------------------------------------------------------------------
vm::~vm()
{
	if (_debug_vm == true)
		std::cout << "[vm destructor called]" << std::endl;
	vm::_nb_vm--;
	return;
}

//------------------------------------------------------------------------------
void					vm::saveInLog(std::string error)
{
	time_t				tim = time(0);
	struct tm			*tstruct;

	tstruct = localtime(&tim);

	this->logTarget << "[" << tstruct->tm_year + 1900;
	this->logTarget.fill('0');
	this->logTarget << tstruct->tm_mon + 1;
	this->logTarget.width(2);
	this->logTarget.fill('0');
	this->logTarget << tstruct->tm_mday;
	this->logTarget << "_";
	this->logTarget.width(2);
	this->logTarget.fill('0');
	this->logTarget << tstruct->tm_hour;
	this->logTarget.width(2);
	this->logTarget.fill('0');
	this->logTarget << tstruct->tm_min;
	this->logTarget.width(2);
	this->logTarget.fill('0');
	this->logTarget << tstruct->tm_sec << "] ";
	this->logTarget << error << std::endl;
}

//------------------------------------------------------------------------------
IOperand const *		vm::getFirstOperand(void)
{
	return this->operands[0];
}

//------------------------------------------------------------------------------
void					vm::popFirstOperand(void)
{
	this->operands.erase(this->operands.begin());
}

//------------------------------------------------------------------------------
std::string				vm::epurLine(std::string & line)
{
	if (line.find(";") != std::string::npos)
	{
		line = line.substr(0, line.find(";"));

	}
	while (line.size() > 0 && line[0] == ' ')
		line.erase(0);
	while (line.size() > 0 && line[line.size() - 1] == ' ')
		line.erase(line.size() - 1);
	return line;
}

//------------------------------------------------------------------------------
int						vm::parseLine(std::string line)
{
	line = this->epurLine(line);
	if (line.size() == 0)
		return 0;

	if (line.find("exit") == 0 && line.size() == 4)
	{
		this->vmExit();
		return -1;
	}
	else if (line.find("add") == 0 && line.size() == 3)
	{
		this->vmAdd();
		return 0;
	}
	else if (line.find("sub") == 0 && line.size() == 3)
	{
		this->vmSub();
		return 0;
	}
	else if (line.find("mul") == 0 && line.size() == 3)
	{
		this->vmMul();
		return 0;
	}
	else if (line.find("div") == 0 && line.size() == 3)
	{
		this->vmDiv();
		return 0;
	}
	else if (line.find("mod") == 0 && line.size() == 3)
	{
		this->vmMod();
		return 0;
	}
	else if (line.find("push ") == 0 && line.size() > 5)
	{
		this->vmPush(line.substr(5, line.size()));
		return 0;
	}
	else if (line.find("pop") == 0 && line.size() == 3)
	{
		this->vmPop();
		return 0;
	}
	else if (line.find("dump") == 0 && line.size() == 4)
	{
		this->vmDump();
		return 0;
	}
	else if (line.find("print") == 0 && line.size() == 5)
	{
		this->vmPrint();
		return 0;
	}
	else if (line.find("assert ") == 0 && line.size() > 7)
	{
		this->vmAssert(line.substr(7, line.size()));
		return 0;
	}
	else
		throw unknownInstructionException();
}

//------------------------------------------------------------------------------
std::string				vm::get_whole_line()
{
	std::string		buff;

	if (std::getline(std::cin, buff))
		return (buff);
	else
	{
		std::cout << "Input error" << std::endl;
		exit(0);
	}
}

//------------------------------------------------------------------------------
void					vm::exec(void)
{
	std::string			errormess;

	for (unsigned int i = 0; i < this->lines.size(); i++)
	{
		try
		{
			if (this->parseLine(this->lines[i]) == -1)
				return;
		}
		catch (std::exception & e)
		{
			if (this->flagLogFile == true)
			{
				errormess = "Error : at line " + std::to_string(i + 1) + " " + e.what();
				this->saveInLog(errormess);
			}
			else
			{
				std::cout << "Error : at line " << i + 1 << " " << e.what() << " - exiting program" << std::endl;
				return;
			}
		}
	}
	throw (noExitException());
}

//------------------------------------------------------------------------------
void					vm::clean(void)
{
	for (unsigned int i = 0; i < this->operands.size(); i++)
		delete this->operands[i];
	this->operands.clear();
	if (this->fileExecTarget.is_open() == true)
		this->fileExecTarget.close();
	if (this->logTarget.is_open() == true)
		this->logTarget.close();
}

//------------------------------------------------------------------------------
int						vm::parseExec(std::vector<std::string> & args)
{
	for (unsigned int i = 0; i < args.size(); i++)
	{
		if (args[i] == "-help")
		{
			std::cout << "./avm" << std::endl << "'-log' will make errors non-blocking and keep a trace in a logfile"
				<< std::endl << "add a filename with all instructions inside, else it will launch in manual mode" << std::endl;
			return -1;
		}
		else if (args[i] == "-log" && this->flagLogFile == false)
			this->flagLogFile = true;
		else if (flagFileExec == false)
		{
			this->fileExecTarget.open(args[i]);
			this->flagFileExec = true;
			if ((this->logTarget.rdstate() & std::ifstream::failbit) != 0)
			{
				std::cout << " - instructions file opening unsucessful, defaulting to standard input" << std::endl;
				this->flagFileExec = false;
			}
		}
	}
	return 0;
}

//------------------------------------------------------------------------------
int						vm::setup(std::vector<std::string> & args)
{
	std::string			shialebuff;

	this->facto = new OperandFactory;
	this->flagLogFile = false;
	this->flagFileExec = false;

	if (this->parseExec(args) == -1)
		return -1;
	if (this->flagLogFile == true)
	{

		this->logTarget.open("vmLogReport");
		if ((this->logTarget.rdstate() & std::ifstream::failbit) != 0)
		{
			std::cout << "[warning] - logfile opening unsuccessful, defaulting to normal error handling" << std::endl;
			this->flagLogFile = false;
		}
	}
	if (this->flagFileExec == false)
	{
		while (1)
		{
			shialebuff = get_whole_line();
			if (shialebuff.find(";;") != std::string::npos)
				return 0;
			this->lines.push_back(shialebuff);
		}
	}
	else if (this->flagFileExec == true)
	{
		while (std::getline(this->fileExecTarget, shialebuff))
		{
			this->lines.push_back(shialebuff);
		}
	}
	if (this->flagFileExec == false)
		std::cout << "[warning] - you somehow didn't put the ';;' to terminate input. Someone stop this madman/madwoman" << std::endl;
	return 0;
}

//==============================================================================
void					vm::switchvmDebug() { vm::_debug_vm = !vm::_debug_vm; }
int						vm::getvmNumber(void) { return (vm::_nb_vm); }

//------------------------------------------------------------------------------
int						vm::_nb_vm = 0;
bool					vm::_debug_vm = false;
