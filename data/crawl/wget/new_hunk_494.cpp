
  X509_NAME *xname = X509_get_subject_name(cert);
  common_name[0] = '\0';
  X509_NAME_get_text_by_NID (xname, NID_commonName, common_name,
                             sizeof (common_name));

  if (!pattern_match (common_name, host))
    {
