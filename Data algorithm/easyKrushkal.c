#include <stdio.h>
#include <stdlib.h>

// Structure to represent a road in the network
typedef struct Road {
    int cityA;      // Starting city of the road
    int cityB;      // Ending city of the road
    int cost;       // Cost of the road
} Road;

// Structure to represent a city group for union-find
typedef struct CityGroup {
    int leader; // Leader city of the group
    int level;  // Level to optimize merging groups
} CityGroup;

// Function to create city groups for each city
void initializeCityGroups(CityGroup cityGroups[], int totalCities) {
    for (int i = 0; i < totalCities; i++) {
        cityGroups[i].leader = i;
        cityGroups[i].level = 0;
    }
}

// Function to find the leader of a city (uses path compression)
int findLeader(CityGroup cityGroups[], int city) {
    if (cityGroups[city].leader != city) {
        cityGroups[city].leader = findLeader(cityGroups, cityGroups[city].leader);
    }
    return cityGroups[city].leader;
}

// Function to merge two city groups (uses union by level)
void mergeCityGroups(CityGroup cityGroups[], int city1, int city2) {
    int leader1 = findLeader(cityGroups, city1);
    int leader2 = findLeader(cityGroups, city2);

    if (cityGroups[leader1].level < cityGroups[leader2].level) {
        cityGroups[leader1].leader = leader2;
    } else if (cityGroups[leader1].level > cityGroups[leader2].level) {
        cityGroups[leader2].leader = leader1;
    } else {
        cityGroups[leader2].leader = leader1;
        cityGroups[leader1].level++;
    }
}

// Comparator function for sorting roads by cost
int compareRoads(const void* a, const void* b) {
    Road* roadA = (Road*)a;
    Road* roadB = (Road*)b;
    return roadA->cost - roadB->cost;
}

// Kruskal's algorithm implementation
void kruskalAlgorithm(int totalCities, int totalRoads, Road roads[]) {
    Road mst[totalCities - 1]; // To store the resultant minimum spanning tree (MST)
    int mstIndex = 0;          // Index for mst[]
    int roadIndex = 0;         // Index for sorted roads

    // Step 1: Sort all the roads in non-decreasing order of cost
    qsort(roads, totalRoads, sizeof(Road), compareRoads);

    // Allocate memory for creating city groups
    CityGroup* cityGroups = (CityGroup*)malloc(totalCities * sizeof(CityGroup));
    initializeCityGroups(cityGroups, totalCities);

    // Step 2: Pick the smallest road and check if it forms a cycle
    while (mstIndex < totalCities - 1 && roadIndex < totalRoads) {
        Road nextRoad = roads[roadIndex++];

        int leaderA = findLeader(cityGroups, nextRoad.cityA);
        int leaderB = findLeader(cityGroups, nextRoad.cityB);

        // If including this road does not form a cycle
        if (leaderA != leaderB) {
            mst[mstIndex++] = nextRoad;
            mergeCityGroups(cityGroups, leaderA, leaderB);
        }
    }

    // Print the result
    printf("Roads in the Minimum Spanning Tree:\n");
    int totalCost = 0;
    for (int i = 0; i < mstIndex; i++) {
        printf("%d -- %d == %d\n", mst[i].cityA, mst[i].cityB, mst[i].cost);
        totalCost += mst[i].cost;
    }
    printf("Total cost of MST: %d\n", totalCost);

    // Free memory
    free(cityGroups);
}

int main() {
    int totalCities, totalRoads;

    // User-defined input for the network
    printf("Enter the number of cities: ");
    scanf("%d", &totalCities);

    printf("Enter the number of roads: ");
    scanf("%d", &totalRoads);

    Road roads[totalRoads];
    printf("Enter the roads (cityA cityB cost):\n");
    for (int i = 0; i < totalRoads; i++) {
        printf("Road %d: ", i + 1);
        scanf("%d %d %d", &roads[i].cityA, &roads[i].cityB, &roads[i].cost);
    }

    // Call Kruskal's algorithm
    kruskalAlgorithm(totalCities, totalRoads, roads);

    return 0;
}
