 	     lossage strikes again!  (xmkmf puts NULs in its makefiles.)
 	     There is nothing really to be done; we synthesize a newline so
 	     the following line doesn't appear to be part of this line.  */
-	  error (flocp, _("warning: NUL character seen; rest of line ignored"));
+	  error (&ebuf->floc,
+                 _("warning: NUL character seen; rest of line ignored"));
 	  p[0] = '\n';
 	  len = 1;
 	}
