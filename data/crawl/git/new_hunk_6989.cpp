			*header.typeflag = TYPEFLAG_REG;
			mode = (mode | ((mode & 0100) ? 0777 : 0666)) & ~tar_umask;
		} else {
			return error("unsupported file mode: 0%o (SHA1: %s)",
					mode, sha1_to_hex(sha1));
		}
		if (pathlen > sizeof(header.name)) {
			size_t plen = get_path_prefix(path, pathlen,
					sizeof(header.prefix));
			size_t rest = pathlen - plen - 1;
			if (plen > 0 && rest <= sizeof(header.name)) {
				memcpy(header.prefix, path, plen);
				memcpy(header.name, path + plen + 1, rest);
			} else {
				sprintf(header.name, "%s.data",
				        sha1_to_hex(sha1));
				strbuf_append_ext_header(&ext_header, "path",
						path, pathlen);
			}
		} else
			memcpy(header.name, path, pathlen);
	}

	if (S_ISLNK(mode) && buffer) {
