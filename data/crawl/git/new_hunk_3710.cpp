		die("cannot use %s as an exclude file", fname);
}

int match_basename(const char *basename, int basenamelen,
		   const char *pattern, int prefix, int patternlen,
		   int flags)
