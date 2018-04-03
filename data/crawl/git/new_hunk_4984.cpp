		}
	}

	cld.argv = (const char **)cld_argv;
	cld.in = incoming;
	cld.out = dup(incoming);

	if (start_command(&cld))
		logerror("unable to fork");
	else
		add_child(&cld, addr, addrlen);
	close(incoming);
}

static void child_handler(int signo)
