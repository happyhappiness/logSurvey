	case UC_ENABLE:
	case UC_FORCE:
		if (git_config_get_untracked_cache() == 0)
			warning("core.untrackedCache is set to false; "
				"remove or change it, if you really want to "
				"enable the untracked cache");
		add_untracked_cache(&the_index);
		report(_("Untracked cache enabled for '%s'"), get_git_work_tree());
		break;