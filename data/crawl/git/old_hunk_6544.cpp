		}
	}
	else if (share && adjust_shared_perm(dir))
		die("Could not make %s writable by group\n", dir);
}

static void copy_templates_1(char *path, int baselen,
