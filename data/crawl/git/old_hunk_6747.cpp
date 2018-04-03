	for (i = 0; i < used_atom_cnt; i++) {
		const char *name = used_atom[i];
		struct atom_value *v = &ref->value[i];
		if (!strcmp(name, "refname"))
			v->s = ref->refname;
		else if (!strcmp(name, "*refname")) {
			int len = strlen(ref->refname);
			char *s = xmalloc(len + 4);
			sprintf(s, "%s^{}", ref->refname);
			v->s = s;
		}
	}

