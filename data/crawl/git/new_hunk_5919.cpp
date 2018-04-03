		if (!n)
			break;
		if (n < 0)
			die_errno("Failed to checksum '%s'", pack_name);
		git_SHA1_Update(&new_sha1_ctx, buf, n);

		aligned_sz -= n;
