class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<list<int>> graph(n);
        vector<int> answer;
        vector<pair<int, int>> leave_edges;
        vector<bool> empty(n, false);
        int empty_count = 0;

        for (int i = 0; i < (int)edges.size(); i++) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }

        while (empty_count <= n - 2) {
            leave_edges.clear();

            for (int i = 0; i < n; i++) {
                if (graph[i].size() == 1) {
                    leave_edges.push_back(pair<int, int>(i, graph[i].front()));
                }
            }

            if (leave_edges.size() == 0) {
                break;
            }

            for (int i = 0; i < (int)leave_edges.size(); i++) {
                int from = leave_edges[i].first;
                int to = leave_edges[i].second;

                graph[from].clear();
                graph[to].remove(from);
                empty_count++;
                empty[from] = true;
            }
        }

        if (empty_count == n - 1) {
            for (int i = 0; i < n; i++) {
                if (!empty[i]) {
                    answer.push_back(i);
                }
            }
        } else {
            for (int i = 0; i < (int)leave_edges.size(); i++) {
                answer.push_back(leave_edges[i].first);
            }
        }

        return answer;
    }
};
