// dfs
struct Person {
    string name;
    Person *mother;   // left
    Person *father;   // right
    Person(string x) : name(x), mother(NULL), father(NULL) {}
};

class Solution {
public:
    vector<string> findAllAncestors(Person* root) {
        vector<string> res;
        findAncestors(root->mother, res);
        findAncestors(root->father, res);
        return res;
    }

    void findAncestors(Person* root, vector<string>& res) {
        if(!root) return;
        res.push_back(root->name);
        findAncestors(root->mother, res);
        findAncestors(root->father, res);
    }
};

int main() {
    Person* root = new Person("a");
    Person* p1 = new Person("b");
    Person* p2 = new Person("c");
    Person* p3 = new Person("d");
    Person* p4 = new Person("e");
    Person* p5 = new Person("f");
    Person* p6 = new Person("g");

    root->mother = p1;
    root->father = p2;
    p1->mother = p3;
    p1->father = p4;
    p2->mother = p5;
    p2->father = p6;

    Solution sol;
    sol.findAllAncestors(root);
}



// bfs
struct Person {
    string name;
    Person *mother;   // left
    Person *father;   // right
    Person(string x) : name(x), mother(NULL), father(NULL) {}
};

class Solution {
public:
    vector<string> findAllAncestors(Person* root) {
        vector<string> res;
        queue<Person*> qu;
        qu.push(root);

        while(!qu.empty()) {
            root = qu.front();
            qu.pop();
            if(root->mother) {
                qu.push(root->mother);
                res.push_back(root->mother->name);
            }
            if(root->father) {
                qu.push(root->father);
                res.push_back(root->father->name);
            }
        }
        return res;
    }
};

int main() {
    Person* root = new Person("a");
    Person* p1 = new Person("b");
    Person* p2 = new Person("c");
    Person* p3 = new Person("d");
    Person* p4 = new Person("e");
    Person* p5 = new Person("f");
    Person* p6 = new Person("g");
    Person* p7 = new Person("h");
    Person* p8 = new Person("i");
    Person* p9 = new Person("j");
    Person* p10 = new Person("k");
    Person* p11 = new Person("l");
    Person* p12 = new Person("m");
    Person* p13 = new Person("n");
    Person* p14 = new Person("o");

    root->mother = p1;
    root->father = p2;
    p1->mother = p3;
    p1->father = p4;
    p2->mother = p5;
    p2->father = p6;
    p3->mother = p7;
    p3->father = p8;
    p4->mother = p9;
    p4->father = p10;
    p5->mother = p11;
    p5->father = p12;
    p6->mother = p13;
    p6->father = p14;
    Solution sol;
    sol.findAllAncestors(root);
}
