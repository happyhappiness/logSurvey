        }
      return xstrdup (env);
    }

  /* If that failed, try $HOME/.wgetrc.  */
  home = home_dir ();
  if (home)
    file = aprintf ("%s/.wgetrc", home);
  xfree_null (home);

#ifdef WINDOWS
  /* Under Windows, if we still haven't found .wgetrc, look for the file
