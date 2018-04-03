          i++;
        }
      printf ("\n");
      if (compiled_features[i] != NULL) 
        {
	  printf (prefix_spaces);
        }
    }
  /* Handle the case when $WGETRC is unset and $HOME/.wgetrc is 
     absent. */
  printf (wgetrc_title);
  env_wgetrc = wgetrc_env_file_name ();
  if (env_wgetrc && *env_wgetrc) 
    {
      printf ("%s (env)\n%s", env_wgetrc, prefix_spaces);
      xfree (env_wgetrc);
    }
  user_wgetrc = wgetrc_user_file_name ();
  if (user_wgetrc) 
    {
      printf ("%s (user)\n%s", user_wgetrc, prefix_spaces);
      xfree (user_wgetrc);
    }
#ifdef SYSTEM_WGETRC
  printf ("%s (system)\n", SYSTEM_WGETRC);
#else
  putchar ('\n');
#endif

  format_and_print_line (locale_title,
			 LOCALEDIR, 
			 max_chars_per_line);
  
  format_and_print_line (compile_title,
			 compilation_string,
			 max_chars_per_line);

  format_and_print_line (link_title,
			 link_string,
			 max_chars_per_line);

  printf ("\n");
  /* TRANSLATORS: When available, an actual copyright character
