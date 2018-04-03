 
 	if (!new_refs)
 		fprintf(stderr, "Everything up-to-date\n");
+	if (ret < 0)
+		return ret;
 	for (ref = remote_refs; ref; ref = ref->next) {
 		switch (ref->status) {
 		case REF_STATUS_NONE:
