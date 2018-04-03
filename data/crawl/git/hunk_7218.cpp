 
 			result_size = len;
 			result = xmalloc(len + 1);
-			while (sz < len) {
-				ssize_t done = xread(fd, result+sz, len-sz);
-				if (done == 0 && sz != len)
-					die("early EOF '%s'", elem->path);
-				else if (done < 0)
-					die("read error '%s'", elem->path);
-				sz += done;
-			}
+
+			done = read_in_full(fd, result, len);
+			if (done < 0)
+				die("read error '%s'", elem->path);
+			else if (done < len)
+				die("early EOF '%s'", elem->path);
+
 			result[len] = 0;
 		}
 		else {