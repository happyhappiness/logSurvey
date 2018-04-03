	if (!author)
		die("Missing author: %s",
		    sha1_to_hex(commit->object.sha1));
	if (*buffer)
		buffer++;
	insert_one_record(log, author, !*buffer ? "<none>" : buffer);
