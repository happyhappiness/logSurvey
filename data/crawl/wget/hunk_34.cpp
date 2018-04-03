   else
     src = host;
 
-  if (!_utf8_is_valid (src))
-    {
-      logprintf (LOG_VERBOSE, _("Invalid UTF-8 sequence: %s\n"),
-                 quote (src));
-      xfree (utf8_encoded);
-      return NULL;
-    }
-
 #if IDN2_VERSION_NUMBER >= 0x00140000
   /* IDN2_TRANSITIONAL implies input NFC encoding */
   if ((ret = idn2_lookup_u8 (src, (uint8_t **) &ascii_encoded, IDN2_TRANSITIONAL)) != IDN2_OK)
