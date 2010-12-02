#ifndef DATABASE_H
#define DATABASE_H
#include "book.h"
class Database
{
    public:
        Database();
        ~Database();
        Database(const Database& other);
        void operator =(const Database& other);
        void resize();
        void search(std::string name);
        void search_id(int id);
        void add(const Book& bk);
        void display_all();
        void remove(std::string name);
        void save(std::ostream& outs):
        void load(std::istream& ins);
        void sort_title();
        void sort_author();
    private:
        void increase_volume();
        int capacity;
        Book *data;
        int used;
};
#endif