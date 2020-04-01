#include "Objects/ObjectManager.hh"
#include "Game/Game.hh"



ObjectManager::ObjectManager()
{}




ObjectManager::~ObjectManager()
{
    std::for_each(obj_map_.begin(), obj_map_.end(), ObjectDeallocator());
}




void ObjectManager::add(std::string name, VisibleObject* obj)
{
    obj_map_.insert(std::pair<std::string, VisibleObject*>(name, obj));
}




void ObjectManager::remove(std::string name)
{
    std::map<std::string, VisibleObject*>::iterator map_iter = obj_map_.find(name);

    if (map_iter != obj_map_.end())
    {
        delete map_iter->second;
        obj_map_.erase(map_iter);
    }
}




VisibleObject* ObjectManager::get(std::string name) const
{
    std::map<std::string, VisibleObject*>::const_iterator map_iter = obj_map_.find(name);

    if (map_iter == obj_map_.end())
        return NULL;

    return map_iter->second;
}




int ObjectManager::get_object_count() const
{
    return obj_map_.size();
}




void ObjectManager::draw_all(sf::RenderWindow& window)
{
    std::map<std::string, VisibleObject*>::const_iterator map_iter = obj_map_.begin();

    while (map_iter != obj_map_.end())
    {
        map_iter->second->draw(window);
        map_iter++;
    }
}




void ObjectManager::update_all()
{
    std::map<std::string, VisibleObject*>::const_iterator map_iter = obj_map_.begin();
    float frame_rate = 1;

    while (map_iter != obj_map_.end())
    {
        map_iter->second->update(frame_rate);
        map_iter++;
    }
}
