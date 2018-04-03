 
 
       while (p >= p2 && (!is_suffix || *p != '.'))
-	{
-	  if (IS_PATHSEP (*p))
-	    break;
-	  --p;
-	}
+        {
+          if (IS_PATHSEP (*p))
+            break;
+          --p;
+        }
 
       if (p >= p2)
-	{
-	  if (is_notdir)
-	    ++p;
-	  else if (*p != '.')
-	    continue;
-	  o = variable_buffer_output (o, p, len - (p - p2));
-	}
+        {
+          if (is_notdir)
+            ++p;
+          else if (*p != '.')
+            continue;
+          o = variable_buffer_output (o, p, len - (p - p2));
+        }
 #ifdef HAVE_DOS_PATHS
       /* Handle the case of "d:foo/bar".  */
       else if (is_notdir && p2[0] && p2[1] == ':')
-	{
-	  p = p2 + 2;
-	  o = variable_buffer_output (o, p, len - (p - p2));
-	}
+        {
+          p = p2 + 2;
+          o = variable_buffer_output (o, p, len - (p - p2));
+        }
 #endif
       else if (is_notdir)
-	o = variable_buffer_output (o, p2, len);
+        o = variable_buffer_output (o, p2, len);
 
       if (is_notdir || p >= p2)
-	{
-	  o = variable_buffer_output (o, " ", 1);
-	  doneany = 1;
-	}
+        {
+          o = variable_buffer_output (o, " ", 1);
+          doneany = 1;
+        }
     }
 
   if (doneany)
