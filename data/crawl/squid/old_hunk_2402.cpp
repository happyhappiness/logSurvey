#define        __BIT_TYPES_DEFINED__
#endif

#if HAVE_DB_185_H
#include <db_185.h>
#elif HAVE_DB_H
#include <db.h>
#endif

static int session_ttl = 3600;
static int fixed_timeout = 0;
char *db_path = NULL;
const char *program_name;

DB *db = NULL;

static void init_db(void)
{
    db = dbopen(db_path, O_CREAT | O_RDWR, 0666, DB_BTREE, NULL);
    if (!db) {
        fprintf(stderr, "FATAL: %s: Failed to open session db '%s'\n", program_name, db_path);
        exit(1);
    }
}

static void shutdown_db(void)
{
    db->close(db);
}

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
        memcpy(&timestamp, data.data, sizeof(timestamp));
