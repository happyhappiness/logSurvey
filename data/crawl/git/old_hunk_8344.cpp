		unuse_pack(&w_curs);
	}

	entry->type = sha1_object_info(entry->sha1, &entry->size);
	if (entry->type < 0)
		die("unable to get type of object %s",
		    sha1_to_hex(entry->sha1));
}

static int pack_offset_sort(const void *_a, const void *_b)
