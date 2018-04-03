				lock->timeout = -1;
			}
			XML_ParserFree(parser);
		}
	} else {
		fprintf(stderr, "Unable to start LOCK request\n");