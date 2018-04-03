 
 		/* Fill next block from the end */
 		cnt = (sizeof(buf) < pos) ? sizeof(buf) : pos;
-		if (fseek(logfp, pos - cnt, SEEK_SET))
-			return error("cannot seek back reflog for %s: %s",
-				     refname, strerror(errno));
+		if (fseek(logfp, pos - cnt, SEEK_SET)) {
+			ret = error("cannot seek back reflog for %s: %s",
+				    refname, strerror(errno));
+			break;
+		}
 		nread = fread(buf, cnt, 1, logfp);
-		if (nread != 1)
-			return error("cannot read %d bytes from reflog for %s: %s",
-				     cnt, refname, strerror(errno));
+		if (nread != 1) {
+			ret = error("cannot read %d bytes from reflog for %s: %s",
+				    cnt, refname, strerror(errno));
+			break;
+		}
 		pos -= cnt;
 
 		scanp = endp = buf + cnt;