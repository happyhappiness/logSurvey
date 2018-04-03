 		add_object_array(e->item, e->name, &refs);
 	}
 
-	prepare_revision_walk(&revs);
+	if (prepare_revision_walk(&revs))
+		die("revision walk setup failed");
 
 	i = req_nr;
 	while (i && (commit = get_revision(&revs)))
