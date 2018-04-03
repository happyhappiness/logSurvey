        safe_free(basicAuthRealm);
}

void
Auth::Basic::Config::dump(StoreEntry * entry, const char *name, Auth::Config * scheme)
{
