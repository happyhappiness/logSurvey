			unsetenv(GIT_WORK_TREE_ENVIRONMENT);
			unsetenv(GRAFT_ENVIRONMENT);
			unsetenv(INDEX_ENVIRONMENT);
			execlp("sh", "sh", "-c", cmd.buf, NULL);
		}
		die("exec failed");
	}
