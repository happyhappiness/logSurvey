				close_pair(fdout);
			else if (cmd->out)
				close(cmd->out);
fail_pipe:
			error("cannot create pipe for %s: %s",
				cmd->argv[0], strerror(failed_errno));
			errno = failed_errno;
			return -1;
		}
		cmd->err = fderr[0];
	}
