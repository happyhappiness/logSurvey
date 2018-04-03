                /* If directory then open database environment. This prevents sync problems
                    between different processes. Otherwise fallback to single file */
                db_env_create(&db_env, 0);
                if (db_env->open(db_env, db_path, DB_CREATE | DB_INIT_MPOOL | DB_INIT_LOCK, 0666)) {
                    fprintf(stderr, "FATAL: %s: Failed to open database environment in '%s'\n", program_name, db_path);
                    db_env->close(db_env, 0);
                    exit(EXIT_FAILURE);
