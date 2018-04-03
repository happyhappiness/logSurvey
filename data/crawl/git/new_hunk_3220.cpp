			 */
			goto retry;
		else {
			unable_to_lock_message(ref_file, errno, err);
			goto error_return;
		}
	}
	return old_sha1 ? verify_lock(lock, old_sha1, mustexist) : lock;

 error_return:
	unlock_ref(lock);
	errno = last_errno;
	return NULL;
}
