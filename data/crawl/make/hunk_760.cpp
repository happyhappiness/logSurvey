 	    }
 	  else
 	    {
-	      /* We use patsubst_expand to do the work of translating
-		 the target pattern, the target's name and the dependencies'
-		 patterns into plain dependency names.  */
+	      /* We use subst_expand to do the work of translating
+		 % to $* in the dependency line.  */
 
               if (this != 0 && find_percent (this->name) != 0)
                 {
-                  PATH_VAR (stem);
                   char *o;
                   char *buffer = variable_expand ("");
 
-                  o = patsubst_expand (buffer, name, pattern, "%",
-                                       pattern_percent + 1, 0);
+                  o = subst_expand (buffer, this->name, "%", "$*",
+                                    1, 2, 0);
 
-
-                  strncpy (stem, buffer, o - buffer);
-                  stem[o - buffer] = '\0';
-
-                  o = subst_expand (buffer, this->name, "%", stem,
-                                    1, strlen (stem), 0);
-
-                  /* If the name expanded to the empty string, that's
-                     illegal.  */
-                  if (o == buffer)
-                    fatal (flocp,
-                           _("target `%s' leaves prerequisite pattern empty"),
-                           name);
 		  free (this->name);
 		  this->name = savestring (buffer, o - buffer);
 		}
