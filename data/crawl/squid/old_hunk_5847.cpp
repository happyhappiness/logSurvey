usage()
{
    fprintf(stderr,
	"%s usage:\n"
	"%s [-b] [-f] domain\\controller [domain\\controller ...]\n"
	"-b, if specified, enables load-balancing among controllers\n"
	"-f, if specified, enables failover among controllers\n"
	"-l, if specified, changes behavior on domain controller failyures to"
	"\tlast-ditch\n\n" "You MUST specify at least one Domain Controller.\n"
	"You can use either \\ or / as separator between the domain name \n"
	"\tand the controller name\n",
	my_program_name, my_program_name);
}

