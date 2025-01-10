#ifndef __LIST_INCLUDED_
#define __LIST_INCLUDED_
#include <iostream>
namespace calc {
    template<typename T>
    class list {
        template<typename U>
        friend std::ostream& operator << (std::ostream &wyj, const list<U> &l);
        template<typename U>
        friend void listswap(list<U> &l1, list<U> &l2);
        template <typename U, class Compare>
        friend bool issorted(const list<U> &list, Compare cmp);
        template <typename U, class Compare>
        friend void sort(list<U> &list, Compare cmp);
        protected:
            class node {
                public:
                    T val;
                    node *next;
                    node(T val2, node *next2);
            };
            int length;
            node *head;
        public:
            list();
            list(const list<T> &l);
            list(list<T> &&l);
            list(std::initializer_list<T> init);
            ~list();
            list<T>& operator=(const list<T> &l);
            list<T>& operator=(list <T> &&l);
            void insert(int idx, T val);
            void push_back(T val);
            void push_front(T val);
            T erase(int idx);
            T pop_front();
            T pop_back();
            void erase_val(T val);
            void erase_all_val(T val);
            int find_val(T val);
            int count_val(T val);
            int get_len() const;
            bool is_empty();
            node* get_head() const;
    };
    template<typename T>
    class lqueue : private list<T> {
        private:
            list<T> l;
        public:
            lqueue();
            ~lqueue();
            void push(T val);
            T pop();
    };
    template<typename T>
    class lstack : private list<T> {
        private:
            list<T> l;
        public:
            lstack();
            ~lstack();
            void push(T val);
            T pop();
    };
}
#include "list.tpp"

#endif