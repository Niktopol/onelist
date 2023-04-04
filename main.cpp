#include <iostream>
struct list {
private:
    struct item{
        int val;
        int id;
        item *next;
        item(int nval, int nid = 0, item* nxt = nullptr):
                val(nval), id(nid), next(nxt){
        };
        void chngId(int frid, int val){
            for (item* p = this; p; p = p->next){
                if (p->id >= frid){
                    p->id += val;
                }
            }
        }
    };
    int len = 0;
    item *fst = nullptr;
public:
    int getLen(){
        return len;
    }
    int getVal(int fid){
        item* p = fst;
        for (; p->id!=fid; p = p->next);
        return p->val;
    }
    void append(int nval){
        len += 1;
        if (!fst){
            fst = new item(nval);
        }else{
            item* p = fst;
            fst = new item(nval, 0, fst);
            p->chngId(p->id, 1);
        }
    }
    void printList(){
        for (item* p = fst; p; p = p->next){
            std::cout << p->id << "   " << p->val << std::endl;
        }
    }
    void del(int frid){
        if (((frid+1) <= len) and frid >= 0){
            len -= 1;
            if (!frid){
                item *temp = fst;
                fst = temp->next;
                delete temp;
                if (fst){
                    fst->chngId(frid+1, -1);
                }
            }else{
                item* p = fst;
                for (; (p->id+1)!=frid; p = p->next);
                item *temp = p->next;
                p->next = temp->next;
                delete temp;
                p->chngId(frid+1, -1);
            }
        }
    }
    ~list(){
        item *temp;
        len = 0;
        while (fst){
            temp = fst;
            fst = fst->next;
            delete temp;
        }
        fst = nullptr;
    }
};

void func(){
    list* a = new list();
    a->append(10);
    a->append(13);
    a->append(54);
    a->append(84);
    a->append(65);
    a->append(16);
    a->append(98);
    a->append(45);
    a->printList();
    std::cout << std::endl;

    list* b = new list();
    b->append(10);
    b->append(13);
    b->append(3);
    b->append(6);
    b->append(48);
    b->append(16);
    b->append(64);
    b->append(45);

    b->printList();
    std::cout << std::endl;

    list* c = new list();
    for (int i = 0; i < a->getLen(); i ++){
        c->append(a->getVal(i));
    }
    for (int i = 0; i < b->getLen(); i ++){
        bool k = true;
        for (int j = 0; j < c->getLen(); j ++){
            if (b->getVal(i) == c->getVal(j)){
                k = false;
                break;
            }
        }
        if (k){
            c->append(b->getVal(i));
        }
    }
    c->printList();
    std::cout << std::endl;
    delete a;
    delete b;
    delete c;
}
int main() {
    //func();
    list* a = new list();
    a->append(1);
    a->append(2);
    a->printList();
    a->del(0);
    a->printList();
    a->del(0);
    a->printList();
    a->append(10);
    a->printList();
    delete a;
    return 0;
}
