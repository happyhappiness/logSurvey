		new_p = add_packed_git(idx_name, strlen(idx_name), 1);
		if (!new_p)
			die("core git rejected index %s", idx_name);
		new_p->windows = old_p->windows;
		all_packs[pack_id] = new_p;
		install_packed_git(new_p);

