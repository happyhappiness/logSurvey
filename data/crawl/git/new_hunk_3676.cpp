		return 0;
	}

	peel_status = peel_entry(entry);
	write_packed_entry(*fd, entry->name, entry->u.value.sha1,
			   peel_status == PEEL_PEELED ?
			   entry->u.value.peeled : NULL);

	return 0;
}