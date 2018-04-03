    }

  /* Try to not encode in UTF-8 if fetching failed */
  if (!(*dt & RETROKF) && get_utf8_encode ())
    {
      set_utf8_encode (false);
      /*printf ("[Fallbacking to non-utf8 for `%s'\n", url);*/
      goto second_try;
    }
