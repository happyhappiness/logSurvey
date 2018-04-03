
		if (!fstat(fd, &st)) {
			*size = xsize_t(st.st_size);
			map = xmmap(NULL, *size, PROT_READ, MAP_PRIVATE, fd, 0);
		}
		close(fd);