// For the graph to be Strongly Connected, traverse the given path matrix using the approach discussed in this article check whether all the values in the cell are 1 or not. If yes then print “Strongly Connected Graph” else check for the other two graphs.
// For the graph to be Unilaterally Connected, traverse the given path matrix using the approach discussed in this article and check the following: 
// If all the values above the main diagonal are 1s and all the values other than that are 0s.
// If all the values below the main diagonal are 1s and all the values other than that are 0s.
// If one of the above two conditions satisfies then the given graph is Unilaterally Connected else the graph is Weakly Connected Graph.



// C++ implementation of the approach

#include <bits/stdc++.h>
using namespace std;
#define V 3

// Function to find the characteristic
// of the given graph
int checkConnected(int graph[][V], int n)
{

    // Check whether the graph is
    // strongly connected or not
    bool strongly = true;

    // Traverse the path matrix
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            // If all the elements are
            // not equal then the graph
            // is not strongly connected
            if (graph[i][j] != graph[j][i]) {
                strongly = false;
                break;
            }
        }

        // Break out of the loop if false
        if (!strongly) {
            break;
        }
    }
    // If true then print strongly
    // connected and return
    if (strongly) {
        cout << "Strongly Connected";
        return 0;
    }

    // Check whether the graph is
    // Unilaterally connected by
    // checking Upper Triangle element
    bool uppertri = true;

    // Traverse the path matrix
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            // If uppertriangle elements
            // are 0 then break out of the
            // loop and check the elements
            // of lowertriangle matrix
            if (i > j && graph[i][j] == 0) {
                uppertri = false;
                break;
            }
        }

        // Break out of the loop if false
        if (!uppertri) {
            break;
        }
    }

    // If true then print unilaterally
    // connected and return
    if (uppertri) {
        cout << "Unilaterally Connected";
        return 0;
    }

    // Check lowertraingle elements
    bool lowertri = true;

    // Traverse the path matrix
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            // If lowertraingle elements
            // are 0 then break cause
            // 1's are expected
            if (i < j && graph[i][j] == 0) {
                lowertri = false;
                break;
            }
        }

        // Break out of the loop if false
        if (!lowertri) {
            break;
        }
    }

    // If true then print unilaterally
    // connected and return
    if (lowertri) {
        cout << "Unilaterally Connected";
        return 0;
    }

    // If elements are in random order
    // unsynchronized then print weakly
    // connected and return
    else {
        cout << "Weakly Connected";
    }

    return 0;
}

// Driver Code
int main()
{
    // Number of nodes
    int n = 3;

    // Given Path Matrix
    int graph[V][V] = {
        { 0, 1, 1 },
        { 0, 0, 1 },
        { 0, 0, 0 },
    };

    // Function Call
    checkConnected(graph, n);
    return 0;
}