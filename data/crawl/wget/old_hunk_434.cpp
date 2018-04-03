     - Ensure that ASN1 strings from the certificate are encoded as
       UTF-8 which can be meaningfully compared to HOST.  */

  X509_NAME *xname = X509_get_subject_name(cert);
  common_name[0] = '\0';
  X509_NAME_get_text_by_NID (xname, NID_commonName, common_name,
                             sizeof (common_name));

  if (!pattern_match (common_name, host))
    {
      logprintf (LOG_NOTQUIET, _("\
%s: certificate common name %s doesn't match requested host name %s.\n"),
                 severity, quote_n (0, common_name), quote_n (1, host));
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


