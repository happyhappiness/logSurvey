			dirname);
		return;
	}
	while ((de = readdir(dir)) != NULL)
		if (!prefixcmp(de->d_name, "tmp_"))
			prune_tmp_object(dirname, de->d_name);
	closedir(dir);
}
