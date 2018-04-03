	info.revs = &revs;
	info.bisect_show_flags = BISECT_SHOW_TRIED | BISECT_SHOW_STRINGED;

	bisect_common(&revs, prefix, &reaches, &all);

	return show_bisect_vars(&info, reaches, all);
}