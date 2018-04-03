 static char *
 func_sort (char *o, char **argv, const char *funcname UNUSED)
 {
-  char **words = 0;
-  int nwords = 0;
-  register int wordi = 0;
-
-  /* Chop ARGV[0] into words and put them in WORDS.  */
-  char *t = argv[0];
+  const char *t;
+  char **words;
+  int wordi;
   char *p;
   unsigned int len;
   int i;
 
-  while ((p = find_next_token (&t, &len)) != 0)
+  /* Find the maximum number of words we'll have.  */
+  t = argv[0];
+  wordi = 1;
+  while (*t != '\0')
     {
-      if (wordi >= nwords - 1)
-	{
-	  nwords = (2 * nwords) + 5;
-	  words = xrealloc (words, nwords * sizeof (char *));
-	}
-      words[wordi++] = savestring (p, len);
+      char c = *(t++);
+
+      if (! isspace ((unsigned char)c))
+        continue;
+
+      ++wordi;
+
+      while (isspace ((unsigned char)*t))
+        ++t;
     }
 
-  if (!wordi)
-    return o;
+  words = xmalloc (wordi * sizeof (char *));
 
-  /* Now sort the list of words.  */
-  qsort (words, wordi, sizeof (char *), alpha_compare);
+  /* Now assign pointers to each string in the array.  */
+  t = argv[0];
+  wordi = 0;
+  while ((p = find_next_token (&t, &len)) != 0)
+    {
+      ++t;
+      p[len] = '\0';
+      words[wordi++] = p;
+    }
 
-  /* Now write the sorted list.  */
-  for (i = 0; i < wordi; ++i)
+  if (wordi)
     {
-      len = strlen (words[i]);
-      if (i == wordi - 1 || strlen (words[i + 1]) != len
-          || strcmp (words[i], words[i + 1]))
+      /* Now sort the list of words.  */
+      qsort (words, wordi, sizeof (char *), alpha_compare);
+
+      /* Now write the sorted list, uniquified.  */
+      for (i = 0; i < wordi; ++i)
         {
-          o = variable_buffer_output (o, words[i], len);
-          o = variable_buffer_output (o, " ", 1);
+          len = strlen (words[i]);
+          if (i == wordi - 1 || strlen (words[i + 1]) != len
+              || strcmp (words[i], words[i + 1]))
+            {
+              o = variable_buffer_output (o, words[i], len);
+              o = variable_buffer_output (o, " ", 1);
+            }
         }
-      free (words[i]);
+
+      /* Kill the last space.  */
+      --o;
     }
-  /* Kill the last space.  */
-  --o;
 
   free (words);
 
