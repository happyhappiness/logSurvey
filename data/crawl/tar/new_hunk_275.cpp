	}
      if (*arc == '\0')
	{
	  char *p = new_name (directory_name, cur);
	  if (! interactive_option || confirm ("delete", p))
	    {
	      if (verbose_option)
		fprintf (stdlis, _("%s: Deleting %s\n"),
			 program_name, quote (p));
	      if (! remove_any_file (p, 1))
		{
		  int e = errno;
		  ERROR ((0, e, _("%s: Cannot remove"), quotearg_colon (p)));
		}
	    }
	  free (p);
	}

    }
  free (current_dir);
  free (archive_dir);
}
