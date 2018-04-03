					struct commit *commit =
						lookup_commit(result_sha1);
					if (!commit)
						die(_("invalid commit %s"), sha1_to_hex(result_sha1));
					if (args->stateless_rpc
					 && ack == ACK_common
					 && !(commit->object.flags & COMMON)) {
