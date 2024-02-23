#include <stdio.h>

int findJudge(int N, int trust[][2], int trustSize) {
    int indegree[N + 1];   // indegree[i] stores the number of people who trust person i
    int outdegree[N + 1];  // outdegree[i] stores the number of people person i trusts
    int i;

    // Initialize indegree and outdegree arrays
    for (i = 1; i <= N; ++i) {
        indegree[i] = 0;
        outdegree[i] = 0;
    }

    // For each trust relationship (a, b), increment indegree[b] and outdegree[a]
    for ( i = 0; i < trustSize; ++i) {
        int a = trust[i][0];
        int b = trust[i][1];
        outdegree[a]++;
        indegree[b]++;
    }

    // The town judge is the person with in-degree N - 1 and out-degree 0
    for ( i = 1; i <= N; ++i) {
        if (indegree[i] == N - 1 && outdegree[i] == 0) {
            return i;
        }
    }

    return -1;
}

int main() {
    // Example usage:
    int N1 = 2;
    int trust1[][2] = {{1, 2}};
    int judge1 = findJudge(N1, trust1, sizeof(trust1) / sizeof(trust1[0]));
    printf("%d\n", judge1);  // Output: 2

    int N2 = 3;
    int trust2[][2] = {{1, 3}, {2, 3}};
    int judge2 = findJudge(N2, trust2, sizeof(trust2) / sizeof(trust2[0]));
    printf("%d\n", judge2);  // Output: 3

    int N3 = 4;
    int trust3[][2] = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    int judge3 = findJudge(N3, trust3, sizeof(trust3) / sizeof(trust3[0]));
    printf("%d\n", judge3);  // Output: -1

    return 0;
}
