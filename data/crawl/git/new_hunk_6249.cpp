			return;
		}
	}
	if (strchr(arg, '%')) {
		save_user_format(rev, arg, 1);
		return;
	}

	die("invalid --pretty format: %s", arg);
}
