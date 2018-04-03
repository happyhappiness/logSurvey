		printf("boundary\n");
	if (suspect->previous) {
		struct origin *prev = suspect->previous;
		printf("previous %s ", sha1_to_hex(prev->commit->object.sha1));
		write_name_quoted(prev->path, stdout, '\n');
	}

