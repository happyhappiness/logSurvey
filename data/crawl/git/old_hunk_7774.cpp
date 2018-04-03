		}
		if (!memcmp(line, "ok", 2))
			continue;
		fputs(line, stderr);
		ret = -1;
	}
	return ret;
