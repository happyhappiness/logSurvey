				die("unable to rename temporary index file: %s",
				    strerror(errno));
			puts(sha1_to_hex(object_list_sha1));
	}
}

static int sha1_sort(const void *_a, const void *_b)
