   return 1;
 }
 
+#ifdef HAVE_SSL
+static int
+cmd_spec_secure_protocol (const char *com, const char *val, void *closure)
+{
+  static const struct decode_item choices[] = {
+    { "auto", secure_protocol_auto },
+    { "sslv2", secure_protocol_sslv2 },
+    { "sslv3", secure_protocol_sslv3 },
+    { "tlsv1", secure_protocol_tlsv1 },
+  };
+  int ok = decode_string (val, choices, countof (choices), closure);
+  if (!ok)
+    fprintf (stderr, _("%s: %s: Invalid value `%s'.\n"), exec_name, com, val);
+  return ok;
+}
+#endif
+
 /* Set all three timeout values. */
 
 static int
