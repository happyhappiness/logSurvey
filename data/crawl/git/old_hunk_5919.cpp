		if (!n)
			break;
		if (n < 0)
			die("Failed to checksum %s: %s", pack_name, strerror(errno));
		git_SHA1_Update(&new_sha1_ctx, buf, n);

		aligned_sz -= n;
