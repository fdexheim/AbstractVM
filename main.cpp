/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdexheim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 10:50:38 by fdexheim          #+#    #+#             */
/*   Updated: 2017/11/13 15:08:02 by fdexheim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.class.h"

void				prepare(int argc, char **argv)
{
	vm*							machine = new vm();
	std::vector<std::string>	args;
	std::string					errormess;

	for (int i = 1; i < argc; i++)
		args.push_back(argv[i]);

	try
	{
		if (machine->setup(args) == -1)
		{
			machine->clean();
			delete machine;
			exit(0);
		}
		machine->exec();
	}
	catch (std::exception & e)
	{
		if (machine->flagLogFile == true)
		{
			errormess = "Error : ";
			errormess += e.what();
			machine->saveInLog(errormess);
		}
		else
		{
			std::cout << e.what() << std::endl;
			return;
		}
	}
	machine->clean();
	delete machine;
}

//------------------------------------------------------------------------------
int					main(int argc, char **argv)
{
	prepare(argc, argv);

	return 0;
}


