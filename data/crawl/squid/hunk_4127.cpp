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
 
     /* Convert ANSI User Name to Unicode */
 
     MultiByteToWideChar(CP_ACP, 0, User,
-	strlen(User) + 1, wszUserName,
-	sizeof(wszUserName) / sizeof(wszUserName[0]));
+                        strlen(User) + 1, wszUserName,
+                        sizeof(wszUserName) / sizeof(wszUserName[0]));
 
     /* Query AD for a DC */
 
     if (DsGetDcName(NULL, NTDomain, NULL, NULL, DS_IS_FLAT_NAME | DS_RETURN_FLAT_NAME, &pDCInfo) != NO_ERROR) {
-	fprintf(stderr, "%s DsGetDcName() failed.'\n", myname);
-	if (pDCInfo != NULL)
-	    NetApiBufferFree(pDCInfo);
-	return result;
+        fprintf(stderr, "%s DsGetDcName() failed.'\n", myname);
+        if (pDCInfo != NULL)
+            NetApiBufferFree(pDCInfo);
+        return result;
     }
     /* Convert ANSI Domain Controller Name to Unicode */
 
     MultiByteToWideChar(CP_ACP, 0, pDCInfo->DomainControllerName,
-	strlen(pDCInfo->DomainControllerName) + 1, wszDomainControllerName,
-	sizeof(wszDomainControllerName) / sizeof(wszDomainControllerName[0]));
+                        strlen(pDCInfo->DomainControllerName) + 1, wszDomainControllerName,
+                        sizeof(wszDomainControllerName) / sizeof(wszDomainControllerName[0]));
 
     debug("Using '%S' as DC for '%s' user's domain.\n", wszDomainControllerName, NTDomain);
     debug("DC Active Directory Site is %s\n", pDCInfo->DcSiteName);
     debug("Machine Active Directory Site is %s\n", pDCInfo->ClientSiteName);
 
     /*
-     * Call the NetUserGetGroups function 
+     * Call the NetUserGetGroups function
      * specifying information level 0.
      */
     dwLevel = 0;
     pBufTmp = NULL;
     nStatus = NetUserGetGroups(wszDomainControllerName,
-	wszUserName,
-	dwLevel,
-	&pBufTmp,
-	dwPrefMaxLen,
-	&dwEntriesRead,
-	&dwTotalEntries);
+                               wszUserName,
+                               dwLevel,
+                               &pBufTmp,
+                               dwPrefMaxLen,
+                               &dwEntriesRead,
+                               &dwTotalEntries);
     pUsrBuf = (LPGROUP_USERS_INFO_0) pBufTmp;
     /*
      * If the call succeeds,
      */
     if (nStatus == NERR_Success) {
-	if ((pTmpBuf = pUsrBuf) != NULL) {
-	    for (i = 0; i < dwEntriesRead; i++) {
-		assert(pTmpBuf != NULL);
-		if (pTmpBuf == NULL) {
-		    result = 0;
-		    break;
-		}
-		if (wcstrcmparray(pTmpBuf->grui0_name, Groups) == 0) {
-		    result = 1;
-		    break;
-		}
-		pTmpBuf++;
-		dwTotalCount++;
-	    }
-	}
+        if ((pTmpBuf = pUsrBuf) != NULL) {
+            for (i = 0; i < dwEntriesRead; i++) {
+                assert(pTmpBuf != NULL);
+                if (pTmpBuf == NULL) {
+                    result = 0;
+                    break;
+                }
+                if (wcstrcmparray(pTmpBuf->grui0_name, Groups) == 0) {
+                    result = 1;
+                    break;
+                }
+                pTmpBuf++;
+                dwTotalCount++;
+            }
+        }
     } else {
-	result = 0;
-	fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
+        result = 0;
+        fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
     }
     /*
      * Free the allocated memory.
      */
     if (pUsrBuf != NULL)
-	NetApiBufferFree(pUsrBuf);
+        NetApiBufferFree(pUsrBuf);
     if (pDCInfo != NULL)
-	NetApiBufferFree((LPVOID) pDCInfo);
+        NetApiBufferFree((LPVOID) pDCInfo);
     return result;
 }
 
 static void
 usage(char *program)
 {
     fprintf(stderr, "Usage: %s [-D domain][-G][-P][-c][-d][-h]\n"
-	" -D    default user Domain\n"
-	" -G    enable Domain Global group mode\n"
-	" -c    use case insensitive compare\n"
-	" -d    enable debugging\n"
-	" -h    this message\n",
-	program);
+            " -D    default user Domain\n"
+            " -G    enable Domain Global group mode\n"
+            " -c    use case insensitive compare\n"
+            " -d    enable debugging\n"
+            " -h    this message\n",
+            program);
 }
 
 void
