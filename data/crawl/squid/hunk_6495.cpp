 	    fi->inner_time = last_time;
 	else
 	    fi->inner_time += fi->time_offset;
-        if (res == frError)
+	if (res == frError)
 	    fi->bad_line_count++;
-	else
-	if (res == frEof) {
+	else if (res == frEof) {
 	    fprintf(stderr, "exhausted %s (%d entries) at %s",
 		fi->fname, fi->line_count, ctime(&fi->inner_time));
 	    fi->inner_time = -1;
-	} else
-	if (fi->inner_time < last_time) {
+	} else if (fi->inner_time < last_time) {
 	    assert(last_time >= 0);
 	    fi->time_warp_count++;
 	    fi->inner_time = last_time;
