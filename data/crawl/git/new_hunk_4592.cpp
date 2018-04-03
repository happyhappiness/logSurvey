			ret = cmd_log_walk(&rev);
			break;
		default:
			ret = error(_("Unknown type: %d"), o->type);
		}
	}
	free(objects);
