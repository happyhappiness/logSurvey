				advice_status_hints
				? _(" (use \"git add\" to track)") : "");
		else if (s->is_initial)
			printf(_("nothing to commit%s\n"), advice_status_hints
				? _(" (create/copy files and use \"git add\" to track)") : "");
		else if (!s->show_untracked_files)
			printf(_("nothing to commit%s\n"), advice_status_hints
				? _(" (use -u to show untracked files)") : "");
		else
			printf(_("nothing to commit%s\n"), advice_status_hints
				? _(" (working directory clean)") : "");
	}
}
