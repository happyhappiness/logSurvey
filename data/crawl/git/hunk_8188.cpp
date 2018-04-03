 			msg = argv[1];
 			if (!*msg)
 				die("Refusing to perform update with empty message");
-			if (strchr(msg, '\n'))
-				die("Refusing to perform update with \\n in message");
 		}
 		else if (!strcmp("--", arg)) {
 			argc--;
