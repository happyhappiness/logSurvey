   return metalink_check_safe_path (basename) ? basename : NULL;
 }
 
+/*
+  Append a separator and a numeric suffix to a string.
+
+  The string is permanently modified.
+*/
+void
+append_suffix_number (char **str, const char *sep, wgint num)
+{
+  char *new, buf[24];
+
+  number_to_string (buf, num);
+  new = aprintf ("%s%s%s", *str ? *str : "", sep ? sep : "", buf);
+  xfree (*str);
+  *str = new;
+}
+
 /* Append the suffix ".badhash" to the file NAME, except without
    overwriting an existing file with that name and suffix.  */
 void
