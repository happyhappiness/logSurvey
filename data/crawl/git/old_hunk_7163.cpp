		die("unable to write sha1 file");
	free(compressed);

	return move_temp_to_file(tmpfile, filename);
}

/*
 * We need to unpack and recompress the object for writing
 * it out to a different file.