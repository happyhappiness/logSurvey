				case ACK_ready:
				case ACK_continue: {
					struct commit *commit =
						lookup_commit(result_oid->hash);
					if (!commit)
						die(_("invalid commit %s"), oid_to_hex(result_oid));
					if (args->stateless_rpc
					 && ack == ACK_common
					 && !(commit->object.flags & COMMON)) {
						/* We need to replay the have for this object
						 * on the next RPC request so the peer knows
						 * it is in common with us.
						 */
						const char *hex = oid_to_hex(result_oid);
						packet_buf_write(&req_buf, "have %s\n", hex);
						state_len = req_buf.len;
						/*
