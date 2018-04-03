    }

  /* Try to not encode in UTF-8 if fetching failed */
  if (!(*dt & RETROKF) && utf8_encoded)
    {
      utf8_encoded = false;
      /*printf ("[Fallbacking to non-utf8 for `%s'\n", url);*/
      goto second_try;
    }
