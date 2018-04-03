	  /* Restore conditional state.  */
	  restore_conditionals (save);

          continue;
	}

      /* Handle the load operations.  */
      if (word1eq ("load") || word1eq ("-load"))
        {
	  /* A 'load' line specifies a dynamic object to load.  */
	  struct nameseq *files;
          int noerror = (p[0] == '-');

          /* Load ends the previous rule.  */
          record_waiting_files ();

	  p = allocated_variable_expand (p2);

          /* If no filenames, it's a no-op.  */
	  if (*p == '\0')
            {
              free (p);
              continue;
            }

	  /* Parse the list of file names.
             Don't expand archive references or strip "./"  */
	  p2 = p;
	  files = PARSE_FILE_SEQ (&p2, struct nameseq, '\0', NULL,
                                  PARSEFS_NOAR|PARSEFS_NOSTRIP);
	  free (p);

	  /* Load each file.  */
	  while (files != 0)
	    {
	      struct nameseq *next = files->next;
	      const char *name = files->name;

	      free_ns (files);
	      files = next;

              if (! load_file (&ebuf->floc, name, noerror) && ! noerror)
                fatal (&ebuf->floc, _("%s: failed to load"), name);
	    }

          continue;
        }

      /* This line starts with a tab but was not caught above because there
         was no preceding target, and the line might have been usable as a
         variable definition.  But now we know it is definitely lossage.  */
