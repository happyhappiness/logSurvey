			node_ctx.prop_delta = !strcmp(val, "true");
		} else if (key == keys.content_length) {
			len = atoi(val);
			buffer_read_line(&input);
			if (active_ctx == REV_CTX) {
				read_props();
			} else if (active_ctx == NODE_CTX) {
				handle_node();
				active_ctx = REV_CTX;
			} else {
				fprintf(stderr, "Unexpected content length header: %"PRIu32"\n", len);
				buffer_skip_bytes(&input, len);
			}
		}
	}
	if (active_ctx == NODE_CTX)
		handle_node();
	if (active_ctx != DUMP_CTX)