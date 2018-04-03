 				  &spnegoTokenLength))!=0 ) {
 	  if (debug)
 	    fprintf(stderr, "%s| %s: makeNegTokenTarg failed with rc=%d\n", LogTime(), PROGRAM, rc);
-	  fprintf(stdout, "NA makeNegTokenTarg failed with rc=%d\n",rc);
+	  fprintf(stdout, "BH makeNegTokenTarg failed with rc=%d\n",rc);
 	  goto cleanup;
 	}
       } else {
