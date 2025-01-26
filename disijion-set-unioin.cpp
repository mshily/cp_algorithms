struct dsu {
    vector < int > par;
    vector < int > sz;

    void init (int _n) {
        par.resize(_n + 1);
        sz.resize(_n + 1, 1);

        iota (all (par), 0);
    }

    int get (int v) {
        return par[v] == v ? v : par[v] = get (par[v]);
    }

    bool uni (int a, int b) {
        a = get (a);
        b = get (b);

        if (a == b) return false;

        if (sz[a] < sz[b]) swap (a, b);

        sz[a] += sz[b];
        par[b] = a;

        return true;
    }
} t;