		for (ext = 0; ext < ARRAY_SIZE(exts); ext++) {
			char *fname, *fname_old;
			struct stat statbuffer;
			int exists = 0;
			fname = mkpathdup("%s/pack-%s%s",
					packdir, item->string, exts[ext].name);
			fname_old = mkpathdup("%s-%s%s",
					packtmp, item->string, exts[ext].name);
			if (!stat(fname_old, &statbuffer)) {
				statbuffer.st_mode &= ~(S_IWUSR | S_IWGRP | S_IWOTH);
				chmod(fname_old, statbuffer.st_mode);
				exists = 1;
			}
			if (exists || !exts[ext].optional) {
				if (rename(fname_old, fname))
					die_errno(_("renaming '%s' failed"), fname_old);
			}
			free(fname);
			free(fname_old);
		}