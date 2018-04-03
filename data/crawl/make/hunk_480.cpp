       if (ambig && !exact)
 	{
 	  if (opterr)
-	    fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
+	    fprintf (stderr, _("%s: option '%s' is ambiguous\n"),
 		     argv[0], argv[optind]);
 	  nextchar += strlen (nextchar);
 	  optind++;
