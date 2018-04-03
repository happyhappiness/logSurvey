  /* look one last time after reading all Makefiles */
  if (no_default_sh_exe)
    no_default_sh_exe = !find_and_set_default_shell(NULL);
#endif /* WINDOWS32 */

#if defined (__MSDOS__) || defined (__EMX__)
