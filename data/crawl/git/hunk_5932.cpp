 			if (sz == 0)
 				break;
 			if (sz < 0)
-				die("test-sha1: %s", strerror(errno));
+				die_errno("test-sha1");
 			this_sz += sz;
 			cp += sz;
 			room -= sz;
