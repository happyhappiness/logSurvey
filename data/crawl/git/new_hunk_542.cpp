				return 0;
			}
			die("object %s cannot be read",
			    oid_to_hex(&src_entry->idx.oid));
		}
		if (sz != src_size)
			die("object %s inconsistent object length (%lu vs %lu)",
			    oid_to_hex(&src_entry->idx.oid), sz,
			    src_size);
		*mem_usage += sz;
	}
	if (!src->index) {
