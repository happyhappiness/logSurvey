  else
#endif /* __MSDOS__ */
#ifdef WINDOWS32
  if ((origin == o_file || origin == o_override)
      && strcmp (expanded_name, "SHELL") == 0)
    {
      extern char* default_shell;

    /*
     * Call shell locator function. If it returns TRUE, then
	 * set no_default_sh_exe to indicate sh was found and
     * set new value for SHELL variable.
	 */
      if (find_and_set_default_shell(value)) {
        v = define_variable_loc (expanded_name, strlen (expanded_name),
                                 default_shell, origin, flavor == f_recursive,
                                 flocp);
        no_default_sh_exe = 0;
      }
    }
  else
#endif

  v = define_variable_loc (expanded_name, strlen (expanded_name), value,
                           origin, flavor == f_recursive, flocp);

  v->append = append;

  if (alloc_value)
    free (alloc_value);
  free (expanded_name);

  return v;
