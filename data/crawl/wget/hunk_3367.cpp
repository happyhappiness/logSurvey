   return 1;
 }
 
-/* Set the value stored in VAL to CLOSURE (which should point to a
-   long int), allowing several postfixes, with the following syntax
-   (regexp):
+/* Poor man's atof: handles only <digits>.<digits>.  Returns 1 on
+   success, 0 on failure.  In case of success, stores its result to
+   *DEST.  */
 
-   [0-9]+       -> bytes
-   [0-9]+[kK]   -> bytes * 1024
-   [0-9]+[mM]   -> bytes * 1024 * 1024
-   inf          -> 0
+static int
+simple_atof (const char *beg, const char *end, double *dest)
+{
+  double result = 0;
+
+  int seen_dot = 0;
+  int seen_digit = 0;
+  double divider = 1;
+
+  const char *p = beg;
+
+  while (p < end)
+    {
+      char ch = *p++;
+      if (ISDIGIT (ch))
+	{
+	  if (!seen_dot)
+	    result = (10 * result) + (ch - '0');
+	  else
+	    result += (ch - '0') / (divider *= 10);
+	  seen_digit = 1;
+	}
+      else if (ch == '.')
+	{
+	  if (!seen_dot)
+	    seen_dot = 1;
+	  else
+	    return 0;
+	}
+    }
+  if (!seen_digit)
+    return 0;
+
+  *dest = result;
+  return 1;
+}
+
+/* Parse VAL as a number and set its value to CLOSURE (which should
+   point to a long int).
+
+   By default, the value is assumed to be in bytes.  If "K", "M", or
+   "G" are appended, the value is multiplied with 1<<10, 1<<20, or
+   1<<30, respectively.  Floating point values are allowed and are
+   cast to integer before use.  The idea is to be able to use things
+   like 1.5k instead of "1536".
+
+   The string "inf" is returned as 0.
+
+   In case of error, 0 is returned and memory pointed to by CLOSURE
+   remains unmodified.  */
 
-   Anything else is flagged as incorrect, and CLOSURE is unchanged.  */
 static int
 cmd_bytes (const char *com, const char *val, void *closure)
 {
-  long result;
-  long *out = (long *)closure;
-  const char *p;
+  long mult;
+  double number;
+  const char *end = val + strlen (val);
 
-  result = 0;
-  p = val;
   /* Check for "inf".  */
-  if (p[0] == 'i' && p[1] == 'n' && p[2] == 'f' && p[3] == '\0')
+  if (0 == strcmp (val, "inf"))
     {
-      *out = 0;
+      *(long *)closure = 0;
       return 1;
     }
-  /* Search for digits and construct result.  */
-  for (; *p && ISDIGIT (*p); p++)
-    result = (10 * result) + (*p - '0');
-  /* If no digits were found, or more than one character is following
-     them, bail out.  */
-  if (p == val || (*p != '\0' && *(p + 1) != '\0'))
+
+  /* Strip trailing whitespace.  */
+  while (val < end && ISSPACE (end[-1]))
+    --end;
+
+  if (val == end)
     {
-      printf (_("%s: Invalid specification `%s'\n"), com, val);
+    err:
+      fprintf (stderr, _("%s: Invalid byte value `%s'\n"), com, val);
       return 0;
     }
-  /* Search for a designator.  */
-  switch (TOLOWER (*p))
+
+  switch (TOLOWER (end[-1]))
     {
-    case '\0':
-      /* None */
-      break;
     case 'k':
-      /* Kilobytes */
-      result *= 1024;
+      --end, mult = 1L<<10;
       break;
     case 'm':
-      /* Megabytes */
-      result *= (long)1024 * 1024;
+      --end, mult = 1L<<20;
       break;
     case 'g':
-      /* Gigabytes */
-      result *= (long)1024 * 1024 * 1024;
+      --end, mult = 1L<<30;
       break;
     default:
-      printf (_("%s: Invalid specification `%s'\n"), com, val);
-      return 0;
+      /* Not a recognized suffix: assume it belongs to the number.
+	 (If not, atof simple_atof will raise an error.)  */
+      mult = 1;
     }
-  *out = result;
+
+  /* Skip leading and trailing whitespace. */
+  while (val < end && ISSPACE (*val))
+    ++val;
+  while (val < end && ISSPACE (end[-1]))
+    --end;
+  if (val == end)
+    goto err;
+
+  if (!simple_atof (val, end, &number))
+    goto err;
+
+  *(long *)closure = (long)(number * mult);
   return 1;
 }
 
