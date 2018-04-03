        } else
            nStatus = (use_PDC_only ? NetGetDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr) : NetGetAnyDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr));
    } else {
        fprintf(stderr, "%s: ERROR: NetServerGetInfo() failed.'\n", program_name);
        if (pSrvBuf != NULL)
            NetApiBufferFree(pSrvBuf);
        return result;
