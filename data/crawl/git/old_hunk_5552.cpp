		}
	}
done:
	packet_write(fd[1], "done\n");
	if (args.verbose)
		fprintf(stderr, "done\n");
	if (retval != 0) {
