       free (text);
       break;
 
+    case function_wordlist:
+      /* Get two comma-separated arguments and expand each one.  */
+      count = 0;
+      for (p = text; p < end; ++p)
+	{
+	  if (*p == startparen)
+	    ++count;
+	  else if (*p == endparen)
+	    --count;
+	  else if (*p == ',' && count <= 0)
+	    break;
+	}
+      if (p == end)
+	BADARGS ("wordlist");
+      text = expand_argument (text, p);
+
+      /* Check the first argument.  */
+      for (p2 = text; *p2 != '\0'; ++p2)
+	if (*p2 < '0' || *p2 > '9')
+	  {
+	    if (reading_filename != 0)
+	      makefile_fatal (reading_filename, *reading_lineno_ptr,
+			      "non-numeric first argument to `wordlist' function");
+	    else
+	      fatal ("non-numeric first argument to `wordlist' function");
+	  }
+      i = (unsigned int)atoi(text);
+      free (text);
+
+      /* Check the next argument */
+      for (p2 = p + 1; isblank(*p2); ++p2)
+        {}
+      count = 0;
+      for (p = p2; p < end; ++p)
+        {
+          if (*p == startparen)
+            ++count;
+          else if (*p == endparen)
+            --count;
+          else if (*p == ',' && count <= 0)
+            break;
+        }
+      if (p == end)
+        BADARGS ("wordlist");
+      text = expand_argument (p2, p);
+
+      for (p2 = text; *p2 != '\0'; ++p2)
+        if (*p2 < '0' || *p2 > '9')
+          {
+            if (reading_filename != 0)
+              makefile_fatal (reading_filename, *reading_lineno_ptr,
+                              "non-numeric second argument to `wordlist' function");
+            else
+              fatal ("non-numeric second argument to `wordlist' function");
+          }
+      j = (unsigned int)atoi(text);
+      free (text);
+
+      if (j > i)
+        j -= i;
+      else
+        {
+          unsigned int k;
+          k = j;
+          j = i - j;
+          i = k;
+        }
+      ++j;
+
+      /* Extract the requested words */
+      text = expand_argument (p + 1, end);
+      p2 = text;
+
+      while (((p = find_next_token (&p2, &len)) != 0) && --i)
+        {}
+      if (p)
+        {
+          while (--j && (find_next_token (&p2, &len) != 0))
+            {}
+          o = variable_buffer_output (o, p, p2 - p);
+        }
+
+      free (text);
+      break;
+
     case function_findstring:
       /* Get two comma-separated arguments and expand each one.  */
       count = 0;
