MONEY_QUERY = "DATA_TEST ?e (person {?p - ?q < 7 and ?p > age and ?q < age})/ ((:A {true}) /(person { ?p - ?q < 7 and ?p > age and ?q < age }))+"

DATING_QUERY = """DATA_TEST ?e (person {?p == age and ?x == pos_x and ?y == pos_y})/ ((:A {true})/(person {true}))*/(:A {true}) /(person {
?p * 0.5 + 7 <= age
and  (?x - pos_x) + (?y - pos_y) <= 20 and
        (?x - pos_x) + (pos_y - ?y) <= 20 and
        (pos_x - ?x) + (?y - pos_y) <= 20 and
        (pos_x - ?x) + (pos_y - ?y) <= 20 
})
"""

CENTRAL_PATH_QUERY = """ DATA_TEST ?e
(person {true})/ ((:A {true}) /(person {
    (?x - pos_x) + (?y - pos_y) <= 35 and
    (?x - pos_x) + (pos_y - ?y) <= 35 and
    (pos_x - ?x) + (?y - pos_y) <= 35 and
    (pos_x - ?x) + (pos_y - ?y) <= 35
}))*
"""


def create_query_command(start_point: str, query: str):
    return f"Match (N{start_point}) =[{query}] => (?to) \n Return * \n Limit 1"
