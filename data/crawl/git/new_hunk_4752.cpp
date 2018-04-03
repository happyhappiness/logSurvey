		}
	}
	else if (share && adjust_shared_perm(dir))
		die(_("Could not make %s writable by group"), dir);
}

static void copy_templates_1(char *path, int baselen,
