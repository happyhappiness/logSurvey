    report_difference (&current_stat_info, _("Mode differs"));
}

static int
dumpdir_cmp (const char *a, const char *b)
{
  size_t len;
  
  while (*a)
    switch (*a)
      {
      case 'Y':
      case 'N':
	if (!strchr ("YN", *b))
	  return 1;
	if (strcmp(a + 1, b + 1))
	  return 1;
	len = strlen (a) + 1;
	a += len;
	b += len;
	break;
	
      case 'D':
	if (strcmp(a, b))
	  return 1;
	len = strlen (a) + 1;
	a += len;
	b += len;
	break;
	
      case 'R':
      case 'T':
      case 'X':
	return *b;
      }
  return *b;
}

static void
diff_dumpdir (void)
{
