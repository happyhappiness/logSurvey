		return grep_source_load_sha1(gs);
	case GREP_SOURCE_BUF:
		return gs->buf ? 0 : -1;
	}
	die("BUG: invalid grep_source type");
}

void grep_source_load_driver(struct grep_source *gs)
