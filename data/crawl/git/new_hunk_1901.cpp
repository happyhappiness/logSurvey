				continue;
			if (starts_with(line, "unshallow "))
				continue;
			die(_("git fetch-pack: expected shallow list"));
		}
	}
}
