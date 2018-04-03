	}
}

int link(const char *oldpath, const char *newpath)
{
	typedef BOOL (WINAPI *T)(LPCWSTR, LPCWSTR, LPSECURITY_ATTRIBUTES);
