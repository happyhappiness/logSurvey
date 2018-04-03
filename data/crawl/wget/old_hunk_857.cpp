      printf ("%s (user)\n%s", user_wgetrc, prefix_spaces);
      xfree (user_wgetrc);
    }
  printf ("%s (system)\n", system_wgetrc);

  format_and_print_line (strdup (locale_title),
			 strdup (locale_dir), 
			 max_chars_per_line);
  
  format_and_print_line (strdup (compile_title),
