		die("cannot stat the open index (%s)", strerror(errno));

	errno = EINVAL;
	istate->mmap_size = xsize_t(st.st_size);
	if (istate->mmap_size < sizeof(struct cache_header) + 20)
		die("index file smaller than expected");

	istate->mmap = xmmap(NULL, istate->mmap_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	close(fd);

	hdr = istate->mmap;
	if (verify_hdr(hdr, istate->mmap_size) < 0)
		goto unmap;

	istate->cache_nr = ntohl(hdr->hdr_entries);
	istate->cache_alloc = alloc_nr(istate->cache_nr);
	istate->cache = xcalloc(istate->cache_alloc, sizeof(struct cache_entry *));

	offset = sizeof(*hdr);
	for (i = 0; i < istate->cache_nr; i++) {
		struct cache_entry *ce;

		ce = (struct cache_entry *)((char *)(istate->mmap) + offset);
		offset = offset + ce_size(ce);
		istate->cache[i] = ce;
	}
	istate->timestamp = st.st_mtime;
	while (offset <= istate->mmap_size - 20 - 8) {
		/* After an array of active_nr index entries,
		 * there can be arbitrary number of extended
		 * sections, each of which is prefixed with
		 * extension name (4-byte) and section length
		 * in 4-byte network byte order.
		 */
		unsigned long extsize;
		memcpy(&extsize, (char *)(istate->mmap) + offset + 4, 4);
		extsize = ntohl(extsize);
		if (read_index_extension(istate,
					 ((const char *) (istate->mmap)) + offset,
					 (char *) (istate->mmap) + offset + 8,
					 extsize) < 0)
			goto unmap;
		offset += 8;
		offset += extsize;
	}
	return istate->cache_nr;

unmap:
	munmap(istate->mmap, istate->mmap_size);
	errno = EINVAL;
	die("index file corrupt");
}

int discard_index(struct index_state *istate)
{
	int ret;

	istate->cache_nr = 0;
	istate->cache_changed = 0;
	istate->timestamp = 0;
	cache_tree_free(&(istate->cache_tree));
	if (istate->mmap == NULL)
		return 0;
	ret = munmap(istate->mmap, istate->mmap_size);
	istate->mmap = NULL;
	istate->mmap_size = 0;

	/* no need to throw away allocated active_cache */
	return ret;
}

#define WRITE_BUFFER_SIZE 8192
