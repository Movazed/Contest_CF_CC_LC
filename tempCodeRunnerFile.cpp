= 0;
    i = 0;
    while (i < n) {
        a[i] < b[i] ? (rm += (b[i] - a[i]), a[i] += 2 * (b[i] - a[i])) : rm += 0;
        i++;
    }

    i = 0;
    while (i < n) {
        a[i] -= rm;
        if (a[i] < 0 || a[i] < b[i]) {
            cout << "NO" << endl;
            return;
        } else {
            i++;
        }
    }

    cout << "YES" << endl;
}