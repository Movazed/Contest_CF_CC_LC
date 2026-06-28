void s() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(all(a), greater<ll>());

    ll need = 0;
    ll ans = 0;

    for (int k = 1; k <= n; ++k) {
        need += b[k - 1];
        if (need > n) break;

        ll x = a[need - 1];
        ans = max(ans, x * k);
    }

    cout << ans << '\n';
}