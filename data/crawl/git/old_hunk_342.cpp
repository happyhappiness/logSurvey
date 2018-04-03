		return grep_source_load_oid(gs);
	case GREP_SOURCE_BUF:
		return gs->buf ? 0 : -1;
	case GREP_SOURCE_SUBMODULE:
		break;
	}
	die("BUG: invalid grep_source type to load");
}
