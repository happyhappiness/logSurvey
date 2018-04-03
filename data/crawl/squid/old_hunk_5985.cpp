    idnsParseNameservers();
    if (0 == nns)
	idnsParseResolvConf();
    if (!init) {
	memDataInit(MEM_IDNS_QUERY, "idns_query", sizeof(idns_query), 0);
	cachemgrRegister("idns",
