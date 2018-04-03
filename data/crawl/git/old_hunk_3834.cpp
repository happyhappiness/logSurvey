#define CRED_MAX_ATTRIBUTES 64

typedef BOOL (WINAPI *CredWriteWT)(PCREDENTIALW, DWORD);
typedef BOOL (WINAPI *CredUnPackAuthenticationBufferWT)(DWORD, PVOID, DWORD,
    LPWSTR, DWORD *, LPWSTR, DWORD *, LPWSTR, DWORD *);
typedef BOOL (WINAPI *CredEnumerateWT)(LPCWSTR, DWORD, DWORD *,
    PCREDENTIALW **);
typedef BOOL (WINAPI *CredPackAuthenticationBufferWT)(DWORD, LPWSTR, LPWSTR,
    PBYTE, DWORD *);
typedef VOID (WINAPI *CredFreeT)(PVOID);
typedef BOOL (WINAPI *CredDeleteWT)(LPCWSTR, DWORD, DWORD);

static HMODULE advapi, credui;
static CredWriteWT CredWriteW;
static CredUnPackAuthenticationBufferWT CredUnPackAuthenticationBufferW;
static CredEnumerateWT CredEnumerateW;
static CredPackAuthenticationBufferWT CredPackAuthenticationBufferW;
static CredFreeT CredFree;
static CredDeleteWT CredDeleteW;

static void load_cred_funcs(void)
{
	/* load DLLs */
	advapi = LoadLibrary("advapi32.dll");
	credui = LoadLibrary("credui.dll");
	if (!advapi || !credui)
		die("failed to load DLLs");

	/* get function pointers */
	CredWriteW = (CredWriteWT)GetProcAddress(advapi, "CredWriteW");
	CredUnPackAuthenticationBufferW = (CredUnPackAuthenticationBufferWT)
	    GetProcAddress(credui, "CredUnPackAuthenticationBufferW");
	CredEnumerateW = (CredEnumerateWT)GetProcAddress(advapi,
	    "CredEnumerateW");
	CredPackAuthenticationBufferW = (CredPackAuthenticationBufferWT)
	    GetProcAddress(credui, "CredPackAuthenticationBufferW");
	CredFree = (CredFreeT)GetProcAddress(advapi, "CredFree");
	CredDeleteW = (CredDeleteWT)GetProcAddress(advapi, "CredDeleteW");
	if (!CredWriteW || !CredUnPackAuthenticationBufferW ||
	    !CredEnumerateW || !CredPackAuthenticationBufferW || !CredFree ||
	    !CredDeleteW)
		die("failed to load functions");
}

static char target_buf[1024];
static char *protocol, *host, *path, *username;
static WCHAR *wusername, *password, *target;

static void write_item(const char *what, WCHAR *wbuf)
{
	char *buf;
	int len = WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, NULL, 0, NULL,
	    FALSE);
	buf = xmalloc(len);

	if (!WideCharToMultiByte(CP_UTF8, 0, wbuf, -1, buf, len, NULL, FALSE))
		die("WideCharToMultiByte failed!");

	printf("%s=", what);
	fwrite(buf, 1, len - 1, stdout);
	putchar('\n');
	free(buf);
}

static int match_attr(const CREDENTIALW *cred, const WCHAR *keyword,
    const char *want)
{
	int i;
	if (!want)
		return 1;

	for (i = 0; i < cred->AttributeCount; ++i)
		if (!wcscmp(cred->Attributes[i].Keyword, keyword))
			return !strcmp((const char *)cred->Attributes[i].Value,
			    want);

	return 0; /* not found */
}

static int match_cred(const CREDENTIALW *cred)
{
	return (!wusername || !wcscmp(wusername, cred->UserName)) &&
	    match_attr(cred, L"git_protocol", protocol) &&
	    match_attr(cred, L"git_host", host) &&
	    match_attr(cred, L"git_path", path);
}

static void get_credential(void)
{
	WCHAR *user_buf, *pass_buf;
	DWORD user_buf_size = 0, pass_buf_size = 0;
	CREDENTIALW **creds, *cred = NULL;
	DWORD num_creds;
	int i;

