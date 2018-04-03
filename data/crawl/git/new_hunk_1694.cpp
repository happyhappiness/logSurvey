				if (stream_blob_to_fd(fileno(f), obj->oid.hash, NULL, 1))
					die_errno("Could not write '%s'", filename);
			} else
				fprintf(f, "%s\n", describe_object(obj));
			if (fclose(f))
				die_errno("Could not finish '%s'",
					  filename);
