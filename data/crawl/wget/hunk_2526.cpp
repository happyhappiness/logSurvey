       char *data = tests_fail[i];
       c = parse_set_cookie (data, true);
       if (c)
-	printf ("Failed to report error on invalid data: %s\n", data);
+        printf ("Failed to report error on invalid data: %s\n", data);
     }
 }
 #endif /* TEST_COOKIES */
