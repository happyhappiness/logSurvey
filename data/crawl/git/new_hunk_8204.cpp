			}
			if (!(f = fopen(filename, "w")))
				die("Could not open %s", filename);
			if (obj->type == OBJ_BLOB) {
				enum object_type type;
				unsigned long size;
				char *buf = read_sha1_file(obj->sha1,
						&type, &size);
				if (buf) {
					fwrite(buf, size, 1, f);
					free(buf);
				}
			} else
				fprintf(f, "%s\n", sha1_to_hex(obj->sha1));
			fclose(f);
		}
		return;