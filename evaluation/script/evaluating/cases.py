import pickle
import sys
import time

from .option import DATA_DIR, DBS_DIR, FB_SIZE, ROOT_TEST_DIR, YOUTUBE_SIZE
from .query import (
    CENTRAL_PATH_QUERY,
    CENTRAL_PATH_QUERY_BIG,
    DATING_QUERY_FB,
    DATING_QUERY_YTB,
    MONEY_QUERY,
    create_query_command,
)
from .util import execute_query, kill_server, sample, send_query, start_server

FB_SAMPLE = 4000
YTB_SAMPLE = 50000


def facebook_graph_query():
    id = 0
    candidate = sample(FB_SAMPLE, FB_SIZE)
    server = start_server(DBS_DIR / "facebook")
    result = []
    query_res = []
    # dating query
    res_dating = []
    query_res_dating = []
    for index in candidate:
        id = id + 1
        sys.stdout.write("\rDATE FOR FB" + str(id))
        query = create_query_command(str(index), DATING_QUERY_FB)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_dating.append((end_time - start_time) / 1000000)
        query_res_dating.append(query_result)
    result.append(("FB", "DATING", res_dating))
    query_res.append(("FB", "DATING", query_res_dating))

    res_money = []
    query_res_money = []

    id = 0
    for index in candidate:
        id = id + 1
        sys.stdout.write("\rDATE FOR FB" + str(id))
        query = create_query_command(str(index), MONEY_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_money.append((end_time - start_time) / 1000000)
        query_res_money.append(query_result)
    result.append(("FB", "MONEY", res_money))
    query_res.append(("FB", "MONEY", query_res_money))

    res_centar = []
    query_res_centar = []

    id = 0
    for index in candidate:
        sys.stdout.write("\rCENTRAL FOR FB" + str(id))
        id = id + 1

        query = create_query_command(str(index), CENTRAL_PATH_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_centar.append((end_time - start_time) / 1000000)
        query_res_centar.append(query_result)

    result.append(("FB", "CENTRAL", res_centar))
    query_res.append(("FB", "CENTRAL", (query_res_centar)))
    kill_server(server)
    with open(ROOT_TEST_DIR / "result" / "fb_static.pkl", "wb") as fb:
        pickle.dump(result, fb)
        print(result)

    with open(ROOT_TEST_DIR / "result" / "fb_result.pkl", "wb") as fb:
        pickle.dump(query_res, fb)
        print(result)


def youtube_graph_query():
    candidate = sample(YTB_SAMPLE, YOUTUBE_SIZE)
    server = start_server(DBS_DIR / "youtube")
    result = []
    query_res = []
    # dating query
    res_dating = []
    query_res_dating = []
    id = 0
    for index in candidate:
        sys.stdout.write("DATING FOR YT " + str(id))
        id = id + 1

        query = create_query_command(str(index), DATING_QUERY_YTB)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_dating.append((end_time - start_time) / 1000000)
        query_res_dating.append(query_result)
    result.append(("YT", "DATING", res_dating))
    query_res.append(("YT", "DATING", query_res_dating))

    res_money = []
    query_res_money = []

    id = 0
    for index in candidate:
        sys.stdout.write("MONEY FOR YT " + str(id))
        id = id + 1

        query = create_query_command(str(index), MONEY_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_money.append((end_time - start_time) / 1000000)
        query_res_money.append(query_result)
    result.append(("YT", "MONEY", res_money))
    query_res.append(("YT", "MONEY", query_res_money))

    res_centar = []
    query_res_centar = []

    id = 0
    for index in candidate:
        sys.stdout.write("CENTRAL FOR YT " + str(id))
        id = id + 1

        query = create_query_command(str(index), CENTRAL_PATH_QUERY_BIG)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_centar.append((end_time - start_time) / 1000000)
        query_res_centar.append(query_result)

    result.append(("YT", "CENTRAL", res_centar))
    query_res.append(("YT", "CENTRAL", query_res_centar))
    kill_server(server)
    with open(ROOT_TEST_DIR / "result" / "ytb_static.pkl", "wb") as fb:
        pickle.dump(result, fb)
        print(result)

    with open(ROOT_TEST_DIR / "result" / "ytb_result.pkl", "wb") as fb:
        pickle.dump(query_res, fb)
        print(result)
