# 1001 Battle Over Cities - Hard Version （35 分）
# It is vitally important to have all the cities connected by highways in a war. If a city is conquered by the enemy, all the highways from/toward that city will be closed. To keep the rest of the cities connected, we must repair some highways with the minimum cost. On the other hand, if losing a city will cost us too much to rebuild the connection, we must pay more attention to that city.

# Given the map of cities which have all the destroyed and remaining highways marked, you are supposed to point out the city to which we must pay the most attention.

# Input Specification:
# Each input file contains one test case. Each case starts with a line containing 2 numbers N (≤500), and M, which are the total number of cities, and the number of highways, respectively. Then M lines follow, each describes a highway by 4 integers: City1 City2 Cost Status where City1 and City2 are the numbers of the cities the highway connects (the cities are numbered from 1 to N), Cost is the effort taken to repair that highway if necessary, and Status is either 0, meaning that highway is destroyed, or 1, meaning that highway is in use.

# Note: It is guaranteed that the whole country was connected before the war.

# Output Specification:
# For each test case, just print in a line the city we must protest the most, that is, it will take us the maximum effort to rebuild the connection if that city is conquered by the enemy.

# In case there is more than one city to be printed, output them in increasing order of the city numbers, separated by one space, but no extra space at the end of the line. In case there is no need to repair any highway at all, simply output 0.

# Sample Input 1:
# 4 5
# 1 2 1 1
# 1 3 1 1
# 2 3 1 0
# 2 4 1 1
# 3 4 1 0
# Sample Output 1:
# 1 2
# Sample Input 2:
# 4 5
# 1 2 1 1
# 1 3 1 1
# 2 3 1 0
# 2 4 1 1
# 3 4 2 1
# Sample Output 2:
# 0

info = input().split()
city_number, road_number = int(info[0]), int(info[1])
road_info = []
cost = []
for i in range(road_number):
    one = input().split()
    road_info.append([[int(one[0]), int(one[1])], int(one[2]), int(one[3])])
bad_road = []
good_rood = []
for i in road_info:
    if i[2]:
        good_rood.append(i)
    else:
        bad_road.append(i)

# 当某一个城市被攻陷后
for i in range(city_number):
    city_group = []
    city_included = [0]*city_number
    # 对每一条路，除去被攻陷的和坏掉的以外，剩下的将城市分开成组（goodroads*log（groups））
    for j in good_rood:
        flag = True
        if i+1 not in j[0]:
            for p in range(len(city_group)):
                if j[0][0] in city_group[p]:
                    flag = False
                    if j[0][1] not in city_group[p]:
                        city_group[p].append(j[0][1])
                        city_included[j[0][1]-1] = 1
                    break
                elif j[0][1] in city_group[p]:
                    flag = False
                    city_group[p].append(j[0][0])
                    city_included[j[0][0]-1] = 1
                    break
            if flag:
                city_group.append([j[0][0], j[0][1]])
                city_included[j[0][1]-1] = 1
                city_included[j[0][0]-1] = 1
    for p in range(city_number):
        if p != i and city_included[p]==0:
            city_group.append([p+1])
            city_included[p]=1
    # 分组之后确定每两个组之间的最短距离（badroads*groups*groups）
    group_number = len(city_group)
    group_map = dict()
    group_status = [0]*group_number
    for j in bad_road:
        if i not in j[0]:
            for p in range(group_number):
                if j[0][0] in city_group[p]:
                    if j[0][1] in city_group[p]:
                        break
                    else:
                        for q in range(group_number):
                            if j[0][1] in city_group[q]:
                                if p < q:
                                    key = str(p)+"-"+str(q)
                                else:
                                    key = str(q)+"-"+str(p)
                                if key in group_map.keys():
                                    if group_map[key] > j[1]:
                                        group_map[key] = j[1]
                                else:
                                    group_map[key] = j[1]
    sorted_group_map = sorted(group_map.items(), key=lambda d: d[1])
    # 计算当前城市被摧毁的耗费（groups）
    temp_cost = 0
    for g in sorted_group_map:
        deal = g[0].split("-")
        temp_groups = [int(deal[0]),int(deal[1])]
        if group_status[temp_groups[0]]:
            if group_status[temp_groups[1]]:
                continue
            else:
                group_status[temp_groups[1]] = 1
                temp_cost += g[1]
        else:
            if group_status[temp_groups[1]]:
                group_status[temp_groups[0]] = 1
            else:
                group_status[temp_groups[1]] = group_status[temp_groups[0]] = 1
            temp_cost += g[1]
    cost.append(temp_cost)

#找出耗费最小的某些城市
temp_max_city = []
temp_max = 0
for i in range(city_number):
    if cost[i] == temp_max:
        temp_max_city.append(i+1)
    elif cost[i] > temp_max:
        temp_max = cost[i]
        temp_max_city = [i+1]

if temp_max == 0:
    print(0,end="")
else:
    for i in range(len(temp_max_city)):
        print(temp_max_city[i],end="")
        if i != len(temp_max_city)-1:
            print(" ",end="")
