      goto redirected;
    }

  /* Try to not encode in UTF-8 if fetching failed */
  if (result != RETROK && utf8_encoded)
    {
      utf8_encoded = false;
      /*printf ("[Fallbacking to non-utf8 for `%s'\n", url);*/
      goto second_try;
    }

  if (local_file && *dt & RETROKF)
    {
      register_download (u->url, local_file);
      if (redirection_count && 0 != strcmp (origurl, u->url))
        register_redirection (origurl, u->url);
      if (*dt & TEXTHTML)
        register_html (u->url, local_file);
    }

  if (file)
