#include "Factory.h"
#include "GameObject.h"
#include "Smurf.h"
#include "Present.h"
#include "Shot.h"
#include "Cat.h"
#include "Rock.h"
#include "Tree.h"
#include "cake.h"
#include "House.h"
#include "Papa.h"

myMapType Factory::m_map = createMap();
//////////////////////////////////////////////////////////////////

myMapType Factory::createMap()
{
	myMapType newMap;
	newMap["Smurf"] = [](V2f  &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Smurf>(s, p,1); };
	newMap["Present"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Present>(s, p); };
	newMap["Cat"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Cat>(s, p); };
	newMap["Shot"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Shot>(s, p); };
	newMap["Papa"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Papa>(s, p); };
	newMap["Tree"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Tree>(s, p); };
	newMap["Cake"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Cake>(s, p); };
	newMap["House"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<House>(s, p); };
	newMap["Rock"] = [](V2f &s, V2f& p)->std::shared_ptr<GameObject> {return std::make_shared<Rock>(s, p); };

	return newMap;
}
//////////////////////////////////////////////////////////////////

std::shared_ptr<GameObject> Factory::create(const std::string & name, V2f & scaling, V2f & position)
{
	auto it = m_map.find(name);
	if (it == m_map.end())
		return nullptr;

	return it->second(scaling, position);
}
//////////////////////////////////////////////////////////////////

bool Factory::registerit(const std::string & name, std::shared_ptr<GameObject>(*f)(V2f &scaling, V2f &position))
{
	m_map.emplace(name, f);
	return true;
}
