     strncpy(NTDomain, UserName, sizeof(NTDomain));
 
     for (j = 0; j < strlen(NTV_VALID_DOMAIN_SEPARATOR); j++) {
-	if ((domain_qualify = strchr(NTDomain, NTV_VALID_DOMAIN_SEPARATOR[j])) != NULL)
-	    break;
+        if ((domain_qualify = strchr(NTDomain, NTV_VALID_DOMAIN_SEPARATOR[j])) != NULL)
+            break;
     }
     if (domain_qualify == NULL) {
-	strcpy(User, NTDomain);
-	strcpy(NTDomain, DefaultDomain);
+        strcpy(User, NTDomain);
+        strcpy(NTDomain, DefaultDomain);
     } else {
-	strcpy(User, domain_qualify + 1);
-	domain_qualify[0] = '\0';
-	strlwr(NTDomain);
+        strcpy(User, domain_qualify + 1);
+        domain_qualify[0] = '\0';
+        strlwr(NTDomain);
     }
 
     debug("Valid_Global_Groups: checking group membership of '%s\\%s'.\n", NTDomain, User);
 
     /* Convert ANSI User Name and Group to Unicode */
 
     MultiByteToWideChar(CP_ACP, 0, User,
-	strlen(User) + 1, wszUserName,
-	sizeof(wszUserName) / sizeof(wszUserName[0]));
+                        strlen(User) + 1, wszUserName,
+                        sizeof(wszUserName) / sizeof(wszUserName[0]));
     MultiByteToWideChar(CP_ACP, 0, machinedomain,
-	strlen(machinedomain) + 1, wszLocalDomain, sizeof(wszLocalDomain) / sizeof(wszLocalDomain[0]));
+                        strlen(machinedomain) + 1, wszLocalDomain, sizeof(wszLocalDomain) / sizeof(wszLocalDomain[0]));
 
 
-/* Call the NetServerGetInfo function for local computer, specifying level 101. */
+    /* Call the NetServerGetInfo function for local computer, specifying level 101. */
     dwLevel = 101;
     nStatus = NetServerGetInfo(NULL, dwLevel, (LPBYTE *) & pSrvBuf);
 
     if (nStatus == NERR_Success) {
-	/* Check if we are running on a Domain Controller */
-	if ((pSrvBuf->sv101_type & SV_TYPE_DOMAIN_CTRL) ||
-	    (pSrvBuf->sv101_type & SV_TYPE_DOMAIN_BAKCTRL)) {
-	    LclDCptr = NULL;
-	    debug("Running on a DC.\n");
-	} else
-	    nStatus = (use_PDC_only ? NetGetDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr) : NetGetAnyDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr));
+        /* Check if we are running on a Domain Controller */
+        if ((pSrvBuf->sv101_type & SV_TYPE_DOMAIN_CTRL) ||
+                (pSrvBuf->sv101_type & SV_TYPE_DOMAIN_BAKCTRL)) {
+            LclDCptr = NULL;
+            debug("Running on a DC.\n");
+        } else
+            nStatus = (use_PDC_only ? NetGetDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr) : NetGetAnyDCName(NULL, wszLocalDomain, (LPBYTE *) & LclDCptr));
     } else {
-	fprintf(stderr, "%s NetServerGetInfo() failed.'\n", myname);
-	if (pSrvBuf != NULL)
-	    NetApiBufferFree(pSrvBuf);
-	return result;
+        fprintf(stderr, "%s NetServerGetInfo() failed.'\n", myname);
+        if (pSrvBuf != NULL)
+            NetApiBufferFree(pSrvBuf);
+        return result;
     }
 
     if (nStatus == NERR_Success) {
-	debug("Using '%S' as DC for '%S' local domain.\n", LclDCptr, wszLocalDomain);
-
-	if (strcmp(NTDomain, machinedomain) != 0) {
-	    MultiByteToWideChar(CP_ACP, 0, NTDomain,
-		strlen(NTDomain) + 1, wszUserDomain, sizeof(wszUserDomain) / sizeof(wszUserDomain[0]));
-	    nStatus = (use_PDC_only ? NetGetDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr) : NetGetAnyDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr));
-	    if (nStatus != NERR_Success) {
-		fprintf(stderr, "%s Can't find DC for user's domain '%s'\n", myname, NTDomain);
-		if (pSrvBuf != NULL)
-		    NetApiBufferFree(pSrvBuf);
-		if (LclDCptr != NULL)
-		    NetApiBufferFree((LPVOID) LclDCptr);
-		if (UsrDCptr != NULL)
-		    NetApiBufferFree((LPVOID) UsrDCptr);
-		return result;
-	    }
-	} else
-	    UsrDCptr = LclDCptr;
-
-	debug("Using '%S' as DC for '%s' user's domain.\n", UsrDCptr, NTDomain);
-	/*
-	 * Call the NetUserGetGroups function 
-	 * specifying information level 0.
-	 */
-	dwLevel = 0;
-	nStatus = NetUserGetGroups(UsrDCptr,
-	    wszUserName,
-	    dwLevel,
-	    (LPBYTE *) & pUsrBuf,
-	    dwPrefMaxLen,
-	    &dwEntriesRead,
-	    &dwTotalEntries);
-	/*
-	 * If the call succeeds,
-	 */
-	if (nStatus == NERR_Success) {
-	    if ((pTmpBuf = pUsrBuf) != NULL) {
-		for (i = 0; i < dwEntriesRead; i++) {
-		    assert(pTmpBuf != NULL);
-		    if (pTmpBuf == NULL) {
-			result = 0;
-			break;
-		    }
-		    if (wcstrcmparray(pTmpBuf->grui0_name, Groups) == 0) {
-			result = 1;
-			break;
-		    }
-		    pTmpBuf++;
-		    dwTotalCount++;
-		}
-	    }
-	} else {
-	    result = 0;
-	    fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
-	}
+        debug("Using '%S' as DC for '%S' local domain.\n", LclDCptr, wszLocalDomain);
+
+        if (strcmp(NTDomain, machinedomain) != 0) {
+            MultiByteToWideChar(CP_ACP, 0, NTDomain,
+                                strlen(NTDomain) + 1, wszUserDomain, sizeof(wszUserDomain) / sizeof(wszUserDomain[0]));
+            nStatus = (use_PDC_only ? NetGetDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr) : NetGetAnyDCName(LclDCptr, wszUserDomain, (LPBYTE *) & UsrDCptr));
+            if (nStatus != NERR_Success) {
+                fprintf(stderr, "%s Can't find DC for user's domain '%s'\n", myname, NTDomain);
+                if (pSrvBuf != NULL)
+                    NetApiBufferFree(pSrvBuf);
+                if (LclDCptr != NULL)
+                    NetApiBufferFree((LPVOID) LclDCptr);
+                if (UsrDCptr != NULL)
+                    NetApiBufferFree((LPVOID) UsrDCptr);
+                return result;
+            }
+        } else
+            UsrDCptr = LclDCptr;
+
+        debug("Using '%S' as DC for '%s' user's domain.\n", UsrDCptr, NTDomain);
+        /*
+         * Call the NetUserGetGroups function
+         * specifying information level 0.
+         */
+        dwLevel = 0;
+        nStatus = NetUserGetGroups(UsrDCptr,
+                                   wszUserName,
+                                   dwLevel,
+                                   (LPBYTE *) & pUsrBuf,
+                                   dwPrefMaxLen,
+                                   &dwEntriesRead,
+                                   &dwTotalEntries);
+        /*
+         * If the call succeeds,
+         */
+        if (nStatus == NERR_Success) {
+            if ((pTmpBuf = pUsrBuf) != NULL) {
+                for (i = 0; i < dwEntriesRead; i++) {
+                    assert(pTmpBuf != NULL);
+                    if (pTmpBuf == NULL) {
+                        result = 0;
+                        break;
+                    }
+                    if (wcstrcmparray(pTmpBuf->grui0_name, Groups) == 0) {
+                        result = 1;
+                        break;
+                    }
+                    pTmpBuf++;
+                    dwTotalCount++;
+                }
+            }
+        } else {
+            result = 0;
+            fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
+        }
     } else {
-	fprintf(stderr, "%s Can't find DC for local domain '%s'\n", myname, machinedomain);
+        fprintf(stderr, "%s Can't find DC for local domain '%s'\n", myname, machinedomain);
     }
     /*
      * Free the allocated memory.
      */
     if (pSrvBuf != NULL)
