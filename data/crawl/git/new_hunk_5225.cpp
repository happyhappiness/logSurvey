			}
		}
	}
	if (options->output_prefix) {
		struct strbuf *msg = NULL;
		msg = options->output_prefix(options,
				options->output_prefix_data);
		fprintf(options->file, "%s", msg->buf);
	}
	fprintf(options->file, " %d files changed, %d insertions(+), %d deletions(-)\n",
	       total_files, adds, dels);
}
