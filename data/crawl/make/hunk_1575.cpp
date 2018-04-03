 		}
 	  }
 
-	  if (p - buf >= 30)
+	  if (p - buf > DESCRIPTION_COLUMN - 2)
+	    /* The list of option names is too long to fit on the same
+	       line with the description, leaving at least two spaces.
+	       Print it on its own line instead.  */
 	    {
 	      fprintf (stderr, "%s\n", buf);
 	      buf[0] = '\0';
 	    }
 
-	  fprintf (stderr, "%-30s%s.\n", buf, cs->description);
+	  fprintf (stderr, "%*s%s.\n",
+		   - DESCRIPTION_COLUMN,
+		   buf, cs->description);
 	}
 
       die (1);
