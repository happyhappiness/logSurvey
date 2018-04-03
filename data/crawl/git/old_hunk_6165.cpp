		const char *name = used_atom[i];
		struct atom_value *v = &ref->value[i];
		int deref = 0;
		if (*name == '*') {
			deref = 1;
			name++;
		}
		if (!prefixcmp(name, "refname")) {
			const char *formatp = strchr(name, ':');
			const char *refname = ref->refname;

			/* look for "short" refname format */
			if (formatp) {
				formatp++;
				if (!strcmp(formatp, "short"))
					refname = get_short_ref(ref);
				else
					die("unknown refname format %s",
					    formatp);
			}

			if (!deref)
				v->s = refname;
			else {
				int len = strlen(refname);
				char *s = xmalloc(len + 4);
				sprintf(s, "%s^{}", refname);
				v->s = s;
			}
		}
	}

