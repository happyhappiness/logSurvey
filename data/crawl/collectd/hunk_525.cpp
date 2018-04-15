 		return (1);
 	}
 
-	fprintf (fh, "%d\n", getpid());
+	fprintf (fh, "%i\n", (int) getpid ());
 	fclose(fh);
 
 	return (0);
