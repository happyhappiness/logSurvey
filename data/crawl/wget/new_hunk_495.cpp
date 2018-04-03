                 severity, quote (common_name), quote (host));
      success = false;
    }
  else
    {
      /* We now determine the length of the ASN1 string. If it differs from
       * common_name's length, then there is a \0 before the string terminates.
       * This can be an instance of a null-prefix attack.
       *
       * https://www.blackhat.com/html/bh-usa-09/bh-usa-09-archives.html#Marlinspike
       * */

      int i = -1, j;
      X509_NAME_ENTRY *xentry;
      ASN1_STRING *sdata;

      if (xname) {
        for (;;)
          {
            j = X509_NAME_get_index_by_NID (xname, NID_commonName, i);
            if (j == -1) break;
            i = j;
          }
      }

      xentry = X509_NAME_get_entry(xname,i);
      sdata = X509_NAME_ENTRY_get_data(xentry);
      if (strlen (common_name) != ASN1_STRING_length (sdata)) 
        {
          logprintf (LOG_NOTQUIET, _("\
%s: certificate common name is invalid (contains a NUL character).\n\
This may be an indication that the host is not who it claims to be\n\
(that is, it is not the real %s).\n"),
                     severity, quote (host));
          success = false;
        }
    }
  

  if (success)
    DEBUGP (("X509 certificate successfully verified and matches host %s\n",
