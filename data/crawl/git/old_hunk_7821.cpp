			pollsize++;
		}

		if (pollsize) {
			if (poll(pfd, pollsize, -1) < 0) {
				if (errno != EINTR) {
					error("poll failed, resuming: %s",
					      strerror(errno));
					sleep(1);
				}
				continue;
			}
			if (0 <= pu && (pfd[pu].revents & (POLLIN|POLLHUP))) {
				/* Data ready; we keep the last byte
				 * to ourselves in case we detect
				 * broken rev-list, so that we can
				 * leave the stream corrupted.  This
				 * is unfortunate -- unpack-objects
				 * would happily accept a valid pack
				 * data with trailing garbage, so
				 * appending garbage after we pass all
				 * the pack data is not good enough to
				 * signal breakage to downstream.
				 */
				char *cp = data;
				ssize_t outsz = 0;
				if (0 <= buffered) {
					*cp++ = buffered;
					outsz++;
				}
				sz = xread(pack_objects.out, cp,
					  sizeof(data) - outsz);
				if (0 < sz)
						;
				else if (sz == 0) {
					close(pack_objects.out);
					pack_objects.out = -1;
				}
				else
					goto fail;
				sz += outsz;
				if (1 < sz) {
					buffered = data[sz-1] & 0xFF;
					sz--;
				}
				else
					buffered = -1;
				sz = send_client_data(1, data, sz);
				if (sz < 0)
					goto fail;
			}
			if (0 <= pe && (pfd[pe].revents & (POLLIN|POLLHUP))) {
				/* Status ready; we ship that in the side-band
				 * or dump to the standard error.
				 */
				sz = xread(pack_objects.err, progress,
					  sizeof(progress));
				if (0 < sz)
					send_client_data(2, progress, sz);
				else if (sz == 0) {
					close(pack_objects.err);
					pack_objects.err = -1;
				}
				else
					goto fail;
			}
		}

		/* See if the children are still there */
		if (rev_list.pid || pack_objects.pid) {
			pid = waitpid(-1, &status, WNOHANG);
			if (!pid)
				continue;
			who = ((pid == rev_list.pid) ? "git-rev-list" :
			       (pid == pack_objects.pid) ? "git-pack-objects" :
			       NULL);
			if (!who) {
				if (pid < 0) {
					error("git-upload-pack: %s",
					      strerror(errno));
					goto fail;
				}
				error("git-upload-pack: we weren't "
				      "waiting for %d", pid);
				continue;
			}
			if (!WIFEXITED(status) || WEXITSTATUS(status) > 0) {
				error("git-upload-pack: %s died with error.",
				      who);
				goto fail;
			}
			if (pid == rev_list.pid)
				rev_list.pid = 0;
			if (pid == pack_objects.pid)
				pack_objects.pid = 0;
			if (rev_list.pid || pack_objects.pid)
				continue;
		}

		/* both died happily */
		if (pollsize)
			continue;

		/* flush the data */
		if (0 <= buffered) {
			data[0] = buffered;
			sz = send_client_data(1, data, 1);
			if (sz < 0)
				goto fail;
			fprintf(stderr, "flushed.\n");
		}
		if (use_sideband)
			packet_flush(1);
		return;
	}
 fail:
	if (pack_objects.pid)
		kill(pack_objects.pid, SIGKILL);
	if (rev_list.pid)
		kill(rev_list.pid, SIGKILL);
	send_client_data(3, abort_msg, sizeof(abort_msg));
	die("git-upload-pack: %s", abort_msg);
}