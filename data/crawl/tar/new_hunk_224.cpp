    }
}

bool
sys_compare_uid (struct stat *a, struct stat *b)
{
  return a->st_uid == b->st_uid;
}

bool
sys_compare_gid (struct stat *a, struct stat *b)
{
  return a->st_gid == b->st_gid;
}

bool
sys_compare_links (struct stat *link_data, struct stat *stat_data)
{
  return stat_data->st_dev == link_data->st_dev
         && stat_data->st_ino == link_data->st_ino;
}

int
