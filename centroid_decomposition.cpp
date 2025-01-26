int find_centroid (int v, int p, int sz) {
    for (auto& to : g[v]) {
        if (used[to] || to == p) continue;
        if (2 * dep[to] > sz) return find_centroid(to, v, sz);
    }
    return v;
}
 
void dfs_size (int v, int p) {
    dep[v] = 1;
    for (auto& to : g[v]) {
        if (to == p || used[to]) continue;
        dfs_size (to, v);
        dep[v] += dep[to];
    }
}
 
void build (int v, int p) {
    dfs_size (v, v);
    int c = find_centroid(v, v, dep[v]);
 
    used[c] = true;
    par[c] = p;
 
    for (auto& to : g[c]) {
        if (used[to]) continue;
        build (to, c);
    }
}