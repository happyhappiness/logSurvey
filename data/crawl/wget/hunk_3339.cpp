 	  ;
 top:	p = endfn;
 	breaks = (char **)malloc(sizeof(char *) * num_breaks * 2);
-	if ( breaks == 0 )
+	if ( breaks == NULL )
 	   {	/* Couldn't allocate break table, give up */
 		fprintf(stderr, "Unable to allocate break table!\n");
 		fputs(buf, out);
