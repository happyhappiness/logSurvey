		if (set_helper_option(transport, TRANS_OPT_PUSH_CERT, "if-asked") != 0)
			die("helper %s does not support --signed=if-asked", name);
	}
}

static int push_refs_with_push(struct transport *transport,