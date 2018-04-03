          return NULL;  /* Nothing to encode or an error occured */
    }

  /* Store in ascii_encoded the ASCII UTF-8 NULL terminated string */
  ret = idna_to_ascii_8z (utf8_encoded ? utf8_encoded : host, &ascii_encoded, IDNA_FLAGS);
  xfree (utf8_encoded);
