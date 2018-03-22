    SUBSTITUTE the address of an 0-or-1 flag recording whether the
    substitute value is negative.  */
 
-static void
+static bool
 to_chars (int negative, uintmax_t value, size_t valsize,
 	  uintmax_t (*substitute) (int *),
 	  char *where, size_t size, const char *type)
 {
-  int base256_allowed = (archive_format == GNU_FORMAT
-			 || archive_format == OLDGNU_FORMAT);
+  int gnu_format = (archive_format == GNU_FORMAT
+		    || archive_format == OLDGNU_FORMAT);
 
   /* Generate the POSIX octal representation if the number fits.  */
   if (! negative && value <= MAX_VAL_WITH_DIGITS (size - 1, LG_8))
     {
       where[size - 1] = '\0';
       to_octal (value, where, size - 1);
+      return true;
     }
-
-  /* Otherwise, generate the base-256 representation if we are
-     generating an old or new GNU format and if the number fits.  */
-  else if (((negative ? -1 - value : value)
-	    <= MAX_VAL_WITH_DIGITS (size - 1, LG_256))
-	   && base256_allowed)
-    {
-      where[0] = negative ? -1 : 1 << (LG_256 - 1);
-      to_base256 (negative, value, where + 1, size - 1);
-    }
-
-  /* Otherwise, if the number is negative, and if it would not cause
-     ambiguity on this host by confusing positive with negative
-     values, then generate the POSIX octal representation of the value
-     modulo 2**(field bits).  The resulting tar file is
-     machine-dependent, since it depends on the host word size.  Yuck!
-     But this is the traditional behavior.  */
-  else if (negative && valsize * CHAR_BIT <= (size - 1) * LG_8)
-    {
-      static int warned_once;
-      if (! warned_once)
-	{
-	  warned_once = 1;
-	  WARN ((0, 0, _("Generating negative octal headers")));
-	}
-      where[size - 1] = '\0';
-      to_octal (value & MAX_VAL_WITH_DIGITS (valsize * CHAR_BIT, 1),
-		where, size - 1);
-    }
-
-  /* Otherwise, output a substitute value if possible (with a
-     warning), and an error message if not.  */
-  else
+  else if (gnu_format)
     {
-      uintmax_t maxval = (base256_allowed
-			  ? MAX_VAL_WITH_DIGITS (size - 1, LG_256)
-			  : MAX_VAL_WITH_DIGITS (size - 1, LG_8));
-      char valbuf[UINTMAX_STRSIZE_BOUND + 1];
-      char maxbuf[UINTMAX_STRSIZE_BOUND];
-      char minbuf[UINTMAX_STRSIZE_BOUND + 1];
-      char const *minval_string;
-      char const *maxval_string = STRINGIFY_BIGINT (maxval, maxbuf);
-      char const *value_string;
-
-      if (base256_allowed)
-	{
-	  uintmax_t m = maxval + 1 ? maxval + 1 : maxval / 2 + 1;
-	  char *p = STRINGIFY_BIGINT (m, minbuf + 1);
-	  *--p = '-';
-	  minval_string = p;
-	}
-      else
-	minval_string = "0";
+      /* Try to cope with the number by using traditional GNU format
+	 methods */
 
-      if (negative)
+      /* Generate the base-256 representation if the number fits.  */
+      if (((negative ? -1 - value : value)
+	   <= MAX_VAL_WITH_DIGITS (size - 1, LG_256)))
 	{
-	  char *p = STRINGIFY_BIGINT (- value, valbuf + 1);
-	  *--p = '-';
-	  value_string = p;
+	  where[0] = negative ? -1 : 1 << (LG_256 - 1);
+	  to_base256 (negative, value, where + 1, size - 1);
+	  return true;
 	}
-      else
-	value_string = STRINGIFY_BIGINT (value, valbuf);
 
-      if (substitute)
+      /* Otherwise, if the number is negative, and if it would not cause
+	 ambiguity on this host by confusing positive with negative
+	 values, then generate the POSIX octal representation of the value
+	 modulo 2**(field bits).  The resulting tar file is
+	 machine-dependent, since it depends on the host word size.  Yuck!
+	 But this is the traditional behavior.  */
+      else if (negative && valsize * CHAR_BIT <= (size - 1) * LG_8)
 	{
-	  int negsub;
-	  uintmax_t sub = substitute (&negsub) & maxval;
-	  /* FIXME: This is the only place where GNU_FORMAT differs from
-             OLDGNU_FORMAT. Apart from this they are completely identical. */
-	  uintmax_t s = (negsub &= archive_format == GNU_FORMAT) ? - sub : sub;
-	  char subbuf[UINTMAX_STRSIZE_BOUND + 1];
-	  char *sub_string = STRINGIFY_BIGINT (s, subbuf + 1);
-	  if (negsub)
-	    *--sub_string = '-';
-	  WARN ((0, 0, _("value %s out of %s range %s..%s; substituting %s"),
-		 value_string, type, minval_string, maxval_string,
-		 sub_string));
-	  to_chars (negsub, s, valsize, 0, where, size, type);
+	  static int warned_once;
+	  if (! warned_once)
+	    {
+	      warned_once = 1;
+	      WARN ((0, 0, _("Generating negative octal headers")));
+	    }
+	  where[size - 1] = '\0';
+	  to_octal (value & MAX_VAL_WITH_DIGITS (valsize * CHAR_BIT, 1),
+		    where, size - 1);
+	  return true;
 	}
-      else
-	ERROR ((0, 0, _("value %s out of %s range %s..%s"),
-		value_string, type, minval_string, maxval_string));
+      /* Otherwise fall back to substitution, if possible: */
     }
+  else
+    substitute = NULL; /* No substitution for formats, other than GNU */
+  
+  return to_chars_subst (negative, gnu_format, value, valsize, substitute,
+			 where, size, type);
 }
 
 static uintmax_t
