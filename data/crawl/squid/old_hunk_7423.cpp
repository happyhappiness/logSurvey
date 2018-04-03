		maxfd = fd;
	}
    }

    if (maxfd++ == 0)
	return;
    if (select(maxfd, &read_mask, &write_mask, NULL, &zero_tv) > 0) {
	getCurrentTime();
	for (i = 0; i < N; i++) {
	    fd = fds[i];
	    if (FD_ISSET(fd, &read_mask)) {
		hdl = fd_table[fd].read_handler;
		fd_table[fd].read_handler = 0;
		hdl(fd, fd_table[fd].read_data);
	    }
	    if (FD_ISSET(fd, &write_mask)) {
		hdl = fd_table[fd].write_handler;
		fd_table[fd].write_handler = 0;
		hdl(fd, fd_table[fd].write_data);
	    }
	}
    }
}


/* Select on all sockets; call handlers for those that are ready. */
int
