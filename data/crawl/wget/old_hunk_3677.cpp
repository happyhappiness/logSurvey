  if (H_20X (statcode))
    *dt |= RETROKF;

  if (type && !strncasecmp (type, TEXTHTML_S, strlen (TEXTHTML_S)))
    *dt |= TEXTHTML;
  else
