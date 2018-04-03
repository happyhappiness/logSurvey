
      xentry = X509_NAME_get_entry(xname,i);
      sdata = X509_NAME_ENTRY_get_data(xentry);
      if (strlen (common_name) != ASN1_STRING_length (sdata)) 
        {
          logprintf (LOG_NOTQUIET, _("\
%s: certificate common name is invalid (contains a NUL character).\n\
