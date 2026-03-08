// Last updated: 08/03/2026, 13:22:53
#define vi vector<int>
#define pb push_back

class Router {
public:
    set<vector<int>> packetSet; 
    queue<vector<int>> packetQueue; 
    unordered_map<int, vector<int>> timestamps; 
    unordered_map<int, int> forwardedCount;  
    int maxSize;

    Router(int memoryLimit)
    {
        maxSize=memoryLimit;
    }

    bool addPacket(int source, int destination, int timestamp) {
        vi packet = {source, destination, timestamp};

      
        if (packetSet.count(packet))
            return false;

     
        if (packetQueue.size() == maxSize) {
            vector<int> oldest=packetQueue.front();
            packetQueue.pop();
            packetSet.erase(oldest);

            forwardedCount[oldest[1]]++; 

        }

      
        packetQueue.push(packet);
        packetSet.insert(packet);
        timestamps[destination].pb(timestamp);
        return true;
    }

    vector<int> forwardPacket()
    {
        if (packetQueue.empty())
            return {};



        vector<int> frontPacket = packetQueue.front();
        packetQueue.pop();
        packetSet.erase(frontPacket);
        forwardedCount[frontPacket[1]]++; 
        return frontPacket;
    }

    int getCount(int destination, int startTime, int endTime)
    {
        if (timestamps.find(destination) == timestamps.end())
            return 0;

        auto &times=timestamps[destination];
        int skip=forwardedCount[destination]; 
        auto left=lower_bound(times.begin() + skip, times.end(), startTime);
        auto right=upper_bound(times.begin() + skip, times.end(), endTime);
        return int(right-left);
        


    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */