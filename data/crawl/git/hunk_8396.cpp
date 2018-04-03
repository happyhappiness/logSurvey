 	idx_tmp_name = xstrdup(tmpname);
 	f = sha1fd(fd, idx_tmp_name);
 
-	if (nr_result) {
-		uint32_t j = 0;
-		sorted_by_sha =
-			xcalloc(nr_result, sizeof(struct object_entry *));
-		for (i = 0; i < nr_objects; i++)
-			if (!objects[i].preferred_base)
-				sorted_by_sha[j++] = objects + i;
-		if (j != nr_result)
-			die("listed %u objects while expecting %u", j, nr_result);
-		qsort(sorted_by_sha, nr_result, sizeof(*sorted_by_sha), sha1_sort);
+	if (nr_written) {
+		sorted_by_sha = written_list;
+		qsort(sorted_by_sha, nr_written, sizeof(*sorted_by_sha), sha1_sort);
 		list = sorted_by_sha;
-		last = sorted_by_sha + nr_result;
+		last = sorted_by_sha + nr_written;
 	} else
 		sorted_by_sha = list = last = NULL;
 
