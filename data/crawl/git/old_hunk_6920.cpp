				 * only files can overwrite each other:
				 * check both source and destination
				 */
				if (S_ISREG(st.st_mode)) {
					fprintf(stderr, "Warning: %s;"
							" will overwrite!\n",
							bad);
					bad = NULL;
					string_list_insert(dst, &overwritten);
				} else
					bad = "Cannot overwrite";
			}
