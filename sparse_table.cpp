
const int LOG = 21;
int lg[N];
void build_lg () {
    for (int i = 0; i < N; ++ i) lg[i] = __lg(i);
}
struct sparse {
    vector < int > t[LOG];

    void build (int _n) {
        for (int i = 0; i <= 20; ++ i) {
            t[i].resize (_n + 1);
        }

        for (int i = 1; i <= _n; ++ i) {
            t[0][i] = p[i];
        }


        for (int l = 1; l < LOG; ++ l) {
            for (int i = 1; i <= _n - pw (l) + 1; ++ i) {
                t[l][i] = max (t[l - 1][i], t[l - 1][i + (1ll << (l - 1))]);
            }
        }
    }

    int get (int l, int r) {
        int L = lg[r - l + 1];
        return max (t[L][l], t[L][r - pw (L) + 1]);
    }
};