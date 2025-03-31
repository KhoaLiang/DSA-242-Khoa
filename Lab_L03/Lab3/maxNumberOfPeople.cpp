#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    // Sort both rooms and people's desired sizes
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());

    int i = 0, j = 0, count = 0;

    // Use two pointers to match people with rooms
    while (i < people.size() && j < rooms.size()) {
        if (rooms[j] >= people[i] - k && rooms[j] <= people[i] + k) {
            // Room is acceptable for the person
            count++;
            i++;
            j++;
        } else if (rooms[j] < people[i] - k) {
            // Room is too small, move to the next room
            j++;
        } else {
            // Room is too large, move to the next person
            i++;
        }
    }

    return count;
}

// Main function for testing
int main() {
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;

    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for (int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for (int i = 0; i < roomCount; i++)
        cin >> rooms[i];

    cout << maxNumberOfPeople(rooms, people, k) << '\n';

    return 0;
}