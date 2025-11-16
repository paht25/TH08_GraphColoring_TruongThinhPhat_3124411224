#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj; // Danh sách kề
vector<int> color;       // color[i] = 0 (chưa tô), 1, 2, 3...
int k = 0;               // Số màu tối đa đã dùng

int main() {
    // Đọc số đỉnh n và số cạnh m
    cin >> n >> m;

    adj.resize(n + 1);
    color.resize(n + 1, 0); // Ban đầu chưa tô màu

    // Đọc m cạnh của đồ thị
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Duyệt qua từng đỉnh u
    for (int u = 1; u <= n; ++u) {
        // Mảng đánh dấu màu đã bị hàng xóm sử dụng
        // Kích thước n+1 là đủ vì số màu không bao giờ vượt quá n
        vector<bool> used_colors(n + 1, false);

        // Duyệt qua các hàng xóm v của u
        for (int v : adj[u]) {
            // Nếu hàng xóm v đã được tô màu
            if (color[v] != 0) {
                // Đánh dấu màu đó là đã dùng
                used_colors[color[v]] = true;
            }
        }

        // Tìm màu c (bắt đầu từ 1) nhỏ nhất chưa được dùng
        int c = 1;
        while (c <= n) {
            if (!used_colors[c]) {
                break; // Tìm thấy màu c
            }
            c++;
        }

        // Gán màu c cho đỉnh u
        color[u] = c;
        
        // Cập nhật số màu lớn nhất đã dùng
        if (c > k) {
            k = c;
        }
    }

    // In kết quả
    
    // Dòng 1 để in số màu đã dùng
    cout << k << endl;

    // k dòng tiếp theo: In danh sách các đỉnh theo từng màu
    for (int c = 1; c <= k; ++c) {
        for (int i = 1; i <= n; ++i) {
            if (color[i] == c) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}