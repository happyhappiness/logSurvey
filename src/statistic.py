from itertools import islice 
from datetime import datetime
import cluster_api
import csv
import json
import my_util

def get_edit_type_for_cluster(cluster, edit_type_dict, cluster_log_counter):
    """
    @ param record list for this cluster and dictory of edit type\n
    @ return edit_type dict and cluster counter\n
    @ involve get dictory for cluster\n
    """
    for record in cluster:
        edit_types = json.loads(record[my_util.EDIT_TYPE_INDEX])
        cluster_log_counter += 1
        for edit_type in edit_types:
            edit_type_dict[edit_type] += 1
    return edit_type_dict, cluster_log_counter

def get_edit_type(file_writer):
    """
    @ param statistic file writer\n
    @ return ...\n
    @ involve get statistical info about edit type\n
    """
    reading_file = file(my_util.CLUSTER_RECORD_FILE, 'rb')
    records = csv.reader(reading_file)
    # initialize edit type dictary
    edit_type_for_log_dict = {}
    edit_type_for_cluster_dict = {}
    for i in my_util.LOG_EDIT_TYPES:
        edit_type_for_log_dict[i] = 0
        edit_type_for_cluster_dict[i] = 0
    # record cluster and log counter
    cluster_log_counter = 0
    cluster_counter = 0
    log_counter = 0
    pre_cluster_id = -1
    curr_cluster = []
    for record in islice(records, 1, None):
        log_counter += 1

        # record edit type for each log record
        edit_types = json.loads(record[my_util.EDIT_TYPE_INDEX])
        for edit_type in edit_types:
            edit_type_for_log_dict[edit_type] += 1

        # compute cluster
        cluster_id = record[-1]
        # same to pre cluster, then add to curr_cluster
        if cluster_id == pre_cluster_id:
            curr_cluster.append(record)
        # start another cluster and deal with pre cluster
        else:
            #  the last one record can not be cluster
            if len(curr_cluster) >= 2:
                edit_type_for_cluster_dict, cluster_log_counter = get_edit_type_for_cluster(curr_cluster, edit_type_for_cluster_dict, cluster_log_counter)
                cluster_counter += 1
            curr_cluster = []
            curr_cluster.append(record)
            pre_cluster_id = cluster_id
 
    # write back cluster counter and log counter
    file_writer.writerow(['cluster counter', 'repetitive cluster counter', 'log_counter', 'cluster log counter'])
    file_writer.writerow([log_counter - cluster_log_counter + cluster_counter, cluster_counter, log_counter, cluster_log_counter])
    # write back cluster edit type and log edit type
    file_writer.writerow(my_util.LOG_EDIT_TYPES)
    log_edit_type = []
    cluster_edit_type = []
    for edit_type in my_util.LOG_EDIT_TYPES:
        log_edit_type.append(edit_type_for_log_dict[edit_type])
        cluster_edit_type.append(edit_type_for_cluster_dict[edit_type])
    file_writer.writerow(log_edit_type)
    file_writer.writerow(cluster_edit_type)

    reading_file.close()

def get_wait_time():
    """
    @ param nothing\n
    @ return nothing\n
    @ involve analyze each cluster to record wait time\n
    """
    writer_file = file(my_util.WAIT_TIME_RECORD_FILE, 'wb')
    writer = csv.writer(writer_file)
    writer.writerow(my_util.WAIT_TIME_RECORD_TITLE)
    reading_file = file(my_util.CLUSTER_RECORD_FILE, 'rb')
    records = csv.reader(reading_file)
    pre_cluster_id = -1
    curr_cluster = []
    for record in islice(records, 1, None):
        cluster_id = record[-1]
        if cluster_id == pre_cluster_id:
            curr_cluster.append(record)
        else:
            if len(curr_cluster) >= 2:
                start_time = min(curr_cluster, key=lambda x: datetime.strptime(x[my_util.DATE_INDEX], "%d %b %Y"))
                start_time = datetime.strptime(start_time[my_util.DATE_INDEX], "%d %b %Y")
                for cluster_record in curr_cluster:
                    writer.writerow(cluster_record + [datetime.strptime(cluster_record[my_util.DATE_INDEX], "%d %b %Y") - start_time])
            else:
                for cluster_record in curr_cluster:
                    writer.writerow(cluster_record + [0])
            curr_cluster = []
            curr_cluster.append(record)
            pre_cluster_id = cluster_id

    # last cluster
    if len(curr_cluster) > 2:
        start_time = min(curr_cluster, key=lambda x:x[my_util.DATE_INDEX])
        for record in curr_cluster:
            writer.writerow(record.append(record[my_util.DATE_INDEX] - start_time))
    else:
            writer.writerow(record + [0])

    reading_file.close()
    writer_file.close()

def get_statistic(file_name='data/analyze/statistic.csv'):
    """
    @ param nothing\n
    @ return nothing\n
    @ involve pre-verify historical modifications by hunk < function\n
    """
    writer_file = file(file_name, 'wb')
    writer = csv.writer(writer_file)
    get_wait_time()
    get_edit_type(writer)

    writer_file.close()

"""
main function
"""
if __name__ == "__main__":
    my_util.set_user_repos(repos_name='tar')
    get_statistic(file_name = 'data/analyze/statistic.csv')
