 			/* Ignore epipe */
 			if (errno == EPIPE)
 				break;
-			die("merge-recursive: %s", strerror(errno));
+			die_errno("merge-recursive");
 		} else if (!ret) {
 			die("merge-recursive: disk full?");
 		}
