
	if (read_state_file(&sb, state, "abort-safety", 1) > 0) {
		if (get_oid_hex(sb.buf, &abort_safety))
			die(_("could not parse %s"), am_path(state, "abort-safety"));
	} else
		oidclr(&abort_safety);
