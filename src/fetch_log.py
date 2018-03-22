#-*-coding: utf-8 -*-
"""
input: hunk info
BY: gumtree
output: log info
log info [hunk info, log type, old log statement, new log statement, log action]
"""
import csv
import sys
import json
from itertools import islice
from gumtree_api import Gumtree
import my_util

reload(sys)
sys.setdefaultencoding('utf-8')

def store_log( hunk_info, old_loc, new_loc, old_log, new_log, writer, gumtree):
    """
    @ param hunk info, old, new loc and log, writer and gumtree object\n
    @ return nothing\n
    @ involve deal with log, get edit type, edit word and edit feature\n
    """
    if old_log is None:
        old_log = ''
    if new_log is None:
        new_log = ''
    # get edit word and feature
    edit_words, edit_feature = gumtree.get_word_edit_from_log(old_log, new_log)
    # get edit type
    old_log_temp_file = 'data/crawl/temp_old_log.cpp'
    new_log_temp_file = 'data/crawl/temp_new_log.cpp'
    my_util.save_file(old_log_temp_file, old_log)
    my_util.save_file(new_log_temp_file, new_log)
    gumtree.set_old_new_file(old_log_temp_file, new_log_temp_file)
    if new_loc == -1:
        edit_types = ['removeLog']
    elif old_loc == -1:
        edit_types = ['addLog']
    else:
        edit_types = gumtree.get_log_edited_type()
    writer.writerow(hunk_info + [old_loc, new_loc, old_log, new_log,\
             json.dumps(edit_types), json.dumps(edit_words), json.dumps(edit_feature)])

def deal_hunk(hunk_record, writer, gumtree, total_log):
    """
    @ param hunk record, log writer, gumtree object and log counter\n
    @ return new log counter\n
    @ involve deal with each hunk and retieve log info\n
    """
    # old and new log locs
    old_log_locs = json.loads(hunk_record[my_util.OLD_LOG_LOCS_INDEX])
    new_log_locs = json.loads(hunk_record[my_util.NEW_LOG_LOCS_INDEX])
    old_hunk_file = hunk_record[my_util.OLD_HUNK_INDEX]
    new_hunk_file = hunk_record[my_util.NEW_HUNK_INDEX]
    # gumtree deal with old and new hunk file
    gumtree.set_old_new_file(old_hunk_file, new_hunk_file)
    gumtree.add_old_log_nodes(old_log_locs)
    gumtree.add_new_log_nodes(new_log_locs)

    # deal with log existing in old file
    for old_loc in old_log_locs:
        if gumtree.set_old_loc(old_loc):
            # get log loc in old hunk, old loc and old log
            old_log = gumtree.get_old_log()

            # get log loc in new hunk, new loc and new log
            new_loc = gumtree.get_new_loc()
            new_log = gumtree.get_new_log()
            # if has corresponding new log
            if new_loc != -1:
                # remove mapping new_log_loc
                if new_loc in new_log_locs:
                    new_log_locs.remove(new_loc)
            # action type = hunk action type + log edit flag
            if gumtree.is_old_log_edited() == 1:
                store_log(hunk_record[:-2], old_loc, new_loc, old_log, new_log, writer, gumtree)
                gumtree.set_old_new_file(old_hunk_file, new_hunk_file)
                total_log += 1

    # deal with inserted log
    for new_loc in new_log_locs:
        if gumtree.set_new_loc(new_loc):
            # new loc and new log
            new_log = gumtree.get_new_log()
            store_log(hunk_record[:-2], -1, new_loc, None, new_log, writer, gumtree)
            gumtree.set_old_new_file(old_hunk_file, new_hunk_file)
            total_log += 1

    return total_log

def fetch_hunk(gumtree):
    """
    @ param gumtree object \n
    @ return nothing \n
    @ involve fetch and analyze each hunk to get log record\n
    """
    # initiate csvfile
    hunk_file = file(my_util.HUNK_RECORD_FILE, 'rb')
    hunk_records = csv.reader(hunk_file)

    log_file = file(my_util.LOG_RECORD_FILE, 'wb')
    log_writer = csv.writer(log_file)
    log_writer.writerow(my_util.LOG_RECORD_TITLE)

    total_log = 0
    total_hunk = 0
    # call deal hunk to anlyze each hunk file
    for hunk_record in islice(hunk_records, 1, None):
        total_hunk += 1
        total_log = deal_hunk(hunk_record, log_writer, gumtree, total_log)
        print 'have dealed with %d hunk, found %d log' %(total_hunk, total_log)

    # close file
    hunk_file.close()
    log_file.close()

"""
main function
"""
if __name__ == "__main__":
    gumtree = Gumtree()
    my_util.set_user_repos(repos_name='tar')
    fetch_hunk(gumtree)