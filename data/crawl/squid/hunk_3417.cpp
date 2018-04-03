 Valid_Global_Groups(char *UserName, const char **Groups)
 {
     int result = 0;
-    WCHAR wszUserName[UNLEN + 1];	// Unicode user name
-
-    WCHAR wszDomainControllerName[UNCLEN + 1];
-
+    WCHAR wszUser[DNLEN + UNLEN + 2];	/* Unicode user name */
     char NTDomain[DNLEN + UNLEN + 2];
+
     char *domain_qualify = NULL;
-    char User[UNLEN + 1];
+    char User[DNLEN + UNLEN + 2];
     size_t j;
 
-    LPGROUP_USERS_INFO_0 pUsrBuf = NULL;
-    LPGROUP_USERS_INFO_0 pTmpBuf;
-    PDOMAIN_CONTROLLER_INFO pDCInfo = NULL;
-    DWORD dwLevel = 0;
-    DWORD dwPrefMaxLen = -1;
-    DWORD dwEntriesRead = 0;
-    DWORD dwTotalEntries = 0;
-    NET_API_STATUS nStatus;
-    DWORD i;
-    DWORD dwTotalCount = 0;
-    LPBYTE pBufTmp = NULL;
+    wchar_t *User_DN, *User_LDAP_path, *User_PrimaryGroup;
+    wchar_t **wszGroups, **tmp;
+    IADs *pUser;
+    HRESULT hr;
 
     strncpy(NTDomain, UserName, sizeof(NTDomain));
 
     for (j = 0; j < strlen(NTV_VALID_DOMAIN_SEPARATOR); j++) {
-        if ((domain_qualify = strchr(NTDomain, NTV_VALID_DOMAIN_SEPARATOR[j])) != NULL)
-            break;
+	if ((domain_qualify = strchr(NTDomain, NTV_VALID_DOMAIN_SEPARATOR[j])) != NULL)
+	    break;
     }
     if (domain_qualify == NULL) {
-        strcpy(User, NTDomain);
-        strcpy(NTDomain, DefaultDomain);
+	strncpy(User, DefaultDomain, DNLEN);
+	strcat(User, "\\");
+	strncat(User, UserName, UNLEN);
+	strncpy(NTDomain, DefaultDomain, DNLEN);
     } else {
-        strcpy(User, domain_qualify + 1);
-        domain_qualify[0] = '\0';
-        strlwr(NTDomain);
+	domain_qualify[0] = '\\';
+	strncpy(User, NTDomain, DNLEN + UNLEN + 2);
+	domain_qualify[0] = '\0';
     }
 
-    debug("Valid_Global_Groups: checking group membership of '%s\\%s'.\n", NTDomain, User);
+    debug("Valid_Global_Groups: checking group membership of '%s'.\n", User);
 
     /* Convert ANSI User Name to Unicode */
 
     MultiByteToWideChar(CP_ACP, 0, User,
-                        strlen(User) + 1, wszUserName,
-                        sizeof(wszUserName) / sizeof(wszUserName[0]));
-
-    /* Query AD for a DC */
+	strlen(User) + 1, wszUser,
+	sizeof(wszUser) / sizeof(wszUser[0]));
 
