      printf ("%s (user)\n%s", user_wgetrc, prefix_spaces);
      xfree (user_wgetrc);
    }
#ifdef SYSTEM_WGETRC
  printf ("%s (system)\n", SYSTEM_WGETRC);
#endif

  format_and_print_line (strdup (locale_title),
			 strdup (LOCALEDIR), 
			 max_chars_per_line);
  
  format_and_print_line (strdup (compile_title),
