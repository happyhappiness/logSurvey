   if (value <= (negative ? minus_minval : maxval))
     return negative ? -value : value;
 
- out_of_range:
   if (type)
-    ERROR ((0, 0, _("Numeric value `%.*s' is out of range for %s"),
-	    (int) digs, where0, type));
+    {
+      char minval_buf[UINTMAX_STRSIZE_BOUND + 1];
+      char maxval_buf[UINTMAX_STRSIZE_BOUND];
+      char value_buf[UINTMAX_STRSIZE_BOUND + 1];
+      char *minval_string = STRINGIFY_BIGINT (minus_minval, minval_buf + 1);
+      char *value_string = STRINGIFY_BIGINT (value, value_buf + 1);
+      if (negative)
+	*--value_string = '-';
+      if (minus_minval)
+	*--minval_string = '-';
+      ERROR ((0, 0, _("Archive value %s is out of %s range %s..%s"),
+	      value_string, type,
+	      minval_string, STRINGIFY_BIGINT (maxval, maxval_buf)));
+    }
+
   return -1;
 }
 
