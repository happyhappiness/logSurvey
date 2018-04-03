			}
			if (!(f = fopen(filename, "w")))
				die("Could not open %s", filename);
			fprintf(f, "%s\n", sha1_to_hex(obj->sha1));
			fclose(f);
		}
		return;