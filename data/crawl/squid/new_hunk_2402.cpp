#define        __BIT_TYPES_DEFINED__
#endif

static int session_ttl = 3600;
static int fixed_timeout = 0;
char *db_path = NULL;
const char *program_name;

DB *db = NULL;
DB_ENV *db_env = NULL;

static void init_db(void)
{
    struct stat st_buf;

    if (db_path) {
        if (!stat(db_path, &st_buf)) {
            if (S_ISDIR (st_buf.st_mode)) {
                /* If directory then open database environment. This prevents sync problems
                    between different processes. Otherwise fallback to single file */
                db_env_create(&db_env, 0);
                if (db_env->open(db_env, db_path, DB_CREATE | DB_INIT_MPOOL | DB_INIT_LOCK , 0666)) {
                    fprintf(stderr, "FATAL: %s: Failed to open database environment in '%s'\n", program_name, db_path);
                    db_env->close(db_env, 0);
                    exit(1);
                }
                db_create(&db, db_env, 0);
            }
        }
    }

    if (db_env) {
        if (db->open(db, NULL, "session", NULL, DB_BTREE, DB_CREATE, 0666)) {
            fprintf(stderr, "FATAL: %s: Failed to open db file '%s' in dir '%s'\n",
                    program_name, "session", db_path);
            db_env->close(db_env, 0);
            exit(1);
        }
    } else {
        db_create(&db, NULL, 0);
        if (db->open(db, NULL, db_path, NULL, DB_BTREE, DB_CREATE, 0666)) {
            fprintf(stderr, "FATAL: %s: Failed to open session db '%s'\n", program_name, db_path);
            exit(1);
        }
    }
}

static void shutdown_db(void)
{
    db->close(db, 0);
    if (db_env) {
        db_env->close(db_env, 0);
    }
}

int session_is_active = 0;

static int session_active(const char *details, size_t len)
{
    DBT key = {0};
    DBT data = {0};
    key.data = (void *)details;
    key.size = len;
    if (db->get(db, NULL, &key, &data, 0) == 0) {
        time_t timestamp;
        if (data.size != sizeof(timestamp)) {
            fprintf(stderr, "ERROR: %s: CORRUPTED DATABASE (%s)\n", program_name, details);
            db->del(db, NULL, &key, 0);
            return 0;
        }
        memcpy(&timestamp, data.data, sizeof(timestamp));
