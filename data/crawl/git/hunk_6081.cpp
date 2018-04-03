 		 */
 		if (mkdir(buf, 0777)) {
 			if (errno == EEXIST && state->force &&
-			    !unlink(buf) && !mkdir(buf, 0777))
+			    !unlink_or_warn(buf) && !mkdir(buf, 0777))
 				continue;
 			die("cannot create directory at %s", buf);
 		}
