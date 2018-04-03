 #define CRED_MAX_ATTRIBUTES 64
 
 typedef BOOL (WINAPI *CredWriteWT)(PCREDENTIALW, DWORD);
-typedef BOOL (WINAPI *CredUnPackAuthenticationBufferWT)(DWORD, PVOID, DWORD,
-    LPWSTR, DWORD *, LPWSTR, DWORD *, LPWSTR, DWORD *);
 typedef BOOL (WINAPI *CredEnumerateWT)(LPCWSTR, DWORD, DWORD *,
     PCREDENTIALW **);
-typedef BOOL (WINAPI *CredPackAuthenticationBufferWT)(DWORD, LPWSTR, LPWSTR,
-    PBYTE, DWORD *);
 typedef VOID (WINAPI *CredFreeT)(PVOID);
 typedef BOOL (WINAPI *CredDeleteWT)(LPCWSTR, DWORD, DWORD);
 
-static HMODULE advapi, credui;
+static HMODULE advapi;
 static CredWriteWT CredWriteW;
-static CredUnPackAuthenticationBufferWT CredUnPackAuthenticationBufferW;
 static CredEnumerateWT CredEnumerateW;
-static CredPackAuthenticationBufferWT CredPackAuthenticationBufferW;
 static CredFreeT CredFree;
 static CredDeleteWT CredDeleteW;
 
 static void load_cred_funcs(void)
 {
 	/* load DLLs */
 	advapi = LoadLibrary("advapi32.dll");
-	credui = LoadLibrary("credui.dll");
-	if (!advapi || !credui)
-		die("failed to load DLLs");
+	if (!advapi)
+		die("failed to load advapi32.dll");
 
 	/* get function pointers */
 	CredWriteW = (CredWriteWT)GetProcAddress(advapi, "CredWriteW");
-	CredUnPackAuthenticationBufferW = (CredUnPackAuthenticationBufferWT)
-	    GetProcAddress(credui, "CredUnPackAuthenticationBufferW");
 	CredEnumerateW = (CredEnumerateWT)GetProcAddress(advapi,
 	    "CredEnumerateW");
-	CredPackAuthenticationBufferW = (CredPackAuthenticationBufferWT)
-	    GetProcAddress(credui, "CredPackAuthenticationBufferW");
 	CredFree = (CredFreeT)GetProcAddress(advapi, "CredFree");
 	CredDeleteW = (CredDeleteWT)GetProcAddress(advapi, "CredDeleteW");
-	if (!CredWriteW || !CredUnPackAuthenticationBufferW ||
-	    !CredEnumerateW || !CredPackAuthenticationBufferW || !CredFree ||
-	    !CredDeleteW)
+	if (!CredWriteW || !CredEnumerateW || !CredFree || !CredDeleteW)
 		die("failed to load functions");
 }
 
-static char target_buf[1024];
-static char *protocol, *host, *path, *username;
-static WCHAR *wusername, *password, *target;
+static WCHAR *wusername, *password, *protocol, *host, *path, target[1024];
 
-static void write_item(const char *what, WCHAR *wbuf)
+static void write_item(const char *what, LPCWSTR wbuf, int wlen)
 {
 	char *buf;
-	int len = WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, NULL, 0, NULL,
+	int len = WideCharToMultiByte(CP_UTF8, 0, wbuf, wlen, NULL, 0, NULL,
 	    FALSE);
 	buf = xmalloc(len);
 
-	if (!WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, buf, len, NULL, FALSE))
+	if (!WideCharToMultiByte(CP_UTF8, 0, wbuf, wlen, buf, len, NULL, FALSE))
 		die("WideCharToMultiByte failed!");
 
 	printf("%s=", what);
-	fwrite(buf, 1, len - 1, stdout);
+	fwrite(buf, 1, len, stdout);
 	putchar('\n');
 	free(buf);
 }
 
-static int match_attr(const CREDENTIALW *cred, const WCHAR *keyword,
-    const char *want)
+/*
+ * Match an (optional) expected string and a delimiter in the target string,
+ * consuming the matched text by updating the target pointer.
+ */
+static int match_part(LPCWSTR *ptarget, LPCWSTR want, LPCWSTR delim)
 {
-	int i;
-	if (!want)
-		return 1;
-
-	for (i = 0; i < cred->AttributeCount; ++i)
-		if (!wcscmp(cred->Attributes[i].Keyword, keyword))
-			return !strcmp((const char *)cred->Attributes[i].Value,
-			    want);
-
-	return 0; /* not found */
+	LPCWSTR delim_pos, start = *ptarget;
+	int len;
+
+	/* find start of delimiter (or end-of-string if delim is empty) */
+	if (*delim)
+		delim_pos = wcsstr(start, delim);
+	else
+		delim_pos = start + wcslen(start);
+
+	/*
+	 * match text up to delimiter, or end of string (e.g. the '/' after
+	 * host is optional if not followed by a path)
+	 */
+	if (delim_pos)
+		len = delim_pos - start;
+	else
+		len = wcslen(start);
+
+	/* update ptarget if we either found a delimiter or need a match */
+	if (delim_pos || want)
+		*ptarget = delim_pos ? delim_pos + wcslen(delim) : start + len;
+
+	return !want || (!wcsncmp(want, start, len) && !want[len]);
 }
 
 static int match_cred(const CREDENTIALW *cred)
 {
-	return (!wusername || !wcscmp(wusername, cred->UserName)) &&
-	    match_attr(cred, L"git_protocol", protocol) &&
-	    match_attr(cred, L"git_host", host) &&
-	    match_attr(cred, L"git_path", path);
+	LPCWSTR target = cred->TargetName;
+	if (wusername && wcscmp(wusername, cred->UserName))
+		return 0;
+
+	return match_part(&target, L"git", L":") &&
+		match_part(&target, protocol, L"://") &&
+		match_part(&target, wusername, L"@") &&
+		match_part(&target, host, L"/") &&
+		match_part(&target, path, L"");
 }
 
 static void get_credential(void)
 {
-	WCHAR *user_buf, *pass_buf;
-	DWORD user_buf_size = 0, pass_buf_size = 0;
-	CREDENTIALW **creds, *cred = NULL;
+	CREDENTIALW **creds;
 	DWORD num_creds;
 	int i;
 
