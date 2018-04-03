			++nr;
		}
	}
	return error_errno(_("unable to write file '%s' mode %o"),
			   path, mode);
}

static int add_conflicted_stages_file(struct apply_state *state,
