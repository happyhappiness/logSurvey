				die("readlink(%s)", name);
			if (ret == sizeof(buf))
				die("symlink too long: %s", name);
			prep_temp_blob(temp, buf, ret,
				       (one->sha1_valid ?
					one->sha1 : null_sha1),
				       (one->sha1_valid ?
