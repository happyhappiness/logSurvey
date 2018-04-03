      file = NULL;
      home = ws_mypath ();
      if (home)
        file = aprintf ("%s/wget.ini", home);
    }
#endif /* WINDOWS */

