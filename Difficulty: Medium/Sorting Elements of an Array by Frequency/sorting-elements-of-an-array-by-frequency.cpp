#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[200];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Frequency array (Ai ≤ 60)
        int freq[61] = {0};

        // Step 1: count frequency
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        // Step 2: sort using if-else logic
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // higher frequency first
                if (freq[arr[i]] < freq[arr[j]]) {
                    swap(arr[i], arr[j]);
                }
                // if same frequency, smaller number first
                else if (freq[arr[i]] == freq[arr[j]] && arr[i] > arr[j]) {
                    swap(arr[i], arr[j]);
                }
            }
        }

        // Step 3: print result
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
