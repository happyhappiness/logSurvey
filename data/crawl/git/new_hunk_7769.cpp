				packet_write(out, "%s %s %s",
					old_hex, new_hex, ref->name);
		}
		ref->status = expect_status_report ?
			REF_STATUS_EXPECTING_REPORT :
			REF_STATUS_OK;
	}

	packet_flush(out);
