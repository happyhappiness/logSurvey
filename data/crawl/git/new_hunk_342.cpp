		return grep_source_load_oid(gs);
	case GREP_SOURCE_BUF:
		return gs->buf ? 0 : -1;
	}
	die("BUG: invalid grep_source type to load");
}
