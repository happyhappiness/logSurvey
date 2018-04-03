 			if (!ferror(stdin))
 				die("fgets returned NULL, not EOF, not error!");
 			if (errno != EINTR)
-				die("fgets: %s", strerror(errno));
+				die_errno("fgets");
 			clearerr(stdin);
 			continue;
 		}
