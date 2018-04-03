 		die("packfile %s cannot be accessed", p->pack_name);
 	if (offset > (p->pack_size - 20))
 		die("offset beyond end of packfile (truncated pack?)");
+	if (offset < 0)
+		die("offset before end of packfile (broken .idx?)");
 
 	if (!win || !in_window(win, offset)) {
 		if (win)
