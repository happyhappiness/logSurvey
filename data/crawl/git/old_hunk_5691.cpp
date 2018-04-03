		ecb.priv = &data;
		xdi_diff(&mf1, &mf2, &xpp, &xecfg, &ecb);

		if ((data.ws_rule & WS_TRAILING_SPACE) &&
		    data.trailing_blanks_start) {
			fprintf(o->file, "%s:%d: ends with blank lines.\n",
				data.filename, data.trailing_blanks_start);
			data.status = 1; /* report errors */
		}
	}
