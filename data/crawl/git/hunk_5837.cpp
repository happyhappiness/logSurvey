 
 			done = read_in_full(fd, result, len);
 			if (done < 0)
-				die("read error '%s'", elem->path);
+				die_errno("read error '%s'", elem->path);
 			else if (done < len)
 				die("early EOF '%s'", elem->path);
 
