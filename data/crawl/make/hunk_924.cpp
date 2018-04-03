 		    continue;
 		  o = patsubst_expand (buffer, name, pattern, d->name,
 				       pattern_percent, percent);
+                  /* If the name expanded to the empty string, that's
+                     illegal.  */
+                  if (o == buffer)
+                    fatal (flocp,
+                           _("target `%s' leaves prerequisite pattern empty"),
+                           name);
 		  free (d->name);
 		  d->name = savestring (buffer, o - buffer);
 		}
