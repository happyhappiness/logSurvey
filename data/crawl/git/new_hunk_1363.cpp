
		diff_fill_sha1_info(p->one);
		diff_fill_sha1_info(p->two);

		len1 = remove_space(p->one->path, strlen(p->one->path));
		len2 = remove_space(p->two->path, strlen(p->two->path));
