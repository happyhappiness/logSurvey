        } else
            nStatus = (use_PDC_only ? NetGetDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr) : NetGetAnyDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr));
    } else {
        fprintf(stderr, "%s NetServerGetInfo() failed.'\n", myname);
        if (pSrvBuf != NULL)
            NetApiBufferFree(pSrvBuf);
        return result;
