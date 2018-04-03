			}
			XML_ParserFree(parser);
			if (!lock_flags)
				error("no DAV locking support on %s",
				      remote->url);

		} else {
