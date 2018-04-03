		case BRANCH_TRACK_OVERRIDE:
			break;
		default:
			return 1;
		}

	if (tracking.matches > 1)
		return error(_("Not tracking: ambiguous information for ref %s"),
				orig_ref);

	install_branch_config(config_flags, new_ref, tracking.remote,
			      tracking.src ? tracking.src : orig_ref);

	free(tracking.src);
	return 0;
}

int read_branch_desc(struct strbuf *buf, const char *branch_name)
