 	if (prepare_revision_walk(&revs))
 		die("revision walk setup failed");
 	mark_edges_uninteresting(revs.commits, &revs, show_edge);
+	if (use_thin_pack)
+		for (i = 0; i < extra_edge_obj.nr; i++)
+			fprintf(pack_pipe, "-%s\n", sha1_to_hex(
+					extra_edge_obj.objects[i].item->sha1));
 	traverse_commit_list(&revs, show_commit, show_object, NULL);
 	fflush(pack_pipe);
 	fclose(pack_pipe);