-    if (DsGetDcName(NULL, NTDomain, NULL, NULL, DS_IS_FLAT_NAME | DS_RETURN_FLAT_NAME, &pDCInfo) != NO_ERROR) {
-        fprintf(stderr, "%s DsGetDcName() failed.'\n", myname);
-        if (pDCInfo != NULL)
-            NetApiBufferFree(pDCInfo);
-        return result;
+    /* Get CN of User */
+    if ((User_DN = My_NameTranslate(wszUser, ADS_NAME_TYPE_NT4, ADS_NAME_TYPE_1779)) == NULL) {
+	debug("Valid_Global_Groups: cannot get DN for '%s'.\n", User);
+	return result;
     }
-    /* Convert ANSI Domain Controller Name to Unicode */
-
-    MultiByteToWideChar(CP_ACP, 0, pDCInfo->DomainControllerName,
-                        strlen(pDCInfo->DomainControllerName) + 1, wszDomainControllerName,
-                        sizeof(wszDomainControllerName) / sizeof(wszDomainControllerName[0]));
-
-    debug("Using '%S' as DC for '%s' user's domain.\n", wszDomainControllerName, NTDomain);
-    debug("DC Active Directory Site is %s\n", pDCInfo->DcSiteName);
-    debug("Machine Active Directory Site is %s\n", pDCInfo->ClientSiteName);
+    wszGroups = build_groups_DN_array(Groups, NTDomain);
+
+    User_LDAP_path = GetLDAPPath(User_DN, GC_MODE);
+
+    hr = ADsGetObject(User_LDAP_path, &IID_IADs, (void **) &pUser);
+    if (SUCCEEDED(hr)) {
+	wchar_t *User_PrimaryGroup_Path;
+	IADs *pGrp;
+
+	User_PrimaryGroup = Get_primaryGroup(pUser);
+	if (User_PrimaryGroup == NULL)
+	    debug("Valid_Global_Groups: cannot get Primary Group for '%s'.\n", User);
+	else {
+	    add_User_Group(User_PrimaryGroup);
+	    User_PrimaryGroup_Path = GetLDAPPath(User_PrimaryGroup, GC_MODE);
+	    hr = ADsGetObject(User_PrimaryGroup_Path, &IID_IADs, (void **) &pGrp);
+	    if (SUCCEEDED(hr)) {
+		hr = Recursive_Memberof(pGrp);
+		pGrp->lpVtbl->Release(pGrp);
+		safe_free(User_PrimaryGroup_Path);
+		User_PrimaryGroup_Path = GetLDAPPath(User_PrimaryGroup, LDAP_MODE);
+	    hr = ADsGetObject(User_PrimaryGroup_Path, &IID_IADs, (void **) &pGrp);
+	    if (SUCCEEDED(hr)) {
+		hr = Recursive_Memberof(pGrp);
+		pGrp->lpVtbl->Release(pGrp);
+	    } else
+		debug("Valid_Global_Groups: ADsGetObject for %S failed, ERROR: %s\n", User_PrimaryGroup_Path, Get_WIN32_ErrorMessage(hr));
+	    } else
+		debug("Valid_Global_Groups: ADsGetObject for %S failed, ERROR: %s\n", User_PrimaryGroup_Path, Get_WIN32_ErrorMessage(hr));
+	    safe_free(User_PrimaryGroup_Path);
+	}
+	hr = Recursive_Memberof(pUser);
+	pUser->lpVtbl->Release(pUser);
+	safe_free(User_LDAP_path);
+	User_LDAP_path = GetLDAPPath(User_DN, LDAP_MODE);
+	hr = ADsGetObject(User_LDAP_path, &IID_IADs, (void **) &pUser);
+	if (SUCCEEDED(hr)) {
+	    hr = Recursive_Memberof(pUser);
+	    pUser->lpVtbl->Release(pUser);
+	} else
+	    debug("Valid_Global_Groups: ADsGetObject for %S failed, ERROR: %s\n", User_LDAP_path, Get_WIN32_ErrorMessage(hr));
+
+	tmp = User_Groups;
+	while (*tmp) {
+	    if (wccmparray(*tmp, wszGroups) == 0) {
+		result = 1;
+		break;
+	    }
+	    tmp++;
+	}
+    } else
+	debug("Valid_Global_Groups: ADsGetObject for %S failed, ERROR: %s\n", User_LDAP_path, Get_WIN32_ErrorMessage(hr));
+
+    safe_free(User_DN);
+    safe_free(User_LDAP_path);
+    safe_free(User_PrimaryGroup);
+    tmp = wszGroups;
+    while (*tmp) {
+	safe_free(*tmp);
+	tmp++;
+    }
+    safe_free(wszGroups);
 
-    /*
-     * Call the NetUserGetGroups function
-     * specifying information level 0.
-     */
-    dwLevel = 0;
-    pBufTmp = NULL;
-    nStatus = NetUserGetGroups(wszDomainControllerName,
-                               wszUserName,
-                               dwLevel,
-                               &pBufTmp,
-                               dwPrefMaxLen,
-                               &dwEntriesRead,
-                               &dwTotalEntries);
-    pUsrBuf = (LPGROUP_USERS_INFO_0) pBufTmp;
-    /*
-     * If the call succeeds,
-     */
-    if (nStatus == NERR_Success) {
-        if ((pTmpBuf = pUsrBuf) != NULL) {
-            for (i = 0; i < dwEntriesRead; i++) {
-                assert(pTmpBuf != NULL);
-                if (pTmpBuf == NULL) {
-                    result = 0;
-                    break;
-                }
-                if (wcstrcmparray(pTmpBuf->grui0_name, Groups) == 0) {
-                    result = 1;
-                    break;
-                }
-                pTmpBuf++;
-                dwTotalCount++;
-            }
-        }
-    } else {
-        result = 0;
-        fprintf(stderr, "%s NetUserGetGroups() failed.'\n", myname);
+    tmp = User_Groups;
+    while (*tmp) {
+	safe_free(*tmp);
+	tmp++;
     }
-    /*
-     * Free the allocated memory.
-     */
-    if (pUsrBuf != NULL)
-        NetApiBufferFree(pUsrBuf);
-    if (pDCInfo != NULL)
-        NetApiBufferFree((LPVOID) pDCInfo);
+    safe_free(User_Groups);
+    User_Groups_Count = 0;
+
     return result;
 }
 
 static void
 usage(char *program)
 {
-    fprintf(stderr, "Usage: %s [-D domain][-G][-P][-c][-d][-h]\n"
-            " -D    default user Domain\n"
-            " -G    enable Domain Global group mode\n"
-            " -c    use case insensitive compare\n"
-            " -d    enable debugging\n"
-            " -h    this message\n",
-            program);
+    fprintf(stderr, "Usage: %s [-D domain][-G][-c][-d][-h]\n"
+	" -D    default user Domain\n"
+	" -G    enable Active Directory Global group mode\n"
+	" -c    use case insensitive compare (local mode only)\n"
+	" -d    enable debugging\n"
+	" -h    this message\n",
+	program);
 }
 
 void
