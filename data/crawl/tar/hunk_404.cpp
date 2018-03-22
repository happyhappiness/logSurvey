 	  char *sub_string = STRINGIFY_BIGINT (s, buf3 + 1);
 	  if (negsub)
 	    *--sub_string = '-';
-	  WARN ((0, 0, _("%s value %s out of range %s..%s; substituting %s"),
-		 type, value_string, minval_string, maxval_string,
+	  WARN ((0, 0, _("value %s out of %s range %s..%s; substituting %s"),
+		 value_string, type, minval_string, maxval_string,
 		 sub_string));
-	  to_chars (negsub, s, valsize, NULL, where, size, type);
+	  to_chars (negsub, s, valsize, 0, where, size, type);
 	}
       else
-	ERROR ((0, 0, _("%s value %s out of range %s..%s"),
-		type, value_string, minval_string, maxval_string));
+	ERROR ((0, 0, _("value %s out of %s range %s..%s"),
+		value_string, type, minval_string, maxval_string));
     }
 }
 
