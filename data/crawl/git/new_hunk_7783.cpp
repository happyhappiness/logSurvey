		int slot = parse_status_slot(k, 13);
		color_parse(v, k, wt_status_colors[slot]);
	}
	return git_default_config(k, v);
}