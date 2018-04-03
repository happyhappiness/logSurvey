                                strlen(NTDomain) + 1, wszUserDomain, sizeof(wszUserDomain) / sizeof(wszUserDomain[0]));
            nStatus = (use_PDC_only ? NetGetDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr) : NetGetAnyDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr));
            if (nStatus != NERR_Success) {
                fprintf(stderr, "%s Can't find DC for user's domain '%s'\n", myname, NTDomain);
                if (pSrvBuf != NULL)
                    NetApiBufferFree(pSrvBuf);
                if (LclDCptr != NULL)
