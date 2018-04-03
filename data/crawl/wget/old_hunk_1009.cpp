  if (!(*dt & RETROKF) && iri->utf8_encode)
    {
      iri->utf8_encode = false;
      printf ("[Fallbacking to non-utf8 for `%s'\n", url);
      goto second_try;
    }

