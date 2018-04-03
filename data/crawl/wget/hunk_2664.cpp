   for (i = 0; i < countof (tests_succ); i++)
     {
       int ind;
-      char *data = tests_succ[i].data;
-      char **expected = tests_succ[i].results;
+      const char *data = tests_succ[i].data;
+      const char **expected = tests_succ[i].results;
       struct cookie *c;
 
-      test_count = 0;
-      c = parse_set_cookies (data, test_parse_cookies_callback, true);
+      c = parse_set_cookie (data, true);
       if (!c)
 	{
 	  printf ("NULL cookie returned for valid data: %s\n", data);
 	  continue;
 	}
 
-      for (ind = 0; ind < test_count; ind += 2)
-	{
-	  if (!expected[ind])
-	    break;
-	  if (0 != strcmp (expected[ind], test_results[ind]))
-	    printf ("Invalid name %d for '%s' (expected '%s', got '%s')\n",
-		    ind / 2 + 1, data, expected[ind], test_results[ind]);
-	  if (0 != strcmp (expected[ind + 1], test_results[ind + 1]))
-	    printf ("Invalid value %d for '%s' (expected '%s', got '%s')\n",
-		    ind / 2 + 1, data, expected[ind + 1], test_results[ind + 1]);
-	}
-      if (ind < test_count || expected[ind])
-	printf ("Unmatched number of results: %s\n", data);
+      /* Test whether extract_param handles these cases correctly. */
+      {
+	param_token name, value;
+	const char *ptr = data;
+	int j = 0;
+	while (extract_param (&ptr, &name, &value))
+	  {
+	    char *n = strdupdelim (name.b, name.e);
+	    char *v = strdupdelim (value.b, value.e);
+	    if (!expected[j])
+	      {
+		printf ("Too many parameters for '%s'\n", data);
+		break;
+	      }
+	    if (0 != strcmp (expected[j], n))
+	      printf ("Invalid name %d for '%s' (expected '%s', got '%s')\n",
+		      j / 2 + 1, data, expected[j], n);
+	    if (0 != strcmp (expected[j + 1], v))
+	      printf ("Invalid value %d for '%s' (expected '%s', got '%s')\n",
+		      j / 2 + 1, data, expected[j + 1], v);
+	    j += 2;
+	    free (n);
+	    free (v);
+	  }
+	if (expected[j])
+	  printf ("Too few parameters for '%s'\n", data);
+      }
     }
 
   for (i = 0; i < countof (tests_fail); i++)
     {
       struct cookie *c;
       char *data = tests_fail[i];
-      test_count = 0;
-      c = parse_set_cookies (data, test_parse_cookies_callback, 1);
+      c = parse_set_cookie (data, true);
       if (c)
 	printf ("Failed to report error on invalid data: %s\n", data);
     }
