import pathlib
import pickle
import random
import time
from subprocess import Popen

from tests.mql.scripts.testing.server_utils import *
from tests.mql.scripts.testing.types import ExecutionStats

from query import CENTRAL_PATH_QUERY, DATING_QUERY, MONEY_QUERY, create_query_command

# some options
YOUTUBE_SIZE = 50
FB_SIZE = 30
server = pathlib.Path("$MDB_HOME/build/Release/bin/mdb-server")
fb_db = pathlib.Path("$MDB_HOME/data/facebook")
ytb_db = pathlib.Path("$MDB_HOME/data/youtube")


def send_query(test: str) -> str | int:

    log(Level.DEBUG, f"query_string: {test}")

    conn = http.client.HTTPConnection(f"{HOST}:{1234}")

    conn.request("POST", "/", headers={"Accept": "text/csv"}, body=test)

    response = conn.getresponse()

    if response.getcode() != 200:
        return 1

    return response.read().decode("utf-8")


def sample(bound):  # type: ignore
    res = []
    random.seed(time.time())
    for _ in range(3000):
        res.append(random.randint(0, bound))  # type: ignore
    return res  # type: ignore


def facebook_graph_query():
    candidate = sample(FB_SIZE)
    print(candidate)
    result = []
    # dating query
    res_dating = []
    for index in candidate:
        query = create_query_command(str(index), DATING_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_dating.append((end_time - start_time) / 1000000)

    result.append(("FB", "DATING", res_dating))
    # res_money = []

    # for index in candidate:
    #     query = create_query_command(str(index), MONEY_QUERY)
    #     start_time = time.time_ns()
    #     query_result = send_query(query)
    #     end_time = time.time_ns()
    #     res_money.append((end_time - start_time) / 1000000)

    # result.append(("FB", "MONEY", res_money))

    # res_centar = []
    # for index in candidate:
    #     query = create_query_command(str(index), CENTRAL_PATH_QUERY)
    #     start_time = time.time_ns()
    #     query_result = send_query(query)
    #     end_time = time.time_ns()
    #     res_centar.append((end_time - start_time) / 1000000)

    # result.append(("FB", "CENTRAL", res_centar))
    with open("fb_res.pkl", "wb") as fb:
        pickle.dump(result, fb)
        print(result)


def ytb_graph_query():
    candidate = sample(YOUTUBE_SIZE)
    print(candidate)
    result = []
    # dating query
    res_dating = []
    for index in candidate:
        query = create_query_command(str(index), DATING_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_dating.append((end_time - start_time) / 1000000)

    result.append(("YT", "DATING", res_dating))
    res_money = []

    for index in candidate:
        query = create_query_command(str(index), MONEY_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_money.append((end_time - start_time) / 1000000)

    result.append(("YT", "MONEY", res_money))

    res_centar = []
    for index in candidate:
        query = create_query_command(str(index), CENTRAL_PATH_QUERY)
        start_time = time.time_ns()
        query_result = send_query(query)
        end_time = time.time_ns()
        res_centar.append((end_time - start_time) / 1000000)

    result.append(("YT", "CENTRAL", res_centar))
    with open("yt_res.pkl", "wb") as fb:
        pickle.dump(result, fb)
        print(result)


if __name__ == "__main__":
    facebook_graph_query()
    # ytb_graph_query()
    print("finish testing")
