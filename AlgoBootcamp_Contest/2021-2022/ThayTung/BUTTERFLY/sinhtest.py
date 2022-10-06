# Import Library
import networkx as nx
import random
import os


def randomGraph(file_path, cnt):
    completeName = os.path.join(file_path, "input" + str(cnt) + ".txt")
    fout = open(completeName, "w+")

    n = 2
    if cnt <= 20:
        n = random.randint(2, 20)
    elif cnt <= 30:
        n = random.randint(20, 100)
    elif cnt <= 47:
        n = random.randint(100, 100000)
    else:
        n = 200000

    graph = nx.random_tree(n)

    fout.write(str(n))
    fout.write("\n")
    for edge in graph.edges():
        fout.write(str(edge[0] + 1) + " " + str(edge[1] + 1))
        fout.write("\n")

    fout.close()


# Main

# Thư mục chứa test
current_path = os.path.dirname(os.path.realpath(__file__))
path = os.path.join(current_path, "in")
if not os.path.exists(path):
    os.mkdir(path)

# Số test cần tạo
Test = 50
for t in range(0, Test):
    randomGraph(path, t + 1)

print("Successfull")