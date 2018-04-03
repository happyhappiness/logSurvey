 		default:
 			; /* ok. (usually accepts an argument) */
 		}
+		if (opts->argh &&
+		    strcspn(opts->argh, " _") != strlen(opts->argh))
+			err |= optbug(opts, "multi-word argh should use dash to separate words");
 	}
 	if (err)
 		exit(128);