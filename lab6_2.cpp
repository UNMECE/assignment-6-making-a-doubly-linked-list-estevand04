#include <iostream>
#include <cstdlib>
#include <cmath>
#include "coordinate.h"
#include <limits>



class CoordinateList{
private:
        Coordinate* head;
        Coordinate* tail;
        int count;
        int idCounter;

public:
        CoordinateList() : head(nullptr), tail(nullptr), count(0), idCounter(0){}

void add_coordinate(int x, int y){
        Coordinate* new_coord = new Coordinate(x, y, ++idCounter);
if(!head){
        head = tail = new_coord;
} else {
        tail->next = new_coord;
        new_coord->previous = tail;
        tail = new_coord;
        }
count++;
}

void forward_display(){
        Coordinate* current = tail;
        while (current) {
                std::cout << "ID:" << current->coord_id << " |X: " << current->x << " |Y: " << current->y << std::endl;
        current = current->previous;
   }
}

void backward_display() {
    Coordinate* current = tail;
    while (current){
        std::cout << "ID: " << current->coord_id << "|X:" << current->x << "|Y:" << current->y << std::endl;
        current = current->previous;
    }
}

void delete_coordinate(int id){
        Coordinate* current = head;
        while (current) {
                if (current->coord_id == id) {
                        if (current->previous){
                                current->previous->next = current->next;
                        } else {
                                head = current->next;
                        }
                if (current->next){
                        current->next->previous = current->previous;
                } else {
                        tail = current->previous;
                }
        delete current;
        count--;
        return;
        }
        current = current->next;
        }
std::cout << "Coordinate with their ID" << id << "not found!" << std::endl;
}

int list_length(){
        return count;
}

void closest_to(int x, int y){
        Coordinate* current = head;
 double min_distance = std::numeric_limits<double>::max();
        Coordinate* closest_coord = nullptr;

        while (current){
                double distance = std::sqrt(std::pow(current->x - x, 2) + std::pow(current->y - y, 2));
        if (distance < min_distance){
                min_distance = distance;
                closest_coord = current;
        }
        current = current->next;
}

if (closest_coord) {
        std::cout << "Closest Coordinate ID: " << closest_coord->coord_id << " |X: " << closest_coord->x << " |Y:" << closest_coord <<  "| Distance: " << min_distance << std::endl;
}
}
};

int main(int argc, char* argv[]) {
        if (argc < 2){
                std::cerr << "please input the number of coordinates: " << std::endl;
                return 1;
                }
        int num_coords = std::atoi(argv[1]);
        CoordinateList coord_list;

        int i;
        for (i=0; i<num_coords; ++i){
                int x = rand() % 100; //random x from  0 to 99
                int y = rand() % 100; //random y from 0 to 99
                coord_list.add_coordinate(x, y);
        }
  std::cout << "Coordinate(Forward):" << std::endl;
        coord_list.forward_display();

        std::cout << "Coordinates(Backward):" << std::endl;
        coord_list.backward_display();

        coord_list.delete_coordinate(2); //example to delete coordinate with ID of 2
        std::cout << "after deletion: " << std::endl;
        coord_list.forward_display();

        coord_list.closest_to(50, 50); //example to find closest to (50,50)

return 0;
}
