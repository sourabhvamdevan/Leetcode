// Last updated: 08/03/2026, 13:23:15
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> timeWentOffline(numberOfUsers, -1000); // time when a user went online
        vector<int> mentions(numberOfUsers);               // number of mentions of a user

        // sort events by timestamp
        sort(events.begin(), events.end(),
            [](const vector<string>& a,
            const vector<string>& b) {
                int t1 = stoi(a[1]);
                int t2 = stoi(b[1]);

                if (t1 == t2) { // timestamps equal, prioritize OFFLINE
                    return a[0] > b[0];
                }
                return t1 < t2;
            }
        );

        for (const auto& event : events) {
            string type = event[0];
            if (type == "MESSAGE") {
                int time = stoi(event[1]);
                const string& mentionString = event[2];

                if (mentionString == "ALL") {
                    for (int userId = 0; userId < numberOfUsers; userId++) {
                        mentions[userId]++; // for every user
                    }
                    continue;
                } else if (mentionString == "HERE") {
                    for (int userId = 0; userId < numberOfUsers; userId++) {
                        if (time >= timeWentOffline[userId] + 60) { // for every online user
                            mentions[userId]++;
                        }
                    }
                    continue;
                }
                stringstream ss(mentionString);
                string user;

                // stringstream makes it easy to split string at spaces
                while (ss >> user) { // mention every user id in string, even if offline
                    int userId = stoi(user.substr(2));
                    mentions[userId]++;
                }
            } else {  // OFFLINE event
                int userId = stoi(event[2]);
                int time = stoi(event[1]);
                timeWentOffline[userId] = time;
            }

            
        }

        return mentions;
    }
};