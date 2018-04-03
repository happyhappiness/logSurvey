         delta_buf = diff_delta(otherbuf, othersize,
 			       buf, size, &delta_size, 0);
         if (!delta_buf || delta_size != entry->delta_size)
-        	die("delta size changed");
+		die("delta size changed");
         free(buf);
         free(otherbuf);
 	return delta_buf;
