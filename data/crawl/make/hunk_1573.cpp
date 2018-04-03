 	    else
 	      printf ("%u", im);
 	    fputs (" impossibilities", stdout);
-	    if (dir->dirstream == 0)
+	    if (dir->contents->dirstream == 0)
 	      puts (".");
 	    else
 	      puts (" so far.");
