from itertools import islice 
from datetime import datetime
from datetime import timedelta
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
        if json.loads(record[my_util.EDIT_FEATURE_INDEX]) == [0]:
            continue
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
    @ return wait counter\n
    @ involve analyze each cluster to record wait time and return wait cluster counter\n
    """
    writer_file = file(my_util.WAIT_TIME_RECORD_FILE, 'wb')
    writer = csv.writer(writer_file)
    writer.writerow(my_util.WAIT_TIME_RECORD_TITLE)
    average_writer_file = file(my_util.AVERAGE_WAIT_TIME_FILE, 'wb')
    average_writer = csv.writer(average_writer_file)
    average_writer.writerow(my_util.WAIT_TIME_RECORD_TITLE + ['cluster_size'])

    reading_file = file(my_util.CLUSTER_RECORD_FILE, 'rb')
    records = csv.reader(reading_file)
    pre_cluster_id = -1
    curr_cluster = []
    wait_counter = 0
    for record in islice(records, 1, None):
        if json.loads(record[my_util.EDIT_FEATURE_INDEX]) == [0]:
            continue
        cluster_id = record[-1]
        if cluster_id == pre_cluster_id:
            curr_cluster.append(record)
        else:
            if len(curr_cluster) >= 2:
                # calculate wait time and average wait time
                average_wait_time = timedelta()
                time_lists = [my_util.strptime_mine(x[my_util.DATE_INDEX]) for x in curr_cluster]
                start_time = min(time_lists)
                for i in range(len(curr_cluster)):
                    wait_time = time_lists[i] - start_time
                    writer.writerow(curr_cluster[i] + [wait_time.total_seconds()/60])
                    average_wait_time += wait_time
                # write average wait time
                average_writer.writerow(curr_cluster[0] + [average_wait_time.total_seconds()/60/len(curr_cluster)] + [len(curr_cluster)])
                if average_wait_time > timedelta():
                    wait_counter += 1
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
    average_writer_file.close()
    writer_file.close()

    return wait_counter

def get_reason_for_consistence(file_writer):
    """
    @ param statistic file writer\n
    @ return nothing\n
    @ involve statistic each reason for consistence, summarize the average wait time, average size, trivial count and wait count\n
    """
    reading_file = file(my_util.AVERAGE_WAIT_TIME_FILE, 'rb')
    records = csv.reader(reading_file)
    # build dict for each sort of reason
    # counter, sum of wait time, sum of wait count, sum of cluster size, sum of trivial
    reason_dict = {}
    for reason in my_util.REASON_FOR_CONSISTENCE:
        reason_dict[reason] = [0, 0, 0, 0, 0]
    for record in islice(records, 1, None):
        if json.loads(record[my_util.EDIT_FEATURE_INDEX]) == [0]:
            continue
        # counster
        reason = record[my_util.REASON_FOR_CONSISTENCE_INDEX]
        if reason == '':
            continue
        reason_dict[reason][my_util.NUM_INDEX] += 1
        # sum of wait time
        wait_time = float(record[my_util.WAIT_TIME_INDEX])
        reason_dict[reason][my_util.SUM_WAIT_TIME_INDEX] += wait_time
        if wait_time != float(0):
            reason_dict[reason][my_util.WAIT_COUNTER_INDEX] += 1
        # sum of cluster size
        cluster_size = int(record[-1])
        reason_dict[reason][my_util.SUM_CLUSTER_SIZE_INDEX] += cluster_size
        # sum of trivial
        is_trivial = record[my_util.TRIVIAL_INDEX]
        if is_trivial == my_util.IS_TRIVIAL:
            reason_dict[reason][my_util.TRIVIAL_COUNTER_INDEX] += 1

    file_writer.writerow(['reason'] + my_util.STATISTIC_REASON_FOR_CONSISTENCE_TITLE)
    for reason in my_util.REASON_FOR_CONSISTENCE:
        file_writer.writerow([reason] + reason_dict[reason])

def get_statistic(file_name='data/analyze/statistic.csv'):
    """
    @ param nothing\n
    @ return nothing\n
    @ involve pre-verify historical modifications by hunk < function\n
    """
    writer_file = file(file_name, 'ab')
    writer = csv.writer(writer_file)
    writer.writerow(['repos name', my_util.REPOS_NAME])
    get_edit_type(writer)
    wait_counter = get_wait_time()
    writer.writerow(['wait counter'])
    writer.writerow([wait_counter])
    get_reason_for_consistence(writer)


    writer_file.close()

"""
main function
"""
if __name__ == "__main__":
    my_util.set_user_repos(repos_name='tar')
    get_statistic(file_name = 'data/analyze/statistic.csv')
