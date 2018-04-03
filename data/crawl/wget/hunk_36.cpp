     {
       logprintf (LOG_VERBOSE, _("idn_encode failed (%d): %s\n"), ret,
                  quote (idn2_strerror (ret)));
-      ascii_encoded = NULL;
     }
 
   xfree (lower);
+#endif
 
-  return ascii_encoded;
+  return ret == IDN2_OK ? ascii_encoded : NULL;
 }
 
 /* Try to decode an "ASCII encoded" host. Return the new domain in the locale
