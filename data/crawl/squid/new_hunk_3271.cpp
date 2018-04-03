            }
        }
        if ((user = strtok(buf, " ")) == NULL) {
            SEND_ERR("");
            continue;
        }
        if ((passwd = strtok(NULL, "")) == NULL) {
            SEND_ERR("");
            continue;
        }
        rfc1738_unescape(user);
        rfc1738_unescape(passwd);
        u = (user_data *) hash_lookup(hash, user);
        if (u == NULL) {
            SEND_ERR("No such user");
#if HAVE_CRYPT
        } else if (strcmp(u->passwd, (char *) crypt(passwd, u->passwd)) == 0) {
            SEND_OK("");
#endif
        } else if (strcmp(u->passwd, (char *) crypt_md5(passwd, u->passwd)) == 0) {
            SEND_OK("");
        } else if (strcmp(u->passwd, (char *) md5sum(passwd)) == 0) {	/* md5 without salt and magic strings - Added by Ramon de Carvalho and Rodrigo Rubira Branco */
            SEND_OK("");
        } else {
            SEND_ERR("Wrong password");
        }
    }
    if (hash != NULL) {
