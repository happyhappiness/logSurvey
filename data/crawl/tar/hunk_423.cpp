 }
 
 /*------------------------------------------------------------------------.
-| Quick and dirty octal conversion.  Result is -1 if the field is invalid |
-| (all blank, or nonoctal).						  |
+| Convert buffer at WHERE0 of size DIGS from external format to uintmax_t.|
+| The data is of type TYPE.  The buffer must represent a value in the     |
+| range -MINUS_MINVAL through MAXVAL.					  |
 `------------------------------------------------------------------------*/
 
 static uintmax_t
-from_oct (const char *where0, size_t digs0, const char *type, uintmax_t maxval)
+from_chars (char const *where0, size_t digs, char const *type,
+	    uintmax_t minus_minval, uintmax_t maxval)
 {
   uintmax_t value;
-  const char *where = where0;
-  size_t digs = digs0;
+  char const *where = where0;
+  char const *lim = where + digs;
+  int negative = 0;
 
   for (;;)
     {
-      if (digs == 0)
+      if (where == lim)
 	{
 	  if (type)
-	    ERROR ((0, 0, _("Blanks in header where octal %s value expected"),
+	    ERROR ((0, 0,
+		    _("Blanks in header where numeric %s value expected"),
 		    type));
 	  return -1;
 	}
       if (!ISSPACE ((unsigned char) *where))
 	break;
       where++;
-      digs--;
     }
 
   value = 0;
-  while (digs != 0 && ISODIGIT (*where))
+  if (ISODIGIT (*where))
     {
-      /* Scan til nonoctal.  */
+      do
+	{
+	  if (value << LG_8 >> LG_8 != value)
+	    goto out_of_range;
+	  value = (value << LG_8) | (*where++ - '0');
+	}
+      while (where != lim && ISODIGIT (*where));
 
-      if (value << 3 >> 3 != value)
-	goto out_of_range;
-      value = (value << 3) | (*where++ - '0');
-      --digs;
+      /* Parse the output of older tars, which output negative values
+	 in two's complement octal.  This method works only if the
+	 type has the same number of bits as it did on the host that
+	 created the tar file, but that's the best we can do.  */
+      if (maxval < value && value - maxval <= minus_minval)
+	{
+	  value = minus_minval - (value - maxval);
+	  negative = 1;
+	}
+    }
+  else if (*where == '-' || *where == '+')
+    {
+      int dig;
+      negative = *where++ == '-';
+      while (where != lim
+	     && (dig = base64_map[(unsigned char) *where]) < 64)
+	{
+	  if (value << LG_64 >> LG_64 != value)
+	    goto out_of_range;
+	  value = (value << LG_64) | dig;
+	  where++;
+	}
     }
 
-  if (digs != 0 && *where && !ISSPACE ((unsigned char) *where))
+  if (where != lim && *where && !ISSPACE ((unsigned char) *where))
     {
       if (type)
 	{
