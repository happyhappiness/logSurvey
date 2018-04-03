    options specially.  */
 
 static int check_user_specified_header PARAMS ((const char *));
+/* Forward decl */
+struct decode_item {
+  const char *name;
+  int code;
+};
+static int decode_string PARAMS ((const char *, const struct decode_item *,
+				  int, int *));
+
+#ifdef HAVE_SSL
+static int
+cmd_spec_cert_type (const char *com, const char *val, void *closure)
+{
+  static const struct decode_item choices[] = {
+    { "pem", cert_type_pem },
+    { "asn1", cert_type_asn1 },
+  };
+  int ok = decode_string (val, choices, countof (choices), closure);
+  if (!ok)
+    fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"), exec_name, com, val);
+  return ok;
+}
+#endif
 
 static int
 cmd_spec_dirstruct (const char *com, const char *val, void *closure)
