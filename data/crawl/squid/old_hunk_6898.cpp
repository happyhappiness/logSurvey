}

static void
parse_snmp_conf(snmpconf **s)
{
	static char buff[256];
	static char *tokens[10], *p;
	if (Mib==NULL)
	{
		if (Config.Snmp.mibPath) 
			init_mib(Config.Snmp.mibPath) ;
		else
			fatal("snmp_mib_path should be defined before any snmp_agent_conf\n");
	}
	p=strtok(NULL, null_string);
	strcpy(buff,p);
	tokenize(buff, tokens, 10 );

	if ( !strcmp("view", tokens[0]) ) {
		if (create_view(tokens) < 0 ) 
			debug(49,5)("snmp: parse_snmpconf(): error\n");
	} else if ( !strcmp("user", tokens[0])) {
		if (create_user(tokens) < 0 )
			debug(49,5)("snmp: parse_snmpconf(): error\n");
	} else if ( !strcmp("community", tokens[0] )) { 
		if ( create_community(tokens) < 0 ) 
			debug(49,5)("snmp: parse_snmpconf(): error\n");
	} else 
		debug(49,5)("snmp: unknown directive %s\n",tokens[0]);
}

static void
