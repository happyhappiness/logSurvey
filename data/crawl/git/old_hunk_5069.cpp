		}
		exit(cmd->exec(cmd->name, arg));
	}
	die("unrecognized command '%s'", prog);
}