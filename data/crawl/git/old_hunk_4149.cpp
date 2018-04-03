					return NULL;
				}
				cwd[offset] = '\0';
				die("Not a git repository (or any parent up to mount parent %s)\n"
				"Stopping at filesystem boundary (GIT_DISCOVERY_ACROSS_FILESYSTEM not set).", cwd);
			}
		}
		if (chdir("..")) {
			cwd[offset] = '\0';
			die_errno("Cannot change to '%s/..'", cwd);
		}
	}
}
