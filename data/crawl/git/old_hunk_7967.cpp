			unsetenv(GIT_WORK_TREE_ENVIRONMENT);
			unsetenv(GRAFT_ENVIRONMENT);
			unsetenv(INDEX_ENVIRONMENT);
			execlp("sh", "sh", "-c", command, NULL);
		}
		die("exec failed");
	}
