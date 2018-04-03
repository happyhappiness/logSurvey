 	{
 	  p = p2 + len;
 #ifdef VMS
-	  while (p >= p2 && *p != (function == function_dir ? ']' : '.'))
+	  while (p >= p2 && *p != ']'
+                 && (function != function_basename || *p != '.'))
 #else
-	  while (p >= p2 && *p != (function == function_dir ? '/' : '.'))
+# ifdef __MSDOS__
+	  while (p >= p2 && *p != '/' && *p != '\\'
+                 && (function != function_basename || *p != '.'))
+# else
+	  while (p >= p2 && *p != '/'
+                 && (function != function_basename || *p != '.'))
+# endif
 #endif
 	    --p;
-	  if (p >= p2)
-	    {
-	      if (function == function_dir)
-		++p;
-	      o = variable_buffer_output (o, p2, p - p2);
-	    }
+	  if (p >= p2 && (function == function_dir))
+	    o = variable_buffer_output (o, p2, ++p - p2);
+          else if (p >= p2 && (*p == '.'))
+            o = variable_buffer_output (o, p2, p - p2);
+#if defined(WINDOWS32) || defined(__MSDOS__)
+        /* Handle the "d:foobar" case */
+          else if (p2[0] && p2[1] == ':' && function == function_dir)
+            o = variable_buffer_output (o, p2, 2);
+#endif
 	  else if (function == function_dir)
 #ifdef VMS
             o = variable_buffer_output (o, "[]", 2);
