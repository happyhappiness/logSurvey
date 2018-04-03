 
 	pipe_fd = xfdopen(pack_objects.in, "w");
 
+	if (shallow_nr)
+		for_each_commit_graft(write_one_shallow, pipe_fd);
+
 	for (i = 0; i < want_obj.nr; i++)
 		fprintf(pipe_fd, "%s\n",
 			sha1_to_hex(want_obj.objects[i].item->sha1));
