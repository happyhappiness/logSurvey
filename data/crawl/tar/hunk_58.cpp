 }
 
 static void
+assign_time_option (char **sval, time_t *tval, const char *input)
+{
+  uintmax_t u;
+  char *p;
+  time_t t = u = strtoumax (input, &p, 10);
+  if (t != u || *p || errno == ERANGE)
+    ERROR ((0, 0, _("Time stamp is out of allowed range")));
+  else
+    {
+      *tval = t;
+      assign_string (sval, input);
+    }
+}
+
+static void
 xheader_set_keyword_equal (char *kw, char *eq)
 {
   bool global = true;
