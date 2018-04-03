       struct cookie *c;
 
       test_count = 0;
-      c = parse_set_cookies (data, test_parse_cookies_callback, 1);
+      c = parse_set_cookies (data, test_parse_cookies_callback, true);
       if (!c)
 	{
 	  printf ("NULL cookie returned for valid data: %s\n", data);
