 	if (offset > (p->pack_size - 20))
 		die("offset beyond end of packfile (truncated pack?)");
 	if (offset < 0)
-		die("offset before end of packfile (broken .idx?)");
+		die(_("offset before end of packfile (broken .idx?)"));
 
 	if (!win || !in_window(win, offset)) {
 		if (win)
