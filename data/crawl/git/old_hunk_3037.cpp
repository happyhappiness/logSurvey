				struct strbuf log_file = STRBUF_INIT;
				int ret;
				const char *ref_name;

				ref_name = mkpath("refs/heads/%s", opts->new_orphan_branch);
				temp = log_all_ref_updates;
				log_all_ref_updates = 1;
				ret = log_ref_setup(ref_name, &log_file);
				log_all_ref_updates = temp;
				strbuf_release(&log_file);
				if (ret) {
					fprintf(stderr, _("Can not do reflog for '%s'\n"),
					    opts->new_orphan_branch);
					return;
				}
			}
