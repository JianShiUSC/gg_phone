struct ListNode {
    string value;
    ListNode* pre;
    ListNode* next;
    ListNode(string v) : value(v), pre(NULL), next(NULL) {}
};

ListNode* remove(ListNode* head, set<string> candidates) {
    ListNode* super = new ListNode("0");
    super->next = head;
    head->pre = super;
    head = super;

    while(head->next) {
        if(candidates.find(head->next->value) != candidates.end()) {
            head->next = head->next->next;
            if(head->next) {
                head->next->pre = head;
            }
        } else {
            head = head->next;
        }
    }
    ListNode* res = super->next;
    if(res) {
        res->pre = NULL;
    }
    delete super;
    return res;
}

int main() {
    ListNode* n1 = new ListNode("1");
    ListNode* n2 = new ListNode("2");
    ListNode* n3 = new ListNode("3");
    ListNode* n4 = new ListNode("4");
    ListNode* n5 = new ListNode("5");
    ListNode* n6 = new ListNode("6");

    n1->next = n2;
    n2->pre = n1;
    n2->next = n3;
    n3->pre = n2;
    n3->next = n4;
    n4->pre = n3;
    n4->next = n5;
    n5->pre = n4;
    n5->next = n6;
    n6->pre = n5;

    set<string> candidates = {"1","6", "7", "8"};
    remove(n1, candidates);
}
