 		      ++count;
 		    else if (*p == closeparen && --count < 0)
 		      break;
+		    else if (colon == 0 && count == 0 && *p == ':')
+		      /* Record where we found a colon, which
+			 indicates a substitution reference.
+			 We want to expand the text before the
+			 reference only.  */
+		      colon = p;
 		  }
 		/* If COUNT is >= 0, there were unmatched opening parens
 		   or braces, so we go to the simple case of a variable name
 		   such as `$($(a)'.  */
 		if (count < 0)
 		  {
-		    char *name = expand_argument (beg, p);
-		    static char start[3] = { '$', }, end[2];
-		    start[1] = openparen;
-		    end[0] = closeparen;
-		    p1 = concat (start, name, end);
-		    free (name);
-		    name = allocated_variable_expand (p1);
-		    o = variable_buffer_output (o, name, strlen (name));
-		    free (name);
-		    break;
+		    char *name = expand_argument (beg, colon == 0 ? p : colon);
+		    unsigned int namelen = strlen (name);
+		    if (colon == 0)
+		      {
+			/* This is a simple reference to the expanded name.  */
+			o = reference_variable (o, name, namelen);
+			free (name);
+			break;
+		      }
+		    else
+		      {
+			/* This is a substitution reference to the expanded
+			   name.  We replace the pending text with a copy
+			   containing the expanded name in place of the
+			   original name, and then fall through to
+			   the normal substitution reference code below.  */
+			unsigned int restlen = strlen (colon) + 1;
+			beg = (char *) alloca (namelen + restlen);
+			bcopy (name, beg, namelen);
+			bcopy (colon, &beg[namelen], restlen);
+			/* Point COLON into the new copy.  */
+			colon = &beg[namelen];
+		      }
 		  }
 	      }
 
