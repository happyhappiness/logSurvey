    sd->max_objsize = size;
}

static struct cache_dir_option common_cachedir_options[] =
{
    {"read-only", parse_cachedir_option_readonly},
    {"max-size", parse_cachedir_option_maxsize},
    {NULL, NULL}
};

