	return connect(s, sa, sz);
}

#undef rename
int mingw_rename(const char *pold, const char *pnew)
{
