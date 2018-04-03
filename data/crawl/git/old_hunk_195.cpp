				NULL, oid_to_hex(&ce->oid),
				state->force ? SUBMODULE_MOVE_HEAD_FORCE : 0);
		break;
	default:
		return error("unknown file mode for %s in index", path);
	}