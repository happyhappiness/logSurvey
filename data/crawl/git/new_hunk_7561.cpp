		die("cannot stat the open index (%s)", strerror(errno));

	errno = EINVAL;
	mmap_size = xsize_t(st.st_size);
	if (mmap_size < sizeof(struct cache_header) + 20)
		die("index file smaller than expected");

	mmap = xmmap(NULL, mmap_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);
	if (mmap == MAP_FAILED)
		die("unable to map index file");

	hdr = mmap;
	if (verify_hdr(hdr, mmap_size) < 0)
		goto unmap;

	istate->cache_nr = ntohl(hdr->hdr_entries);
	istate->cache_alloc = alloc_nr(istate->cache_nr);
	istate->cache = xcalloc(istate->cache_alloc, sizeof(struct cache_entry *));

	/*
	 * The disk format is actually larger than the in-memory format,
	 * due to space for nsec etc, so even though the in-memory one
	 * has room for a few  more flags, we can allocate using the same
	 * index size
	 */
	istate->alloc = xmalloc(mmap_size);

	src_offset = sizeof(*hdr);
	dst_offset = 0;
	for (i = 0; i < istate->cache_nr; i++) {
		struct ondisk_cache_entry *disk_ce;
		struct cache_entry *ce;

		disk_ce = (struct ondisk_cache_entry *)((char *)mmap + src_offset);
		ce = (struct cache_entry *)((char *)istate->alloc + dst_offset);
		convert_from_disk(disk_ce, ce);
		istate->cache[i] = ce;

		src_offset += ondisk_ce_size(ce);
		dst_offset += ce_size(ce);
	}
	istate->timestamp = st.st_mtime;
	while (src_offset <= mmap_size - 20 - 8) {
		/* After an array of active_nr index entries,
		 * there can be arbitrary number of extended
		 * sections, each of which is prefixed with
		 * extension name (4-byte) and section length
		 * in 4-byte network byte order.
		 */
		unsigned long extsize;
		memcpy(&extsize, (char *)mmap + src_offset + 4, 4);
		extsize = ntohl(extsize);
		if (read_index_extension(istate,
					 (const char *) mmap + src_offset,
					 (char *) mmap + src_offset + 8,
					 extsize) < 0)
			goto unmap;
		src_offset += 8;
		src_offset += extsize;
	}
	munmap(mmap, mmap_size);
	return istate->cache_nr;

unmap:
	munmap(mmap, mmap_size);
	errno = EINVAL;
	die("index file corrupt");
}

int discard_index(struct index_state *istate)
{
	istate->cache_nr = 0;
	istate->cache_changed = 0;
	istate->timestamp = 0;
	cache_tree_free(&(istate->cache_tree));
	free(istate->alloc);
	istate->alloc = NULL;

	/* no need to throw away allocated active_cache */
	return 0;
}

#define WRITE_BUFFER_SIZE 8192
