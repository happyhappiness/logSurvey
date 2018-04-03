 
       /* Check the next argument */
       for (p2 = p + 1; isblank(*p2); ++p2)
-        {}
+	{}
       count = 0;
       for (p = p2; p < end; ++p)
-        {
-          if (*p == startparen)
-            ++count;
-          else if (*p == endparen)
-            --count;
-          else if (*p == ',' && count <= 0)
-            break;
-        }
+	{
+	  if (*p == startparen)
+	    ++count;
+	  else if (*p == endparen)
+	    --count;
+	  else if (*p == ',' && count <= 0)
+	    break;
+	}
       if (p == end)
-        BADARGS ("wordlist");
+	BADARGS ("wordlist");
       text = expand_argument (p2, p);
 
       for (p2 = text; *p2 != '\0'; ++p2)
-        if (*p2 < '0' || *p2 > '9')
-          {
-            if (reading_filename != 0)
-              makefile_fatal (reading_filename, *reading_lineno_ptr,
-                              "non-numeric second argument to `wordlist' function");
-            else
-              fatal ("non-numeric second argument to `wordlist' function");
-          }
+	if (*p2 < '0' || *p2 > '9')
+	  {
+	    if (reading_filename != 0)
+	      makefile_fatal (reading_filename, *reading_lineno_ptr,
+			      "non-numeric second argument to `wordlist' function");
+	    else
+	      fatal ("non-numeric second argument to `wordlist' function");
+	  }
       j = (unsigned int)atoi(text);
       free (text);
 
       if (j > i)
-        j -= i;
+	j -= i;
       else
-        {
-          unsigned int k;
-          k = j;
-          j = i - j;
-          i = k;
-        }
+	{
+	  unsigned int k;
+	  k = j;
+	  j = i - j;
+	  i = k;
+	}
       ++j;
 
       /* Extract the requested words */
