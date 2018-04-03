
/* Call the NetServerGetInfo function for local computer, specifying level 101. */
    dwLevel = 101;
    nStatus = NetServerGetInfo(NULL, dwLevel, (LPBYTE *) & pSrvBuf);

    if (nStatus == NERR_Success) {
	/* Check if we are running on a Domain Controller */
	if ((pSrvBuf->sv101_type & SV_TYPE_DOMAIN_CTRL) ||
	    (pSrvBuf->sv101_type & SV_TYPE_DOMAIN_BAKCTRL)) {
	    LclDCptr = NULL;
	    debug("Running on a DC.\n");
	} else
	    nStatus = (use_PDC_only ? NetGetDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr) : NetGetAnyDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr));
    } else {
	fprintf(stderr, "%s NetServerGetInfo() failed.'\n", myname);
	if (pSrvBuf != NULL)
	    NetApiBufferFree(pSrvBuf);
	return result;
    }

    if (nStatus == NERR_Success) {
	debug("Using '%S' as DC for '%S' local domain.\n", LclDCptr, wszLocalDomain);

	if (strcmp(NTDomain, machinedomain) != 0) {
	    MultiByteToWideChar(CP_ACP, 0, NTDomain,
		strlen(NTDomain) + 1, wszUserDomain, sizeof(wszUserDomain) / sizeof(wszUserDomain[0]));
	    nStatus = (use_PDC_only ? NetGetDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr) : NetGetAnyDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr));
	    if (nStatus != NERR_Success) {
		fprintf(stderr, "%s Can't find DC for user's domain '%s'\n", myname, NTDomain);
		if (pSrvBuf != NULL)
		    NetApiBufferFree(pSrvBuf);
		if (LclDCptr != NULL)
		    NetApiBufferFree((LPVOID) LclDCptr);
		if (UsrDCptr != NULL)
		    NetApiBufferFree((LPVOID) UsrDCptr);
		return result;
	    }
	} else
	    UsrDCptr = LclDCptr;

	debug("Using '%S' as DC for '%s' user's domain.\n", UsrDCptr, NTDomain);
	/*
	 * Call the NetUserGetGroups function 
	 * specifying information level 0.
	 */
	dwLevel = 0;
	nStatus = NetUserGetGroups(UsrDCptr,
	    wszUserName,
	    dwLevel,
	    (LPBYTE *) & pUsrBuf,
	    dwPrefMaxLen,
	    &dwEntriesRead,
	    &dwTotalEntries);
	/*
	 * If the call succeeds,
	 */
	if (nStatus == NERR_Success) {
	    if ((pTmpBuf = pUsrBuf) != NULL) {
		for (i = 0; i < dwEntriesRead; i++) {