-	NetApiBufferFree(pSrvBuf);
+        NetApiBufferFree(pSrvBuf);
     if (pUsrBuf != NULL)
-	NetApiBufferFree(pUsrBuf);
+        NetApiBufferFree(pUsrBuf);
     if ((UsrDCptr != NULL) && (UsrDCptr != LclDCptr))
-	NetApiBufferFree((LPVOID) UsrDCptr);
+        NetApiBufferFree((LPVOID) UsrDCptr);
     if (LclDCptr != NULL)
-	NetApiBufferFree((LPVOID) LclDCptr);
+        NetApiBufferFree((LPVOID) LclDCptr);
     return result;
 }
 
 static void
 usage(char *program)
 {
     fprintf(stderr, "Usage: %s [-D domain][-G][-P][-c][-d][-h]\n"
-	" -D    default user Domain\n"
-	" -G    enable Domain Global group mode\n"
-	" -P    use ONLY PDCs for group validation\n"
-	" -c    use case insensitive compare\n"
-	" -d    enable debugging\n"
-	" -h    this message\n",
-	program);
+            " -D    default user Domain\n"
+            " -G    enable Domain Global group mode\n"
+            " -P    use ONLY PDCs for group validation\n"
+            " -c    use case insensitive compare\n"
+            " -d    enable debugging\n"
+            " -h    this message\n",
+            program);
 }
 
 void