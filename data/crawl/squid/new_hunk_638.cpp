                        --len;
                    }

                    try { // std::regex constructor throws on pattern errors
                        // insert into list of expressions
                        if (!head)
                            tail = head = new REList(line,option=='F');
                        else {
                            tail->next = new REList(line,option=='F');
                            tail = tail->next;
                        }
                    } catch (std::regex_error &e) {
                        fprintf(stderr, "%s:%lu: invalid regular expression\n", optarg, lineno);
                        exit(1);
                    }
                }
                fclose(rfile);
