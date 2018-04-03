	return ret;
}

static char *xstrdup(const char *str)
{
	char *ret = strdup(str);
	if (!ret)
		die("Out of memory");
	return ret;
}

/* MinGW doesn't have wincred.h, so we need to define stuff */

typedef struct _CREDENTIAL_ATTRIBUTEW {
