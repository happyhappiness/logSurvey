			strbuf_addbuf(&pp->buffered_output, &pp->children[i].err);
			strbuf_reset(&pp->children[i].err);
		} else {
			fputs(pp->children[i].err.buf, stderr);
			strbuf_reset(&pp->children[i].err);

			/* Output all other finished child processes */
			fputs(pp->buffered_output.buf, stderr);
			strbuf_reset(&pp->buffered_output);

			/*
