#pragma once

#include <algorithm>
#include <map>
#include <utility>

#include "Objects/VisibleObject.hh"



class ObjectManager
{

    public:

        ObjectManager();
        ~ObjectManager();

        void add(std::string name, VisibleObject* obj);
        void remove(std::string name);
        void clear();

        int get_object_count() const;
        VisibleObject* get(std::string name) const;

        void draw_all(sf::RenderWindow& window);
        void update_all();


    private:

        std::map<std::string, VisibleObject*> obj_map_;

        struct ObjectDeallocator
        {
            void operator()(const std::pair<std::string, VisibleObject*>& pair) const
            {
                delete pair.second;
            }
        };
};
