 	      else
 		bad = 1;
 	      if (bad)
-		fatal ("Couldn't change back to original directory.");
+		fatal (NILF, "Couldn't change back to original directory.");
 	    }
 
 #ifndef _AMIGA
