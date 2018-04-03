       p2 = text;
 
       while (((p = find_next_token (&p2, &len)) != 0) && --i)
-        {}
+	{}
       if (p)
-        {
-          while (--j && (find_next_token (&p2, &len) != 0))
-            {}
-          o = variable_buffer_output (o, p, p2 - p);
-        }
+	{
+	  while (--j && (find_next_token (&p2, &len) != 0))
+	    {}
+	  o = variable_buffer_output (o, p, p2 - p);
+	}
 
       free (text);
       break;
