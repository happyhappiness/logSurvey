	    if (read_reply(pconn_fd) != 0)
		pconn_fd = -1;
	}
    }
}

void
usage(void)
{
    fprintf(stderr, "usage: %s: -p port -h host -n max\n", progname);
}

int
