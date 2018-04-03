	 * (it also writes the merge result to the object database even
	 * when it may contain conflicts).
	 */
	if (write_object_file(result_buf.ptr, result_buf.size, blob_type, &oid))
		die(_("Unable to add merge result for '%s'"), path);
	free(result_buf.ptr);
	ce = make_cache_entry(mode, oid.hash, path, 2, 0);
