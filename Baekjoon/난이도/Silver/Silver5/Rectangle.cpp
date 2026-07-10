#include <iostream>
using namespace std;

class Rectangle{
    private:
        int width, height;
    public:
        Rectangle(int x=0, int y=0):width(x),height(y){}
        int get_width() const{
            return width;
        }
        int get_height() const{
            return height;
        }
        void set_width(int new_width){
            if(new_width>0 && new_width<=1000){
                width=new_width;
            }
        }
        void set_height(int new_height){
            if(new_height>0 && new_height<=2000){
                height=new_height;
            }
        }
        int area() const{
            return width*height;
        }
        int perimeter() const{
            return 2*(width+height);
        }
        bool is_square() const{
            if(width==height)
                return true;
            else
                return false;
        }
};

int main(void){
    Rectangle rect(10,20);
    cout << "Width: " << rect.get_width() << endl;
    cout << "Height: " << rect.get_height() << endl;
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;
    cout << "Is square? " << (rect.is_square() ? "Yes" : "No") << endl;

    rect.set_width(30);
    rect.set_height(30);
    cout << "Width: " << rect.get_width() << endl;
    cout << "Height: " << rect.get_height() << endl;
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;
    cout << "Is square? " << (rect.is_square() ? "Yes" : "No") << endl;

    return 0;
}