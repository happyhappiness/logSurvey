                        --len;
                    }

                    // insert into list of expressions
                    if ( head == 0 ) tail = head = new REList(line,option=='F');
                    else {
                        tail->next = new REList(line,option=='F');
                        tail = tail->next;
                    }
                }
                fclose(rfile);
