                    decodedLen = base64_decode(decoded, sizeof(decoded), c);
                    debug("sending 'AF' %s to squid with data:\n", cred);
                    if (c != NULL)
                        hex_dump(reinterpret_cast<unsigned char*>(decoded), decodedLen);
                    else
                        fprintf(stderr, "No data available.\n");
                    printf("AF %s %s\n", c, cred);
