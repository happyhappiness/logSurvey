             */
            user=xmalloc(output_token.length+1);
            if (user == NULL) {
                if (debug)
                    fprintf(stderr, "%s| %s: Not enough memory\n", LogTime(), PROGRAM);
                fprintf(stdout, "BH Not enough memory\n");
                goto cleanup;
            }
            memcpy(user,output_token.value,output_token.length);
            user[output_token.length]='\0';
