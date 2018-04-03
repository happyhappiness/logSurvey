					item->arg, item->arg_len, opts, res,
					!res);
			}
		} else if (!is_noop(item->command))
			return error(_("unknown command %d"), item->command);
