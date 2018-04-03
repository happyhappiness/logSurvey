 	if (index < suc->failed_clones_nr) {
 		int *p;
 		ce = suc->failed_clones[index];
-		if (!prepare_to_clone_next_submodule(ce, child, suc, err))
-			die("BUG: ce was a submodule before?");
+		if (!prepare_to_clone_next_submodule(ce, child, suc, err)) {
+			suc->current ++;
+			strbuf_addf(err, "BUG: submodule considered for cloning,"
+				    "doesn't need cloning any more?\n");
+			return 0;
+		}
 		p = xmalloc(sizeof(*p));
 		*p = suc->current;
 		*idx_task_cb = p;