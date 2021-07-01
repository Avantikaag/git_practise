def traversal(graph, g_visited, current, way, stack, a):
    if current==a-1:
        way.append(stack.copy())
        stack.pop()
        return way, stack
    else:
        g_visited[current] = 1
        for ele in graph[current]:
            if g_visited[ele] == 0:
                stack.append(ele)
                way, stack = traversal(graph, g_visited, ele, way, stack, a)
        stack.pop()
        return way, stack

a, m, test, c = map(int, input().split())

graph = [[] for _ in range(a)]
g_visited = [0 for _ in range(a)]
for _ in range(m):
    a,b = map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

way, _ = traversal(graph, g_visited, 0, [], [0], a)

way.sort(key=lambda x:len(x))

# print(way)
timid= 0
l = len(way[0])
for i in range(1, l):
    timid += c
    if i==l-1:
        break
    else:
        temp = timid//test
        if temp%2==1:
            timid = (temp+1)*test

print(timid)