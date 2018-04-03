              {
                unsigned int l = p - variable_buffer;
                *(--semip) = ';';
                variable_buffer_output (p2 + strlen (p2),
                                        semip, strlen (semip)+1);
                p = variable_buffer + l;
