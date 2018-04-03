	}

	if (delta && delta_size < deflate_size) {
		fprintf(file, "%sdelta %lu\n", prefix, orig_size);
		free(deflated);
		data = delta;
		data_size = delta_size;
	}
	else {
		fprintf(file, "%sliteral %lu\n", prefix, two->size);
		free(delta);
		data = deflated;
		data_size = deflate_size;
