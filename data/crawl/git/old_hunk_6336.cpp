			}
			XML_ParserFree(parser);
			if (!lock_flags)
				error("Error: no DAV locking support on %s",
				      remote->url);

		} else {
