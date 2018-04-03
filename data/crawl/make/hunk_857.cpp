 	 following lines.  */
 
       if (!in_ignored_define
-	  && (word1eq ("ifdef", 5) || word1eq ("ifndef", 6)
-	      || word1eq ("ifeq", 4) || word1eq ("ifneq", 5)
-	      || word1eq ("else", 4) || word1eq ("endif", 5)))
+	  && (word1eq ("ifdef") || word1eq ("ifndef")
+	      || word1eq ("ifeq") || word1eq ("ifneq")
+	      || word1eq ("else") || word1eq ("endif")))
 	{
-	  int i = conditional_line (p, &fileinfo);
-	  if (i >= 0)
-	    ignoring = i;
-	  else
-	    fatal (&fileinfo, _("invalid syntax in conditional"));
+	  int i = conditional_line (p, fstart);
+	  if (i < 0)
+	    fatal (fstart, _("invalid syntax in conditional"));
+
+          ignoring = i;
 	  continue;
 	}
 
-      if (word1eq ("endef", 5))
+      if (word1eq ("endef"))
 	{
-	  if (in_ignored_define)
-	    in_ignored_define = 0;
-	  else
-	    fatal (&fileinfo, _("extraneous `endef'"));
+	  if (!in_ignored_define)
+	    fatal (fstart, _("extraneous `endef'"));
+          in_ignored_define = 0;
 	  continue;
 	}
 
-      if (word1eq ("define", 6))
+      if (word1eq ("define"))
 	{
 	  if (ignoring)
 	    in_ignored_define = 1;
 	  else
 	    {
-	      p2 = next_token (p + 6);
               if (*p2 == '\0')
-                fatal (&fileinfo, _("empty variable name"));
+                fatal (fstart, _("empty variable name"));
 
 	      /* Let the variable name be the whole rest of the line,
 		 with trailing blanks stripped (comments have already been
