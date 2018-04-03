
  if (memname_p != 0)
    *memname_p = savestring (p + 1, end - (p + 1));
}

static long int ar_member_date_1 PARAMS ((int desc, char *mem, int truncated, long int hdrpos,
	long int datapos, long int size, long int date, int uid, int gid, int mode, char *name));
