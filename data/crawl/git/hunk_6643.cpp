 		else
 			lo = mi + 1;
 	} while (lo < hi);
-	die("internal error: pack revindex corrupt");
+	error("bad offset for revindex");
+	return NULL;
 }
 
 void discard_revindex(void)
