                if i < last:
                    quit = False
                    while True:
                        print "What do you want to do?"
                        response = raw_input("[s]kip this commit but apply"
                                             " the rest, or [q]uit? ")
                        if not response:
                            continue
                        if response[0] == "s":
                            print "Skipping this commit, but applying the rest"
                            break
