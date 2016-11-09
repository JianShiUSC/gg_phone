struct Message {
    string parentId;
    string id;
    string content;
    Message(string x, string y, string z) : parentId(x), id(y), content(z) {}
};

class Solution {
public:
    vector<string> messageSchedule(vector<Message> messages, Message* rootMessage) {
        vector<string> res;
        unordered_map<string, unordered_set<string>> graph;
        for(auto message : messages) {
            if(message.id != rootMessage->id) {
                graph[message.parentId].insert(message.id);
            }
        }

        queue<string> qu;
        qu.push(rootMessage->id);

        while(!qu.empty()) {
            string temp = qu.front();
            qu.pop();
            res.push_back(temp);
            for(auto message : graph[temp]) {
                qu.push(message);
            }
        }
        return res;
    }
};


int main() {
    Message* p1 = new Message("1", "1", "我是你大爷");
    Message* p2 = new Message("1", "2", "我是你大爷");
    Message* p3 = new Message("1", "3", "我是你大爷");
    Message* p4 = new Message("2", "4", "我是你大爷");
    Message* p5 = new Message("3", "5", "我是你大爷");
    Message* p6 = new Message("5", "6", "我是你大爷");
    vector<Message> messages;
    messages.push_back(*p1);
    messages.push_back(*p2);
    messages.push_back(*p3);
    messages.push_back(*p4);
    messages.push_back(*p5);
    messages.push_back(*p6);
    Solution sol;
    sol.messageSchedule(messages, p1);
}
