     - Ensure that ASN1 strings from the certificate are encoded as
       UTF-8 which can be meaningfully compared to HOST.  */

  subjectAltNames = X509_get_ext_d2i (cert, NID_subject_alt_name, NULL, NULL);

  if (subjectAltNames)
    {
      /* Test subject alternative names */

      /* Do we want to check for dNSNAmes or ipAddresses (see RFC 2818)?
       * Signal it by host_in_octet_string. */
      ASN1_OCTET_STRING *host_in_octet_string = NULL;
      host_in_octet_string = a2i_IPADDRESS (host);

      int numaltnames = sk_GENERAL_NAME_num (subjectAltNames);
      int i;
      for (i=0; i < numaltnames; i++)
        {
          const GENERAL_NAME *name =
            sk_GENERAL_NAME_value (subjectAltNames, i);
          if (name)
            {
              if (host_in_octet_string)
                {
                  if (name->type == GEN_IPADD)
                    {
                      /* Check for ipAddress */
                      /* TODO: Should we convert between IPv4-mapped IPv6
                       * addresses and IPv4 addresses? */
                      alt_name_checked = true;
                      if (!ASN1_STRING_cmp (host_in_octet_string,
                            name->d.iPAddress))
                        break;
                    }
                }
              else if (name->type == GEN_DNS)
                {
                  /* Check for dNSName */
                  alt_name_checked = true;
                  /* dNSName should be IA5String (i.e. ASCII), however who
                   * does trust CA? Convert it into UTF-8 for sure. */
                  unsigned char *name_in_utf8 = NULL;
                  if (0 <= ASN1_STRING_to_UTF8 (&name_in_utf8, name->d.dNSName))
                    {
                      /* Compare and check for NULL attack in ASN1_STRING */
                      if (pattern_match ((char *)name_in_utf8, host) &&
                            (strlen ((char *)name_in_utf8) ==
                                ASN1_STRING_length (name->d.dNSName)))
                        {
                          OPENSSL_free (name_in_utf8);
                          break;
                        }
                      OPENSSL_free (name_in_utf8);
                    }
                }
            }
        }
      sk_GENERAL_NAME_free (subjectAltNames);
      if (host_in_octet_string)
        ASN1_OCTET_STRING_free(host_in_octet_string);

      if (alt_name_checked == true && i >= numaltnames)
        {
          logprintf (LOG_NOTQUIET,
              _("%s: no certificate subject alternative name matches\n"
                "\trequested host name %s.\n"),
                     severity, quote_n (1, host));
          success = false;
        }
    }
  
  if (alt_name_checked == false)
    {
      /* Test commomName */
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
          /* We now determine the length of the ASN1 string. If it
           * differs from common_name's length, then there is a \0
           * before the string terminates.  This can be an instance of a
           * null-prefix attack.
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
    }


