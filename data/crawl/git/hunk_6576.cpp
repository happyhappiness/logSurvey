 			len = readlink(buf, next_buf, PATH_MAX);
 			if (len < 0)
 				die ("Invalid symlink: %s", buf);
+			if (PATH_MAX <= len)
+				die("symbolic link too long: %s", buf);
 			next_buf[len] = '\0';
 			buf = next_buf;
 			buf_index = 1 - buf_index;