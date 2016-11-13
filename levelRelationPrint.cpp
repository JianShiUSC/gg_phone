struct Person {
    string name;
    string id;
    string parentId;
    Person(string _name, string _id, string _parentId) : name(_name), id(_id), parentId(_parentId) {}
};

vector<string> levelRelationPrint(vector<Person> nums) {
    int size = nums.size();
    vector<string> res;
    unordered_map<string, vector<string>> graph;

    for(int i = 0; i < size; i++) {
        graph[nums[i].parentId].push_back(nums[i].id);
    }

    queue<string> qu;
    for(int i = 0; i < size; i++) {
        if(nums[i].parentId == nums[i].id) {
            qu.push(nums[i].id);
            break;
        }
    }

    while(!qu.empty()) {
        string temp = qu.front();
        res.push_back(temp);
        qu.pop();

        for(auto person : graph[temp]) {
            if(person != temp) {
                qu.push(person);
            }
        }
    }
    return res;
}


int main() {
    vector<Person> nums;
    Person manager = Person("shijian", "1", "1");
    Person p1 = Person("p1", "2", "1");
    Person p2 = Person("p2", "3", "2");
    Person p3 = Person("p3", "4", "2");
    Person p4 = Person("p4", "5", "1");
    nums.push_back(manager);
    nums.push_back(p1);
    nums.push_back(p2);
    nums.push_back(p3);
    nums.push_back(p4);
    levelRelationPrint(nums);
}
