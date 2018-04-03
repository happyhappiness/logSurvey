			/* Ignore it, we already handled it */
			break;
		default:
			if (state->apply_verbosely)
				error(_("invalid start of line: '%c'"), first);
			applied_pos = -1;
			goto out;
