 		return 0;	/* error was already reported */
 
 	if (strbuf_read(&nbuf, async.out, len) < 0) {
-		error("read from external filter '%s' failed", cmd);
-		ret = 0;
+		err = error("read from external filter '%s' failed", cmd);
 	}
 	if (close(async.out)) {
-		error("read from external filter '%s' failed", cmd);
-		ret = 0;
+		err = error("read from external filter '%s' failed", cmd);
 	}
 	if (finish_async(&async)) {
-		error("external filter '%s' failed", cmd);
-		ret = 0;
+		err = error("external filter '%s' failed", cmd);
 	}
 
-	if (ret) {
+	if (!err) {
 		strbuf_swap(dst, &nbuf);
 	}
 	strbuf_release(&nbuf);
-	return ret;
+	return !err;
 }
 
 static struct convert_driver {