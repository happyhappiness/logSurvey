{
    char **tmp = NULL;
    int i;
    if (CacheDirs == NULL) {
	CacheDirsAllocated = 4;
	CacheDirs = xcalloc(CacheDirsAllocated, sizeof(char *));
