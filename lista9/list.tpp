namespace calc {
    template <typename U>
    std::ostream& operator << (std::ostream &wyj, const list<U> &l) {
        wyj << "[";
        auto cur = l.head;
        while(cur != nullptr) {
            wyj << cur->val << (cur->next != nullptr?", ":"");
            cur = cur->next;
        }
        wyj << "]";
        return wyj;
    }
    template <typename U>
    void listswap(list<U> &l1, list<U> &l2) {
        std::swap(l1.head, l2.head);
        std::swap(l1.length, l2.length);
    }

    template <typename U, class Compare = std::less_equal<U>>
    bool issorted(const list<U> &list, Compare cmp = Compare()) {
        if(std::is_same<const char *, U>::value) {
            auto cmp = [](const char* a, const char* b)
            {
                return strcmp(a,b)<0;
            };
        }
        bool sorted = true;
        if(list.get_len() <= 1) return true;
        auto *prev = list.get_head();
        auto *cur = list.get_head()->next;
        while(cur){
            if(!cmp(prev->val, cur->val)) sorted = false;
            prev = cur;
            cur = cur->next;
        }
        return sorted;
    }
    template <typename U, class Compare = std::less_equal<U>>
    void sort(list<U> &list, Compare cmp = Compare()) {
        if(list.get_len() <= 1) return;
        for(int i = 0; i < list.get_len(); i++) {
            auto *prev = list.get_head();
            auto *cur = list.get_head()->next;
            while(cur){
                if(!cmp(prev->val, cur->val)) {
                    U tmp = prev->val;
                    prev->val = cur->val;
                    cur->val = tmp;
                }
                prev = cur;
                cur = cur->next;
            }
        }
    }
    template <typename T>
    list<T>::node::node(T val2, node *next2) {
        val = val2;
        next = next2;
    } 
    template <typename T>
    list<T>::list() {
        length = 0;
        head = nullptr;
    }
    template <typename T>
    list<T>::list(const list<T> &l) {
        list<T> tmp;
        tmp.head = l.head;
        tmp.length = l.length;
        calc::listswap(*this, tmp);
    }
    template <typename T>
    list<T>::list(list<T> &&l) {
        calc::listswap(*this, l);
    }
    template <typename T>
    list<T>::list(std::initializer_list<T> init) {
        length = 0;
        head = nullptr;
        for(T x : init) {
            push_back(x);
        }
    }
    template <typename T>
    list<T>::~list() {
        while(head) {
            node *cur = head;
            head = head->next;
            delete cur;
        }
    }
    template <typename T>
    list<T>& list<T>::operator=(const list<T> &l) {
        list<T> l2(l);
        return l2;
    }
    template <typename T>
    list<T>& list<T>::operator=(list<T> &&l) {
        listswap(*this, l);
        return *this;
    }
    template <typename T>
    void list<T>::insert(int idx, T val) {
        if(idx > length || idx < 0)
            throw std::invalid_argument("wrong index");
        if(idx == 0) {
            head = new node(val, head);
        } else {
            node *prev = nullptr;
            node *cur = head;
            for(int i = 0; i < idx; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = new node(val, cur);
        }
        length++;
    }
    template <typename T>
    void list<T>::push_back(T val) {
        insert(length, val);
    }
    template <typename T>
    void list<T>::push_front(T val) {
        insert(0, val);
    }
    template <typename T>
    T list<T>::erase(int idx) {
        if(idx < 0 || idx >= length)
            throw std::invalid_argument("wrong idx");
        if(length == 0)
            throw std::invalid_argument("empty list");
        T val;
        if(idx == 0) {
            node *cur = head;
            val = head->val;
            head = head->next;
            delete cur;
        } else {
            node *prev = nullptr;
            node *cur = head;
            for(int i = 0; i < idx; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            val = cur->val;
            delete cur;
        }
        length--;
        return val;
    }
    template <typename T>
    T list<T>::pop_back() {
        return erase(length-1);
    }
    template <typename T>
    T list<T>::pop_front() {
        return erase(0);
    }
    template <typename T>
    void list<T>::erase_val(T val) {
        node *cur = head;
        int idx = 0;
        while(cur && cur->val != val) {
            idx++;
            cur = cur->next;
        }
        if(cur == nullptr) 
            throw std::invalid_argument("havent found elem");
        erase(idx);
    }
    template <typename T>
    void list<T>::erase_all_val(T val) {
        while(true) {
            try{
                erase_val(val);
            } catch(const std::invalid_argument &e) {
                break;
            }
        }
    }
    template <typename T>
    int list<T>::find_val(T val) {
        node *cur = head;
        int idx = 0;
        while(cur && cur->val != val) {
            idx++;
            cur = cur->next;
        }
        if(cur == nullptr) 
            throw std::invalid_argument("havent found elem");
        return idx;
    }
    template <typename T>
    int list<T>::count_val(T val) {
        node *cur = head;
        int cnt = 0;
        while(cur) {
            if(cur->val) cnt++;
            cur = cur->next;
        }
        return cnt;
    }
    template <typename T>
    int list<T>::get_len() const {
        return length;
    }
    template <typename T>
    bool list<T>::is_empty() {
        return length == 0;
    }
    template<typename T>
    typename list<T>::node *list<T>::get_head() const {
        return head;
    }

    template <typename T>
    lqueue<T>::lqueue() : list<T>() {
        l = list<T>();
    }
    template <typename T>
    lqueue<T>::~lqueue() {
        delete l;
    }
    template <typename T>
    void lqueue<T>::push(T val) {
        push_back(val);
    }
    template <typename T>
    T lqueue<T>::pop() {
        return l.pop_front();
    }
    template <typename T>
    lstack<T>::lstack() {
        l = list<T>();
    }
    template <typename T>
    lstack<T>::~lstack() {
        delete l;
    }
    template <typename T>
    void lstack<T>::push(T val) {
        l.push_front(val);
    }
    template <typename T>
    T lstack<T>::pop() {
        return l.pop_front();
    }
    
};
