      {
	off_t offset;

	name_length = strlen (current_file_name) - 1;
	if (current_file_name[name_length] == '/')
	  goto really_dir;

	if (!get_stat_data (&stat_data))
	  break;

	if (!S_ISREG (stat_data.st_mode))
	  {
	    report_difference (_("Not a regular file"));
	    skip_file ((long) current_stat.st_size);
	    break;
	  }

	stat_data.st_mode &= 07777;
	offset = from_oct (1 + 12, current_header->oldgnu_header.offset);
	if (stat_data.st_size != current_stat.st_size + offset)
	  {
	    report_difference (_("Size differs"));
	    skip_file ((long) current_stat.st_size);
	    break;
	  }

	diff_handle = open (current_file_name, O_NDELAY | O_RDONLY | O_BINARY);

	if (diff_handle < 0)
	  {
	    WARN ((0, errno, _("Cannot open file %s"), current_file_name));
	    report_difference (NULL);
	    skip_file ((long) current_stat.st_size);
	    break;
	  }

	status = lseek (diff_handle, offset, 0);
	if (status != offset)
	  {
	    WARN ((0, errno, _("Cannot seek to %ld in file %s"),
		   offset, current_file_name));
	    report_difference (NULL);
	    break;
	  }

	if (multi_volume_option)
	  {
	    assign_string (&save_name, current_file_name);
	    save_totsize = stat_data.st_size;
	    /* save_sizeleft is set in read_and_process.  */
	  }

	read_and_process ((long) (current_stat.st_size), process_rawdata);

	if (multi_volume_option)
	  assign_string (&save_name, NULL);

	status = close (diff_handle);
	if (status < 0)
	  ERROR ((0, errno, _("Error while closing %s"), current_file_name));

	break;
      }
    }
}

/*---.
| ?  |
`---*/

void
verify_volume (void)
{
