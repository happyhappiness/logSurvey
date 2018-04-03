	}

	if (delta && delta_size < deflate_size) {
		printf("delta %lu\n", orig_size);
		free(deflated);
		data = delta;
		data_size = delta_size;
	}
	else {
		printf("literal %lu\n", two->size);
		free(delta);
		data = deflated;
		data_size = deflate_size;
