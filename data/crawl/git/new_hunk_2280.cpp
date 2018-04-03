			refname = branch_get_push(branch, NULL);
			if (!refname)
				continue;
		} else if (starts_with(name, "color:")) {
			v->s = atom->u.color;
			continue;
		} else if (!strcmp(name, "flag")) {
			char buf[256], *cp = buf;