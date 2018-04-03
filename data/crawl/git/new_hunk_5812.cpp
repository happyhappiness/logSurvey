			++nr;
		}
	}
	die_errno("unable to write file '%s' mode %o", path, mode);
}

static void create_file(struct patch *patch)
