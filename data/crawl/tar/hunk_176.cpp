 	*--value_string = '-';
       if (minus_minval)
 	*--minval_string = '-';
-      ERROR ((0, 0, _("Archive value %s is out of %s range %s.%s"),
+      /* TRANSLATORS: Second %s is type name (gid_t,uid_t,etc.) */
+      ERROR ((0, 0, _("Archive value %s is out of %s range %s..%s"),
 	      value_string, type,
 	      minval_string, STRINGIFY_BIGINT (maxval, maxval_buf)));
     }
