	return ret;
}

static struct imap_cmd *v_issue_imap_cmd(struct imap_store *ctx,
					 struct imap_cmd_cb *cb,
					 const char *fmt, va_list ap)
