 
     buf.append(" [", 2);
 
-	buf.Printf("%d<=%d", (int)theGetSize, (int)thePutSize);
+	buf.Printf("%"PRIu64"<=%"PRIu64, theGetSize, thePutSize);
     if (theBodySize >= 0)
-        buf.Printf("<=%d", (int)theBodySize);
+        buf.Printf("<=%"PRId64, theBodySize);
 	else
 		buf.append("<=?", 3);
 
