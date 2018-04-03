#-*-coding: utf-8 -*-
import csv
import re
from itertools import islice
import commands
import json
import my_util

def store_hunk(old_hunk, new_hunk, patch_hunk, total_hunk):
    """
    @ param old, new and patch hunk and hunk counter\n
    @ return old, new, patch hunk file name and new counter\n
    @ involve store old, new and patch hunk file\n
    """
    # store old hunk file
    old_hunk_name = my_util.OLD_HUNK_FILE_PREFIX + str(total_hunk) + '.cpp'
    my_util.save_file(old_hunk_name, old_hunk)

    # store new hunk file
    new_hunk_name = my_util.NEW_HUNK_FILE_PREFIX + str(total_hunk) + '.cpp'
    my_util.save_file(new_hunk_name, new_hunk)

    # store patch hunk file
    patch_hunk_name = my_util.HUNK_FILE_PREFIX + str(total_hunk) + '.cpp'
    my_util.save_file(patch_hunk_name,patch_hunk)
    total_hunk += 1

    return total_hunk, old_hunk_name, new_hunk_name, patch_hunk_name

def deal_patch(patch_record, total_hunk, writer):
    """
    @ param patch record, hunk counter and hunk writer\n
    @ return new hunk counter\n
    @ involve split each hunk and record old log locs and new log locs if exist\n
    """
    # old and new hunk content
    old_hunk = new_hunk = patch_hunk = ''
    # old and new log locations
    old_loc = new_loc = 0
    old_log_locs = []
    new_log_locs = []

    # deal with each line of patch
    patch_file = file(patch_record[my_util.FILE_NAME_INDEX], 'rb')
    patch = patch_file.readlines()
    for line in patch:
        # recognize change hunk by description info
        is_hunk = re.match(r'^@@ -\d*,\d* \+\d*,\d* @@', line)
        # deal with past hunk and record new one
        if is_hunk:
            # if found log modification
            if len(old_log_locs) != 0 or len(new_log_locs) != 0:
                total_hunk, old_hunk_name, new_hunk_name, patch_hunk_name = store_hunk(old_hunk, new_hunk, patch_hunk, total_hunk)
                writer.writerow(patch_record[:-1] + [patch_hunk_name] + [None, None] + [old_hunk_name, new_hunk_name, \
                    json.dumps(old_log_locs), json.dumps(new_log_locs)])
            # initialize hunk info
            old_hunk = new_hunk = patch_hunk = ''
            old_loc = new_loc = 0
            old_log_locs = []
            new_log_locs = []
            continue

        # record change type flag
        change_type = line[0]
        if change_type not in ['-', '+', ' '] or line.startswith('--') or line.startswith('++'):
            continue
        patch_hunk += line
        line = line[1:]
        # decide if it belongs to log change
        is_log_change = re.search(my_util.LOG_PATTERN, line, re.I)
        # + and common
        if change_type != '-':
            new_hunk += line
            if is_log_change:
                new_log_locs.append(new_loc)
            new_loc += 1
        # - and common
        if change_type != '+':
            old_hunk += line
            if is_log_change:
                old_log_locs.append(old_loc)
            old_loc += 1

    # deal with last hunk, if has log update
    if len(old_log_locs) != 0 or len(new_log_locs) != 0:
            total_hunk, old_hunk_name, new_hunk_name, patch_hunk_name = store_hunk(old_hunk, new_hunk, patch_hunk, total_hunk)
            writer.writerow(patch_record[:-1] + [patch_hunk_name] + [None, None] + [old_hunk_name, new_hunk_name, \
                json.dumps(old_log_locs), json.dumps(new_log_locs)])

    patch_file.close()
    return total_hunk

def fetch_patch():
    """
    @ param nothing\n
    @ return nothing\n
    @ involve analyze each patch record to get hunk record\n
    """
    # initiate csv file
    patch_file = file(my_util.PATCH_RECORD_FILE, 'rb')
    patch_records = csv.reader(patch_file)
    hunk_file = file(my_util.HUNK_RECORD_FILE, 'wb')
    hunk_writer = csv.writer(hunk_file)
    hunk_writer.writerow(my_util.HUNK_RECORD_TITLE)

    # fetch patch file record
    total_hunk = 0
    total_patch = 0
    for record in islice(patch_records, 1, None):
        if record == [] or record[0] == '':
            continue
        total_hunk = deal_patch(record, total_hunk, hunk_writer)
        total_patch += 1
        print 'now processing patch %d, found hunk %d' %(total_patch, total_hunk)
    # close file and output analysis result
    patch_file.close()
    hunk_file.close()

"""
main function
"""
if __name__ == "__main__":
    my_util.set_user_repos(repos_name='tar')
    fetch_patch()


