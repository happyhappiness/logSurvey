   return res;
 }
 #endif
+
+#if 0
+/* Debugging and testing support for path_simplify. */
+
+/* Debug: run path_simplify on PATH and return the result in a new
+   string.  Useful for calling from the debugger.  */
+static char *
+ps (char *path)
+{
+  char *copy = xstrdup (path);
+  path_simplify (copy);
+  return copy;
+}
+
+static void
+run_test (char *test, char *expected_result, int expected_change)
+{
+  char *test_copy = xstrdup (test);
+  int modified = path_simplify (test_copy);
+
+  if (0 != strcmp (test_copy, expected_result))
+    {
+      printf ("Failed path_simplify(\"%s\"): expected \"%s\", got \"%s\".\n",
+	      test, expected_result, test_copy);
+    }
+  if (modified != expected_change)
+    {
+      if (expected_change == 1)
+	printf ("Expected no modification with path_simplify(\"%s\").\n",
+		test);
+      else
+	printf ("Expected modification with path_simplify(\"%s\").\n",
+		test);
+    }
+  xfree (test_copy);
+}
+
+static void
+test_path_simplify (void)
+{
+  static struct {
+    char *test, *result;
+    int should_modify;
+  } tests[] = {
+    { "",		"",		0 },
+    { ".",		"",		1 },
+    { "..",		"",		1 },
+    { "foo",		"foo",		0 },
+    { "foo/bar",	"foo/bar",	0 },
+    { "foo///bar",	"foo/bar",	1 },
+    { "foo/.",		"foo/",		1 },
+    { "foo/./",		"foo/",		1 },
+    { "foo./",		"foo./",	0 },
+    { "foo/../bar",	"bar",		1 },
+    { "foo/../bar/",	"bar/",		1 },
+    { "foo/bar/..",	"foo/",		1 },
+    { "foo/bar/../x",	"foo/x",	1 },
+    { "foo/bar/../x/",	"foo/x/",	1 },
+    { "foo/..",		"",		1 },
+    { "foo/../..",	"",		1 },
+    { "a/b/../../c",	"c",		1 },
+    { "./a/../b",	"b",		1 }
+  };
+  int i;
+
+  for (i = 0; i < ARRAY_SIZE (tests); i++)
+    {
+      char *test = tests[i].test;
+      char *expected_result = tests[i].result;
+      int   expected_change = tests[i].should_modify;
+      run_test (test, expected_result, expected_change);
+    }
+
+  /* Now run all the tests with a leading slash before the test case,
+     to prove that the slash is being preserved.  */
+  for (i = 0; i < ARRAY_SIZE (tests); i++)
+    {
+      char *test, *expected_result;
+      int expected_change = tests[i].should_modify;
+
+      test = xmalloc (1 + strlen (tests[i].test) + 1);
+      sprintf (test, "/%s", tests[i].test);
+
+      expected_result = xmalloc (1 + strlen (tests[i].result) + 1);
+      sprintf (expected_result, "/%s", tests[i].result);
+
+      run_test (test, expected_result, expected_change);
+
+      xfree (test);
+      xfree (expected_result);
+    }
+}
+#endif
