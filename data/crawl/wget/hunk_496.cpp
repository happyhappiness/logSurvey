      - Ensure that ASN1 strings from the certificate are encoded as
        UTF-8 which can be meaningfully compared to HOST.  */
 
+  X509_NAME *xname = X509_get_subject_name(cert);
   common_name[0] = '\0';
-  X509_NAME_get_text_by_NID (X509_get_subject_name (cert),
+  X509_NAME_get_text_by_NID (xname,
                              NID_commonName, common_name, sizeof (common_name));
+
+  /* We now determine the length of the ASN1 string. If it differs from
+   * common_name's length, then there is a \0 before the string terminates.
+   * This can be an instance of a null-prefix attack [0].
+   *
+   * [0] https://www.blackhat.com/html/bh-usa-09/bh-usa-09-archives.html#Marlinspike
+   * */
+
+  int i=-1,j;
+  if(xname) {
+	  for(;(j=X509_NAME_get_index_by_NID (xname, NID_commonName, i))!=-1;i=j);
+  }
+
+  X509_NAME_ENTRY *xentry = X509_NAME_get_entry(xname,i);
+  ASN1_STRING *sdata = X509_NAME_ENTRY_get_data(xentry);
+
+  if (strlen(common_name) != ASN1_STRING_length(sdata)) 
+    {
+      logprintf (LOG_NOTQUIET, _("\
+%s: certificate common name is invalid. It is possible that someone is \
+eavesdropping on you (man-in-the-middle attack)!\n"),
+                 severity);
+      success = false;
+    }
+
   if (!pattern_match (common_name, host))
     {
       logprintf (LOG_NOTQUIET, _("\
