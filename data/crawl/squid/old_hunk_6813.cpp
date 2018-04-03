	    status = errno == ENOSPC ? DISK_NO_SPACE_LEFT : DISK_ERROR;
	    debug(50, 1) ("diskHandleWrite: FD %d: disk write error: %s\n",
		fd, xstrerror());
	    if (fdd->wrt_handle == NULL || status != DISK_NO_SPACE_LEFT) {
		/* FLUSH PENDING BUFFERS */
		do {
		    fdd->write_q = q->next;
		    if (q->free_func)
			(q->free_func) (q->buf);
		    safe_free(q);
		} while ((q = fdd->write_q));
	    }
	}
	len = 0;
    }
