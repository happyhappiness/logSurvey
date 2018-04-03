 
       len = strlen (p);
       if (len == 0)
-	{
-	  /* This only happens when the first thing on the line is a '\0'.
-	     It is a pretty hopeless case, but (wonder of wonders) Athena
-	     lossage strikes again!  (xmkmf puts NULs in its makefiles.)
-	     There is nothing really to be done; we synthesize a newline so
-	     the following line doesn't appear to be part of this line.  */
-	  error (&ebuf->floc,
+        {
+          /* This only happens when the first thing on the line is a '\0'.
+             It is a pretty hopeless case, but (wonder of wonders) Athena
+             lossage strikes again!  (xmkmf puts NULs in its makefiles.)
+             There is nothing really to be done; we synthesize a newline so
+             the following line doesn't appear to be part of this line.  */
+          error (&ebuf->floc,
                  _("warning: NUL character seen; rest of line ignored"));
-	  p[0] = '\n';
-	  len = 1;
-	}
+          p[0] = '\n';
+          len = 1;
+        }
 
       /* Jump past the text we just read.  */
       p += len;
