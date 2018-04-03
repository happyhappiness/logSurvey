	}

	if (nr_deltas) {
		qsort(delta_list, n, sizeof(*delta_list), type_size_sort);
		find_deltas(delta_list, n, nr_deltas, window+1, depth);
	}
	free(delta_list);
}