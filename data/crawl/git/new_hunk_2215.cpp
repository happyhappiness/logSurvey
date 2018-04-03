			strbuf_addbuf(&pp->buffered_output, &pp->children[i].err);
			strbuf_reset(&pp->children[i].err);
		} else {
			strbuf_write(&pp->children[i].err, stderr);
			strbuf_reset(&pp->children[i].err);

			/* Output all other finished child processes */
			strbuf_write(&pp->buffered_output, stderr);
			strbuf_reset(&pp->buffered_output);

			/*
