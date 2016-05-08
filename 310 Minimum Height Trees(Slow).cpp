class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        this->n = n;
        this->graph.resize(n);
        this->dist.resize(n);

        for (int i = 0; i < (int)edges.size(); i++) {
            this->graph[edges[i].first].push_back(edges[i].second);
            this->graph[edges[i].second].push_back(edges[i].first);
        }

        init();
        for (int i = 0; i < n; i++) {
            walk(i);
        }

        vector<int> answer;
        int min_height = 0x7FFFFFFF;
        for (int i = 0; i < n; i++) {
            int height = find_height(i);
            if (height < min_height) {
                min_height = height;
                answer.clear();
                answer.push_back(i);
            } else if (height == min_height) {
                answer.push_back(i);
            }
        }

        return answer;
    }

    void init() {
        for (int i = 0; i < this->n; i++) {
            this->dist[i].resize(n, 0x7FFFFFFF);
            this->dist[i][i] = 0;
        }
    }

    void walk(int start) {
        vector<bool> used(this->n, false);
        queue<int> q;

        q.push(start);
        used[start] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < (int)this->graph[node].size(); i++) {
                int to = this->graph[node][i];
                if (used[to]) {
                    continue;
                }
                if (dist[start][to] > dist[start][node] + 1) {
                    dist[start][to] = dist[start][node] + 1;
                    q.push(to);
                    used[to] = true;
                }
            }
        }
    }

    int find_height(int start) {
        int max_height = 0;
        for (int i = 0; i < this->n; i++) {
            if (this->dist[start][i] > max_height) {
                max_height = this->dist[start][i];
            }
        }
        return max_height;
    }

private:
    int n;
    vector<vector<int>> graph;
    vector<vector<int>> dist;
};
