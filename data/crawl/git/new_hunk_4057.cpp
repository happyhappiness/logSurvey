		end_revision();
}

static void init(int report_fd)
{
	fast_export_init(report_fd);
	strbuf_init(&dump_ctx.uuid, 4096);
	strbuf_init(&dump_ctx.url, 4096);
	strbuf_init(&rev_ctx.log, 4096);
