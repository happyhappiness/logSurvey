	return parse_ls_response(get_response_line(), mode, dataref);
}

void fast_export_blob_delta(uint32_t mode,
				uint32_t old_mode, const char *old_data,
				off_t len, struct line_buffer *input)
