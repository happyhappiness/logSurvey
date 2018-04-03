     char **argv;
     const char *funcname;
{
  int i=0;
  int j=0;

  /* Check the first argument.  */
  check_numeric (argv[0],
		 _("non-numeric first argument to `wordlist' function"));
  i =atoi(argv[0]);
  check_numeric (argv[1],
		 _("non-numeric second argument to `wordlist' function"));

  j = atoi(argv[1]);


  {
    char *p;
    char *end_p = argv[2];

    int start = (i < j) ? i : j;
    int count = j -i ;
    if (count < 0)
      count = - count;
    count ++;



    while (((p = find_next_token (&end_p, 0)) != 0) && --start)
      {}
    if (p)
      {
	while (--count && (find_next_token (&end_p, 0) != 0))
	  {}
	o = variable_buffer_output (o, p, end_p - p);
      }
  }
  return o;
}

static char*
func_findstring(o, argv, funcname)
     char *o;
     char **argv;
     const char *funcname;
