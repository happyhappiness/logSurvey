		return error("Unable to start request");
	}

	if (buffer.posn != 41)
		return 1;
        hex[40] = '\0';
	return get_sha1_hex(hex, sha1);
}

static void one_remote_object(const char *hex)
