#-*-coding: utf-8 -*-
import csv
import sys
import json
from itertools import islice
import cluster_api
import my_util

reload(sys)
sys.setdefaultencoding('utf-8')

def cluster_edition():
    """
    @ param nothing\n
    @ return nothing\n
    @ involve cluster by edition\n
    """
    # initialize read file
    read_file = file(my_util.LOG_RECORD_FILE, 'rb')
    records = csv.reader(read_file)

    feature_lists = []
    # build feature list
    for record in islice(records, 1, None):
        # old cdg feature
        edit_feature = json.loads(record[my_util.EDIT_FEATURE_INDEX])
        feature_lists.append(edit_feature)
    read_file.close()

    # cluster log statement based on cdg_list and ddg_list
    cluster_lists = cluster_api.cluster_record_with_equality_mine(feature_lists)
    # record cluster index of each log statement
    read_file = file(my_util.LOG_RECORD_FILE, 'rb')
    records = csv.reader(read_file)
    sort_records = []
    index = 0
    for record in islice(records, 1, None):
        record = record + [cluster_lists[index]]
        sort_records.append(record)
        index += 1
    read_file.close()
    #  call sort to sort
    sort_records.sort(key=lambda x:x[-1], reverse=True)
    #  writer sorted log record
    write_file = file(my_util.CLUSTER_RECORD_FILE, 'wb')
    write_file_writer = csv.writer(write_file)
    write_file_writer.writerow(my_util.CLUSTER_RECORD_TITLE)
    for record in sort_records:
        write_file_writer.writerow(record)

    # close files
    write_file.close()

"""
main function
"""
if __name__ == "__main__":
    my_util.set_user_repos(repos_name='tar')
    cluster_edition()