		}
		apply_autostash(opts);

		fprintf(stderr, "Successfully rebased and updated %s.\n",
			head_ref.buf);

		strbuf_release(&buf);
		strbuf_release(&head_ref);
	}