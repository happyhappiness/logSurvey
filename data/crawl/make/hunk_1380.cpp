 	  p = p2 + len;
 #ifdef VMS
 	  while (p >= p2 && *p != ']'
-                 && (function != function_suffix || *p != '.'))
+		 && (function != function_suffix || *p != '.'))
 #else
 # ifdef __MSDOS__
 	  while (p >= p2 && *p != '/' && *p != '\\'
-                 && (function != function_suffix || *p != '.'))
+		 && (function != function_suffix || *p != '.'))
 # else
 	  while (p >= p2 && *p != '/'
-                 && (function != function_suffix || *p != '.'))
+		 && (function != function_suffix || *p != '.'))
 # endif
 #endif
 	    --p;
 	  if (p >= p2)
 	    {
 	      if (function == function_notdir)
-                ++p;
-              else if (*p != '.')
-                continue;
+		++p;
+	      else if (*p != '.')
+		continue;
 	      o = variable_buffer_output (o, p, len - (p - p2));
 	    }
 #if defined(WINDOWS32) || defined(__MSDOS__)
-          /* Handle the case of "d:foo/bar". */
-          else if (function == function_notdir && p2[0] && p2[1] == ':')
-            {
-              p = p2 + 2;
-              o = variable_buffer_output (o, p, len - (p - p2));
-            }
+	  /* Handle the case of "d:foo/bar".  */
+	  else if (function == function_notdir && p2[0] && p2[1] == ':')
+	    {
+	      p = p2 + 2;
+	      o = variable_buffer_output (o, p, len - (p - p2));
+	    }
 #endif
 	  else if (function == function_notdir)
 	    o = variable_buffer_output (o, p2, len);
