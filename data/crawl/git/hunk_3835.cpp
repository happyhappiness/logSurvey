 	/* search for the first credential that matches username */
 	for (i = 0; i < num_creds; ++i)
 		if (match_cred(creds[i])) {
-			cred = creds[i];
+			write_item("username", creds[i]->UserName,
+				wcslen(creds[i]->UserName));
+			write_item("password",
+				(LPCWSTR)creds[i]->CredentialBlob,
+				creds[i]->CredentialBlobSize / sizeof(WCHAR));
 			break;
 		}
-	if (!cred)
-		return;
-
-	CredUnPackAuthenticationBufferW(0, cred->CredentialBlob,
-	    cred->CredentialBlobSize, NULL, &user_buf_size, NULL, NULL,
-	    NULL, &pass_buf_size);
-
-	user_buf = xmalloc(user_buf_size * sizeof(WCHAR));
-	pass_buf = xmalloc(pass_buf_size * sizeof(WCHAR));
-
-	if (!CredUnPackAuthenticationBufferW(0, cred->CredentialBlob,
-	    cred->CredentialBlobSize, user_buf, &user_buf_size, NULL, NULL,
-	    pass_buf, &pass_buf_size))
-		die("CredUnPackAuthenticationBuffer failed");
 
 	CredFree(creds);
-
-	/* zero-terminate (sizes include zero-termination) */
-	user_buf[user_buf_size - 1] = L'\0';
-	pass_buf[pass_buf_size - 1] = L'\0';
-
-	write_item("username", user_buf);
-	write_item("password", pass_buf);
-
-	free(user_buf);
-	free(pass_buf);
-}
-
-static void write_attr(CREDENTIAL_ATTRIBUTEW *attr, const WCHAR *keyword,
-    const char *value)
-{
-	attr->Keyword = (LPWSTR)keyword;
-	attr->Flags = 0;
-	attr->ValueSize = strlen(value) + 1; /* store zero-termination */
-	attr->Value = (LPBYTE)value;
 }
 
 static void store_credential(void)
 {
 	CREDENTIALW cred;
-	BYTE *auth_buf;
-	DWORD auth_buf_size = 0;
-	CREDENTIAL_ATTRIBUTEW attrs[CRED_MAX_ATTRIBUTES];
 
 	if (!wusername || !password)
 		return;
 
-	/* query buffer size */
-	CredPackAuthenticationBufferW(0, wusername, password,
-	    NULL, &auth_buf_size);
-
-	auth_buf = xmalloc(auth_buf_size);
-
-	if (!CredPackAuthenticationBufferW(0, wusername, password,
-	    auth_buf, &auth_buf_size))
-		die("CredPackAuthenticationBuffer failed");
-
 	cred.Flags = 0;
 	cred.Type = CRED_TYPE_GENERIC;
 	cred.TargetName = target;
 	cred.Comment = L"saved by git-credential-wincred";
-	cred.CredentialBlobSize = auth_buf_size;
-	cred.CredentialBlob = auth_buf;
+	cred.CredentialBlobSize = (wcslen(password)) * sizeof(WCHAR);
+	cred.CredentialBlob = (LPVOID)password;
 	cred.Persist = CRED_PERSIST_LOCAL_MACHINE;
-	cred.AttributeCount = 1;
-	cred.Attributes = attrs;
+	cred.AttributeCount = 0;
+	cred.Attributes = NULL;
 	cred.TargetAlias = NULL;
 	cred.UserName = wusername;
 
-	write_attr(attrs, L"git_protocol", protocol);
-
-	if (host) {
-		write_attr(attrs + cred.AttributeCount, L"git_host", host);
-		cred.AttributeCount++;
-	}
-
-	if (path) {
-		write_attr(attrs + cred.AttributeCount, L"git_path", path);
-		cred.AttributeCount++;
-	}
-
 	if (!CredWriteW(&cred, 0))
 		die("CredWrite failed");
 }
