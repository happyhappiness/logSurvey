     - Ensure that ASN1 strings from the certificate are encoded as
       UTF-8 which can be meaningfully compared to HOST.  */

  common_name[0] = '\0';
  X509_NAME_get_text_by_NID (X509_get_subject_name (cert),
                             NID_commonName, common_name, sizeof (common_name));
  if (!pattern_match (common_name, host))
    {
      logprintf (LOG_NOTQUIET, _("\
