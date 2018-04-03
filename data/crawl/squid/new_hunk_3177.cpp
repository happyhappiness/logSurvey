
int session_is_active = 0;

static int session_active(const char *details, size_t len)
{
    DBT key, data;
    key.data = (void *)details;
    key.size = len;
    if (db->get(db, &key, &data, 0) == 0) {
        time_t timestamp;
        if (data.size != sizeof(timestamp)) {
            fprintf(stderr, "ERROR: %s: CORRUPTED DATABASE (%s)\n", program_name, details);
            db->del(db, &key, 0);
            return 0;
        }
