 
 	  /* A $ followed by a random char is a variable reference:
 	     $a is equivalent to $(a).  */
-	  {
-	    /* We could do the expanding here, but this way
-	       avoids code repetition at a small performance cost.  */
-	    char name[5];
-	    name[0] = '$';
-	    name[1] = '(';
-	    name[2] = *p;
-	    name[3] = ')';
-	    name[4] = '\0';
-	    p1 = allocated_variable_expand (name);
-	    o = variable_buffer_output (o, p1, strlen (p1));
-	    free (p1);
-	  }
+          o = reference_variable (o, p, 1);
 
 	  break;
 	}
