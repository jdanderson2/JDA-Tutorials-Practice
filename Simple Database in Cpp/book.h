#ifndef BOOK_H
#define BOOK_H
class Book
{
    public:
        Book();
        Book(std::string new_title, int new_id, std::string new_location, double new_price, int new_years_);
        //accesors
        std::string get_title()const{return name;}
        int get_id_number()const{return location;}
        double get_price()const{return price;}
        int get_year_published()const{return year_published;}
        void output(std::ostream& outs);
        void input(std::istream& ins);
    private:
        std::string name;
        int id_number;
        std::string location;
        double price;
        int year_published;
};
std::ostream& operator <<(std::ostream& outs, Book& tmp);
std::istream& operator >>(std::istream ins, Bokk& tmp);
#endif