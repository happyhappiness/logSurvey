      free (new_argv);
    }

#ifdef __MSDOS__
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
     batch = fopen(bename, "w"); /* Create a file.  */
     if (batch != NULL)
       fclose (batch);
     batch = fopen (dos_bname, "w");
     fputs ("@echo off\n", batch);
     fputs (line, batch);
     fprintf (batch, "\nif errorlevel 1 del %s\n", dos_bename);
     fclose (batch);
     new_argv = (char **) xmalloc(2 * sizeof(char *));
     new_argv[0] = strdup (bname);
     new_argv[1] = 0;
   }
#else	/* Not MSDOS.  */
  {
    /* SHELL may be a multi-word command.  Construct a command line
       "SHELL -c LINE", with all special chars in LINE escaped.
