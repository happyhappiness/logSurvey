	}
}

static int repack_ref_fn(struct ref_entry *entry, void *cb_data)
{
	int *fd = cb_data;
