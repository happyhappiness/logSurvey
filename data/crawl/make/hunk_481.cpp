 		   if (argv[optind - 1][1] == '-')
 		    /* --option */
 		    fprintf (stderr,
-		     _("%s: option `--%s' doesn't allow an argument\n"),
+		     _("%s: option '--%s' doesn't allow an argument\n"),
 		     argv[0], pfound->name);
 		   else
 		    /* +option or -option */
 		    fprintf (stderr,
-		     _("%s: option `%c%s' doesn't allow an argument\n"),
+		     _("%s: option '%c%s' doesn't allow an argument\n"),
 		     argv[0], argv[optind - 1][0], pfound->name);
 
 		  nextchar += strlen (nextchar);
