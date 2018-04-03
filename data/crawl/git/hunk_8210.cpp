 			i++;
 			if (i == argc)
 				die("option -F needs an argument.");
+			if (message)
+				die("only one -F or -m option is allowed.");
 
 			if (!strcmp(argv[i], "-"))
 				fd = 0;
