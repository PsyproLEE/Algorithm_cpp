#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> parent;
vector<int> rankv;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_sets(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (rankv[a] < rankv[b])
            swap(a, b);
        parent[b] = a;
        if (rankv[a] == rankv[b])
            rankv[a]++;
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t; // 테스트케이스
    int ca = 1;

    while (t--)
    {
        int n, k;
        cin >> n; // 유저수
        parent.assign(n, 0);
        rankv.assign(n, 0);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }

        cin >> k; // 친구관계 수
        while (k--)
        {
            int a, b;
            cin >> a >> b;
            union_sets(a, b);
        }
        int m;
        cin >> m; // 구해야할 쌍의 수
        cout << "Scenario " << ca << ":" <<'\n';   
        while(m--){
            int u , v;
            cin >> u >> v;
            if(find(u) == find(v)){
                cout << 1 << '\n';
            }
            else cout << 0 << '\n';
        }
        cout << '\n';
        ca++;
    }
    return 0;
}