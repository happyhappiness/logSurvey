    if (!Mib)
	Mib = read_mib("mib.txt");
#ifdef MIBFILEPATH
    if (!Mib)
      {
	char tmp [1024];
	sprintf (tmp, "%s/mib.txt", MIBFILEPATH);
	Mib = read_mib(tmp);
      }
#endif
    if (!Mib)
	Mib = read_mib("/etc/mib.txt");
    if (!Mib){
	fprintf(stderr, "Couldn't find mib file\n");
	exit(2);
    }
    prefix = getenv("PREFIX");
    if (! prefix) {
      prefix = Standard_Prefix;
    }

    /* save prefix: */
    snmp_new_prefix (prefix);

    if (getenv("SUFFIX"))
	Suffix = TRUE;
