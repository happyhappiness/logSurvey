	}
	if (!src->index) {
		src->index = create_delta_index(src->data, src_size);
		if (!src->index)
			die("out of memory");
	}

	delta_buf = create_delta(src->index, trg->data, trg_size, &delta_size, max_size);