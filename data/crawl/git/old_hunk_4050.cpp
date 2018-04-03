	return ret;
}

void fast_export_data(uint32_t mode, off_t len, struct line_buffer *input)
{
	assert(len >= 0);
