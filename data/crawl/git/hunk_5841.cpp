 			if (errno == EEXIST && state->force &&
 			    !unlink_or_warn(buf) && !mkdir(buf, 0777))
 				continue;
-			die("cannot create directory at %s", buf);
+			die_errno("cannot create directory at '%s'", buf);
 		}
 	}
 	free(buf);
