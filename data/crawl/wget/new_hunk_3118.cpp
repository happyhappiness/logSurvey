      return xstrdup (env);
    }

  /* If that failed, try $HOME/.wgetrc.  */
  home = home_dir ();
  if (home)
    file = aprintf ("%s/.wgetrc", home);
  xfree_null (home);

#ifdef WINDOWS
  /* Under Windows, if we still haven't found .wgetrc, look for the file
     `wget.ini' in the directory where `wget.exe' resides; we do this for
     backward compatibility with previous versions of Wget.
     SYSTEM_WGETRC should not be defined under WINDOWS.  */
  if (!file || !file_exists_p (file))
    {
      xfree_null (file);
      file = NULL;
      home = ws_mypath ();
      if (home)
	file = aprintf ("%s/wget.ini", home);
    }
#endif /* WINDOWS */

