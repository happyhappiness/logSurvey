		} else if (0 <= nth)
			at_time = 0;
		else {
			char *tmp = xstrndup(str + at + 2, reflog_len);
			at_time = approxidate(tmp);
			free(tmp);
		}
		if (read_ref_at(real_ref, at_time, nth, sha1, NULL,
