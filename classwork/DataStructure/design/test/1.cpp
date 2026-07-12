void TransInformation::dijkstra_Time(const std::string &startCity)
{
    init();

    int start = cityID[startCity];
    distance[start] = 0;
    arriveTime[start] = 0;
    std::priority_queue<node> Q;
    Q.push(node(start, 0));

    while (!Q.empty())
    {
        node u = Q.top();
        Q.pop();
        if (visited[u.id])
            continue;
        visited[u.id] = true;

        for (auto &i : cityList[u.id - 1].trans)
        {
            int v = cityID[i.endCity];
            if (visited[v])
                continue;

            int dep = i.startTime.toMinutes();
            int arr = i.endTime.toMinutes();

            if (dep < arriveTime[u.id])
                continue;

            if (distance[v] > arr)
            {
                distance[v] = arr;
                arriveTime[v] = arr;
                Q.push(node(v, distance[v]));
                pre[v] = i;
            }
        }
    }
}