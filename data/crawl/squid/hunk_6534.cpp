     xfree(fi);
 }
 
+static void
+fileIteratorSetCurTime(FileIterator *fi, time_t ct)
+{
+    assert(fi);
+    assert(fi->inner_time > 0);
+    fi->time_offset = ct - fi->inner_time;
+}
+
 static void
 fileIteratorAdvance(FileIterator *fi)
 {
     int res;
     assert(fi);
     do {
-	time_t last_time = fi->inner_time;
+	const time_t last_time = fi->inner_time;
+	fi->inner_time = -1;
 	res = fi->reader(fi);
 	fi->line_count++;
+	if (fi->inner_time < 0)
+	    fi->inner_time = last_time;
+	else
+	    fi->inner_time += fi->time_offset;
         if (res == frError)
 	    fi->bad_line_count++;
 	else
-	if (res == frEof)
+	if (res == frEof) {
+	    fprintf(stderr, "exhausted %s (%d entries) at %s",
+		fi->fname, fi->line_count, ctime(&fi->inner_time));
 	    fi->inner_time = -1;
-	else
+	} else
 	if (fi->inner_time < last_time) {
 	    assert(last_time >= 0);
 	    fi->time_warp_count++;
 	    fi->inner_time = last_time;
 	}
 	/* report progress */
 	if (!(fi->line_count % 50000))
-	    fprintf(stderr, "%s scanned %d K entries (%d bad)\n",
-		fi->fname, fi->line_count / 1000, fi->bad_line_count);
+	    fprintf(stderr, "%s scanned %d K entries (%d bad) at %s",
+		fi->fname, fi->line_count / 1000, fi->bad_line_count,
+		ctime(&fi->inner_time));
     } while (res < 0);
 }
 
