class Solution {
public:
    int R, C;
    vector<int> parent, size;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a); 
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int idx(int r, int c){
        return r * C + c;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        R = row; 
        C = col;

        int N = row * col;
        parent.resize(N + 2);
        size.assign(N + 2, 1);

        int top = N;
        int bottom = N + 1;

        for(int i = 0; i < N + 2; i++) parent[i] = i;

        vector<vector<int>> open(row, vector<int>(col, 0));

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        for(int i = cells.size() - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            open[r][c] = 1;

            int id = idx(r, c);

            if(r == 0) unite(id, top);
            if(r == row - 1) unite(id, bottom);

            for(int k = 0; k < 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && open[nr][nc]){
                    unite(id, idx(nr, nc));
                }
            }

            if(find(top) == find(bottom))
                return i;
        }

        return 0;
    }
};
