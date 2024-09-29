MONEY_QUERY = "DATA_TEST ?e (person {?p - ?q < 7 and ?p > age and ?q < age})/ ((:A {true}) /(person { ?p - ?q < 7 and ?p > age and ?q < age }))+"

DATING_QUERY_FB = """DATA_TEST ?e (person {?p == age and ?x == pos_x and ?y == pos_y})/ ((:A {true})/(person {true}))*/(:A {true}) /(person {
?p * 0.5 + 7 <= age
and  (?x - pos_x) + (?y - pos_y) <= 20 and
        (?x - pos_x) + (pos_y - ?y) <= 20 and
        (pos_x - ?x) + (?y - pos_y) <= 20 and
        (pos_x - ?x) + (pos_y - ?y) <= 20 and status == "single"
})
"""

DATING_QUERY_YTB = """DATA_TEST ?e (person {?p == age and ?x == pos_x and ?y == pos_y})/ ((:B {true})/(person {true}))*/(:B {true}) /(person {
?p * 0.5 + 7 <= age
and  (?x - pos_x) + (?y - pos_y) <= 20 and
        (?x - pos_x) + (pos_y - ?y) <= 20 and
        (pos_x - ?x) + (?y - pos_y) <= 20 and
        (pos_x - ?x) + (pos_y - ?y) <= 20 and status == "single"
})
"""

CENTRAL_PATH_QUERY = """ DATA_TEST ?e
(person {
 (?x - pos_x) + (?y - pos_y) <= 35 and
    (?x - pos_x) + (pos_y - ?y) <= 35 and
    (pos_x - ?x) + (?y - pos_y) <= 35 and
    (pos_x - ?x) + (pos_y - ?y) <= 35
})/ ((:A {true}) /(person {
    (?x - pos_x) + (?y - pos_y) <= 35 and
    (?x - pos_x) + (pos_y - ?y) <= 35 and
    (pos_x - ?x) + (?y - pos_y) <= 35 and
    (pos_x - ?x) + (pos_y - ?y) <= 35
}))*
"""

CENTRAL_PATH_QUERY_BIG = """ DATA_TEST ?e
(person {
 (?x - pos_x) + (?y - pos_y) <= 350 and
    (?x - pos_x) + (pos_y - ?y) <= 350 and
    (pos_x - ?x) + (?y - pos_y) <= 350 and
    (pos_x - ?x) + (pos_y - ?y) <= 350
})/ ((:A {true}) /(person {
    (?x - pos_x) + (?y - pos_y) <= 350 and
    (?x - pos_x) + (pos_y - ?y) <= 350 and
    (pos_x - ?x) + (?y - pos_y) <= 350 and
    (pos_x - ?x) + (pos_y - ?y) <= 350
}))*
"""


def create_query_command(start_point: str, query: str):
    return f"Match (N{start_point}) =[{query}] => (?to) \n Return * \n Limit 1"
