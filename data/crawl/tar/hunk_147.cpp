 
 
 /* Implementations */
+
+static void
+out_of_range_header (char const *keyword, char const *value,
+		     uintmax_t minus_minval, uintmax_t maxval)
+{
+  char minval_buf[UINTMAX_STRSIZE_BOUND + 1];
+  char maxval_buf[UINTMAX_STRSIZE_BOUND];
+  char *minval_string = umaxtostr (minus_minval, minval_buf + 1);
+  char *maxval_string = umaxtostr (maxval, maxval_buf);
+  if (minus_minval)
+    *--minval_string = '-';
+
+  /* TRANSLATORS: The first %s is the pax extended header keyword
+     (atime, gid, etc.).  */
+  ERROR ((0, 0, _("Extended header %s=%s is out of range %s..%s"),
+	  keyword, value, minval_string, maxval_string));
+}
+
 static void
 code_string (char const *string, char const *keyword, struct xheader *xhdr)
 {
