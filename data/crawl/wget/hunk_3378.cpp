   hash_table_destroy (jar->chains_by_domain);
   xfree (jar);
 }
+
+/* Test cases.  Currently this is only tests parse_set_cookies.  To
+   use, recompile Wget with -DTEST_COOKIES and call test_cookies()
+   from main.  */
+
+#ifdef TEST_COOKIES
+int test_count;
+char *test_results[10];
+
+static int test_parse_cookies_callback (struct cookie *ignored,
+					const char *nb, const char *ne,
+					const char *vb, const char *ve)
+{
+  test_results[test_count++] = strdupdelim (nb, ne);
+  test_results[test_count++] = strdupdelim (vb, ve);
+  return 1;
+}
+
+void
+test_cookies (void)
+{
+  /* Tests expected to succeed: */
+  static struct {
+    char *data;
+    char *results[10];
+  } tests_succ[] = {
+    { "", {NULL} },
+    { "arg=value", {"arg", "value", NULL} },
+    { "arg1=value1;arg2=value2", {"arg1", "value1", "arg2", "value2", NULL} },
+    { "arg1=value1; arg2=value2", {"arg1", "value1", "arg2", "value2", NULL} },
+    { "arg1=value1;  arg2=value2;", {"arg1", "value1", "arg2", "value2", NULL} },
+    { "arg1=value1;  arg2=value2;  ", {"arg1", "value1", "arg2", "value2", NULL} },
+    { "arg1=\"value1\"; arg2=\"\"", {"arg1", "value1", "arg2", "", NULL} },
+    { "arg=", {"arg", "", NULL} },
+    { "arg1=; arg2=", {"arg1", "", "arg2", "", NULL} },
+    { "arg1 = ; arg2= ", {"arg1", "", "arg2", "", NULL} },
+  };
+
+  /* Tests expected to fail: */
+  static char *tests_fail[] = {
+    ";",
+    "arg=\"unterminated",
+    "=empty-name",
+    "arg1=;=another-empty-name",
+  };
+  int i;
+
+  for (i = 0; i < ARRAY_SIZE (tests_succ); i++)
+    {
+      int ind;
+      char *data = tests_succ[i].data;
+      char **expected = tests_succ[i].results;
+      struct cookie *c;
+
+      test_count = 0;
+      c = parse_set_cookies (data, test_parse_cookies_callback, 1);
+      if (!c)
+	{
+	  printf ("NULL cookie returned for valid data: %s\n", data);
+	  continue;
+	}
+
+      for (ind = 0; ind < test_count; ind += 2)
+	{
+	  if (!expected[ind])
+	    break;
+	  if (0 != strcmp (expected[ind], test_results[ind]))
+	    printf ("Invalid name %d for '%s' (expected '%s', got '%s')\n",
+		    ind / 2 + 1, data, expected[ind], test_results[ind]);
+	  if (0 != strcmp (expected[ind + 1], test_results[ind + 1]))
+	    printf ("Invalid value %d for '%s' (expected '%s', got '%s')\n",
+		    ind / 2 + 1, data, expected[ind + 1], test_results[ind + 1]);
+	}
+      if (ind < test_count || expected[ind])
+	printf ("Unmatched number of results: %s\n", data);
+    }
+
+  for (i = 0; i < ARRAY_SIZE (tests_fail); i++)
+    {
+      struct cookie *c;
+      char *data = tests_fail[i];
+      test_count = 0;
+      c = parse_set_cookies (data, test_parse_cookies_callback, 1);
+      if (c)
+	printf ("Failed to report error on invalid data: %s\n", data);
+    }
+}
+#endif /* TEST_COOKIES */
