 			/* Make sure we do not get outside of paths */
 			for (i = 0; paths[i]; i++)
 				if (strncmp(prefix, paths[i], opt.prefix_length))
-					die("git-grep: cannot generate relative filenames containing '..'");
+					die("git grep: cannot generate relative filenames containing '..'");
 		}
 	}
 	else if (prefix) {
