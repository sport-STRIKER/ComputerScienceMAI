#ifndef NPC_H
#define NPC_H

#include "declaration.h"
#include "observer.h"

class NPC : public std::enable_shared_from_this<NPC>
{
    public:
        NPC(NpcType _type, std::string _name, int _x, int _y);
        NPC(NpcType _type, std::istream& is);
        virtual ~NPC() = default;

        std::string getName();
        std::string getType();
        float distance(NPC &other);

        virtual bool accept(NPC &visitor) = 0;
        virtual bool visit(Bear &monster);
        virtual bool visit(Squirrel &monster);
        virtual bool visit(Orc &monster);

        size_t countObservers();
        void subscribe(std::shared_ptr<Observer> observer);
        void unsubscribe(std::shared_ptr<Observer> observer);
        void notify(NPC &attacker, NPC &defender);

        friend std::ostream &operator<<(std::ostream &os, NPC &npc);

    public:
        NpcType type;
        std::string name;
        int x;
        int y;
        std::set<std::shared_ptr<Observer>> observers;
};

#endif
