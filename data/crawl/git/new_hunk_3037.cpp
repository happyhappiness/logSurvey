				struct strbuf log_file = STRBUF_INIT;
				int ret;
				const char *ref_name;
				struct strbuf err = STRBUF_INIT;

				ref_name = mkpath("refs/heads/%s", opts->new_orphan_branch);
				temp = log_all_ref_updates;
				log_all_ref_updates = 1;
				ret = log_ref_setup(ref_name, &log_file, &err);
				log_all_ref_updates = temp;
				strbuf_release(&log_file);
				if (ret) {
					fprintf(stderr, _("Can not do reflog for '%s': %s\n"),
						opts->new_orphan_branch, err.buf);
					strbuf_release(&err);
					return;
				}
			}
