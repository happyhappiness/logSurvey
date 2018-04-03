    ++line;
  if (*line == '\0')
    return 0;
#endif

#if defined(__MSDOS__) || defined(WIN32)
#ifdef WIN32
   /*
    * only come here if no sh.exe command
    */
   if (no_default_sh_exe)
#endif
   {
     FILE *batch;
     dos_batch_file = 1;
     if (dos_bname == 0)
       {
	 dos_bname = tempnam (".", "mk");
	 for (i = 0; dos_bname[i] != '\0'; ++i)
	   if (dos_bname[i] == '/')
	     dos_bname[i] = '\\';
	 dos_bename = (char *) xmalloc (strlen (dos_bname) + 5);
	 strcpy (dos_bename, dos_bname);
	 strcat (dos_bname, ".bat");
	 strcat (dos_bename, ".err");
       }
     batch = fopen (dos_bename, "w"); /* Create a file.  */
     if (batch != NULL)
       fclose (batch);
     batch = fopen (dos_bname, "w");
     fputs ("@echo off\n", batch);
     fputs (line, batch);
     fprintf (batch, "\nif errorlevel 1 del %s\n", dos_bename);
     fclose (batch);
     new_argv = (char **) xmalloc(2 * sizeof(char *));
     new_argv[0] = strdup (dos_bname);
     new_argv[1] = 0;
   }
#endif /* MSDOS. */
#ifdef _AMIGA
   {
     char *ptr;
     char *buffer;
     char *dptr;

     buffer = (char *)xmalloc (strlen (line)+1);

     ptr = line;
     for (dptr=buffer; *ptr; )
     {
	if (*ptr == '\\' && ptr[1] == '\n')
	    ptr += 2;
	else if (*ptr == '@') /* Kludge: multiline commands */
	{
	    ptr += 2;
	    *dptr++ = '\n';
	}
	else
	    *dptr++ = *ptr++;
     }
     *dptr = 0;

     new_argv = (char **) xmalloc(2 * sizeof(char *));
     new_argv[0] = buffer;
     new_argv[1] = 0;
   }
#else	/* Not MSDOS or Amiga  */
#ifdef WIN32
  /*
   * This is technically an else to the above 'if (no_default_sh_exe)',
   * but (IMHO) coding if-else across ifdef is dangerous.
   */
  if (!no_default_sh_exe)
#endif
  {
    /* SHELL may be a multi-word command.  Construct a command line
       "SHELL -c LINE", with all special chars in LINE escaped.
