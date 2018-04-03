 			i++;
 			if (i == argc)
 				die("option -m needs an argument.");
+			if (message)
+				die("only one -F or -m option is allowed.");
 			message = xstrdup(argv[i]);
 			continue;
 		}
